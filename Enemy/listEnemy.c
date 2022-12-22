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

void setNextE(listEnemy * ListEnemy, listEnemy * ListEnemyNext){
    ListEnemy->next = ListEnemyNext;
}

/* ----- Initialisation ----- */

listEnemy* initListEnemy(){
    listEnemy* ListeEnnemis = calloc(1, sizeof (listEnemy));
    setEnemy(ListeEnnemis, initEnemy(0,0,-1));
    setSpriteIsNull(getEnemySprite(getEnemy(ListeEnnemis)), 1);
    setNextE(ListeEnnemis, NULL);
    return ListeEnnemis;
}

/* ----- Autre ----- */

int isEmptyLE(listEnemy* ListEnemy){
    return getNextE(ListEnemy) == NULL && getSpriteIsNull(getEnemySprite(getEnemy(ListEnemy)));
}

void freeListEnemy(listEnemy* ListeEnnemis){
    if(ListeEnnemis!=NULL){
        freeListEnemy(getNextE(ListeEnnemis));
        free(ListeEnnemis);
    }
}

void deleteEnemiesToBeDestroyed(listEnemy * ListeEnnemis){
    if(!isEmptyLE(ListeEnnemis)){
        if(getSpriteToBeDestroyed(getEnemySprite(getEnemy(ListeEnnemis)))){
            listEnemy* temp = getNextE(ListeEnnemis);

            setEnemy(ListeEnnemis, *getEnemy(getNextE(ListeEnnemis)));
            setNextE(ListeEnnemis, getNextE(getNextE(ListeEnnemis)));

            free(temp);
        }

        if(!isEmptyLE(ListeEnnemis)){
            deleteEnemiesToBeDestroyed(getNextE(ListeEnnemis));
        }
    }
}

void addEnemy(listEnemy* ListeEnnemis, enemy Ennemi){
    if(isEmptyLE(ListeEnnemis)){
        setEnemy(ListeEnnemis, Ennemi);
        listEnemy* temp = initListEnemy(0);
        setNextE(ListeEnnemis, temp);
    }
    else{
        addEnemy(getNextE(ListeEnnemis), Ennemi);
    }
}

void fillListEnemy(listEnemy* ListeEnnemis, int nb){
    // Premier maillon
    if(nb>0) {

        // Générateur d'aléatoire
        srand(time(0));

        float posX, posY;

        //Premiers maillons
        for (int i = 0; i < nb; i++) {
            //Position aléatoire
            posX = rand() % (SCREEN_WIDTH - ENEMY_SIZE + 1);
            posY = rand() % (SCREEN_HEIGHT - ENEMY_SIZE + 1);

            enemy Ennemi = initEnemy(posX, posY, -1);
            addEnemy(ListeEnnemis, Ennemi);
        }
    }
}