#ifndef GRAPHISMES_H
#define GRAPHISMES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "donnees.h"

/**
 * @brief Charge un sprite
 * @param renderer Le renderer
 * @param file L'emplacement et le nom du fichier au format BMP (ex : dossier1/dossier2/fichier.bmp)
 * @return le sprite
 */
SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file);

/**
 * @brief Initialise la texture de tous les blocs
 * @param renderer Le renderer
 * @param ListeBlocs La liste des blocs
 */
void initListBlocTextures(SDL_Renderer* renderer, listBloc* ListeBlocs);

/**
 * @brief Initialise la texture de tous les ennemis
 * @param renderer Le renderer
 * @param ListeEnnemis La liste des ennemis
 */
void initListEnemyTextures(SDL_Renderer* renderer, listEnemy* ListeEnnemis);

/**
 * @brief initialise les textures
 * @param renderer le renderer
 * @param player le joueur
 * @param ListeEnnemis La liste des ennemis
 * @param ListeBlocs la liste des blocs
 */
void initTextures(SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, listBloc* ListeBlocs);

/**
 * @brief Affiche le sprite à l'écran
 * @param renderer Le renderer
 * @param x La coordonnée x
 * @param y La coordonnée y
 * @param w La largeur
 * @param h La hauteur
 */
void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Texture* texture);

/**
 * @brief Affiche le sprite de tous les blocs à l'écran
 * @param renderer Le renderer
 * @param ListeBlocs  La liste des blocs
 */
void drawListBlocSprites(SDL_Renderer* renderer, listBloc* ListeBlocs);

/**
 * @brief Detruit le sprite de tous les blocs
 * @param ListeBlocs la liste des blocs
 */
void destroyListBlocTextures(listBloc* ListeBlocs);

/**
 * @brief Affiche le sprite de tous les ennemis à l'écran
 * @param renderer Le renderer
 * @param ListeEnnemis  La liste des ennemis
 */
void drawListEnemySprites(SDL_Renderer* renderer, listEnemy* ListeEnnemis);

/**
 * @brief Détruit le sprite de tous les ennemis
 * @param ListeEnnemis la liste des ennemis
 */
void destroyListEnemyTextures(listEnemy* ListeEnnemis);


/**
 * @brief Ferme la fenetre et quite sdl
 * @param fenetre La fenetre
 * @param renderer Le renderer
 * @param Player Le joueur
 * @param ListeEnnemis La liste des ennemis
 * @param ListeBlocs la liste des blocs
 */
void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, listBloc* ListeBlocs);

#endif