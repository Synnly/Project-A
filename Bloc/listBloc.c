#include <time.h>
#include "listBloc.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

bloc* getBloc(bloc* ListeBlocs, int index){return &(ListeBlocs[index]);}
int getListeWidth(){return (SCREEN_WIDTH / BLOC_SIZE) ;}
int getListeHeight(){return (SCREEN_HEIGHT / BLOC_SIZE) ;}

/* ----- Initialisation ----- */

bloc* initListBloc(){
    bloc* ListeBlocs = malloc((getListeHeight() * getListeWidth()) * sizeof(bloc));
    for(int i = 0; i < getListeWidth() * getListeHeight(); i++){
        int x = (i % getListeWidth())*BLOC_SIZE;
        int y = (i/getListeWidth())*BLOC_SIZE;
        ListeBlocs[i] = initBloc(x,y,BLOC_TYPE);
        if((x == 0 || x == SCREEN_WIDTH - BLOC_SIZE) || (y == 0 || y == SCREEN_HEIGHT - BLOC_SIZE)){
            setBlocObstacle(&(ListeBlocs[i]));
        }

        srand(time(NULL));
        int nbClusters = (rand() % 6)+2;

        // Nb aleatoire de clusters de blocs
        for(int i = 0; i < nbClusters; i++){
            setBlocObstacle(&ListeBlocs[rand()% sizeOfListBloc(ListeBlocs)]);
            setBlocSpread(&ListeBlocs[rand()% sizeOfListBloc(ListeBlocs)], 100);
        }
    }

    spreadListeBlocs(ListeBlocs, 0);

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

void spreadObstacles(bloc* ListeBlocs, int current){

    int random = rand() % 101;
    if(getBlocSpread(&ListeBlocs[current]) >= random){
        setBlocObstacle(&ListeBlocs[current]);

        // pourcentage de change de contamination
        for(int pos = current-1; pos <= current+1; pos++){
            if (pos >= getListeWidth()) {
                setBlocSpread(&ListeBlocs[pos - getListeWidth()], getBlocSpread(&ListeBlocs[current]) / 1.5);
            }

            if(pos!=current && pos<sizeOfListBloc(ListeBlocs)) {
                setBlocSpread(&ListeBlocs[pos], getBlocSpread(&ListeBlocs[current]) / 1.5);
            }

            if (pos < sizeOfListBloc(ListeBlocs)-getListeWidth()) {
                setBlocSpread(&ListeBlocs[pos + getListeWidth()], getBlocSpread(&ListeBlocs[current]) / 1.5);
            }
        }

        //Contagion aux 8 blocs autour
        for(int pos = current-1; pos <= current+1; pos++) {

            if (pos >= getListeWidth()) {
                spreadObstacles(ListeBlocs, pos - getListeWidth());
            }

            if(pos!=current) {
                spreadObstacles(ListeBlocs, pos);
            }

            if (pos < sizeOfListBloc(ListeBlocs)-getListeWidth()) {
                spreadObstacles(ListeBlocs, pos + getListeWidth());
            }
        }
    }
}

void spreadListeBlocs(bloc* ListeBlocs, int current){
    while(current < sizeOfListBloc(ListeBlocs) && getBlocSpread(&ListeBlocs[current])==0){
        current++;
    }

    if(current < sizeOfListBloc(ListeBlocs)){
        spreadListeBlocs(ListeBlocs, current+1);

        // on contagie seulement les blocs qui ont un pourcent non nul
        if(getBlocSpread(&ListeBlocs[current]) > 0) {
            spreadObstacles(ListeBlocs, current);
        }
    }
}