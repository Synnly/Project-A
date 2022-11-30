#ifndef PROJECT_A_MATHS_H
#define PROJECT_A_MATHS_H

/**
 * @brief Renvoie la valeur max entre deux valeurs
 * @param val1 la première valeur
 * @param val2 la deuxième valeur
 * @return le max entre les deux valeurs
 */
float max(float val1, float val2);

/**
 * @brief Renvoie la valeur min entre deux valeurs
 * @param val1 la première valeur
 * @param val2 la deuxième valeur
 * @return le min entre les deux valeurs
 */
float min(float val1, float val2);

/**
 * @brief Retourne la longueur de l'adjacent d'un triangle rectangle isocèle d'hypoténuse c
 * @param c L'hypoténuse
 * @return La longueur de l'adjacent
 */
float pythagore(float c);

/**
 * @brief Indique si f1 et f2 sont égaux à epsilon pès
 * @param f1 Le premier réel
 * @param f2 Le deuxième réel
 * @return 1 si ils sont égaux, 0 sinon
 */
int floatEquals(float f1, float f2);


#endif //PROJECT_A_MATHS_H
