#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "donnees.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED

// Boucle de jeu
void boucleDeJeu(SDL_Renderer* renderer, player* player, listEnemy* listeEnnemis, listBloc* listeBlocs){
    int is_playing = 1;
    int fps = 0;
    int fpstimer = 0;
    Uint32 start = SDL_GetTicks();

    initTextures(renderer,player,listeEnnemis,listeBlocs);

    while(is_playing){
        Uint32 end = SDL_GetTicks();

        //Cap à 60 fps
        if(fpsCap(start,&end)) {continue;}

        // Gestion des evenements
        SDL_Event event;
        handleEvents(&event, &is_playing, player, (end-start)/1000.);

        //Fermeture du jeu
        if(!is_playing){break;}

        //Rafraichissement de l'ecran
        SDL_RenderClear(renderer);

        moveListEnemyToPlayer(listeEnnemis, player, (end-start)/1000.);

        //printf("%f, %f\n", getEnemyPosX(getEnemy(listeEnnemis)), getEnemyPosY(getEnemy(listeEnnemis)));
        //printf("%f, %f\n----------------\n", getEnemyPosX(getNext(getEnemy(listeEnnemis))), getEnemyPosY(getNext(getEnemy(listeEnnemis))));

        //Affichage du joueur
        drawListBlocSprites(renderer, listeBlocs);
        drawSprite(renderer, (int)getPlayerPosX(player), (int)getPlayerPosY(player), PLAYER_SIZE, PLAYER_SIZE, getPlayerTexture(player));
        drawListEnemySprites(renderer, listeEnnemis);

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
    listBloc listeBlocs = initListBloc();
    player joueur = initPLayer();
    listEnemy listeEnnemis = initListEnemy(NB_ENNEMIS);
  

    // Creation de la fenetre
    if(SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Project A");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

    boucleDeJeu(renderer, &joueur, &listeEnnemis, &listeBlocs);
    endSDL(fenetre, renderer, &joueur, &listeEnnemis, &listeBlocs);
    freeListEnemy(&listeEnnemis);
    freeListBloc(&listeBlocs);
    return 0; 
}
