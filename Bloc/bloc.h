#ifndef PROJECT_A_BLOC_H
#define PROJECT_A_BLOC_H

#include "../Sprite/sprite.h"

struct bloc_t{          // Structure d'un bloc obstacle
    sprite sprite;
    int spread;         //Pourcentage de chance que le bloc se transforme en obstacle
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
    @brief Retourne le pourcentage de contagion du bloc
    @param Bloc Le bloc
    @return La pourcentage de contagion
*/
int getBlocSpread(bloc * Bloc);

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
*/
void setBlocPosX(bloc * Bloc, float posX);

/*
    @brief Modifie la coordonnée Y du bloc
    @param Bloc Le bloc
    @param posY Sa nouvelle coordonnée Y
*/
void setBlocPosY(bloc * Bloc, float posY);

/*
    @brief Modifie le pourcentage de contagion du bloc
    @param Bloc Le bloc
    @param spread Son nouveau spread
*/
void setBlocSpread(bloc * Bloc, int spread);

/*
    @brief Rend le bloc obstacle
    @param Bloc Le bloc
*/
void setBlocObstacle(bloc * Bloc);

/*
    @brief Rend le bloc non-obstacle
    @param Bloc Le bloc
*/
void setBlocNotObstacle(bloc * Bloc);

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
    @param spread Son spread
    @return Le bloc
*/
bloc initBloc(int posX, int posY, int spread);

#endif //PROJECT_A_BLOC_H
