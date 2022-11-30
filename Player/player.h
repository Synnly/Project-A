#ifndef PROJECT_A_PLAYER_H
#define PROJECT_A_PLAYER_H

#include "../Donnees/donnees.h"
#include "../Sprite/sprite.h"

struct player_t{      //Structure du joueur
    sprite sprite;
    int life;
    int speed;
    int weaponType;
    int money;
};

typedef struct player_t player;

/* ----- Getter ----- */

/*
    @brief Retourne la coordonnée X du joueur
    @param Player Le joueur
    @return Sa coordonnée X
*/
float getPlayerPosX(player * Player);

/*
    @brief Retourne la coordonnée Y du joueur
    @param Player Le joueur
    @return Sa coordonnée Y
*/
float getPlayerPosY(player * Player);

/*
    @brief Retourne la vie restante du joueur
    @param Player Le joueur
    @return Sa quatitié de vie restante
*/
int getPlayerLife(player * Player);

/*
    @brief Retourne la vitesse du joueur
    @param Player Le joueur
    @return Sa vitesse
*/
int getPlayerSpeed(player * Player);

/*
    @brief Retourne le type de l'arme du joueur
    @param Player Le joueur
    @return Le type de son arme
*/
int getPlayerWeaponType(player * Player);

/*
    @brief Retourne la quatité d'argent du joueur
    @param Player Le joueur
    @return Sa quatité d'argent
*/
int getPlayerMoney(player * Player);

/**
 * @brief Retourne la texture du sprite du joueur
 * @param player le joueur
 * @return la texture
 */
SDL_Texture* getPlayerTexture(player* Player);

/**
 * @brief Retourne le sprite
 * @param Player Le joueur
 * @return Le sprite
 */
sprite* getPlayerSprite(player* PLayer);

/* ----- Setter ----- */

/*
    @brief Modifie la coordonnée X du joueur
    @param Player Le joueur
    @param posX Sa coordonnée X
*/
void setPlayerPosX(player * Player, float posX);

/*
    @brief Modifie la coordonnée Y du joueur
    @param Player Le joueur
    @param posY Sa coordonnée Y
*/
void setPlayerPosY(player * Player, float posY);

/*
    @brief Modifie la vie restante du joueur
    @param Player Le joueur
    @param life Sa vie restante
*/
void setPlayerLife(player * Player, int life);

/*
    @brief Modifie la vitesse du joueur
    @param Player Le joueur
    @param speed Sa vitesse
*/
void setPlayerSpeed(player * Player, int speed);

/*
    @brief Modifie le type de l'arme du joueur
    @param Player Le joueur
    @param weaponType Le type de son arme
*/
void setPlayerWeaponType(player * Player, int weaponType);

/*
    @brief Modifie le montant de l'argent du joueur
    @param Player le joueur
    @param money le nouveau montant de l'argent du joueur
*/
void setPlayerMoney(player* Player, int money);

/**
 * @brief Met à jour la texture du sprite du joueur
 * @param player le joueur
 * @param texture la texture
 */
void setPlayerTexture(player* Player, SDL_Texture* texture);

/**
 * @brief Modifie le sprite
 * @param Player Le joueur
 * @param Sprite Le sprite
 */
void setPlayerSprite(player* Player, sprite* Sprite);

/* ----- Initialisation ----- */

/*
    @brief Initialise un joueur
    @return Le joueur
*/
player initPLayer();

#endif
