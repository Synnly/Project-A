#ifndef DONNEES_H
#define DONNEES_H

#include <SDL2/SDL.h>
#include "../Sprite/sprite.h"
#include "../Player/player.h"
#include "../Enemy/enemy.h"
#include "../Enemy/listEnemy.h"
#include "../Bloc/bloc.h"
#include "../Bloc/listBloc.h"
#include "../Bullet/bullet.h"
#include "../Bullet/listBullet.h"

typedef struct player_t player;
typedef struct sprite_t sprite;
typedef struct enemy_t enemy;
typedef struct listEnemy_t listEnemy;
typedef struct bloc_t bloc;
typedef struct listBloc_t listBloc;
typedef struct bullet_t bullet;
typedef struct listBullet_t listBullet;

/* ----- FPS ----- */

/**
 * @brief Donne le nombre de fps
 * @param fps le nombre d'image par seconde
 * @param fpstimer l'image de la dernière seconde
 */
void fpsCounter(int* fps, int* fpstimer);

/**
 * @brief Limite le nombre de fps à 60
 * @param start le tick de départ
 * @param end le tick actuel
 * @return 1 si on depasse les 60 fps et 0 sinon
 */
int fpsCap(Uint32 start, Uint32* end);

/* ----- Autres ----- */

/**
 * @brief Gere les entrees clavier, souris et fenetre
 * @param event Les evenements
 * @param is_playing Variable qui traque si le jeu est en cours ou non
 * @param player Le joueur
 * @param ListeBlocs la liste des blocs
 * @param listeBalles la liste des balles
 * @param dt intervalle de temps
 * @param startFire Compteur de frames pour le tir en continu
 */
void handleEvents(SDL_Event* event, int* is_playing, player* player, listBloc* ListeBlocs, listBullet* listeBalles, double dt, double* startFire);


/**
 * @brief Déplace l'ennemi vers le joueur
 * @param enemy L'ennemi
 * @param player Le joueur
 * @param dt L'intervalle de temps
 */
void moveToPlayer(enemy* enemy, player* player, double dt);

/**
 * @brief Deplace tous les ennemis vers le joueur
 * @param ListeEnnemis La liste des ennemis
 * @param player Le joueur
 * @param dt L'intervalle de temps
 */
void moveListEnemyToPlayer(listEnemy* ListeEnnemis, player* player, double dt);

/**
 * @brief Indique si deux sprites sont en collision
 * @param Sprite1 Le premier sprite
 * @param Sprite2 LE deuxième sprite
 * @return 1 si ils sont en collision, 0 sinon
 */
int inCollision(sprite* Sprite1, sprite* Sprite2);

/**
 * @brief Indique si un sprite et un bloc obstacle sont en collision
 * @param Sprite Le sprite
 * @param ListeBlocs la liste des blocs
 * @return 1 si collision 0 sinon
 */
int spriteCollidesWalls(sprite* Sprite, listBloc* ListeBlocs);

/**
 * @brief Initialise la vitesse de la balle dans chaque axe en fonction de sa destination
 * @param Balle La balle
 * @param x La coordonnée x de sa destination
 * @param y La coordonnée x de sa destination
 */
void setBulletSpeeds(bullet* Balle, int x, int y);

#endif