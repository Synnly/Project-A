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

#endif //PROJECT_A_FILES_H
