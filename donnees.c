#include <SDL2/SDL.h>
#include "donnees.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* ---------- Getter / Setter -------- */

/* ----- Bloc ----- */

int getBlocPosX(bloc * Bloc){return Bloc->posX;}
int getBlocPosY(bloc * Bloc){return Bloc->posY;}
int getBlocType(bloc * Bloc){return Bloc->type;}
int getBlocIsObstacle(bloc * Bloc){return Bloc->isObstacle;}

int setBlocPosX(bloc * Bloc, int posX){
    Bloc->posX = posX;
    if(getBlocPosX(Bloc) == posX){
        return 0;
    }
    return -1;
}

int setBlocPosY(bloc * Bloc, int posY){
    Bloc->posY = posY;
    if(getBlocPosY(Bloc) == posY){
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

/* ----- Player ----- */

float getPlayerPosX(player* Player){return Player->posX;}
float getPlayerPosY(player* Player){return Player->posY;}
int getPlayerLife(player* Player){return Player->life;}
int getPlayerSpeed(player* Player){return Player->speed;}
int getPlayerWeaponType(player* Player){return Player->weaponType;}
int getPlayerMoney(player* Player){return Player->money;}
SDL_Texture* getPlayerTexture(player* Player){return Player->texture;}

int setPlayerPosX(player* Player, float posX){
    Player->posX = posX;
    if(fabs(getPlayerPosX(Player) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setPlayerPosY(player* Player, float posY){
    Player->posY = posY;
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
    Player->texture = texture;
}

/* ----- Enemy ----- */

float getEnemyPosX(enemy* Enemy){return Enemy->posX;}
float getEnemyPosY(enemy* Enemy){return Enemy->posY;}
int getEnemyLife(enemy* Enemy){return Enemy->life;}
int getEnemySpeed(enemy* Enemy){return Enemy->speed;}
int getEnemyType(enemy* Enemy){return Enemy->type;}
SDL_Texture* getEnemyTexture(enemy* Enemy){return Enemy->texture;}

int setEnemyPosX(enemy* Enemy, float posX){
    Enemy->posX = posX;
    if(fabs(getEnemyPosX(Enemy) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setEnemyPosY(enemy* Enemy, float posY){
    Enemy->posY = posY;
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
    Enemy->texture = texture;
}

/* ----- listEnemy ----- */

enemy* getEnemy(listEnemy * ListEnemy){return &(ListEnemy->Enemy);}
listEnemy* getNext(listEnemy * ListEnemy){return ListEnemy->next;}

void setEnemy(listEnemy *ListEnemy, enemy Enemy) {
    ListEnemy->Enemy = Enemy;
}

int setNext(listEnemy * ListEnemy, listEnemy * ListEnemyNext){
    ListEnemy->next = ListEnemyNext;
    if(ListEnemy->next == ListEnemyNext){
        return 0;
    }
    return -1;
}

int isEmpty(listEnemy* ListEnnemy){
    return (ListEnnemy == NULL);
}

void freeListEnemy(listEnemy* ListeEnnemis){
    if(!isEmpty(ListeEnnemis)){
        freeListEnemy(getNext(ListeEnnemis));
        free(ListeEnnemis);
    }
}

/* -------- Fonctions -------- */

bloc initBloc(int posX, int posY, int type){
    bloc Bloc;
    setBlocPosX(&Bloc,posX);
    setBlocPosY(&Bloc,posY);
    setBlocType(&Bloc,type);
    setBlocNotObstacle(&Bloc);
    return Bloc;
}

player initPLayer(){
    player Player;
    // Placage du joueur au centre de l'ecran
    setPlayerPosX(&Player,SCREEN_WIDTH/2 - PLAYER_SIZE/2); 
    setPlayerPosY(&Player,SCREEN_HEIGHT/2 - PLAYER_SIZE/2);

    setPlayerLife(&Player,PLAYER_LIFE);
    setPlayerSpeed(&Player,PLAYER_SPEED);
    setPlayerWeaponType(&Player,PISTOL_TYPE);
    setPlayerMoney(&Player,0);
    return Player;
}

enemy initEnemy(float posX, float posY, int type){
    enemy Ennemi;
    setEnemyPosX(&Ennemi, posX);
    setEnemyPosY(&Ennemi, posY);

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
            setNext(CurrentListEnnemis, malloc(sizeof(listEnemy)));

            printf("x : %f, y : %f\n", getEnemyPosX(getEnemy(CurrentListEnnemis)), getEnemyPosX(getEnemy(CurrentListEnnemis)));
            CurrentListEnnemis = getNext(CurrentListEnnemis);
        }

        //Position aléatoire
        posX = rand() % (SCREEN_WIDTH - PLAYER_SIZE + 1);
        posY = rand() % (SCREEN_HEIGHT - PLAYER_SIZE + 1);

        //Initialisation et attribution de l'ennemi
        setEnemy(CurrentListEnnemis, initEnemy(posX, posY, 1));

        setNext(CurrentListEnnemis, NULL);

        printf("x : %f, y : %f\n", getEnemyPosX(getEnemy(CurrentListEnnemis)), getEnemyPosX(getEnemy(CurrentListEnnemis)));
    }
    return *ListeEnnemis;
}



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
    if(!isEmpty(ListeEnnemis)){
        moveToPlayer(getEnemy(ListeEnnemis), player, dt);
        moveListEnemyToPlayer(getNext(ListeEnnemis), player, dt);
    }
}
