#ifndef FONTS__H
#define FONTS__H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 * @brief Initialise le module ttf
 */
void init_ttf();

/**
 * @brief Charge une police d'écriture
 * @param path Le chemin d'accès à la police
 * @param font_size La taille de la police
 * @return La police chargée
 */
TTF_Font * load_font(const char* path, int font_size);

/**
 * @brief Applique du texte sur le renderer
 * @param renderer Le renderer
 * @param x La position en x du texte
 * @param y La position en y du texte
 * @param w La largeur du texte
 * @param h La hauteur du texte
 * @param text Le texte à afficher
 * @param font La police a utiliser
 */
void apply_text(SDL_Renderer *renderer,int x, int y, int w, int h, const char *text, TTF_Font *font);

/**
 * @brief Nettoie la police
 * @param font La police
 */
void clean_font(TTF_Font * font);

#endif
