#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Graphismes/graphismes.h"
#include "Donnees/donnees.h"
#include "Donnees/constantes.h"
#include <stdio.h>
#define SDL_MAIN_HANDLED


int afficherMenu(SDL_Renderer* renderer){
    // Buffer pour getMouseState
    int x,y;

    // Sprites des boutons
    sprite BoutonJouer = initSprite(SCREEN_WIDTH/2 - 80 ,SCREEN_HEIGHT/2 - 40,40,160);
    sprite BoutonCharger = initSprite(SCREEN_WIDTH/2 - 80,SCREEN_HEIGHT/2 + 40,40,160);
    sprite BoutonQuitter = initSprite(SCREEN_WIDTH/2 - 80,SCREEN_HEIGHT/2 + 120,40,160);

    // Set des textures des boutons
    setSpriteTexture(&BoutonJouer,loadSprite(renderer,"assets/img/Jouer.bmp"));
    setSpriteTexture(&BoutonCharger,loadSprite(renderer,"assets/img/Charger.bmp"));
    setSpriteTexture(&BoutonQuitter,loadSprite(renderer,"assets/img/Quitter.bmp"));

    // Creation et remplissage du tableau des boutons
    sprite boutons[NBBOUTONS];
    boutons[0] = BoutonJouer;
    boutons[1] = BoutonCharger;
    boutons[2] = BoutonQuitter;


    SDL_Event event;
    while(1){
        while(SDL_PollEvent(&event)){

            SDL_GetMouseState(&x,&y);
            SDL_RenderClear(renderer);

            switch(event.type){

                case SDL_QUIT:

                    for(int i = 0; i<NBBOUTONS; i++) {
                        SDL_DestroyTexture(getSpriteTexture(&boutons[i]));
                    }
                    return 2;

                case SDL_MOUSEMOTION:

                    for(int i = 0; i <NBBOUTONS;i++){

                        float xS = getSpritePosX(&boutons[i]);
                        float yS = getSpritePosY(&boutons[i]);
                        int wS = getSpriteWidth(&boutons[i]);
                        int hS = getSpriteHeight(&boutons[i]);

                        // Vérification des coordonnées de la souris pour voir si elles sont en collision avec un bouton
                        if(x>=xS && x<=wS + xS && y>=yS && y<=yS + hS){ // Si collision changement de la texture pour la texture de survol
                            drawSprite(renderer, xS,yS,wS,hS,1, getSpriteTexture(&boutons[i]));
                        }else{ //Sinon on redessine la texture normale
                            drawSprite(renderer, xS,yS,wS,hS,0, getSpriteTexture(&boutons[i]));
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:

                    for(int i = 0; i<NBBOUTONS; i++){

                        float xS = getSpritePosX(&boutons[i]);
                        float yS = getSpritePosY(&boutons[i]);
                        int wS = getSpriteWidth(&boutons[i]);
                        int hS = getSpriteHeight(&boutons[i]);

                        if(x>=xS && x<=wS + xS && y>=yS && y<=yS + hS){

                            for(int j = 0; j < NBBOUTONS; j++){
                                SDL_DestroyTexture(getSpriteTexture(&boutons[i]));
                            }
                            return i;
                        }
                    }
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    }

}

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



    while(is_playing){
        Uint32 end = SDL_GetTicks();
        dt = (end-start)/1000.;

        //Cap à 60 fps
        if(fpsCap(start,&end)) {continue;}

        // Déplacement des entités autres que le joueur
        moveListEnemyToPlayer(listeEnnemis, listeEnnemis, listeBlocs, player, dt);
        moveBullets(listeBalles, listeBlocs, dt);

        // Recuperation de l'état de la souris
        mouseBitMask = SDL_GetMouseState(&mouseX, &mouseY);

        // Gestion des evenements
        SDL_Event event;
        handleEvents(&event, &is_playing, player, listeBlocs, listeBalles, dt, &startFire, mouseX, mouseY, mouseBitMask);

        bulletsCollidesEnemies(listeBalles, listeEnnemis);
        destroyToBeDestroyedBulletTextures(listeBalles);
        deleteBulletsToBeDestroyed(listeBalles);

        destroyToBeDestroyedEnemyTextures(listeEnnemis);
        deleteEnemiesToBeDestroyed(listeEnnemis);


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
        
        // Gestion des fps
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
    listEnemy* listeEnnemis = initListEnemy();
    fillListEnemy(listeEnnemis, NB_ENNEMIS);
    listBullet* listeBalles = initListBullet();


    SDL_SetMainReady();
    if(SDL_Init(SDL_INIT_VIDEO)){
        printf("Erreur d'initilisation de SDL : %s", SDL_GetError());
        return -1;
    }

    // Creation de la fenetre
    if(SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &fenetre, &renderer)){
        printf("Echec de creation de fenetre/renderer : %s", SDL_GetError());
        return -1;
    }
    SDL_SetWindowTitle(fenetre, "Segfault");
    SDL_SetRenderDrawColor(renderer, 32, 34, 37, SDL_ALPHA_OPAQUE);

    // Initialisation des textures du jeu
    initTextures(renderer,&joueur,&listeEnnemis,listeBlocs);

    int i = afficherMenu(renderer);

    if(i == 0){
        // Jeu
        boucleDeJeu(renderer, &joueur, &listeEnnemis, listeBlocs, listeBalles);
    }else if(i == 1){
        //chargement de map
        return 0;
    }
    // Nettoyage final
    endSDL(fenetre, renderer, &joueur, &listeEnnemis, listeBlocs, listeBalles);

    freeListEnemy(&listeEnnemis);
    freeListBloc(listeBlocs);
    freeListBullet(listeBalles);

    return 0;

}
