#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "donnees.h"

SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file){
    SDL_Surface* sprite = SDL_LoadBMP(file);
    SDL_Texture* textureSprite = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);
    return textureSprite;
}

void initListEnemyTextures(SDL_Renderer* renderer, listEnemy* ListeEnnemis){
    if(!isEmpty(ListeEnnemis)){
        setEnemyTexture(getEnemy(ListeEnnemis),loadSprite(renderer, "assets/img/enemy.bmp"));
        initListEnemyTextures(renderer, getNext(ListeEnnemis));
    }
}

void initTextures(SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis){
    //Joueur
    setPlayerTexture(Player,loadSprite(renderer, "assets/img/player.bmp"));

    //Ennemis
    initListEnemyTextures(renderer, ListeEnnemis);
}

void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Texture* textureSprite){
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer,textureSprite,NULL,&dest);
}

void drawListEnemySprites(SDL_Renderer* renderer, listEnemy* ListeEnnemis){
    if(!isEmpty(ListeEnnemis)){
        drawSprite(renderer, getEnemyPosX(getEnemy(ListeEnnemis)), getEnemyPosY(getEnemy(ListeEnnemis)), PLAYER_SIZE, PLAYER_SIZE, getEnemyTexture(getEnemy(ListeEnnemis)));
        drawListEnemySprites(renderer, getNext(ListeEnnemis));
    }
}

void destroyListEnemyTextures(listEnemy* ListeEnnemis){
    if(!isEmpty(ListeEnnemis)){
        SDL_DestroyTexture(getEnemyTexture(getEnemy(ListeEnnemis)));
        destroyListEnemyTextures(getNext(ListeEnnemis));
    }
}

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis){
    SDL_DestroyTexture(getPlayerTexture(Player));
    destroyListEnemyTextures(ListeEnnemis);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}