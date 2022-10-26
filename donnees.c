#include <SDL2/SDL.h>
#include "donnees.h"

/* ---------- Getter / Setter -------- */

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


/* -------- Fonctions -------- */

bloc initBloc(int posX, int posY, int type){
    bloc Bloc;
    Bloc.posX = posX;
    Bloc.posY = posY;
    Bloc.type = type;
    Bloc.isObstacle = 0;
    return Bloc;
}

player initPLayer(){
    player Player;
    // Placage du joueur au centre de l'ecran
    Player.posX = SCREEN_WIDTH/2 - PLAYER_SIZE/2;
    Player.posY = SCREEN_HEIGHT/2 - PLAYER_SIZE/2;

    Player.life = PLAYER_LIFE;
    Player.speed = PLAYER_SPEED;
    Player.weaponType = PISTOL_TYPE;
    Player.money = 0;
    return Player;
}

enemy initEnemy(int posX, int posY, int type){
    enemy Ennemi;
    Ennemi.posX = posX;
    Ennemi.posY = posY;

    switch(type){
        
        // A remplir au moment de l'ajout des ennemis
        case 0:
            break;

        default:
            Ennemi.life = PLAYER_LIFE;
            Ennemi.speed = PLAYER_SPEED;
    }
    return Ennemi;
}
