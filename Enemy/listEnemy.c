#include "listEnemy.h"
#include "../Donnees/constantes.h"
#include <time.h>

/* ----- Getter ----- */

enemy* getEnemy(listEnemy * ListEnemy){return &(ListEnemy->Enemy);}
listEnemy* getNextE(listEnemy * ListEnemy){return ListEnemy->next;}

/* ----- Setter ----- */

void setEnemy(listEnemy *ListEnemy, enemy Enemy) {
    ListEnemy->Enemy = Enemy;
}

int setNextE(listEnemy * ListEnemy, listEnemy * ListEnemyNext){
    ListEnemy->next = ListEnemyNext;
    if(ListEnemy->next == ListEnemyNext){
        return 0;
    }
    return -1;
}

/* ----- Initialisation ----- */

listEnemy initListEnemy(int nb){
    listEnemy* ListeEnnemis;

    // Premier maillon
    if(nb>0) {

        // Générateur d'aléatoire
        srand(time(0));

        float posX, posY;
        listEnemy* CurrentListEnnemis;
        ListeEnnemis = malloc(sizeof(listEnemy));
        CurrentListEnnemis = ListeEnnemis;

        //Premiers maillons
        for(int i = 0; i<nb-1; i++){

            //Position aléatoire
            posX = rand() % (SCREEN_WIDTH - ENEMY_SIZE + 1);
            posY = rand() % (SCREEN_HEIGHT - ENEMY_SIZE + 1);

            //Initialisation et attribution de l'ennemi
            setEnemy(CurrentListEnnemis, initEnemy(posX, posY, 1));

            //Initialisation et attribution du prochain maillon
            setNextE(CurrentListEnnemis, malloc(sizeof(listEnemy)));

            CurrentListEnnemis = getNextE(CurrentListEnnemis);
        }

        //Position aléatoire
        posX = rand() % (SCREEN_WIDTH - ENEMY_SIZE + 1);
        posY = rand() % (SCREEN_HEIGHT - ENEMY_SIZE + 1);

        //Initialisation et attribution de l'ennemi
        setEnemy(CurrentListEnnemis, initEnemy(posX, posY, 1));

        setNextE(CurrentListEnnemis, NULL);

    }
    return *ListeEnnemis;
}

/* ----- Autre ----- */

int isEmptyLE(listEnemy* ListEnnemy){
    return (ListEnnemy == NULL);
}

void freeListEnemy(listEnemy* ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        freeListEnemy(getNextE(ListeEnnemis));
        free(ListeEnnemis);
    }
}