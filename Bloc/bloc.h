#ifndef PROJECT_A_BLOC_H
#define PROJECT_A_BLOC_H

#include "../Sprite/sprite.h"

struct bloc_t{    // Structure d'un bloc obstacle
    sprite sprite;
    int type;   //0 bloc classique, 1 bloc
    int isObstacle;     // 1 si le bloc est un obstacle, 0 sinon
};

typedef struct bloc_t bloc;

/* ----- Getter ----- */

/*
    @brief Retourne la coordonne X du bloc
    @param Bloc Le bloc
    @return La coordonnée X
*/
float getBlocPosX(bloc * Bloc);

/*
    @brief Retourne la coordonne Y du bloc
    @param Bloc Le bloc
    @return La coordonnée Y
*/
float getBlocPosY(bloc * Bloc);

/*
    @brief Retourne le type du bloc
    @param Bloc Le bloc
    @return 0 = Mur, 1 = Entrée d'ennemis, 2 = Zone de soin
*/
int getBlocType(bloc * Bloc);

/*
    @brief Retourne si le bloc est obstacle ou non
    @param Bloc Le bloc
    @return 1 si le bloc est un obstacle, 0 sinon
*/
int getBlocIsObstacle(bloc * Bloc);

/**
 * @brief Retourne la texture du bloc
 * @param Bloc le bloc
 */
SDL_Texture* getBlocTexture(bloc* Bloc);

/**
 * @brief Retourne le sprite
 * @param Bloc Le bloc
 * @return Le sprite
 */
sprite* getBlocSprite(bloc* Bloc);

/* ----- Setter ----- */

/*
    @brief Modifie la coordonnée X du bloc
    @param Bloc Le bloc
    @param posX Sa nouvelle coordonnée X
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocPosX(bloc * Bloc, float posX);

/*
    @brief Modifie la coordonnée Y du bloc
    @param Bloc Le bloc
    @param posY Sa nouvelle coordonnée Y
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocPosY(bloc * Bloc, float posY);

/*
    @brief Modifie le type du bloc
    @param Bloc Le bloc
    @param type Son nouveau type
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocType(bloc * Bloc, int type);

/*
    @brief Rend le bloc obstacle
    @param Bloc Le bloc
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocObstacle(bloc * Bloc);

/*
    @brief Rend le bloc non-obstacle
    @param Bloc Le bloc
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocNotObstacle(bloc * Bloc);

/**
 *@brief Met la texture du bloc
 * @param Bloc Le bloc
 *@param texture La texture
 */
void setBlocTexture(bloc* Bloc, SDL_Texture* texture);

/**
 * @brief Modifie le sprite
 * @param Bloc Le bloc
 * @param Sprite Le sprite
 */
void setBlocSprite(bloc* Bloc, sprite* Sprite);

/* ----- Initialisation ----- */

/*
    @brief Initialise un bloc non-obstacle
    @param posX Sa coordonnée X
    @param posY Sa coordonnée Y
    @param type Son type
    @return Le bloc
*/
bloc initBloc(int posX, int posY, int type);

#endif //PROJECT_A_BLOC_H
