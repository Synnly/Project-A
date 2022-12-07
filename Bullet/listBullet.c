#include "listBullet.h"
#include "../Donnees/constantes.h"

/* ----- Getter ----- */

bullet* getBullet(listBullet * ListeBalles){return &(ListeBalles->Bullet);}
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

    listBullet* ListeBalles = malloc(sizeof(listBullet));
    setNextBullet(ListeBalles, NULL);
    return *ListeBalles;
}

/* ----- Autres ----- */

int isEmptyListBullet(listBullet* ListeBalles){
    return (ListeBalles == NULL);
}

void freeListBullet(listBullet* ListeBalles){

    if(!isEmptyListBullet(ListeBalles)){

        freeListBullet(getNextBullet(ListeBalles));
        free(ListeBalles);
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
    if(!isEmptyListBullet(ListeBalles) && Balle != NULL) {


        //La balle est la première de la liste
        if (isSameBullet(Balle, getBullet(ListeBalles))) {

            //On récupère puis libère la balle
            listBullet *temp = ListeBalles;
            ListeBalles = getNextBullet(ListeBalles);

            freeListBullet(temp);

        } else {

            // On parcourt le reste de la liste pour trouver la bonne balle
            deleteBullet(getNextBullet(ListeBalles), Balle);
        }
    }
}

void moveBullets(listBullet* ListeBalles, double dt){
    if(!isEmptyListBullet(ListeBalles)){

        setBulletPosX(getBullet(ListeBalles), getBulletPosX(getBullet(ListeBalles)) - getBulletXSpeed(getBullet(ListeBalles)) * dt);
        setBulletPosY(getBullet(ListeBalles), getBulletPosY(getBullet(ListeBalles)) - getBulletYSpeed(getBullet(ListeBalles)) * dt);

        moveBullets(getNextBullet(ListeBalles), dt);
    }
}