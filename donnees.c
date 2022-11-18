#include <SDL2/SDL.h>
#include "donnees.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* ---------- Getter / Setter -------- */

/* ----- Sprite ----- */

float getSpritePosX(sprite* Sprite){return Sprite->posX;}
float getSpritePosY(sprite* Sprite){return Sprite->posY;}
int getSpriteHeight(sprite* Sprite){return Sprite->height;}
int getSpriteWidth(sprite* Sprite){return Sprite->width;}
SDL_Texture* getSpriteTexture(sprite* Sprite){return Sprite->texture;}

int setSpritePosX(sprite* Sprite, float posX){
    Sprite->posX = posX;
    if(fabs(getSpritePosX(Sprite) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setSpritePosY(sprite* Sprite, float posY) {
    Sprite->posY = posY;
    if (fabs(getSpritePosY(Sprite) - posY) >= EPSILON) {
        return 0;
    }
    return -1;
}


int setSpriteHeight(sprite* Sprite, int height){
    Sprite->height = height;
    if((getSpritePosY(Sprite) - height) == 0) {
        return 0;
    }
    return -1;
}

int setSpriteWidth(sprite* Sprite, int width){
    Sprite->width = width;
    if((getSpritePosY(Sprite) - width) == 0) {
        return 0;
    }
    return -1;
}

void setSpriteTexture(sprite* Sprite, SDL_Texture* texture){
    Sprite->texture = texture;
}

/* ----- Bloc ----- */

float getBlocPosX(bloc * Bloc){return getSpritePosX(getBlocSprite(Bloc));}
float getBlocPosY(bloc * Bloc){return getSpritePosY(getBlocSprite(Bloc));}
int getBlocType(bloc * Bloc){return Bloc->type;}
int getBlocIsObstacle(bloc * Bloc){return Bloc->type == OBSTACLE_TYPE;}
SDL_Texture* getBlocTexture(bloc* Bloc){return getSpriteTexture(getBlocSprite(Bloc));}
sprite* getBlocSprite(bloc* Bloc){return &(Bloc->sprite);}

int setBlocPosX(bloc* Bloc, float posX){
    setSpritePosX(getBlocSprite(Bloc),  posX);
    if(fabs(getBlocPosX(Bloc) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setBlocPosY(bloc* Bloc, float posY){
    setSpritePosY(getBlocSprite(Bloc),  posY);
    if(fabs(getBlocPosY(Bloc) - posY) >= EPSILON){
        return 0;
    }
    return -1;
}

int setBlocType(bloc * Bloc, int type){
    Bloc->type = type;
    if(getBlocType(Bloc) == type){
        return 0;
    }
    return -1;
}

int setBlocObstacle(bloc * Bloc){
    Bloc->isObstacle = 1;
    if(getBlocIsObstacle(Bloc)){
        return 0;
    }
    return -1;
}

int setBlocNotObstacle(bloc * Bloc){
    Bloc->isObstacle = 0;
    if(!getBlocIsObstacle(Bloc)){
        return 0;
    }
    return -1;
}

void setBlocTexture(bloc* Bloc, SDL_Texture* texture){
    setSpriteTexture(getBlocSprite(Bloc), texture);
}

void setBlocSprite(bloc* Bloc, sprite* Sprite){
    Bloc->sprite = *Sprite;
}

/* ----- listBlock -----*/

bloc* getBloc(listBloc * ListeBlocs){return &(ListeBlocs->Bloc);}
listBloc* getNextB(listBloc * ListeBlocs){return ListeBlocs->next;}

void setBloc(listBloc *ListeBlocs, bloc Bloc) {
    ListeBlocs->Bloc = Bloc;
}

int setNextB(listBloc * ListeBlocs, listBloc * ListeBlocNext){
    ListeBlocs->next = ListeBlocNext;
    if(ListeBlocs->next == ListeBlocNext){
        return 0;
    }
    return -1;
}

int isEmptyLB(listBloc* ListeBloc){
    return (ListeBloc == NULL);
}

void freeListBloc(listBloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        freeListBloc(getNextB(ListeBlocs));
        free(ListeBlocs);
    }
}

/* ----- Player ----- */

float getPlayerPosX(player* Player){return getSpritePosX(getPlayerSprite(Player));}
float getPlayerPosY(player* Player){return getSpritePosY(getPlayerSprite(Player));}
int getPlayerLife(player* Player){return Player->life;}
int getPlayerSpeed(player* Player){return Player->speed;}
int getPlayerWeaponType(player* Player){return Player->weaponType;}
int getPlayerMoney(player* Player){return Player->money;}
SDL_Texture* getPlayerTexture(player* Player){return getSpriteTexture(getPlayerSprite(Player));}
sprite* getPlayerSprite(player* Player){return &(Player->sprite);}

int setPlayerPosX(player* Player, float posX){
    setSpritePosX(getPlayerSprite(Player),  posX);
    if(fabs(getPlayerPosX(Player) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setPlayerPosY(player* Player, float posY){
    setSpritePosY(getPlayerSprite(Player),  posY);
    if(fabs(getPlayerPosY(Player) - posY) >= EPSILON){
        return 0;
    }
    return -1;
}

int setPlayerLife(player* Player, int life){
    Player->life = life;
    if(getPlayerLife(Player) == life){
        return 0;
    }
    return -1;
}

int setPlayerSpeed(player* Player, int speed){
    Player->speed = speed;
    if(getPlayerSpeed(Player) == speed){
        return 0;
    }
    return -1;
}

int setPlayerWeaponType(player* Player, int weapontype){
    Player->weaponType = weapontype;
    if(getPlayerWeaponType(Player) == weapontype){
        return 0;
    }
    return -1;
}

int setPlayerMoney(player* Player, int money){
    Player->money = money;
    if(getPlayerMoney(Player) == money){
        return 0;
    }
    return -1;
}

void setPlayerTexture(player* Player, SDL_Texture* texture){
    setSpriteTexture(getPlayerSprite(Player),  texture);
}

void setPlayerSprite(player* Player, sprite* Sprite){
    Player->sprite = *Sprite;
}

/* ----- Enemy ----- */

float getEnemyPosX(enemy* Enemy){return getSpritePosX(getEnemySprite(Enemy));}
float getEnemyPosY(enemy* Enemy){return getSpritePosY(getEnemySprite(Enemy));}
int getEnemyLife(enemy* Enemy){return Enemy->life;}
int getEnemySpeed(enemy* Enemy){return Enemy->speed;}
int getEnemyType(enemy* Enemy){return Enemy->type;}
SDL_Texture* getEnemyTexture(enemy* Enemy){return getSpriteTexture(getEnemySprite(Enemy));}
sprite* getEnemySprite(enemy* Enemy){return &(Enemy->sprite);}

int setEnemyPosX(enemy* Enemy, float posX){
    setSpritePosX(getEnemySprite(Enemy), posX);
    if(fabs(getEnemyPosX(Enemy) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setEnemyPosY(enemy* Enemy, float posY){
    setSpritePosY(getEnemySprite(Enemy), posY);
    if(fabs(getEnemyPosY(Enemy) - posY) >= EPSILON){
        return 0;
    }
    return -1;
}

int setEnemyLife(enemy* Enemy, int life){
    Enemy->life = life;
    if(getEnemyLife(Enemy) == life){
        return 0;
    }
    return -1;
}

int setEnemySpeed(enemy* Enemy, int speed){
    Enemy->speed = speed;
    if(getEnemySpeed(Enemy) == speed){
        return 0;
    }
    return -1;
}

int setEnemyType(enemy* Enemy, int type){
    Enemy->type = type;
    if(getEnemyType(Enemy) == type){
        return 0;
    }
    return -1;
}

void setEnemyTexture(enemy* Enemy, SDL_Texture* texture){
    setSpriteTexture(getEnemySprite(Enemy), texture);;
}

void setEnemySprite(enemy * Enemy, sprite* Sprite){
    Enemy->sprite = *Sprite;
}

/* ----- listEnemy ----- */

enemy* getEnemy(listEnemy * ListEnemy){return &(ListEnemy->Enemy);}
listEnemy* getNextE(listEnemy * ListEnemy){return ListEnemy->next;}

void setEnemy(listEnemy *ListEnemy, enemy Enemy) {
    ListEnemy->Enemy = Enemy;
}

int setNextE(listEnemy * ListEnemy, listEnemy * ListEnemyNext){
    ListEnemy->next = ListEnemyNext;
    if(ListEnemy->next == ListEnemyNext){
        return 0;
    }
    return -1;
}

int isEmptyLE(listEnemy* ListEnnemy){
    return (ListEnnemy == NULL);
}

void freeListEnemy(listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        freeListEnemy(getNextE(ListeEnnemis));
        free(ListeEnnemis);
    }
}

/* -------- Fonctions -------- */

/* ----- Initialisation ----- */

sprite initSprite(float posX, float posY, int height, int width){
    sprite Sprite;
    setSpritePosX(&Sprite, posX);
    setSpritePosY(&Sprite, posY);
    setSpriteHeight(&Sprite, height);
    setSpriteWidth(&Sprite, width);
    return Sprite;
}

bloc initBloc(int posX, int posY, int type){
    bloc Bloc;
    sprite Sprite = initSprite(posX, posY, PLAYER_SIZE, PLAYER_SIZE);
    setBlocSprite(&Bloc, &Sprite);
    setBlocType(&Bloc,type);
    //setBlocNotObstacle(&Bloc);
    return Bloc;
}

listBloc initListBloc(){
    listBloc* ListeBlocs = malloc(sizeof(listBloc));
    listBloc* CurrentListeBlocs;
    CurrentListeBlocs = ListeBlocs;
    for(int i = 0; i <= SCREEN_WIDTH - PLAYER_SIZE; i+= PLAYER_SIZE){
        for(int j = 0; j <= SCREEN_HEIGHT - PLAYER_SIZE; j+= PLAYER_SIZE){
            if((i == 0 || i == SCREEN_WIDTH) && (j == 0 || j == SCREEN_HEIGHT)){

                //Attribution du bloc
                setBloc(CurrentListeBlocs, initBloc(i,j,OBSTACLE_TYPE));

                //Initialisation et attribution de la prochaine liste
                setNextB(CurrentListeBlocs, malloc(sizeof(listBloc)));

                CurrentListeBlocs = getNextB(CurrentListeBlocs);
            }else{
                //Attribution du bloc
                setBloc(CurrentListeBlocs, initBloc(i,j,NOBSTACLE_TYPE));

                //Initialisation et attribution de la prochaine liste
                setNextB(CurrentListeBlocs, malloc(sizeof(listBloc)));

                CurrentListeBlocs = getNextB(CurrentListeBlocs);
            }
        }
    }
    //Attribution du dernier bloc de la liste
    setBloc(CurrentListeBlocs,initBloc(SCREEN_WIDTH-PLAYER_SIZE,SCREEN_HEIGHT-PLAYER_SIZE,OBSTACLE_TYPE));
    setNextB(CurrentListeBlocs, NULL);
    return *ListeBlocs;

}

player initPLayer(){
    player Player;
    sprite Sprite = initSprite(SCREEN_WIDTH/2 - PLAYER_SIZE/2, SCREEN_HEIGHT/2 - PLAYER_SIZE/2, PLAYER_SIZE, PLAYER_SIZE);

    setPlayerSprite(&Player, &Sprite);
    setPlayerLife(&Player,PLAYER_LIFE);
    setPlayerSpeed(&Player,PLAYER_SPEED);
    setPlayerWeaponType(&Player,PISTOL_TYPE);
    setPlayerMoney(&Player,0);
    return Player;
}

enemy initEnemy(float posX, float posY, int type){
    enemy Ennemi;
    sprite Sprite = initSprite(posX, posY, PLAYER_SIZE, PLAYER_SIZE);
    setEnemySprite(&Ennemi, &Sprite);

    switch(type){
        
        // A remplir au moment de l'ajout des ennemis
        case 0:
            break;

        default:
            setEnemyLife(&Ennemi,PLAYER_LIFE);
            setEnemySpeed(&Ennemi,PLAYER_SPEED/2);
    }

    setEnemyType(&Ennemi, type);
    return Ennemi;
}

listEnemy initListEnemy(int nb){
    listEnemy* ListeEnnemis;

    // Premier maillon
    if(nb>0) {

        // Générateur d'aléatoire
        srand(time(0));

        float posX, posY;
        listEnemy* CurrentListEnnemis;
        ListeEnnemis = malloc(sizeof(listEnemy));
        CurrentListEnnemis = ListeEnnemis;

        //Premiers maillons
        for(int i = 0; i<nb-1; i++){

            //Position aléatoire
            posX = rand() % (SCREEN_WIDTH - PLAYER_SIZE + 1);
            posY = rand() % (SCREEN_HEIGHT - PLAYER_SIZE + 1);

            //Initialisation et attribution de l'ennemi
            setEnemy(CurrentListEnnemis, initEnemy(posX, posY, 1));

            //Initialisation et attribution du prochain maillon
            setNextE(CurrentListEnnemis, malloc(sizeof(listEnemy)));

            CurrentListEnnemis = getNextE(CurrentListEnnemis);
        }

        //Position aléatoire
        posX = rand() % (SCREEN_WIDTH - PLAYER_SIZE + 1);
        posY = rand() % (SCREEN_HEIGHT - PLAYER_SIZE + 1);

        //Initialisation et attribution de l'ennemi
        setEnemy(CurrentListEnnemis, initEnemy(posX, posY, 1));

        setNextE(CurrentListEnnemis, NULL);

    }
    return *ListeEnnemis;
}

/* ----- FPS ----- */

void fpsCounter(int* fps, int* fpstimer){
    int fpsNow = SDL_GetTicks();
    if(fpsNow > *fpstimer + 1000){
        printf("%d fps\n",*fps);
        *fpstimer = fpsNow;
        *fps = 0;
    }
}

int fpsCap(Uint32 start, Uint32* end){
    *end = SDL_GetTicks();
    if (*end-start < 1000/FPS) {
        return 1;
    }
    return 0;
}

/* ----- Autres ----- */

void handleEvents(SDL_Event* event, int* is_playing, player* player, double dt){

    // On retire tous les evenements sauf l'indication de fermer le jeu
    SDL_FlushEvents(SDL_APP_TERMINATING, SDL_USEREVENT);

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    // Fermeture du jeu
    if(SDL_PollEvent(event) && ((event->type==SDL_QUIT) || keystates[SDL_SCANCODE_ESCAPE])){

        *is_playing = 0;

    }else if(((keystates[SDL_SCANCODE_LEFT]  || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]))){ // Déplacement en haut à gauche

        setPlayerPosX(player, max(0, getPlayerPosX(player)-pythagore(PLAYER_SPEED*dt)));
        setPlayerPosY(player, max(0, getPlayerPosY(player)-pythagore(PLAYER_SPEED*dt)));

    }else if(((keystates[SDL_SCANCODE_LEFT]  || keystates[SDL_SCANCODE_A]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]))){ // Déplaceent en bas à gauche

        setPlayerPosX(player, max(0, getPlayerPosX(player)-pythagore(PLAYER_SPEED*dt)));
        setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE,getPlayerPosY(player) + pythagore(PLAYER_SPEED*dt)));

    }else if(((keystates[SDL_SCANCODE_RIGHT]  || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]))){ // Déplacement en haut à droite

        setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE,getPlayerPosX(player) + pythagore(PLAYER_SPEED*dt)));
        setPlayerPosY(player, max(0,getPlayerPosY(player)-pythagore(PLAYER_SPEED*dt)));

    }else if((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])){ // Déplacement en bas à droite

        setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE,getPlayerPosX(player) + pythagore(PLAYER_SPEED*dt)));
        setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE,getPlayerPosY(player) + pythagore(PLAYER_SPEED*dt)));

    }else if(keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]){ // Déplacement à gauche

        setPlayerPosX(player, max(0, getPlayerPosX(player)-PLAYER_SPEED*dt));

    }else if(keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]){ // Déplacement en haut

        setPlayerPosY(player, max(0,getPlayerPosY(player)-PLAYER_SPEED*dt));

    }else if(keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]){ // Déplacement à droite

        setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE,getPlayerPosX(player) + PLAYER_SPEED*dt));

    }else if(keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]){ // Déplacement en bas

        setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE,getPlayerPosY(player) + PLAYER_SPEED*dt));

    }

}

float max(float val1, float val2){
    if(val1>=val2){
        return val1;
    }
    return val2;
}

float min(float val1, float val2){
    if(val1<=val2){
        return val1;
    }
    return val2;
}

float pythagore(float c) {
    return sqrt((pow(c , 2)/2));
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

int floatEquals(float f1, float f2){
    return fabs(f1-f2)<EPSILON;
}