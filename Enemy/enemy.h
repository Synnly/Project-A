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

/**
 * @brief Donne la hauteur du sprite de l'ennemi
 * @param Enemy l'ennemi
 */
int getEnemyHeight(enemy * Enemy);

/**
 * @brief Donne la largeur du sprite de l'ennemi
 * @param Enemy l'ennemi
 */
int getEnemyWidth(enemy * Enemy);

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
    @brief Retourne le spread de l'ennemi
    @param Enemy L'ennemi
    @return Son spread
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
*/
void setEnemyPosX(enemy * Enemy, float posX);

/*
    @brief Modifie la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @param posY Sa coordonnée Y
*/
void setEnemyPosY(enemy * Enemy, float posY);

/*
    @brief Modifie la vie restante de l'ennemi
    @param Enemy L'ennemi
    @param life Sa vie restante
*/
void setEnemyLife(enemy * Enemy, int life);

/*
    @brief Modifie la vitesse de l'ennemi
    @param Enemy L'ennemi
    @param speed Sa vitesse
*/
void setEnemySpeed(enemy * Enemy, int speed);

/*
    @brief Modifie le spread de l'ennemi
    @param Enemy L'ennemi
    @param spread Son spread
*/
void setEnemyType(enemy * Enemy, int type);

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
    @param spread Son spread
*/
enemy initEnemy(float posX, float posY, int type);

/* ----- Autre ----- */

/**
 * @brief Compare deux ennemis
 * @param Enemy1 le premier ennmi
 * @param Enemy2 le deuxieme ennemi
 * @return 1 si les deux ennemis sont les mêmes 0 sinon
 */
int isSameEnemy(enemy * Enemy1, enemy * Enemy2);

/**
 * @brief retire dmg points de vie a un enemy
 * @param Enemy L'enemy
 * @param dmg Le nombre de pv a retirer
 */
void enemyTakeDamage(enemy* Enemy,int dmg);

#endif //PROJECT_A_ENEMY_H
