#include "listBloc.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

bloc* getBloc(listBloc * ListeBlocs){return &(ListeBlocs->Bloc);}
listBloc* getNextB(listBloc * ListeBlocs){return ListeBlocs->next;}

/* ----- Setter ----- */

void setBloc(listBloc *ListeBlocs, bloc Bloc) {
    ListeBlocs->Bloc = Bloc;
}

int setNextB(listBloc * ListeBlocs, listBloc * ListeBlocNext){
    ListeBlocs->next = ListeBlocNext;
    if(ListeBlocs->next == ListeBlocNext){
        return 0;
    }
}

/* ----- Initialisation ----- */

listBloc initListBloc(){
    listBloc* ListeBlocs = malloc(sizeof(listBloc));
    listBloc* CurrentListeBlocs;
    CurrentListeBlocs = ListeBlocs;
    for(int i = 0; i <= SCREEN_WIDTH - BLOC_SIZE; i+= BLOC_SIZE){
        for(int j = 0; j <= SCREEN_HEIGHT - BLOC_SIZE; j+= BLOC_SIZE){
            if((i == 0 || i == SCREEN_WIDTH - BLOC_SIZE) || (j == 0 || j == SCREEN_HEIGHT - BLOC_SIZE)){

                //Attribution du bloc
                setBloc(CurrentListeBlocs, initBloc(i,j,BLOC_TYPE));
                setBlocObstacle(getBloc(CurrentListeBlocs));

                //Initialisation et attribution de la prochaine liste
                setNextB(CurrentListeBlocs, malloc(sizeof(listBloc)));

                CurrentListeBlocs = getNextB(CurrentListeBlocs);
            }else{
                //Attribution du bloc
                setBloc(CurrentListeBlocs, initBloc(i,j,BLOC_TYPE));

                //Initialisation et attribution de la prochaine liste
                setNextB(CurrentListeBlocs, malloc(sizeof(listBloc)));

                CurrentListeBlocs = getNextB(CurrentListeBlocs);
            }
        }
    }
    //Attribution du dernier bloc de la liste
    setBloc(CurrentListeBlocs,initBloc(SCREEN_WIDTH-BLOC_SIZE,SCREEN_HEIGHT-BLOC_SIZE,BLOC_TYPE));
    setBlocObstacle(getBloc(CurrentListeBlocs));
    setNextB(CurrentListeBlocs, NULL);
    return *ListeBlocs;
}

/* ----- Autres ----- */

int isEmptyLB(listBloc* ListeBloc){
    return (ListeBloc == NULL);
}

void freeListBloc(listBloc* ListeBlocs){
    if(!isEmptyLB(ListeBlocs)){
        freeListBloc(getNextB(ListeBlocs));
        free(ListeBlocs);
    }
}