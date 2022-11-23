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
 * @brief Retourne le bloc de la liste chainée
 * @param ListeBlocs La liste
 * @return L'ennemi
 */
bloc* getBloc(listBloc * ListeBlocs);

/**
 * @brief Retourne la liste chainee suivante
 * @param ListeBlocs La liste
 * @return La liste suivante
 */
listBloc* getNextB(listBloc * ListeBlocs);

/* ----- Setter ----- */

/**
 * @brief Modifie le bloc de la liste chainée
 * @param ListeBlocs La liste
 * @param Bloc Le bloc
 */
void setBloc(listBloc * ListeBlocs, bloc Bloc);

/**
 * @brief Modifie la liste chainee suivante
 * @param ListeBlocs La liste
 * @param ListeBlocNext La liste suivante
 * @return -1 en cas d'échec, 0 sinon
 */
int setNextB(listBloc * ListeBlocs, listBloc * ListeBlocNext);

/* ----- Initialisation ----- */

/**
 * @brief Initialise la liste des blocs
 */
listBloc initListBloc();

/* ----- Autres ----- */

/**
 * @brief Indique si la liste est vide
 * @param ListeBlocs La liste
 * @return 1 si la liste est vide, 0 sinon
 */
int isEmptyLB(listBloc* ListeBlocs);

/**
 * @brief Libere la liste
 * @param ListeBlocs La liste de blocs
 */
void freeListBloc(listBloc* ListeBlocs);

#endif //PROJECT_A_LISTBLOC_H