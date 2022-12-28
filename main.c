#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Graphismes/graphismes.h"
#include "Donnees/donnees.h"
#include "Donnees/constantes.h"
#include <stdio.h>
#include "Graphismes/fonts.h"

#define SDL_MAIN_HANDLED


int afficherMenu(SDL_Renderer* renderer, int type){
    // Buffer pour getMouseState
    int x,y;
    sprite Bouton1;
    sprite Bouton2;
    sprite Bouton3;
    if(type == 0){ // Menu principal
        // Sprites des boutons
        Bouton1 = initSprite(SCREEN_WIDTH/2 - 80 ,SCREEN_HEIGHT/2 - 40,40,160);
        Bouton2 = initSprite(SCREEN_WIDTH/2 - 80,SCREEN_HEIGHT/2 + 40,40,160);
        Bouton3 = initSprite(SCREEN_WIDTH/2 - 80,SCREEN_HEIGHT/2 + 120,40,160);

        // Set des textures des boutons
        setSpriteTexture(&Bouton1,loadSprite(renderer,"assets/img/Jouer.bmp"));
        setSpriteTexture(&Bouton2,loadSprite(renderer,"assets/img/Charger.bmp"));
        setSpriteTexture(&Bouton3,loadSprite(renderer,"assets/img/Quitter.bmp"));

    }else{ // Menu GameOver
        //Sprites des boutons
        Bouton1 = initSprite(SCREEN_WIDTH/2 - 80 ,SCREEN_HEIGHT/2 - 40,40,160);
        Bouton2 = initSprite(SCREEN_WIDTH/2 - 80,SCREEN_HEIGHT/2 + 40,40,160);
        Bouton3 = initSprite(SCREEN_WIDTH/2 - 80,SCREEN_HEIGHT/2 + 120,40,160);

        // Set des textures des boutons
        setSpriteTexture(&Bouton1,loadSprite(renderer,"assets/img/Rejouer.bmp"));
        setSpriteTexture(&Bouton2,loadSprite(renderer,"assets/img/Menu.bmp"));
        setSpriteTexture(&Bouton3,loadSprite(renderer,"assets/img/Quitter.bmp"));


    }
    // Creation et remplissage du tableau des boutons
    sprite boutons[NBBOUTONS];
    boutons[0] = Bouton1;
    boutons[1] = Bouton2;
    boutons[2] = Bouton3;





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
                                SDL_DestroyTexture(getSpriteTexture(&boutons[j]));
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


void boucleDeJeu(SDL_Renderer* renderer, player* player, listEnemy* listeEnnemis, bloc* listeBlocs, listBullet* listeBalles, int* gameState){

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
        TTF_Font* font = load_font("assets/fonts/Minecraft.ttf",FONT_SIZE);
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
        handleEvents(&event, &is_playing, player, listeBlocs, listeBalles, dt, &startFire, mouseX, mouseY, mouseBitMask, gameState);

        bulletsCollidesEnemies(listeBalles, listeEnnemis, getPlayerScore(player));
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

        if(getPlayerLife(player)>0){
            printLives(renderer,player,font);
            printScore(renderer,player,font);
        }

        // Rendu
        SDL_RenderPresent(renderer);

        // Gestion des fps
        fps++;
        start = end;
        fpsCounter(&fps,&fpstimer);

        if(getPlayerLife(player) <= 0){
            is_playing = 0;
        }
        clean_font(font);
    }
}


int main(){
    // Initialisation des structures
    SDL_Window* fenetre;
    SDL_Renderer* renderer;
    bloc* listeBlocs = NULL;
    player joueur;
    listEnemy* listeEnnemis = initListEnemy();
    listBullet* listeBalles = initListBullet();
    init_ttf();
    int type = 0;


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


    int gameState = afficherMenu(renderer,type);

    while(gameState != 2){
        if(gameState == 0){
            // Liste des blocs initialisee normalement
            listeBlocs = initListBloc();
        }else if(gameState == 1 && type == 0) {
            //chargement de map
            const char *nomFichier = "assets/maps/MapLoad";

            // Liste des blocs initialisee avec un fichier
            listeBlocs = initListBlocFile(nomFichier);
        }

        //Initialisation des données du jeu
        //Player
        joueur = initPLayer();

        //List Enemy
        listEnemy* tempE = initListEnemy();
        fillListEnemy(tempE,NB_ENNEMIS);
        freeListEnemy(listeEnnemis);
        listeEnnemis = tempE;

        //List Bullet
        freeListBullet(listeBalles);
        listeBalles = initListBullet();

        // Initialisation des textures du jeu
        initTextures(renderer,&joueur,listeEnnemis,listeBlocs);

        // Jeu
        boucleDeJeu(renderer, &joueur, listeEnnemis, listeBlocs, listeBalles, &gameState);

        //Sauvegarde de la map dans un fichier
        writeFile("assets/maps/MapLoad", listeBlocs);

        //Passage au menu de game over
        type = 1;

        //Nettoyage
        destroyAllTextures(&joueur,listeEnnemis,listeBlocs,listeBalles);
        freeListBloc(listeBlocs);

        // Si le joueur n'a pas quitté le jeu
        if(gameState != 2){
            gameState = afficherMenu(renderer,type);
        }

        // Le joueur appuie sur le bouton de retour au menu principal
        if(gameState == 1 ){
            type = 0;
            gameState = afficherMenu(renderer, type);
        }
    }

    // Nettoyage final
    endSDL(fenetre, renderer);
    freeListEnemy(listeEnnemis);
    freeListBullet(listeBalles);
    return 0;
}
