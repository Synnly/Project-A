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
 * @param startFire Nombre de secondes depuis le dernier tir
 * @param mouseX La position dans l'axe X de la souris
 * @param mouseY La position dans l'axe Y de la souris
 * @param mouseBitMask L'état des boutons de la souris
 */
void handleEvents(SDL_Event* event, int* is_playing, player* player, bloc* ListeBlocs, listBullet* listeBalles, double dt, double* startFire,  int mouseX, int mouseY, Uint32 mouseBitMask);

/**
 * @brief Déplace l'ennemi vers le joueur
 * @param enemy L'ennemi
 * @param ListeEnnemis La liste des ennemis
 * @param ListeBlocs La liste des blocs
 * @param player Le joueur
 * @param dt L'intervalle de temps
 */
void moveToPlayer(enemy* enemy, listEnemy* ListeEnnemis, bloc* ListeBlocs, player* player, double dt);

/**
 * @brief Deplace tous les ennemis vers le joueur
 * @param ListeEnnemisActuelle La liste actuele des ennemis
 * @param ListeEnnemis La liste complete des ennemis
 * @param ListeBlocs La liste des blocs
 * @param player Le joueur
 * @param dt L'intervalle de temps
 */
void moveListEnemyToPlayer(listEnemy* ListeEnnemisActuelle, listEnemy* ListeEnnemis, bloc* ListeBlocs, player* player, double dt);

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
int spriteCollidesWalls(sprite* Sprite, bloc* ListeBlocs);

/**
 * @brief Initialise la vitesse de la balle dans chaque axe en fonction de sa destination
 * @param Balle La balle
 * @param x La coordonnée x de sa destination
 * @param y La coordonnée x de sa destination
 */
void setBulletSpeeds(bullet* Balle, int x, int y);

/**
 * @Brief Dessine une ligne rouge de (x1, y1) et qui dépasse (x2, y2)
 * @param renderer Le renderer
 * @param x1 Coordonnée X du point de départ
 * @param y1 Coordonnée Y du point de départ
 * @param x2 Coordonnée X du point d'arrivée
 * @param y2 Coordonnée Y du point d'arrivée
 */
void drawLine(SDL_Renderer* renderer, float x1, float y1, float x2, float y2);

/**
 * @brief Indique si la balle est en collision avec un ennemiw
 * @param Balle La balle
 * @param listeEnnemis La liste des ennemis
 * @return 1 si la balle touche un ennemi, 0 sinon
 */
int bulletCollidesEnemies(bullet* Balle, listEnemy* listeEnnemis);

/**
 * @brief Marque une balle a etre detruite si elle touche un ennemi
 * @param ListeBalle La liste des balles
 * @param ListeEnnemi La liste des ennemis
 */
void bulletsCollidesEnemies(listBullet* ListeBalle, listEnemy* ListeEnnemi);

/**
 * @brief Verifie si l'ennemi est en collision qvec un autre ennemi de la liste
 * @param Ennemi L'ennemi
 * @param ListeEnnemis La liste des ennemis
 * @return 1 si l'ennemi entre en collision avec un autre, 0 sinon;
 */
int enemyIsCollidingListEnemy(enemy* Ennemi, listEnemy* ListeEnnemis);

/**
 * @brief Déplace toutes les balles
 * @param ListeBalles La liste des balles
 * @param ListeBlocs La liste des blocs
 * @param dt Le laps de temps écoulé depuis la dernière execution
 */
void moveBullets(listBullet* ListeBalles, bloc* ListeBlocs, double dt);

#endif