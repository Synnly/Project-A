#include <stdio.h>
#include <stdlib.h>
#include "../Bloc/listBloc.h"
#include "files.h"
#include "../Donnees/maths.h"

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
        for(int i = 0; i<(sizeOfListBloc()); i++){
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

void writeScore(const char* nomFichier, int* score){

    // Ouverture du classement
    FILE* fichier = fopen(nomFichier,"a");
    if(fichier == NULL){
        perror("Erreur d'ouverture du fichier\n");
    }

    //Enregistrement du score du joueur
    fprintf(fichier,"%d%c",*score,'\n');
    fclose(fichier);

    fopen(nomFichier,"r");

    //Compte du nombre de ligne du classement
    char c = fgetc(fichier);
    int cpt = 0;
    while(c != EOF){
        if(c == '\n'){
            cpt ++;
        }
        c = fgetc(fichier);
    }

    //Fermeture du classement
    fclose(fichier);

    //Vérification du nombre de ligne du fichier
    if(cpt > 1){ // Si il y a plus d'une ligne dans le classement alors on le trie
        sortLeaderboard(cpt);
    }


}

void sortLeaderboard(int length){
    //Ouverture des différents fichiers
    FILE* leaderboard = fopen("assets/save/leaderboard","r");
    if(leaderboard == NULL){
        perror("Erreur d'ouverture du paramètre");
    }

    FILE* fichier = fopen("assets/save/leaderboard_temp","w");
    if(fichier == NULL){
        perror("Erreur d'ouverture du fichier");
    }

    //Initialisation du tableau qui va contenir tous les scores
    int tab[length];

    //Remplissage du tableau de score
    for(int i = 0; i < length; i++){
        fscanf(leaderboard, "%d", &tab[i]);
    }

    //Triage du tableau de score
    quickSortDesc(tab,0,length-1);
    for(int j = 0; j < length; j++){
        fprintf(fichier,"%d%c",tab[j],'\n');
    }
    //Fermeture des fichiers
    fclose(fichier);
    fclose(leaderboard);
    remove("assets/save/leaderboard");
    rename("assets/save/leaderboard_temp","assets/save/leaderboard");
}
