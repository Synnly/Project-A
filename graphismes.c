#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "donnees.h"

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer, player* Player, enemy* Enemy){
    SDL_DestroyTexture(getPlayerTexture(Player));
    SDL_DestroyTexture(getEnemyTexture(Enemy));
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}


void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Texture* textureSprite){
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer,textureSprite,NULL,&dest);
}

SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file){
    SDL_Surface* sprite = SDL_LoadBMP(file);
    SDL_Texture* textureSprite = SDL_CreateTextureFromSurface(renderer, sprite);
    return textureSprite;
}

void initTextures(SDL_Renderer* renderer, player* Player, enemy* Enemy){
    setPlayerTexture(Player,loadSprite(renderer, "assets/img/player.bmp"));
    setEnemyTexture(Enemy,loadSprite(renderer, "assets/img/enemy.bmp"));
}