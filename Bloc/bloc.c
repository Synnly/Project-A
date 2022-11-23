#include "bloc.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

float getBlocPosX(bloc * Bloc){return getSpritePosX(getBlocSprite(Bloc));}
float getBlocPosY(bloc * Bloc){return getSpritePosY(getBlocSprite(Bloc));}
int getBlocType(bloc * Bloc){return Bloc->type;}
int getBlocIsObstacle(bloc * Bloc){return Bloc->isObstacle == 1;}
SDL_Texture* getBlocTexture(bloc* Bloc){return getSpriteTexture(getBlocSprite(Bloc));}
sprite* getBlocSprite(bloc* Bloc){return &(Bloc->sprite);}

/* ----- Setter ----- */

int setBlocPosX(bloc* Bloc, float posX){
    setSpritePosX(getBlocSprite(Bloc),  posX);
    if(fabs(getBlocPosX(Bloc) - posX) >= EPSILON){
        return 0;
    }
    return -1;
}

int setBlocPosY(bloc* Bloc, float posY){
    setSpritePosY(getBlocSprite(Bloc),  posY);
    if(fabs(getBlocPosY(Bloc) - posY) >= EPSILON){
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

void setBlocTexture(bloc* Bloc, SDL_Texture* texture){
    setSpriteTexture(getBlocSprite(Bloc), texture);
}

void setBlocSprite(bloc* Bloc, sprite* Sprite){
    Bloc->sprite = *Sprite;
}

/* ----- Initialisation ----- */

bloc initBloc(int posX, int posY, int type){
    bloc Bloc;
    sprite Sprite = initSprite(posX, posY, BLOC_SIZE, BLOC_SIZE);
    setBlocSprite(&Bloc, &Sprite);
    setBlocType(&Bloc,type);
    setBlocNotObstacle(&Bloc);
    return Bloc;
}
