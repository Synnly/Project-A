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
    int fps = 0;
    int fpstimer = 0;
    Uint32 start = SDL_GetTicks();
    Uint32 end = SDL_GetTicks();

    while(is_playing){

        //Cap à 60 fps
        if(fpsCap(start,&end)) {continue;}

        SDL_Event event;

        // Gestion des evenements
        handleEvents(&event, &is_playing, player, (end-start)/1000.);

        //Fermeture du jeu
        if(!is_playing){break;}

        //printf("x : %d, y : %d\n", getPlayerPosX(player), getPlayerPosY(player));
        

        //Rafraichissement de l'ecran
        SDL_RenderClear(renderer);

        //Affichage du joueur
        drawSprite(renderer, (int)getPlayerPosX(player), (int)getPlayerPosY(player), PLAYER_SIZE, PLAYER_SIZE, "assets/img/player.bmp");

        SDL_RenderPresent(renderer);
        
        //Gestion des fps
        fps++;
        start = end;
        fpsCounter(&fps,&fpstimer);

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