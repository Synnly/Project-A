#include "listBullet.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

bullet* getBullet(listBullet * ListeBalles){
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

listBullet* initListBullet(){
    listBullet* ListeBalles = calloc(1, sizeof (listBullet));
    setBullet(ListeBalles, initBullet(0,0,0,0,0));
    setSpriteIsNull(getBulletSprite(getBullet(ListeBalles)), 1);
    setNextBullet(ListeBalles, NULL);
    return ListeBalles;
}

/* ----- Autres ----- */

int isEmptyListBullet(listBullet* ListeBalles){
    return (getSpriteIsNull(getBulletSprite(getBullet(ListeBalles))) && getNextBullet(ListeBalles)==NULL);
}

void freeListBullet(listBullet* ListeBalles){
    if(ListeBalles!=NULL){
        freeListBullet(getNextBullet(ListeBalles));
        free(ListeBalles);
    }
}

void addBullet(listBullet* ListeBalles, bullet Balle){
    if(isEmptyListBullet(ListeBalles)){
        setBullet(ListeBalles, Balle);
        setNextBullet(ListeBalles, initListBullet());
    }
    else{
        addBullet(getNextBullet(ListeBalles), Balle);
    }
}

void deleteBullet(listBullet* ListeBalles, bullet* Balle){
    //Si liste non vide ET balle non vide
    if(!isEmptyListBullet(ListeBalles) && Balle != NULL) {

        //La balle est la première de la liste
        if (isSameBullet(Balle, getBullet(ListeBalles))) {
            listBullet* temp = getNextBullet(ListeBalles);

            setBullet(ListeBalles, *getBullet(getNextBullet(ListeBalles)));
            setNextBullet(ListeBalles, getNextBullet(getNextBullet(ListeBalles)));

            free(temp);

        } else {

            // On parcourt le reste de la liste pour trouver la bonne balle
            deleteBullet(getNextBullet(ListeBalles), Balle);
        }
    }
}

void deleteBulletsToBeDestroyed(listBullet* ListeBalles) {
    if (!isEmptyListBullet(ListeBalles)) {
        if (getSpriteToBeDestroyed(getBulletSprite(getBullet(ListeBalles)))) {
            deleteBullet(ListeBalles, getBullet(ListeBalles));
        }

        if ((getNextBullet(ListeBalles)) != NULL) {
            deleteBulletsToBeDestroyed(getNextBullet(ListeBalles));
        }
    }
}