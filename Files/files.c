#include <stdio.h>
#include <stdlib.h>
#include "../Bloc/listBloc.h"
#include "files.h"

char* readFile(const char* nomFichier){
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur d'overture du fichier\n");
    }
    else {
        char caractere;
        char* tabFichier = malloc(sizeof(char) * getListeHeight() * getListeWidth());

        int i = 0;
        while (i<getListeWidth()*getListeHeight()){
            caractere = fgetc(fichier);

            // Fin de ligne ou espace
            while(caractere == '\n' || caractere == ' '){
                caractere = fgetc(fichier);
            }

            tabFichier[i] = caractere;

            i++;
        }
        fclose(fichier);
        return tabFichier;
    }
}

void writeFile(const char* nomFichier, bloc* ListeBloc){
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur d'overture du fichier\n");
    }
    else {
        for(int i = 0; i<(sizeOfListBloc(ListeBloc)); i++){
            // Arret de ligne
            if(i%getListeWidth() == 0 && i != 0){
                fprintf(fichier, "%c", '\n');
            }

            // Murs
            if((i%getListeWidth() == 0 || i%getListeWidth() == getListeWidth()-1 || i/getListeWidth() == 0 || i/getListeWidth() == getListeHeight()-1)  && getBlocIsObstacle(&ListeBloc[i])){
                fprintf(fichier, "%s", "m ");
            }

                // Sol
            else if(!getBlocIsObstacle(&ListeBloc[i])){
                fprintf(fichier, "%s", "0 ");
            }

                // Clusters
            else if(getBlocSpread(&ListeBloc[i]) >= 90){
                fprintf(fichier, "%s", "c ");
            }

                // Blocs classiques
            else {
                printf("%d\n", getBlocSpread(&ListeBloc[i]));
                fprintf(fichier, "%d ", (getBlocSpread(&ListeBloc[i])/10)+1);
            }
        }
        fclose(fichier);
    }
}