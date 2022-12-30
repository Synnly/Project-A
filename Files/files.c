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
                fprintf(fichier, "%d ", (getBlocSpread(&ListeBloc[i])/10)+1);
            }
        }
        fclose(fichier);
    }
}

void writeScore(int* score){
    // Ouverture du classement
    FILE* fichier = fopen("../assets/maps/leaderboard.txt","a+");
    if(fichier == NULL){
        perror("Erreur d'ouverture du fichier\n");
    }

    //Enregistrement du score du joueur
    fprintf(fichier,"%d %c",*score,'\n');

    //Compte du nombre de ligne du classement
    char c = fgetc(fichier);
    int cpt = 0;
    while(c != feof(fichier)){
        if(c == '\n'){
            cpt ++;
        }
        c = fgetc(fichier);
    }

    //Vérification du nombre de ligne du fichier
    if(cpt > 1){ // Si il y a plus d'une ligne dans le classement alors on le trie
        sortLeaderboard(cpt);
    }

    //Fermeture du classement
    fclose(fichier);
}

void sortLeaderboard(int length){
    //Ouverture des différents fichiers
    FILE* leaderboard = fopen("../assets/maps/leaderboard.txt","r");
    if(leaderboard == NULL){
        perror("Erreur d'ouverture du paramètre");
    }
    FILE* fichier = fopen("../assets/maps/leaderboard_temp.txt","w");
    if(fichier == NULL){
        perror("Erreur d'ouverture du fichier");
    }

    char c = fgetc(leaderboard);
    int* tab = malloc(length * sizeof(int));
    int i = 0;
    while(i < length){
        if(c == '\n'){
            i++;
        }else{
            tab[i] = (int)c;
        }
        c = fgetc(leaderboard);
    }
    quickSortDesc(tab,0,length-1);
    for(int j = 0; j < length; j++){
        fprintf(fichier,"%d %c",tab[0],'\n');
    }
    fclose(fichier);
    fclose(leaderboard);
    remove("../assets/maps/leaderboard.txt");
    rename("../assets/maps/leaderboard_temp.txt","../assets/maps/leaderboard.txt");


}

void quickSortDesc(int *array, int start, int end) {
    int i = start;
    int j = end;
    int pivot = array[(start + end) / 2];
    while (i <= j) {
        while (array[i] > pivot) {
            i++;
        }
        while (array[j] < pivot) {
            j--;
        }
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (start < j) {
        quickSortDesc(array, start, j);
    }
    if (i < end) {
        quickSortDesc(array, i, end);
    }
}
