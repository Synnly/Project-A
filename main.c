#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphismes.h"
#include "donnees.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED

// Boucle de jeu
void boucleDeJeu(SDL_Renderer* renderer, player* player, listEnemy* listeEnnemis){
    int is_playing = 1;
    int fps = 0;
    int fpstimer = 0;
    Uint32 start = SDL_GetTicks();

    
    float x, y;
    x = getEnemyPosX(getEnemy(listeEnnemis));
    y = getEnemyPosY(getEnemy(listeEnnemis));
    printf("%f, %f\n", x, y);

    initTextures(renderer,player,getEnemy(listeEnnemis));

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

        moveToPlayer(getEnemy(listeEnnemis), player, (end-start)/1000.);

        x = getEnemyPosX(getEnemy(listeEnnemis));
        y = getEnemyPosY(getEnemy(listeEnnemis));
        printf("%f, %f\n", x, y);

        //Affichage du joueur
        drawSprite(renderer, (int)getPlayerPosX(player), (int)getPlayerPosY(player), PLAYER_SIZE, PLAYER_SIZE, getPlayerTexture(player));
        drawSprite(renderer, (int)getEnemyPosX(getEnemy(listeEnnemis)), (int)getEnemyPosY(getEnemy(listeEnnemis)), PLAYER_SIZE, PLAYER_SIZE, getEnemyTexture(getEnemy(listeEnnemis)));

        //printf("x %f, y %f\n", getEnemyPosX(&ennemi), getEnemyPosY(&ennemi));
        //printf("x : %f, y : %f\n", getPlayerPosX(player), getPlayerPosY(player));

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
    listEnemy listeEnnemis = initListEnemy(1);
  

    // Creation de la fenetre
    if(SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Project A");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

    boucleDeJeu(renderer, &joueur, &listeEnnemis);

    endSDL(fenetre, renderer, &joueur, getEnemy(&listeEnnemis));
    return 0; 
}