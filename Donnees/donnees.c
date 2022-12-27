#include <SDL2/SDL.h>
#include "donnees.h"
#include "constantes.h"
#include "maths.h"
#include "../Files/files.h"
#include <stdlib.h>

/* ----- FPS ----- */

void fpsCounter(int* fps, int* fpstimer){
    int fpsNow = SDL_GetTicks();
    if(fpsNow > *fpstimer + 1000){
        printf("%d fps\n", *fps);
        *fpstimer = fpsNow;
        *fps = 1;
    }
}

int fpsCap(Uint32 start, Uint32* end){
    *end = SDL_GetTicks();
    if (*end-start < 1000./FPS) {
        return 1;
    }
    return 0;
}

/* ----- Autres ----- */

void handleEvents(SDL_Event* event, int* is_playing, player* player, bloc* ListeBlocs, listBullet* listeBalles, double dt, double* startFire, int mouseX, int mouseY, Uint32 mouseBitMask, int* gameState) {

    // On retire tous les evenements sauf l'indication de fermer le jeu
    SDL_FlushEvents(SDL_APP_TERMINATING, SDL_USEREVENT);

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    // Fermeture du jeu
    if (SDL_PollEvent(event) && ((event->type == SDL_QUIT) || keystates[SDL_SCANCODE_ESCAPE])) {

        *gameState = 2;
        *is_playing = 0;

    } else {

        if (((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]))) { // Déplacement en haut à gauche

            setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player,min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            }

            setPlayerPosY(player,min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosY(player, max(0, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));
            }
        }

        else if (((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]))) { // Déplaceent en bas à gauche

            setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player,min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            }

            setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosY(player, max(0, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));
            }

        } else if (((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]))) { // Déplacement en haut à droite

            setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
            }

            setPlayerPosY(player, max(0, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosY(player,min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));
            }

        } else if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])) { // Déplacement en bas à droite

            setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
            }

            setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));
            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosY(player, max(0, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));
            }

        } else if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) { // Déplacement à gauche

            setPlayerPosX(player, max(0, getPlayerPosX(player) - PLAYER_SPEED * dt));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {

                setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + PLAYER_SPEED * dt));
            }

        } else if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) { // Déplacement en haut

            setPlayerPosY(player, max(0, getPlayerPosY(player) - PLAYER_SPEED * dt));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + PLAYER_SPEED * dt));
            }

        } else if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) { // Déplacement à droite

            setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + PLAYER_SPEED * dt));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player, max(0, getPlayerPosX(player) - PLAYER_SPEED * dt));
            }

        } else if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) { // Déplacement en bas

            setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + PLAYER_SPEED * dt));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosY(player, max(0, getPlayerPosY(player) - PLAYER_SPEED * dt));
            }
        }

        if ((keystates[SDL_SCANCODE_SPACE] || mouseBitMask == SDL_BUTTON(SDL_BUTTON_LMASK)) && *startFire>0.25){

            // Initialisation et ajout de la balle dans la liste
            bullet Balle = initBullet(getPlayerPosX(player) + getSpriteWidth(getPlayerSprite(player)) / 2,getPlayerPosY(player) + getSpriteHeight(getPlayerSprite(player)) / 2, 0, 0, 0);
            setBulletSpeeds(&Balle, mouseX, mouseY);

            addBullet(listeBalles, Balle);

            //Reset du compteur de frames
            *startFire = 0.;
        }

        //Incrementation du compteur de frames du tir
        *startFire += dt;
    }
}

void moveToPlayer(enemy* enemy, listEnemy* ListeEnnemis, bloc* ListeBlocs, player* player, double dt){
    //Distance de l'ennemi au joueur
    float distToPlayer = sqrt(pow(getPlayerPosX(player) - getEnemyPosX(enemy), 2) + pow(getPlayerPosY(player) - getEnemyPosY(enemy), 2));

    //Pourcentage de la distance que l'ennemi peut parcourir en dt s
    float prctDist = (getEnemySpeed(enemy)*dt)/distToPlayer;

    //Distance a parcourir dans chaque axe
    float distX = (getPlayerPosX(player)- getEnemyPosX(enemy))*prctDist;
    float distY = (getPlayerPosY(player)- getEnemyPosY(enemy))*prctDist;

    setEnemyPosX(enemy, getEnemyPosX(enemy)+distX);

    // Si en se deplacant l;ennemi en touche un autre
    if(enemyIsCollidingListEnemy(enemy, ListeEnnemis) || spriteCollidesWalls(getEnemySprite(enemy), ListeBlocs)){
        setEnemyPosX(enemy, getEnemyPosX(enemy)-distX);
    }

    setEnemyPosY(enemy, getEnemyPosY(enemy)+distY);

    // Si en se deplacant l;ennemi en touche un autre
    if(enemyIsCollidingListEnemy(enemy, ListeEnnemis) || spriteCollidesWalls(getEnemySprite(enemy), ListeBlocs)){
        setEnemyPosY(enemy, getEnemyPosY(enemy)-distY);
    }
}

void moveListEnemyToPlayer(listEnemy* ListeEnnemisActuelle, listEnemy* ListeEnnemis, bloc* ListeBlocs, player* player, double dt){
    if(!isEmptyLE(ListeEnnemisActuelle)){
        //Si pas en collision avec le joueur
        if(!inCollision(getPlayerSprite(player), getEnemySprite(getEnemy(ListeEnnemisActuelle)))) {
            moveToPlayer(getEnemy(ListeEnnemisActuelle), ListeEnnemis, ListeBlocs, player, dt);
        }else{
            setSpriteToBeDestroyed(getEnemySprite(getEnemy(ListeEnnemisActuelle)),1);
            playerTakeDamage(player,ENEMY_DMG);
        }
        moveListEnemyToPlayer(getNextE(ListeEnnemisActuelle), ListeEnnemis, ListeBlocs, player, dt);
    }
}

int inCollision(sprite* Sprite1, sprite* Sprite2) {

    //Coordonnees des coins haut gauche et bas droite du sprite 2
    float x1 = getSpritePosX(Sprite2);
    float y1 = getSpritePosY(Sprite2);
    float w1 = (float) getSpriteWidth(Sprite2);
    float h1 = (float) getSpriteHeight(Sprite2);

    // Coordonnees des coins du sprite 1
    float pos[4][2] = {{getSpritePosX(Sprite1) + 1,getSpritePosY(Sprite1)+ 1},
                       {getSpritePosX(Sprite1) + getSpriteWidth(Sprite1) - 1, getSpritePosY(Sprite1)+ 1},
                       {getSpritePosX(Sprite1) + 1,getSpritePosY(Sprite1) + getSpriteHeight(Sprite1) - 1 },
                       {getSpritePosX(Sprite1) + getSpriteWidth(Sprite1) - 1, getSpritePosY(Sprite1) + getSpriteHeight(Sprite1)- 1} };

    // Verification pour les 4 coins
    for (int point = 0; point < 4; point++) {
        float x = pos[point][0];
        float y = pos[point][1];

        if ((x > x1 || floatEquals(x, x1)) && (x < x1 + w1 || floatEquals(x, x1 + w1)) &&
            (y > y1 || floatEquals(y, y1)) && (y < y1 + h1 || floatEquals(y, y1 + h1))) {
            return SDL_TRUE;
        }
    }
    return SDL_FALSE;
}

int spriteCollidesWalls(sprite* Sprite, bloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        for(int i = 0; i < sizeOfListBloc(ListeBlocs);i++){
            if(getBlocIsObstacle(getBloc(ListeBlocs,i)) && (inCollision(Sprite, getBlocSprite(getBloc(ListeBlocs,i))))){
                return 1;
            }
        }
    }
    return 0;
}

void drawLine(SDL_Renderer* renderer, float x1, float y1, float x2, float y2){
    float distX = x2-x1;
    float distY = y2-y1;
    SDL_RenderDrawLine(renderer, (int)x1, (int)y1, (int)(x1 + distX*3), (int)(y1 + distY*3));
}

int bulletCollidesEnemies(bullet* Balle, listEnemy* listeEnnemis){
    if(!isEmptyLE(listeEnnemis)){
        if(inCollision(getBulletSprite(Balle), getEnemySprite(getEnemy(listeEnnemis)))){
            enemyTakeDamage(getEnemy(listeEnnemis),PISTOL_DMG);
            if(getEnemyLife(getEnemy(listeEnnemis)) == 0){
                setSpriteToBeDestroyed(getEnemySprite(getEnemy(listeEnnemis)), 1);
            }
            return 1;
        }
        else {
            return bulletCollidesEnemies(Balle, getNextE(listeEnnemis));
        }
    }
    return 0;
}

void bulletsCollidesEnemies(listBullet* ListeBalle, listEnemy* ListeEnnemi){
    if(!isEmptyListBullet(ListeBalle)){
        if(bulletCollidesEnemies(getBullet(ListeBalle), ListeEnnemi)){
            setSpriteToBeDestroyed(getBulletSprite(getBullet(ListeBalle)), 1);
        }
        bulletsCollidesEnemies(getNextBullet(ListeBalle), ListeEnnemi);
    }
}

int enemyIsCollidingListEnemy(enemy* Ennemi, listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        if(Ennemi == getEnemy(ListeEnnemis)){
            return enemyIsCollidingListEnemy(Ennemi, getNextE(ListeEnnemis));
        }
        else {
            return inCollision(getEnemySprite(Ennemi), getEnemySprite(getEnemy(ListeEnnemis))) || enemyIsCollidingListEnemy(Ennemi, getNextE(ListeEnnemis));
        }
    }
    return 0;
}

void moveBullets(listBullet* ListeBalles, bloc* ListeBlocs, double dt){
    if(!isEmptyListBullet(ListeBalles)){

        setBulletPosX(getBullet(ListeBalles), getBulletPosX(getBullet(ListeBalles)) - getBulletXSpeed(getBullet(ListeBalles)) * dt);
        setBulletPosY(getBullet(ListeBalles), getBulletPosY(getBullet(ListeBalles)) - getBulletYSpeed(getBullet(ListeBalles)) * dt);

        // Si la balle touche un mur/bloc
        if(spriteCollidesWalls(getBulletSprite(getBullet(ListeBalles)), ListeBlocs)){
            setSpriteToBeDestroyed(getBulletSprite(getBullet(ListeBalles)), 1);
        }

        moveBullets(getNextBullet(ListeBalles), ListeBlocs, dt);
    }
}

bloc* initListBlocFile(const char* nomFichier){
    char* tabFichier = readFile(nomFichier);

    if(tabFichier == NULL) {
        return NULL;
    }

    else {
        bloc* ListeBloc = malloc((getListeHeight() * getListeWidth()) * sizeof(bloc));

        for (int i = 0; i < (sizeOfListBloc(ListeBloc)); i++) {
            int posx = (i%getListeWidth()) * BLOC_SIZE;
            int posy = (i/getListeWidth()) * BLOC_SIZE;
            bloc newBloc = initBloc(posx, posy, 0);

            switch (tabFichier[i]) {
                // Mur
                case 'm': {
                    setBlocSpread(&newBloc, 0);
                    setBlocObstacle(&newBloc);
                    break;
                }

                    // Blocs non-obstacle
                case '0': {
                    setBlocSpread(&newBloc, 0);
                    break;
                }

                    // Blocs obstacle
                case '1': {
                    setBlocSpread(&newBloc, 10);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '2': {
                    setBlocSpread(&newBloc, 20);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '3': {
                    setBlocSpread(&newBloc, 30);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '4': {
                    setBlocSpread(&newBloc, 40);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '5': {
                    setBlocSpread(&newBloc, 50);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '6': {
                    setBlocSpread(&newBloc, 60);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '7': {
                    setBlocSpread(&newBloc, 70);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '8': {
                    setBlocSpread(&newBloc, 80);
                    setBlocObstacle(&newBloc);
                    break;
                }

                case '9': {
                    setBlocSpread(&newBloc, 90);
                    setBlocObstacle(&newBloc);
                    break;
                }

                    // Cluster
                case 'c': {
                    setBlocSpread(&newBloc, 100);
                    setBlocObstacle(&newBloc);
                    break;
                }
            }
            ListeBloc[i] = newBloc;
        }
        return ListeBloc;
    }
}

void initGame(player* Joueur, listEnemy* ListeEnnemis,listBullet* ListeBalles){
    *Joueur = initPLayer();

    freeListEnemy(ListeEnnemis);
    listEnemy* listETemp = initListEnemy();
    *ListeEnnemis = *listETemp;
    fillListEnemy(ListeEnnemis,NB_ENNEMIS);

    freeListBullet(ListeBalles);
    listBullet* listBTemp = initListBullet();
    *ListeBalles = *listBTemp;

}