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

int deleteBullet(listBullet* ListeBalles, bullet* Balle){
    if(isEmptyListBullet(ListeBalles) || Balle == NULL){return -1;}

    listBullet* temp;

    //La balle est la première de la liste
    if(isSameBullet(Balle,getBullet(ListeBalles))){
        temp = ListeBalles;
        ListeBalles = getNextBullet(ListeBalles);
        freeListBullet(temp);
        return 1;

    }else{ // On parcourt le reste de la liste pour trouver la bonne balle
        listBullet* currentListBullet;

        while(getNextBullet(currentListBullet)!=NULL){

            //On a trouvé la balle
            if(isSameBullet(Balle,getBullet(getNextBullet(currentListBullet)))){
                temp = getNextBullet(currentListBullet);

                //On supprime la balle
                setNextBullet(currentListBullet,getNextBullet(getNextBullet(currentListBullet)));
                freeListBullet(temp);
                return 1;

            }else{//La balle n'a pas été trouvée on passe à la suivante
                currentListBullet = getNextBullet(currentListBullet);
            }
        }
    }
    return 0;
}

void moveBullets(listBullet* ListeBalles){
    if(!isEmptyListBullet(ListeBalles)){
        //printf("%f xspeed, %f yspeed\n", getBulletXSpeed(getBullet(ListeBalles)), getBulletYSpeed(getBullet(ListeBalles)));
        setBulletPosX(getBullet(ListeBalles), getBulletPosX(getBullet(ListeBalles)) - getBulletXSpeed(getBullet(ListeBalles)));
        setBulletPosY(getBullet(ListeBalles), getBulletPosY(getBullet(ListeBalles)) - getBulletYSpeed(getBullet(ListeBalles)));
        moveBullets(getNextBullet(ListeBalles));
    }
}