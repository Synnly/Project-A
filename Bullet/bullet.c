#include "bullet.h"
#include "../Donnees/constantes.h"
#include "../Donnees/maths.h"
#include <SDL2/SDL.h>

/* ----- Getter ----- */

sprite* getBulletSprite(bullet* Balle){return &(Balle->sprite);}
float getBulletPosX(bullet* Balle){return getSpritePosX(getBulletSprite(Balle));}
float getBulletPosY(bullet* Balle){return getSpritePosY(getBulletSprite(Balle));}
int getBulletHeight(bullet* Balle){return getSpriteHeight(getBulletSprite(Balle));}
int getBulletWidth(bullet* Balle){return getSpriteWidth(getBulletSprite(Balle));}
float getBulletXSpeed(bullet* Balle){return Balle->xspeed;}
float getBulletYSpeed(bullet* Balle){return Balle->yspeed;}
int getBulletType(bullet* Balle){return Balle->type;}
SDL_Texture* getBulletTexture(bullet* Balle){return getSpriteTexture(getBulletSprite(Balle));}

/* ----- Setter ----- */

void setBulletSprite(sprite* Sprite, bullet* Balle){
    Balle->sprite = *Sprite;
}

int setBulletPosX(bullet* Balle, float posX){
    setSpritePosX(getBulletSprite(Balle), posX);
    if(fabs(getBulletPosX(Balle) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setBulletPosY(bullet* Balle, float posY){
    setSpritePosY(getBulletSprite(Balle), posY);
    if(fabs(getBulletPosY(Balle) - posY) >= EPSILON){
        return 0;
    }
    return -1;
}

int setBulletXSpeed(bullet* Balle, float xSpeed){
    Balle->xspeed = xSpeed;
    if(Balle->xspeed == xSpeed){
        return 1;
    }
    return 0;
}

int setBulletYSpeed(bullet* Balle, float ySpeed){
    Balle->yspeed = ySpeed;
    if(Balle->yspeed == ySpeed){
        return 1;
    }
    return 0;
}

int setBulletType(bullet* Balle, int type){
    Balle->type = type;
    if(Balle->type == type){
        return 1;
    }
    return 0;
}

void setBulletTexture(bullet* Balle, SDL_Texture* texture){
    setSpriteTexture(getBulletSprite(Balle),texture);
}

/* ----- Initialisation ----- */

bullet initBullet(float posX, float posY, int speedX, int speedY, int type){
    bullet Balle;

    // Positionné au centre du joueur
    sprite Sprite = initSprite(posX,posY,BULLET_SIZE,BULLET_SIZE);
    setBulletSprite(&Sprite, &Balle);

    switch (type){

        //à compléter plus tard (avec un peu de chance)
        case 1:
            break;
        default:
            setBulletXSpeed(&Balle, speedX);
            setBulletYSpeed(&Balle, speedY);
            break;
    }
    setBulletType(&Balle, type);

    //La texture est initilisée à NULL pour pouvoir la différencier des balles qui ont une texture pour initialiser sa texture dans graphismes.c/initListBulletTextures()
    setBulletTexture(&Balle, NULL);
    return Balle;
}

/* ----- Autre ----- */

int isSameBullet(bullet* Balle1, bullet* Balle2){
    if((getBulletPosX(Balle1) == getBulletPosX(Balle2)) && (getBulletPosY(Balle1) == getBulletPosY(Balle2)) &&
       (getBulletHeight(Balle1) == getBulletHeight(Balle2)) && (getBulletWidth(Balle1) == getBulletWidth(Balle2)) &&
       (getBulletXSpeed(Balle1) == getBulletXSpeed(Balle2)) && (getBulletYSpeed(Balle1) == getBulletYSpeed(Balle2)) &&
       (getBulletType(Balle1) == getBulletType(Balle2))){
        return 1;
    }
    return 0;
}

void setBulletSpeeds(bullet* Balle, int x, int y){

    // Distance sur chaque axe à parcourir
    float distX = getBulletPosX(Balle)-x;
    float distY = getBulletPosY(Balle)-y;

    // Distance à parcourir
    float dist = sqrt(pow(distX, 2) + pow(distY, 2));

    // Pourcentage de la distance à parcourir en 1s
    float prct = BULLET_SPEED/dist;

    setBulletXSpeed(Balle, distX * prct);
    setBulletYSpeed(Balle, distY * prct);
}

