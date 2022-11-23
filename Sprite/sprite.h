#ifndef PROJECT_A_SPRITE_H
#define PROJECT_A_SPRITE_H

#include <SDL2/SDL.h>

struct sprite_t{
    float posX;
    float posY;
    int height;
    int width;
    SDL_Texture* texture;
};

typedef struct sprite_t sprite;

/* ----- Getter ----- */

/**
 * @brief Retourne la coordonnée x du sprite
 * @param Sprite Le sprite
 * @return La coordonnée x;
 */
float getSpritePosX(sprite* Sprite);

/**
 * @brief Retourne la coordonnée y du sprite
 * @param Sprite Le sprite
 * @return La coordonnée y;
 */
float getSpritePosY(sprite* Sprite);

/**
 * @brief Retourne la hauteur du sprite
 * @param Sprite Le sprite
 * @return La hauteur;
 */
int getSpriteHeight(sprite* Sprite);

/**
 * @brief Retourne la largeur du sprite
 * @param Sprite Le sprite
 * @return La largeur;
 */
int getSpriteWidth(sprite* Sprite);

/**
 * @brief Retourne la texture du sprite
 * @param Sprite Le sprite
 * @return La texture
 */
SDL_Texture* getSpriteTexture(sprite* Sprite);

/* ----- Setter ----- */

/**
 * @brief Modifie la coordonnée X du joueur
 * @param Sprite Le sprite
 * @param posX Sa coordonnée X
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpritePosX(sprite* Sprite, float posX);

/**
 * @brief Modifie la coordonnée Y du joueur
 * @param Sprite Le sprite
 * @param posY Sa coordonnée Y
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpritePosY(sprite* Sprite, float posY);

/**
 * @brief Modifie la hauteur du sprite
 * @param Sprite Le sprite
 * @param height Sa hauteur
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpriteHeight(sprite* Sprite, int height);

/**
 * @brief Modifie la largeur du sprite
 * @param Sprite Le sprite
 * @param height Sa largeur
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpriteWidth(sprite* Sprite, int width);

/**
 * @brief Met à jour la texture du sprite
 * @param Sprite Le sprite
 * @param texture la texture
 */
void setSpriteTexture(sprite* Sprite, SDL_Texture* texture);

/* ----- Initialisation ----- */

/**
 * @brief Initialise un sprite
 * @param posX Sa position X
 * @param posY Sa position Y
 * @param height Sa hauteur
 * @param width Sa largeur
 * @return
 */
sprite initSprite(float posX, float posY, int height, int width);

#endif //PROJECT_A_SPRITE_H