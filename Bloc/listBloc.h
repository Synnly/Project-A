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
 * @param ListeBlocs
 * @return la taille de la liste
 */
int sizeOfListBloc(bloc* ListeBlocs);

#endif //PROJECT_A_LISTBLOC_H