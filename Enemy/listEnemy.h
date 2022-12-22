#ifndef PROJECT_A_LISTENEMY_H
#define PROJECT_A_LISTENEMY_H

#include "enemy.h"
typedef struct enemy_t enemy;

struct listEnemy_t{
    enemy Enemy;
    struct listEnemy_t* next;
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
 */
void setNextE(listEnemy * ListEnemy, listEnemy * ListEnemyNext);

/* ----- Initialisation ----- */

/*
    @brief Initialise une liste chainée d'ennemis
    @return La liste chainées des ennemis
*/
listEnemy* initListEnemy();

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
 * @brief Supprime les ennemis qui sont marquees comme "a detruire"
 * @param ListeEnnemis La liste des ennemis
 */
void deleteEnemiesToBeDestroyed(listEnemy* ListeEnnemis);

/**
 * @brief Ajoute un ennemi a la liste
 * @param ListeEnnemis La liste des ennemis
 * @param Ennemi L'ennemi a ajouter
 */
void addEnemy(listEnemy* ListeEnnemis, enemy Ennemi);

/**
 * @brief Remplis la liste de nb ennemis
 * @param ListeEnnemis La liste d'ennemis
 * @param nb Le nombre d'ennemis a ajouter
 */
void fillListEnemy(listEnemy* ListeEnnemis, int nb);

#endif //PROJECT_A_LISTENEMY_H
