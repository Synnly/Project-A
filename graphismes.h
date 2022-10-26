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

#endif