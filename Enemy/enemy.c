#include "enemy.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

float getEnemyPosX(enemy* Enemy){return getSpritePosX(getEnemySprite(Enemy));}
float getEnemyPosY(enemy* Enemy){return getSpritePosY(getEnemySprite(Enemy));}
int getEnemyHeight(enemy* Enemy){return getSpriteHeight(getEnemySprite(Enemy));}
int getEnemyWidth(enemy* Enemy){return getSpriteWidth(getEnemySprite(Enemy));}
int getEnemyLife(enemy* Enemy){return Enemy->life;}
int getEnemySpeed(enemy* Enemy){return Enemy->speed;}
int getEnemyType(enemy* Enemy){return Enemy->type;}
SDL_Texture* getEnemyTexture(enemy* Enemy){return getSpriteTexture(getEnemySprite(Enemy));}
sprite* getEnemySprite(enemy* Enemy){return &(Enemy->sprite);}

/* ----- Setter ----- */

void setEnemyPosX(enemy* Enemy, float posX){
    setSpritePosX(getEnemySprite(Enemy), posX);
}

void setEnemyPosY(enemy* Enemy, float posY) {
    setSpritePosY(getEnemySprite(Enemy), posY);
}

void setEnemyLife(enemy* Enemy, int life){
    Enemy->life = life;
}

void setEnemySpeed(enemy* Enemy, int speed){
    Enemy->speed = speed;
}

void setEnemyType(enemy* Enemy, int type){
    Enemy->type = type;
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

/* ----- Autre ----- */

int isSameEnemy(enemy* Enemy1, enemy* Enemy2){

    if(Enemy1 == NULL || Enemy2 == NULL){
        printf("Ennemi1 ou 2 null\n");
        return 0;
    }

    else if((getEnemyPosX(Enemy1) == getEnemyPosX(Enemy2)) && (getEnemyPosY(Enemy1) == getEnemyPosY(Enemy2)) &&
            (getEnemyHeight(Enemy1) == getEnemyHeight(Enemy2)) && (getEnemyWidth(Enemy1) == getEnemyWidth(Enemy2)) &&
            (getEnemySpeed(Enemy1) == getEnemySpeed(Enemy2)) && (getEnemyLife(Enemy1) == getEnemyLife(Enemy2)) &&
            (getEnemyType(Enemy1) == getEnemyType(Enemy2))){
        return 1;
    }
    return 0;
}

void enemyTakeDamage(enemy* Enemy, int dmg){
    if(dmg > getEnemyLife(Enemy)){
        setEnemyLife(Enemy,0);
    }else{
        setEnemyLife(Enemy, getEnemyLife(Enemy)-dmg);
    }
}