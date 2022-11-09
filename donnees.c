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


float getPlayerPosX(player* Player){return Player->posX;}
float getPlayerPosY(player* Player){return Player->posY;}
int getPlayerLife(player* Player){return Player->life;}
int getPlayerSpeed(player* Player){return Player->speed;}
int getPlayerWeaponType(player* Player){return Player->weaponType;}
int getPlayerMoney(player* Player){return Player->money;}

int setPlayerPosX(player* Player, float posX){
    Player->posX = posX;
    if(abs(getPlayerPosX(Player) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setPlayerPosY(player* Player, float posY){
    Player->posY = posY;
    if(abs(getPlayerPosY(Player) - posY) >= EPSILON){
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

int fpsCounter(int* fps, int* fpstimer){
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
        SDL_Delay(1);
        return 1;
    }
    return 0;
}



void handleEvents(SDL_Event* event, int* is_playing, player* player, double dt){

    // Fermeture du jeu    
    if((SDL_PollEvent(event) && (event->type==SDL_QUIT))){*is_playing = 0;}

    if(event->type == SDL_KEYDOWN){
        switch (event->key.keysym.sym)
        {
        
        /*
        TO DO : Syteme de deplacement "continu" -> le joueur continue de se deplacer immediatement apres avoir 
        appuyé sur la touche et tant que la touche est maintenue au lieu de devoir attendre quelques instants
        -> implémentation avec playerXVelocity et while SDL_KEYDOWN ? 
        */

        case SDLK_LEFT:
            setPlayerPosX(player, max(0, getPlayerPosX(player)-PLAYER_SPEED*dt));
            break;
        
        case SDLK_RIGHT:
            setPlayerPosX(player, min(SCREEN_WIDTH - PLAYER_SIZE,getPlayerPosX(player) + PLAYER_SPEED*dt));
            break;

        case SDLK_DOWN:
            setPlayerPosY(player, min(SCREEN_HEIGHT - PLAYER_SIZE,getPlayerPosY(player) + PLAYER_SPEED*dt));
            break;

        case SDLK_UP:
            setPlayerPosY(player, max(0,getPlayerPosY(player)-PLAYER_SPEED*dt));
            break;
        
        default:
            break;
        }
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

