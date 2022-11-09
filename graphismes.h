#ifndef GRAPHISMES_H
#define GRAPHISMES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * @brief Ferme la fenetre et quite sdl
 * @param fenetre La fenetre
 * @param renderer Le renderer
 */
void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer);

/**
 * @brief Affiche le sprite à l'écran
 * @param renderer Le renderer
 * @param x La coordonnée x
 * @param y La coordonnée y
 * @param w La largeur
 * @param h La hauteur
 * @param file L'emplacement et nom du fichier au format BMP (ex : dossier1/dossier2/fichier.bmp)
 */
void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, const char* file);

#endif