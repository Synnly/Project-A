#include "listBloc.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

bloc* getBloc(bloc* ListeBlocs, int index){return &(ListeBlocs[index]);}

/* ----- Initialisation ----- */

bloc* initListBloc(){
    bloc* ListeBlocs = malloc(((SCREEN_HEIGHT/BLOC_SIZE) * (SCREEN_WIDTH/BLOC_SIZE)) * sizeof(bloc));
    for(int i = 0; i < (SCREEN_WIDTH / BLOC_SIZE) * (SCREEN_HEIGHT / BLOC_SIZE); i++){
        int x = (i / (SCREEN_HEIGHT/BLOC_SIZE))*BLOC_SIZE;
        int y = (i%(SCREEN_HEIGHT/BLOC_SIZE))*BLOC_SIZE;
        ListeBlocs[i] = initBloc(x,y,BLOC_TYPE);
        if((x == 0 || x == SCREEN_WIDTH - BLOC_SIZE) || (y == 0 || y == SCREEN_HEIGHT - BLOC_SIZE)){
            setBlocObstacle(&(ListeBlocs[i]));
        }
    }
    return ListeBlocs;
}

/* ----- Autres ----- */

int isEmptyLB(bloc* ListeBloc){
    return (ListeBloc == NULL);
}

void freeListBloc(bloc* ListeBlocs){
    free(ListeBlocs);
}

int sizeOfListBloc(bloc* ListeBlocs){
   return (SCREEN_HEIGHT/BLOC_SIZE) * (SCREEN_WIDTH/BLOC_SIZE);
}