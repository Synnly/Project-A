#include "player.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

float getPlayerPosX(player* Player){return getSpritePosX(getPlayerSprite(Player));}
float getPlayerPosY(player* Player){return getSpritePosY(getPlayerSprite(Player));}
int getPlayerLife(player* Player){return Player->life;}
int getPlayerSpeed(player* Player){return Player->speed;}
int getPlayerWeaponType(player* Player){return Player->weaponType;}
int getPlayerMoney(player* Player){return Player->money;}
SDL_Texture* getPlayerTexture(player* Player){return getSpriteTexture(getPlayerSprite(Player));}
sprite* getPlayerSprite(player* Player){return &(Player->sprite);}

/* ----- Setter ----- */

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

/* ----- Initialisation ----- */

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