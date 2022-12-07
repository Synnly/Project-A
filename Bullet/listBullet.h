#ifndef PROJECT_A_LISTBULLET_H
#define PROJECT_A_LISTBULLET_H

#include "bullet.h"
typedef struct bullet_t bullet;

struct listBullet_t{
    bullet Bullet;
    struct listBullet_t* next;
};

typedef struct listBullet_t listBullet;

/* ----- Getter ----- */

/**
 * @brief Renvoie la balle
 * @param ListeBalles la liste de balles
 * @return la balle
 */
bullet* getBullet(listBullet * ListeBalles);

/**
 * @brief Renvoie la liste de balles suivante
 *
 * @param ListeBalles la liste de balles
 * @return la prochaine liste de balles
 */
listBullet* getNextBullet(listBullet * ListeBalles);

/* ----- Setter ----- */

/**
 * @brief Met à jour la balle de la liste
 * @param ListeBalles la liste de balles
 * @param Balle la balle
 */
void setBullet(listBullet *ListeBalles, bullet Balle);

/**
 * @brief Met à jour la balle suivante de la liste
 * @param ListeBalles La liste des balles
 * @param ListeBallesNext Le prochain maillon de la liste
 * @return int
 */
int setNextBullet(listBullet * ListeBalles, listBullet * ListeBallesNext);

/* ----- Initialisation ----- */

/**
 * @brief initialise la liste de balles
 * @return la liste de balles intialisée
 */
listBullet initListBullet();

/* ----- Autre ----- */

/**
 * @brief Retourne l'etat de la liste de balles
 * @param ListeBalles la liste de balles
 * @return 1 si vide 0 sinon
 */
int isEmptyListBullet(listBullet* ListeBalles);

/**
 * @brief Libère la mémoire reservée par la liste de balles
 * @param ListeBalles la liste de balles
 */
void freeListBullet(listBullet* ListeBalles);

/**
 * @brief Ajoute une balle dans la liste de balles
 * @param ListeBalles La liste de balles
 * @param Balle la balle à ajouter
 */
void addBullet(listBullet* ListeBalles, bullet* Balle);

/**
 * @brief Supprime une balle de la liste de balles
 * @param ListeBalles la liste de balles
 * @param Balle la balle à supprimer
 */
void deleteBullet(listBullet* ListeBalles, bullet* Balle);

/**
 * @brief Supprime les balles qui sont marquees comme "a detruire"
 * @param ListeBalles La liste des balles
 */
void deleteBulletsToBeDesttroyed(listBullet* ListeBalles);

/**
 * @brief Déplace toutes les balles
 * @param ListeBalles La liste des balles
 * @param dt Le laps de temps écoulé depuis la dernière execution
 */
void moveBullets(listBullet* ListeBalles, double dt);

#endif //PROJECT_A_LISTBULLET_H