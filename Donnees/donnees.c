#include <SDL2/SDL.h>
#include "donnees.h"
#include "constantes.h"
#include "maths.h"
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

void handleEvents(SDL_Event* event, int* is_playing, player* player, listBloc* ListeBlocs, listBullet* listeBalles, double dt, double* startFire) {

    // On retire tous les evenements sauf l'indication de fermer le jeu
    SDL_FlushEvents(SDL_APP_TERMINATING, SDL_USEREVENT);

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    // Fermeture du jeu
    if (SDL_PollEvent(event) && ((event->type == SDL_QUIT) || keystates[SDL_SCANCODE_ESCAPE])) {

        *is_playing = 0;

    } else {

        if (((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]))) { // Déplacement en haut à gauche

            setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
            setPlayerPosY(player, max(0, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player,min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
                setPlayerPosY(player,min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));
            }
        }

        else if (((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]))) { // Déplaceent en bas à gauche

        setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
        setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));

        if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
            setPlayerPosX(player,min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            setPlayerPosY(player, max(0, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));
        }

        } else if (((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]))) { // Déplacement en haut à droite

            setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            setPlayerPosY(player, max(0, getPlayerPosY(player) - pythagore(PLAYER_SPEED * dt)));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
                setPlayerPosY(player,min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));
            }

        } else if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])) { // Déplacement en bas à droite

            setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE, getPlayerPosX(player) + pythagore(PLAYER_SPEED * dt)));
            setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE, getPlayerPosY(player) + pythagore(PLAYER_SPEED * dt)));

            if (spriteCollidesWalls(getPlayerSprite(player), ListeBlocs)) {
                setPlayerPosX(player, max(0, getPlayerPosX(player) - pythagore(PLAYER_SPEED * dt)));
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
        if (keystates[SDL_SCANCODE_SPACE] && *startFire>0.25){
            int x, y;
 
            // Position de la souris
            SDL_GetMouseState(&x, &y);

            // Initialisation et ajout de la balle dans la liste
            bullet Balle = initBullet(getPlayerPosX(player) + getSpriteWidth(getPlayerSprite(player)) / 2,getPlayerPosY(player) + getSpriteHeight(getPlayerSprite(player)) / 2, 0, 0, 0);
            setBulletSpeeds(&Balle, x, y);
            addBullet(listeBalles, &Balle);

            //Reset du compteur de frames
            *startFire = 0.;
        }

        //Incrementation du compteur de frames du tir
        *startFire += dt;
    }
}

void moveToPlayer(enemy* enemy, player* player, double dt){
    //Distance de l'ennemi au joueur
    float distToPlayer = sqrt(pow(getPlayerPosX(player) - getEnemyPosX(enemy), 2) + pow(getPlayerPosY(player) - getEnemyPosY(enemy), 2));

    //Pourcentage de la distance que l'ennemi peut parcourir en dt s
    float prctDist = (getEnemySpeed(enemy)*dt)/distToPlayer;

    //Distance a parcourir dans chaque axe
    float distX = (getPlayerPosX(player)- getEnemyPosX(enemy))*prctDist;
    float distY = (getPlayerPosY(player)- getEnemyPosY(enemy))*prctDist;

    setEnemyPosX(enemy, getEnemyPosX(enemy)+distX);
    setEnemyPosY(enemy, getEnemyPosY(enemy)+distY);
}

void moveListEnemyToPlayer(listEnemy* ListeEnnemis, player* player, double dt){
    if(!isEmptyLE(ListeEnnemis)){
        if(!inCollision(getPlayerSprite(player), getEnemySprite(getEnemy(ListeEnnemis)))) {
            moveToPlayer(getEnemy(ListeEnnemis), player, dt);
        }
        moveListEnemyToPlayer(getNextE(ListeEnnemis), player, dt);
    }
}

int inCollision(sprite* Sprite1, sprite* Sprite2) {
    float x1 = getSpritePosX(Sprite1);
    float x2 = getSpritePosX(Sprite2);
    float y1 = getSpritePosY(Sprite1);
    float y2 = getSpritePosY(Sprite2);
    float w1 = (float) getSpriteWidth(Sprite1);
    float w2 = (float) getSpriteWidth(Sprite2);
    float h1 = (float) getSpriteHeight(Sprite1);
    float h2 = (float) getSpriteHeight(Sprite2);

    // Coin bas-droite (sprite1) contre/dans l'autre (sprite2)
    if (((x1 + w1 > x2 || floatEquals(x1 + w1, x2)) && (y1 + w1 > y2 || floatEquals(y1 + h1, y2)) &&

         // Distance entre les deux points < h1 et < w1
         (fabs(x1 + w1 - x2) < w1 || floatEquals(x1 + w1 - x2, w1)) &&
         (fabs(y1 + w1 - y2) < h1 || floatEquals(y1 + w1 - h2, h1))) ||

        // Coin bas-gauche contre/dans l'autre
        ((x1 < x2 + w2 || floatEquals(x1, x2 + w2)) && (y1 + h1 > y2 || floatEquals(y1 + h1, y2)) &&

         // Distance entre les deux points < h1 et < w1
         (fabs(x2 + w2 - x1) < w1 || floatEquals(x2 + w2 - x1, w1)) &&
         (fabs(y1 + h1 - y2) < h1 || floatEquals(y1 + h1 - y2, h1))) ||

        // Coin haut-droite contre/dans l'autre
        ((x1 + w1 > x2 || floatEquals(x1 + w1, x2)) && (y1 < y2 + h2 || floatEquals(y1, y2 + h2)) &&

         // Distance entre les deux points < h1 et < w1
         (fabs(x1 + w1 - x2) < w1 || floatEquals(x1 + w1 - x2, w1)) &&
         (fabs(y2 + h2 - y1) < h1 || floatEquals(y2 + h2 - y1, h1))) ||

        // Coin haut-gauche contre/dans l'autre
        ((x1 < x2 + w2 || floatEquals(x1, x2 + w2)) && (y1 < y2 + h2 || floatEquals(y1, y2 + h2)) &&

         // Distance entre les deux points < h1 et < w1
         (fabs(x2 + w2 - x1) < w1 || floatEquals(x2 + w2 - x1, w1)) &&
         (fabs(y2 + h2 - y1) < h1 || floatEquals(y2 + h2 - y1, h1)))) {
        return 1;
    }
    return 0;
}

int spriteCollidesWalls(sprite* Sprite, listBloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        if(getBlocIsObstacle(getBloc(ListeBlocs))){
            return inCollision(Sprite, getBlocSprite(getBloc(ListeBlocs))) || spriteCollidesWalls(Sprite, getNextB(ListeBlocs));
        }else{
            return spriteCollidesWalls(Sprite, getNextB(ListeBlocs));
        }
    }
    return 0;
}