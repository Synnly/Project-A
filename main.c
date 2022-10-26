#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "donnees.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED

// Boucle de jeu
void boucleDeJeu(SDL_Renderer* renderer){
    while(1){
        SDL_Event event;

        //Fermeture du jeu
        if((SDL_PollEvent(&event) && (event.type==SDL_QUIT)) || (event.type = SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
            break;
        }

        

        //Rafraichissement de l'ecran
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}

int main(){
    SDL_SetMainReady();
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("Erreur d'initilisation de SDL : %s", SDL_GetError());
        return -1;
    }

    SDL_Window* fenetre;
    SDL_Renderer* renderer;
    player* joueur = initPLayer();

    if(SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Project A");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

    //initWindow(fenetre, renderer);

    boucleDeJeu(renderer);

    endSDL(fenetre, renderer);
    return 0; 
}