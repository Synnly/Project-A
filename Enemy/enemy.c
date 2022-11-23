#include "enemy.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

float getEnemyPosX(enemy* Enemy){return getSpritePosX(getEnemySprite(Enemy));}
float getEnemyPosY(enemy* Enemy){return getSpritePosY(getEnemySprite(Enemy));}
int getEnemyLife(enemy* Enemy){return Enemy->life;}
int getEnemySpeed(enemy* Enemy){return Enemy->speed;}
int getEnemyType(enemy* Enemy){return Enemy->type;}
SDL_Texture* getEnemyTexture(enemy* Enemy){return getSpriteTexture(getEnemySprite(Enemy));}
sprite* getEnemySprite(enemy* Enemy){return &(Enemy->sprite);}

/* ----- Setter ----- */

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
    setSpriteTexture(getEnemySprite(Enemy), texture);
}

void setEnemySprite(enemy * Enemy, sprite* Sprite){
    Enemy->sprite = *Sprite;
}

/* ----- Initialisation ----- */

enemy initEnemy(float posX, float posY, int type){
    enemy Ennemi;
    sprite Sprite = initSprite(posX, posY, ENEMY_SIZE, ENEMY_SIZE);
    setEnemySprite(&Ennemi, &Sprite);

    switch(type){

        // A remplir au moment de l'ajout des ennemis
        case 0:
            break;

        default:
            setEnemyLife(&Ennemi,ENEMY_LIFE);
            setEnemySpeed(&Ennemi,ENEMY_SPEED/2);
    }

    setEnemyType(&Ennemi, type);
    return Ennemi;
}