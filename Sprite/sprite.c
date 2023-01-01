#include "sprite.h"
#include "../Donnees/donnees.h"

/* ----- Getter ----- */

float getSpritePosX(sprite* Sprite){return Sprite->posX;}
float getSpritePosY(sprite* Sprite){return Sprite->posY;}
int getSpriteHeight(sprite* Sprite){return Sprite->height;}
int getSpriteWidth(sprite* Sprite){return Sprite->width;}
SDL_Texture* getSpriteTexture(sprite* Sprite){return Sprite->texture;}
int getSpriteToBeDestroyed(sprite* Sprite){return Sprite->toBeDestroyed;}
int getSpriteIsNull(sprite* Sprite){return Sprite->isNull;}


/* ----- Setter ----- */

void setSpritePosX(sprite* Sprite, float posX){Sprite->posX = posX;}
void setSpritePosY(sprite* Sprite, float posY) {Sprite->posY = posY;}
void setSpriteHeight(sprite* Sprite, int height){Sprite->height = height;}
void setSpriteWidth(sprite* Sprite, int width){Sprite->width = width;}
void setSpriteTexture(sprite* Sprite, SDL_Texture* texture){Sprite->texture = texture;}
void setSpriteToBeDestroyed(sprite* Sprite, int valeur){Sprite->toBeDestroyed = valeur;}
void setSpriteIsNull(sprite* Sprite, int valeur){Sprite->isNull = valeur;}

/* ----- Initialisation ----- */

sprite initSprite(float posX, float posY, int height, int width){
    sprite Sprite;
    setSpritePosX(&Sprite, posX);
    setSpritePosY(&Sprite, posY);
    setSpriteHeight(&Sprite, height);
    setSpriteWidth(&Sprite, width);
    setSpriteToBeDestroyed(&Sprite, 0);
    setSpriteIsNull(&Sprite, 0);
    setSpriteTexture(&Sprite,NULL);
    return Sprite;
}