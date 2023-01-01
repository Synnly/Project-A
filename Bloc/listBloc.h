#ifndef PROJECT_A_LISTBLOC_H
#define PROJECT_A_LISTBLOC_H

#include "bloc.h"
typedef struct bloc_t bloc;

struct listBloc_t{
    bloc Bloc;
    struct listBloc_t* next;
};

typedef struct listBloc_t listBloc;

/* ----- Getter ----- */

/**
 * @brief Retourne le bloc à l'indice index de la liste
 * @param ListeBlocs La liste
 * @param index L'index
 * @return Le bloc de l'indice index de la liste
 */
bloc* getBloc(bloc* ListeBlocs, int index);

/**
 * @Brief Retourne le nombre de blocs en largeur sur l'ecran
 * @return Le nombre de blocs en largeur sur l'ecran
 */
int getListeWidth();

/**
 * @Brief Retourne le nombre de blocs en hauteur sur l'ecran
 * @return Le nombre de blocs en hauteur sur l'ecran
 */
int getListeHeight();

/* ----- Initialisation ----- */

/**
 * @brief Initialise la liste des blocs
 */
bloc* initListBloc();

/* ----- Autres ----- */

/**
 * @brief Indique si la liste est vide
 * @param ListeBlocs La liste
 * @return 1 si la liste est vide, 0 sinon
 */
int isEmptyLB(bloc* ListeBlocs);

/**
 * @brief Libere la liste
 * @param ListeBlocs La liste de blocs
 */
void freeListBloc(bloc* ListeBlocs);
/**
 * @brief Donne la taille de la liste
 * @return la taille de la liste
 */
int sizeOfListBloc();

/**
 * @brief Transforme le bloc en obstacle avec assez de chance et transmets la contagion a ses plus proches voisins
 * @param ListeBlocs La liste des blocs
 * @param current L'indice du bloc actuel
 */
void spreadObstacles(bloc* ListeBlocs, int current);

/**
 * @brief Demarre la contagion de blocs a partir des clusters
 * @param ListeBlocs La liste des blocs
 * @param current L'indice bloc actuel
 */
void spreadListeBlocs(bloc* ListeBlocs, int current);

#endif //PROJECT_A_LISTBLOC_H