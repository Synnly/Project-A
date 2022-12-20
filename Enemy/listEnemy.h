#ifndef PROJECT_A_LISTENEMY_H
#define PROJECT_A_LISTENEMY_H

#include "enemy.h"
typedef struct enemy_t enemy;

struct listEnemy_t{
    enemy Enemy;
    struct listEnemy_t * next;
};

typedef struct listEnemy_t listEnemy;

/* ----- Getter ----- */

/**
 * @brief Retourne l'ennemi de la liste chainée
 * @param ListEnemy La liste
 * @return L'ennemi
 */
enemy* getEnemy(listEnemy * ListEnemy);

/**
 * @brief Retourne la liste chainee suivante
 * @param ListEnemy La liste
 * @return La liste suivante
 */
listEnemy* getNextE(listEnemy * ListEnemy);

/* ----- Setter ----- */

/**
 * @brief Modifie l'ennemi de la liste chainée
 * @param ListEnemy La liste
 * @param Enemy L'ennemi
 */
void setEnemy(listEnemy * ListEnemy, enemy Enemy);

/**
 * @brief Modifie la liste chainee suivante
 * @param ListEnemy La liste
 * @param ListEnemyNext La liste suivante
 * @return -1 en cas d'échec, 0 sinon
 */
int setNextE(listEnemy * ListEnemy, listEnemy * ListEnemyNext);

/* ----- Initialisation ----- */

/*
    @brief Initialise une liste chainée de nb ennemis
    @param nb Le nombre d'ennemis
    @return La liste chainées des ennemis
*/
listEnemy initListEnemy(int nb);

/* ----- Autre ----- */

/**
 * @brief Indique si la liste est vide
 * @param ListEnnemy La liste
 * @return 1 si la liste est vide, 0 sinon
 */
int isEmptyLE(listEnemy* ListEnnemy);

/**
 * @brief Libere la liste
 * @param ListeEnnemis La liste d'ennemis
 */
void freeListEnemy(listEnemy* ListeEnnemis);

/**
 * @brief Supprime un ennemi de la liste d'ennemis
 * @param ListeEnnemis la liste des ennemis
 * @param Ennemi l'ennemi à supprimer
 */
void deleteEnemy(listEnemy* ListeEnnemis, enemy * Ennemi);

/**
 * @brief Supprime les ennemis qui sont marquees comme "a detruire"
 * @param ListeEnnemis La liste des ennemis
 */
void deleteEnemiesToBeDestroyed(listEnemy* ListeEnnemis);

#endif //PROJECT_A_LISTENEMY_H
