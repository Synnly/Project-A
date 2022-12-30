#ifndef PROJECT_A_FILES_H
#define PROJECT_A_FILES_H

/**
 * @brief Lis le contenu d'un fichier et retourne le tableau correspondant
 * @param nomFichier Le nom du fichier
 * @return Le tableau representant le fichier
 */
char* readFile(const char* nomFichier);

/**
 * @brief Ecris le contenu du tableau ListeBloc dans le fichier
 * @param nomFichier Le nom du fichier
 * @param ListeBloc Le tableau
 */
void writeFile(const char* nomFichier, bloc* ListeBloc);

/**
 * @brief Ecris le score du joueur dans le fichier Leaderboard
 * @param score Le score du joueur
 */
void writeScore(int* score);

/**
 * @brief Trie dans l'ordre décroissant les valeurs du classement des scores
 * @param length Le nombre de ligne du classement
 */
void sortLeaderboard(int length);

/**
 * @brief Fonction qui trie un tableau de manière décroissante en utilisant la méthode quicksort
 * @param array Le tableau
 * @param start L'indice de la première valeur
 * @param end L'indice de la dernière valeur
 */
void quickSortDesc(int* array, int start, int end);

#endif //PROJECT_A_FILES_H
