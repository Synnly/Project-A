#include "listBullet.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

bullet* getBullet(listBullet * ListeBalles){
    if(isEmptyListBullet(ListeBalles)){
        return NULL;
    }
    return &(ListeBalles->Bullet);
}
listBullet* getNextBullet(listBullet * ListeBalles){return ListeBalles->next;}

/* ----- Setter ----- */

void setBullet(listBullet *ListeBalles, bullet Balle) {
    ListeBalles->Bullet = Balle;
}

int setNextBullet(listBullet * ListeBalles, listBullet * ListeBallesNext){
    ListeBalles->next = ListeBallesNext;
    if(ListeBalles->next == ListeBallesNext){
        return 0;
    }
    return -1;
}

/* ----- Initialisation ----- */

listBullet initListBullet(){

    listBullet ListeBalles = {};
    return ListeBalles;
}

/* ----- Autres ----- */

int isEmptyListBullet(listBullet* ListeBalles){
    return (ListeBalles == NULL);
}

void freeListBullet(listBullet* ListeBalles){

    if(!isEmptyListBullet(ListeBalles)){

        freeListBullet(getNextBullet(ListeBalles));
        free(getNextBullet(ListeBalles));
    }
}

void addBullet(listBullet* ListeBalles, bullet* Balle){

    if(!isEmptyListBullet(getNextBullet(ListeBalles))){
        addBullet(getNextBullet(ListeBalles),Balle);

    }else{
        listBullet* ListeBulletNext = malloc(sizeof(listBullet));
        setBullet(ListeBulletNext,*Balle);

        setNextBullet(ListeBulletNext,NULL);
        setNextBullet(ListeBalles,ListeBulletNext);
    }
}

void deleteBullet(listBullet* ListeBalles, bullet* Balle){

    //Si liste non vide ET balle non vide
    if(!isEmptyListBullet(getNextBullet(ListeBalles)) && Balle != NULL) {

        //La balle est la première de la liste
        if (isSameBullet(Balle, getBullet(ListeBalles))) {

            setBullet(ListeBalles, *getBullet(getNextBullet(ListeBalles)));
            setNextBullet(ListeBalles, getNextBullet(getNextBullet(ListeBalles)));

        } else {

            // On parcourt le reste de la liste pour trouver la bonne balle
            deleteBullet(getNextBullet(ListeBalles), Balle);
        }
    }
}

void deleteBulletsToBeDesttroyed(listBullet* ListeBalles){
    if(!isEmptyListBullet(ListeBalles)){
        if(getSpriteToBeDestroyed(getBulletSprite(getBullet(ListeBalles)))){
            deleteBullet(ListeBalles, getBullet(ListeBalles));
        }
        deleteBulletsToBeDesttroyed(getNextBullet(ListeBalles));
    }
}