#ifndef GRAPHISMES_H
#define GRAPHISMES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "donnees.h"

/**
 * @brief Ferme la fenetre et quite sdl
 * @param fenetre La fenetre
 * @param renderer Le renderer
 * @param Player Le joueur
 * @param Enemy L'ennemi
 */
void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer, player* Player, enemy* Enemy);

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
 * @brief Charge un sprite
 * @param renderer Le renderer
 * @param file L'emplacement et le nom du fichier au format BMP (ex : dossier1/dossier2/fichier.bmp)
 * @return le sprite
 */
SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* file);

/**
 * @brief initialise les textures
 * @param renderer le renderer
 * @param player le joueur
 * @param enemy l'ennemi
 */
void initTextures(SDL_Renderer* renderer, player* Player, enemy* Enemy);
#endif