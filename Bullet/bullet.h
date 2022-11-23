#ifndef PROJECT_A_BULLET_H
#define PROJECT_A_BULLET_H

#include "../Sprite/sprite.h"

struct bullet_t{
    sprite sprite;
    int xspeed;
    int yspeed;
    int type;
};

typedef struct bullet_t bullet;

/* ----- Getter ----- */

/**
 * @brief donne le sprite de la balle
 * @param Balle la balle
 */
sprite* getBulletSprite(bullet* Balle);

/**
 * @brief donne la coordonnée en x de la balle
 * @param Balle la balle
 */
float getBulletPosX(bullet* Balle);

/**
 * @brief donne la coordonnée en y de la balle
 * @param Balle la balle
 */
float getBulletPosY(bullet* Balle);

/**
 * @brief donne la hauteur du sprite de la balle
 * @param Balle la balle
 */
int getBulletHeight(bullet* Balle);

/**
 * @brief donne la largeur du sprite de la balle
 * @param Balle la balle
 */
int getBulletWidth(bullet* Balle);

/**
 * @brief donne la vitesse en x de la balle
 * @param Balle la balle
 */
int getBulletXSpeed(bullet* Balle);

/**
 * @brief donne la vitesse en y de la balle
 * @param Balle la balle
 */
int getBulletYSpeed(bullet* Balle);

/**
 * @brief donne le type de la balle
 * @param Balle la balle
 */
int getBulletType(bullet* Balle);

/**
 * @brief donne la texture du sprite de la balle
 * @param Balle la balle
 */
SDL_Texture* getBulletTexture(bullet* Balle);

/* ----- Setter ----- */

/**
 * @brief met à jour le sprite de la balle
 * @param Sprite le sprite
 * @param Balle la balle
 */
void setBulletSprite(sprite* Sprite, bullet* Balle);

/**
 * @brief Met à jour la position x de la balle
 * @param Balle la balle
 * @param posX la position en x
 * @return 1 si réussite 0 sinon
 */
int setBulletPosX(bullet* Balle, float posX);

/**
 * @brief Met à jour la coordonnée y de la balle
 * @param Balle la balle
 * @param posY la position en y
 * @return 1 si réussite 0 sinon
 */
int setBulletPosY(bullet* Balle, float posY);

/**
 * @brief Met à jour la vitesse en x de la balle
 * @param Balle la balle
 * @param xSpeed la vitesse en x
 * @return 1 si réussite 0 sinon
 */
int setBulletXSpeed(bullet* Balle, int xSpeed);

/**
 * @brief Met à jour la vitesse y de la balle
 * @param Balle la balle
 * @param ySpeed la vitesse en y
 * @return 1 si réussite 0 sinon
 */
int setBulletYSpeed(bullet* Balle, int ySpeed);

/**
 * @brief Met à jour le type de la balle
 * @param Balle la balle
 * @param type le type
 * @return 1 si réussite 0 sinon
 */
int setBulletType(bullet* Balle, int type);

/**
 * @brief Met à jour la texture de la balle
 * @param Balle la balle
 * @param texture la texture
 */
void setBulletTexture(bullet* Balle, SDL_Texture* texture);

/* ----- Initialisation ----- */

/**
 * @brief initialise une balle
 * @param posX la position en x de la balle
 * @param posY la position en y de la balle
 * @param speedX la vitesse en x de la balle
 * @param speedY la vitesse en y de la balle
 * @param type le type de la balle
 * @return la balle initialisée
 */
bullet initBullet(float posX, float posY, int speedX, int speedY, int type);

/* ----- Autre ----- */

/**
 * @brief Compare deux balles
 * @param Balle1 la première balle
 * @param Balle2 la deuxième balle
 * @return 1 si les deux balles sont les mêmes 0 sinon
 */
int isSameBullet(bullet* Balle1, bullet* Balle2);

#endif //PROJECT_A_BULLET_H
