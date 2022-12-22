#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "../Donnees/constantes.h"

SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file){
    SDL_Surface* sprite = SDL_LoadBMP(file);
    SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 255, 0, 255));
    SDL_Texture* textureSprite = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);
    return textureSprite;
}

void initListBlocTextures(SDL_Renderer* renderer, bloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        for(int i = 0; i < sizeOfListBloc(ListeBlocs); i ++){
            setBlocTexture(getBloc(ListeBlocs,i),loadSprite(renderer, "assets/img/wall.bmp"));
        }
    }
}

void initListEnemyTextures(SDL_Renderer* renderer, listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        setEnemyTexture(getEnemy(ListeEnnemis),loadSprite(renderer, "assets/img/enemy.bmp"));
        initListEnemyTextures(renderer, getNextE(ListeEnnemis));
    }
}

void initListBulletTextures(SDL_Renderer* renderer, listBullet* listeBalles){
    if(!isEmptyListBullet(listeBalles)){
        if(getBulletTexture(getBullet(listeBalles)) == NULL){
            setBulletTexture(getBullet(listeBalles),loadSprite(renderer, "assets/img/bullet.bmp"));
        }
        initListBulletTextures(renderer, getNextBullet(listeBalles));
    }
}

void initTextures(SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, bloc* ListeBlocs){
    //Blocs
    initListBlocTextures(renderer, ListeBlocs);

    //Joueur
    setPlayerTexture(Player,loadSprite(renderer, "assets/img/player.bmp"));

    //Ennemis
    initListEnemyTextures(renderer, ListeEnnemis);
}

void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, int spriteIndex, SDL_Texture* textureSprite){

    // Rectangle source
    SDL_Rect src = {w*spriteIndex,0,w,h};

    // Rectangle destination
    SDL_Rect dest = {x, y, w, h};

    SDL_RenderCopy(renderer,textureSprite,&src,&dest);
}

void drawListBlocSprites(SDL_Renderer* renderer, bloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        for(int i = 0; i < sizeOfListBloc(ListeBlocs); i ++) {
            drawSprite(renderer, getBlocPosX(getBloc(ListeBlocs,i)), getBlocPosY(getBloc(ListeBlocs,i)), PLAYER_SIZE,
                       PLAYER_SIZE, getBlocIsObstacle(getBloc(ListeBlocs,i)), getBlocTexture(getBloc(ListeBlocs,i)));
        }
    }
}

void drawListEnemySprites(SDL_Renderer* renderer, listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        drawSprite(renderer, getEnemyPosX(getEnemy(ListeEnnemis)), getEnemyPosY(getEnemy(ListeEnnemis)), PLAYER_SIZE, PLAYER_SIZE, 0, getEnemyTexture(getEnemy(ListeEnnemis)));
        drawListEnemySprites(renderer, getNextE(ListeEnnemis));
    }
}

void drawListBulletSprites(SDL_Renderer* renderer, listBullet * ListeBalle){
    if(!isEmptyListBullet(ListeBalle)){
        drawSprite(renderer, getBulletPosX(getBullet(ListeBalle)), getBulletPosY(getBullet(ListeBalle)), getSpriteWidth(getBulletSprite(getBullet(ListeBalle))), getSpriteHeight(getBulletSprite(getBullet(ListeBalle))), 0, getBulletTexture(getBullet(ListeBalle)));
        drawListBulletSprites(renderer, getNextBullet(ListeBalle));
    }
}

void destroyListBlocTextures(bloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        for(int i = 0; i < sizeOfListBloc(ListeBlocs); i ++) {
            SDL_DestroyTexture(getBlocTexture(getBloc(ListeBlocs,i)));
        }
    }
}

void destroyListEnemyTextures(listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        SDL_DestroyTexture(getEnemyTexture(getEnemy(ListeEnnemis)));
        destroyListEnemyTextures(getNextE(ListeEnnemis));
    }
}

void destroyToBeDestroyedBulletTextures(listBullet* ListeBalles){
    if(!isEmptyListBullet(ListeBalles)){
        if(getSpriteToBeDestroyed(getBulletSprite(getBullet(ListeBalles)))){
            SDL_DestroyTexture(getBulletTexture(getBullet(ListeBalles)));
        }
        destroyToBeDestroyedBulletTextures(getNextBullet(ListeBalles));
    }
}

void destroyToBeDestroyedEnemyTextures(listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        if(getSpriteToBeDestroyed(getEnemySprite(getEnemy(ListeEnnemis)))){
            SDL_DestroyTexture(getEnemyTexture(getEnemy(ListeEnnemis)));
        }
        destroyToBeDestroyedEnemyTextures(getNextE(ListeEnnemis));
    }
}

void destroyListBulletTextures(listBullet * listeBalles){
    if(!isEmptyListBullet(listeBalles)){
        SDL_DestroyTexture(getBulletTexture(getBullet(listeBalles)));
        destroyListBulletTextures(getNextBullet(listeBalles));
    }
}

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, bloc* ListeBlocs, listBullet * ListeBalles){
    SDL_DestroyTexture(getPlayerTexture(Player));

    destroyListBlocTextures(ListeBlocs);
    destroyListEnemyTextures(ListeEnnemis);
    destroyListBulletTextures(ListeBalles);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);

    SDL_Quit();
}