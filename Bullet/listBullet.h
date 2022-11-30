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
 * @return 1 si la balle a été supprimée, 0 si la balle n'est pas dans la liste, -1 si la liste ou la balle est vide
 */
int deleteBullet(listBullet* ListeBalles, bullet* Balle);


/**
 * @brief Déplace toutes les balles
 * @param ListeBalles La liste des balles
 */
void moveBullets(listBullet* ListeBalles);

#endif //PROJECT_A_LISTBULLET_H