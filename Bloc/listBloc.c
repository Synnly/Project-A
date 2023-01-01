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


        //Murs en bord d'ecran
        if((x == 0 || x == SCREEN_WIDTH - BLOC_SIZE) || (y == 0 || y == SCREEN_HEIGHT - BLOC_SIZE)){
            setBlocObstacle(&(ListeBlocs[i]));
        }

        // Nb aleatoire de clusters de blocs
        srand(time(NULL));
        int nbClusters = (rand() % 5)+4;

        for(int i = 0; i < nbClusters; i++){
            setBlocObstacle(&ListeBlocs[rand()% sizeOfListBloc()]);
            setBlocSpread(&ListeBlocs[rand()% sizeOfListBloc()], 100);
        }
    }

    spreadListeBlocs(ListeBlocs, 0);

    //Portes et couloirs pour les ennemis
    for(int i = 0; i<getListeWidth()*getListeHeight(); i++){
        int x = i%getListeWidth();
        int y = i/getListeWidth();

        if((x>=8 && x<=9) || (x>=21 && x<=22) || (y>=8 && y<=9)){
            setBlocNotObstacle(&(ListeBlocs[i]));
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

int sizeOfListBloc(){
    return (SCREEN_HEIGHT/BLOC_SIZE) * (SCREEN_WIDTH/BLOC_SIZE);
}

void spreadObstacles(bloc* ListeBlocs, int current){

    int random = (rand() % 100) + 1;

    // Si le bloc se propage
    if(getBlocSpread(&ListeBlocs[current]) >= random){
        setBlocObstacle(&ListeBlocs[current]);

        // pourcentage de chance de contamination
        for(int pos = current-1; pos <= current+1; pos++){

            if (pos >= getListeWidth()) {
                if (getBlocSpread(&ListeBlocs[pos - getListeWidth()]) == 0) {
                    setBlocSpread(&ListeBlocs[pos - getListeWidth()], getBlocSpread(&ListeBlocs[current]) / 2);
                }
            }

            if(pos!=current && pos<sizeOfListBloc()) {
                if (getBlocSpread(&ListeBlocs[pos]) == 0) {
                    setBlocSpread(&ListeBlocs[pos], getBlocSpread(&ListeBlocs[current]) / 2);
                }
            }

            if (pos < sizeOfListBloc()-getListeWidth()) {
                if (getBlocSpread(&ListeBlocs[pos + getListeWidth()]) == 0) {
                    setBlocSpread(&ListeBlocs[pos + getListeWidth()], getBlocSpread(&ListeBlocs[current]) / 2);
                }
            }
        }

        //Contagion aux 8 blocs autour
        for(int pos = current-1; pos <= current+1; pos++) {

            if (pos >= getListeWidth() && !getBlocIsObstacle(&ListeBlocs[pos - getListeWidth()])) {
                spreadObstacles(ListeBlocs, pos - getListeWidth());
            }

            if(pos!=current && !getBlocIsObstacle(&ListeBlocs[pos])) {
                spreadObstacles(ListeBlocs, pos);
            }

            if (pos < sizeOfListBloc()-getListeWidth()  && !getBlocIsObstacle(&ListeBlocs[pos + getListeWidth()])) {
                spreadObstacles(ListeBlocs, pos + getListeWidth());
            }
        }
    }
}

void spreadListeBlocs(bloc* ListeBlocs, int current){
    while(current < sizeOfListBloc() && getBlocSpread(&ListeBlocs[current])==0){
        current++;
    }

    if(current < sizeOfListBloc()){
        spreadListeBlocs(ListeBlocs, current+1);
        spreadObstacles(ListeBlocs, current);
    }
}