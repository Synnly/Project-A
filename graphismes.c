#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"

void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}


void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, const char* file){
    SDL_Surface* sprite = SDL_LoadBMP(file);
    SDL_Texture* textureSprite = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer,textureSprite,NULL,&dest);
}