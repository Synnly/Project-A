#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "donnees.h"
#include <stdio.h>
#include <time.h>
#define SDL_MAIN_HANDLED

// Boucle de jeu
void boucleDeJeu(SDL_Renderer* renderer, player* player){
    int is_playing = 1;
    while(is_playing){
        SDL_Event event;

        // Gestion des evenements
        handleEvents(&event, &is_playing, player);

        //Fermeture du jeu
        if(!is_playing){break;}

        printf("x : %d, y : %d\n", getPlayerPosX(player), getPlayerPosY(player));


        //Rafraichissement de l'ecran
        SDL_RenderClear(renderer);

        //Affichage du joueur
        drawSprite(renderer, getPlayerPosX(player), getPlayerPosY(player), PLAYER_SIZE, PLAYER_SIZE, "assets/img/player.bmp");

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
    player joueur = initPLayer();

    // Creation de la fenetre
    if(SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Project A");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);



    boucleDeJeu(renderer, &joueur);

    endSDL(fenetre, renderer);
    return 0; 
}