#include "sprite.h"
#include "../Donnees/donnees.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

float getSpritePosX(sprite* Sprite){return Sprite->posX;}
float getSpritePosY(sprite* Sprite){return Sprite->posY;}
int getSpriteHeight(sprite* Sprite){return Sprite->height;}
int getSpriteWidth(sprite* Sprite){return Sprite->width;}
SDL_Texture* getSpriteTexture(sprite* Sprite){return Sprite->texture;}

/* ----- Getter ----- */

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

/* ----- Initialisation ----- */

sprite initSprite(float posX, float posY, int height, int width){
    sprite Sprite;
    setSpritePosX(&Sprite, posX);
    setSpritePosY(&Sprite, posY);
    setSpriteHeight(&Sprite, height);
    setSpriteWidth(&Sprite, width);
    return Sprite;
}