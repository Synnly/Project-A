#include "player.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

float getPlayerPosX(player* Player){return getSpritePosX(getPlayerSprite(Player));}
float getPlayerPosY(player* Player){return getSpritePosY(getPlayerSprite(Player));}
int getPlayerLife(player* Player){return Player->life;}
int getPlayerSpeed(player* Player){return Player->speed;}
int getPlayerWeaponType(player* Player){return Player->weaponType;}
int* getPlayerScore(player* Player){return &Player->score;}
SDL_Texture* getPlayerTexture(player* Player){return getSpriteTexture(getPlayerSprite(Player));}
sprite* getPlayerSprite(player* Player){return &(Player->sprite);}

/* ----- Setter ----- */

void setPlayerPosX(player* Player, float posX){
    setSpritePosX(getPlayerSprite(Player),  posX);
}

void setPlayerPosY(player* Player, float posY){
    setSpritePosY(getPlayerSprite(Player),  posY);
}

void setPlayerLife(player* Player, int life){
    Player->life = life;
}

void setPlayerSpeed(player* Player, int speed){
    Player->speed = speed;
}

void setPlayerWeaponType(player* Player, int weapontype){
    Player->weaponType = weapontype;
}

void setPlayerScore(player* Player, int score){
    Player->score = score;
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
    setPlayerScore(&Player,0);
    return Player;
}

void playerTakeDamage(player* Player, int dmg){
    if(dmg > getPlayerLife(Player)){
        setPlayerLife(Player,0);
    }else{
        setPlayerLife(Player, getPlayerLife(Player)-dmg);
    }
}