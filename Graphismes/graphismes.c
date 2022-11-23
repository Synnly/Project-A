#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "../Donnees/donnees.h"

SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file){
    SDL_Surface* sprite = SDL_LoadBMP(file);
    SDL_Texture* textureSprite = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);
    return textureSprite;
}

void initListBlocTextures(SDL_Renderer* renderer, listBloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        setBlocTexture(getBloc(ListeBlocs),loadSprite(renderer, "assets/img/wall.bmp"));
        initListBlocTextures(renderer, getNextB(ListeBlocs));
    }
}

void initListEnemyTextures(SDL_Renderer* renderer, listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        setEnemyTexture(getEnemy(ListeEnnemis),loadSprite(renderer, "assets/img/enemy.bmp"));
        initListEnemyTextures(renderer, getNextE(ListeEnnemis));
    }
}

void initTextures(SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, listBloc* ListeBlocs){
    //Blocs
    initListBlocTextures(renderer, ListeBlocs);

    //Joueur
    setPlayerTexture(Player,loadSprite(renderer, "assets/img/player.bmp"));

    //Ennemis
    initListEnemyTextures(renderer, ListeEnnemis);
}

void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, int spriteIndex, SDL_Texture* textureSprite){
    SDL_Rect src = {w*spriteIndex,0,w,h};
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer,textureSprite,&src,&dest);
}

void drawListBlocSprites(SDL_Renderer* renderer, listBloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        drawSprite(renderer, getBlocPosX(getBloc(ListeBlocs)),getBlocPosY(getBloc(ListeBlocs)),PLAYER_SIZE, PLAYER_SIZE, getBlocIsObstacle(getBloc(ListeBlocs)),getBlocTexture(getBloc(ListeBlocs)));
        drawListBlocSprites(renderer, getNextB(ListeBlocs));
    }
}

void destroyListBlocTextures(listBloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        SDL_DestroyTexture(getBlocTexture(getBloc(ListeBlocs)));
        destroyListBlocTextures(getNextB(ListeBlocs));
    }
}

void drawListEnemySprites(SDL_Renderer* renderer, listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        drawSprite(renderer, getEnemyPosX(getEnemy(ListeEnnemis)), getEnemyPosY(getEnemy(ListeEnnemis)), PLAYER_SIZE, PLAYER_SIZE, 0, getEnemyTexture(getEnemy(ListeEnnemis)));
        drawListEnemySprites(renderer, getNextE(ListeEnnemis));
    }
}


void destroyListEnemyTextures(listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        SDL_DestroyTexture(getEnemyTexture(getEnemy(ListeEnnemis)));
        destroyListEnemyTextures(getNextE(ListeEnnemis));
    }
}

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, listBloc* ListeBlocs){
    destroyListBlocTextures(ListeBlocs);
    SDL_DestroyTexture(getPlayerTexture(Player));
    destroyListEnemyTextures(ListeEnnemis);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}