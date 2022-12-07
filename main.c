#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Graphismes/graphismes.h"
#include "Donnees/donnees.h"
#include "Donnees/constantes.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED

void boucleDeJeu(SDL_Renderer* renderer, player* player, listEnemy* listeEnnemis, bloc* listeBlocs, listBullet* listeBalles){

    //Initialisation
    int is_playing = 1;
    int fps = 1;
    int fpstimer = 0;
    Uint32 start = SDL_GetTicks();
    double startFire = 0.;
    double dt;
    int mouseX, mouseY;
    Uint32 mouseBitMask;

    initTextures(renderer,player,listeEnnemis,listeBlocs);

    while(is_playing){
        Uint32 end = SDL_GetTicks();
        dt = (end-start)/1000.;

        //Cap à 60 fps
        if(fpsCap(start,&end)) {continue;}

        // Déplacement des entités autres que le joueur
        moveListEnemyToPlayer(listeEnnemis, player, dt);
        moveBullets(listeBalles, dt);

        bulletsCollidesEnemies(listeBalles, listeEnnemis);
        destroyToBeDestroyedBulletTextures(listeBalles);
        deleteBulletsToBeDesttroyed(listeBalles);

        // Recuperation de l'état de la souris
        mouseBitMask = SDL_GetMouseState(&mouseX, &mouseY);

        // Gestion des evenements
        SDL_Event event;
        handleEvents(&event, &is_playing, player, listeBlocs, listeBalles, dt, &startFire, mouseX, mouseY, mouseBitMask);

        //Fermeture du jeu
        if(!is_playing){break;}

        //Rafraichissement de l'ecran
        SDL_RenderClear(renderer);

        //Affichage des sprites
        drawListBlocSprites(renderer, listeBlocs);

            // Initialisation des textures des balles qui n'ont pas de textures
        initListBulletTextures(renderer, listeBalles);

        drawListBulletSprites(renderer, listeBalles);
        drawListEnemySprites(renderer, listeEnnemis);

            // Dessin du laser
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        drawLine(renderer, (getPlayerPosX(player) + getSpriteWidth(getPlayerSprite(player))/2),
                           (getPlayerPosY(player) + getSpriteHeight(getPlayerSprite(player))/2),
                 (float)mouseX, (float)mouseY);
        SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

        drawSprite(renderer, (int)getPlayerPosX(player), (int)getPlayerPosY(player), PLAYER_SIZE, PLAYER_SIZE, 0, getPlayerTexture(player));

        // Rendu
        SDL_RenderPresent(renderer);
        
        //Gestion des fps
        fps++;
        start = end;
        fpsCounter(&fps,&fpstimer);
    }
}


int main(){
    // Initialisation des structures
    SDL_Window* fenetre;
    SDL_Renderer* renderer;
    bloc* listeBlocs = initListBloc();
    player joueur = initPLayer();
    listEnemy listeEnnemis = initListEnemy(NB_ENNEMIS);
    listBullet listeBalles = initListBullet();

    SDL_SetMainReady();
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("Erreur d'initilisation de SDL : %s", SDL_GetError());
        return -1;
    }

    // Creation de la fenetre
    if(SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Segfault");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

    // Jeu
    boucleDeJeu(renderer, &joueur, &listeEnnemis, listeBlocs, &listeBalles);

    // Nettoyage final
    endSDL(fenetre, renderer, &joueur, &listeEnnemis, listeBlocs, &listeBalles);

    freeListEnemy(&listeEnnemis);
    freeListBloc(listeBlocs);
    freeListBullet(&listeBalles);

    return 0; 
}
