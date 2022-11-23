#ifndef PROJECT_A_ENEMY_H
#define PROJECT_A_ENEMY_H

#include "../Sprite/sprite.h"


struct enemy_t{       //Structure d'un ennemi
    sprite sprite;
    int life;
    int speed;
    int type;
};

typedef struct enemy_t enemy;

/* ----- Getter ----- */

/*
    @brief Retourne la coordonnée X de l'ennemi
    @param Enemy L'ennemi
    @return Sa coordonnée X
*/
float getEnemyPosX(enemy * Enemy);

/*
    @brief Retourne la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @return Sa coordonnée Y
*/
float getEnemyPosY(enemy * Enemy);

/*
    @brief Retourne la vie restante de l'ennemi
    @param Enemy L'ennemi
    @return Sa quatitié de vie restante
*/
int getEnemyLife(enemy * Enemy);

/*
    @brief Retourne la vitesse de l'ennemi
    @param Enemy L'ennemi
    @return Sa vitesse
*/
int getEnemySpeed(enemy * Enemy);

/*
    @brief Retourne le type de l'ennemi
    @param Enemy L'ennemi
    @return Son type
*/
int getEnemyType(enemy * Enemy);

/**
 * @brief Retourne la texture du sprite de l'ennemi
 * @param Enemy l'ennemi
 * @return la texture
 */
SDL_Texture* getEnemyTexture(enemy* Enemy);

/**
 * @brief Retourne le sprite
 * @param Enemy L'ennemi
 * @return Le sprite
 */
sprite* getEnemySprite(enemy* Enemy);

/* ----- Setter ----- */

/*
    @brief Modifie la coordonnée X de l'ennemi
    @param Enemy L'ennemi
    @param posX Sa coordonnée X
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyPosX(enemy * Enemy, float posX);

/*
    @brief Modifie la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @param posY Sa coordonnée Y
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyPosY(enemy * Enemy, float posY);

/*
    @brief Modifie la vie restante de l'ennemi
    @param Enemy L'ennemi
    @param life Sa vie restante
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyLife(enemy * Enemy, int life);

/*
    @brief Modifie la vitesse de l'ennemi
    @param Enemy L'ennemi
    @param speed Sa vitesse
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemySpeed(enemy * Enemy, int speed);

/*
    @brief Modifie le type de l'ennemi
    @param Enemy L'ennemi
    @param type Son type
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyType(enemy * Enemy, int type);

/**
 * @brief Met à jour la texture du sprite de l'ennemi
 * @param Enemy l'ennemi
 * @param texture la texture
 */
void setEnemyTexture(enemy* Enemy, SDL_Texture* texture);

/**
 * @brief Modifie le sprite
 * @param Enemy L'ennemi
 * @param Sprite Le sprite
 * @return Le sprite
 */
void setEnemySprite(enemy* Enemy, sprite* Sprite);

/* ----- Initialisation ----- */

/*
    @brief Initialise un ennemi
    @param posX Sa coordonnée X
    @param posY Sa coordonnée Y
    @param type Son type
*/
enemy initEnemy(float posX, float posY, int type);

#endif //PROJECT_A_ENEMY_H
