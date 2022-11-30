#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Graphismes/graphismes.h"
#include "Donnees/donnees.h"
#include "Donnees/constantes.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED

// Boucle de jeu
void boucleDeJeu(SDL_Renderer* renderer, player* player, listEnemy* listeEnnemis, listBloc* listeBlocs, listBullet* listeBalles){
    int is_playing = 1;
    int fps = 1;
    int fpstimer = 0;
    Uint32 start = SDL_GetTicks();

    double startFire = 0.;

    initTextures(renderer,player,listeEnnemis,listeBlocs);

    while(is_playing){
        Uint32 end = SDL_GetTicks();

        //Cap à 60 fps
        if(fpsCap(start,&end)) {continue;}

        moveListEnemyToPlayer(listeEnnemis, player, (end-start)/1000.);
        moveBullets(listeBalles);

        // Gestion des evenements
        SDL_Event event;
        handleEvents(&event, &is_playing, player, listeBlocs, listeBalles,(end-start)/1000., &startFire);

        //Fermeture du jeu
        if(!is_playing){break;}

        //Rafraichissement de l'ecran
        SDL_RenderClear(renderer);


        //Affichage des sprites
        drawListBlocSprites(renderer, listeBlocs);
        drawSprite(renderer, (int)getPlayerPosX(player), (int)getPlayerPosY(player), PLAYER_SIZE, PLAYER_SIZE, 0, getPlayerTexture(player));
        drawListEnemySprites(renderer, listeEnnemis);

        initListBulletTextures(renderer, listeBalles);
        drawListBulletSprites(renderer, listeBalles);

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
    listBullet listeBalles = initListBullet();
  

    // Creation de la fenetre
    if(SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Project A");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

    boucleDeJeu(renderer, &joueur, &listeEnnemis, &listeBlocs, &listeBalles);
    endSDL(fenetre, renderer, &joueur, &listeEnnemis, &listeBlocs, &listeBalles);
    freeListEnemy(&listeEnnemis);
    freeListBloc(&listeBlocs);
    return 0; 
}
