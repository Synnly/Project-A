#ifndef GRAPHISMES_H
#define GRAPHISMES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../Donnees/donnees.h"

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
void initListBlocTextures(SDL_Renderer* renderer, bloc* ListeBlocs);

/**
 * @brief Initialise la texture de tous les ennemis
 * @param renderer Le renderer
 * @param ListeEnnemis La liste des ennemis
 */
void initListEnemyTextures(SDL_Renderer* renderer, listEnemy* ListeEnnemis);

/**
 * @Brief Initialise la texture des balles si elles sont vides
 * @param renderer Le renderer
 * @param listeBalles La liste des balles
 */
void initListBulletTextures(SDL_Renderer* renderer, listBullet* listeBalles);

/**
 * @brief initialise les textures
 * @param renderer le renderer
 * @param player le joueur
 * @param ListeEnnemis La liste des ennemis
 * @param ListeBlocs la liste des blocs
 */
void initTextures(SDL_Renderer* renderer, player* Player, listEnemy* ListeEnnemis, bloc* ListeBlocs);

/**
 * @brief Affiche le sprite à l'écran
 * @param renderer Le renderer
 * @param x La coordonnée x
 * @param y La coordonnée y
 * @param w La largeur
 * @param h La hauteur
 * @param spriteIndex l'indice du sprite sur la sheet
 * @param texture l'adresse de la texture du sprite
 */
void drawSprite(SDL_Renderer* renderer, int x, int y, int w, int h, int spriteIndex, SDL_Texture* texture);

/**
 * @brief Affiche le sprite de tous les blocs à l'écran
 * @param renderer Le renderer
 * @param ListeBlocs  La liste des blocs
 */
void drawListBlocSprites(SDL_Renderer* renderer, bloc* ListeBlocs);

/**
 * @brief Affiche le sprite de tous les ennemis à l'écran
 * @param renderer Le renderer
 * @param ListeEnnemis  La liste des ennemis
 */
void drawListEnemySprites(SDL_Renderer* renderer, listEnemy* ListeEnnemis);

/**
 * @brief Detruis la texture de toutes les balles marquees comme "a detruire"
 * @param ListeBalles La liste des balles
 */
void destroyToBeDestroyedBulletTextures(listBullet* ListeBalles);

/**
 * @brief Detruis la texture de tous les ennemis marquees comme "a detruire"
 * @param ListeEnnemis La liste des ennemis
 */
void destroyToBeDestroyedEnemyTextures(listEnemy * ListeEnnemis);

/**
 * @brief Affiche le sprite de chaque balle
 * @param renderer Le renderer
 * @param ListeBalle La liste des balles
 */
void drawListBulletSprites(SDL_Renderer* renderer, listBullet * ListeBalle);

/**
 * @brief Detruit le sprite de tous les blocs
 * @param ListeBlocs la liste des blocs
 */
void destroyListBlocTextures(bloc* ListeBlocs);

/**
 * @brief Détruit le sprite de tous les ennemis
 * @param ListeEnnemis la liste des ennemis
 */
void destroyListEnemyTextures(listEnemy* ListeEnnemis);

/**
 * @brief Détruit toutes les textures du jeu
 * @param Player Le joueur
 * @param ListeEnnemis La liste d'ennemis
 * @param ListeBlocs La liste de blocs
 * @param ListeBalles La liste de balles
 */
void destroyAllTextures(player* Player, listEnemy* ListeEnnemis, bloc* ListeBlocs, listBullet * ListeBalles);

/**
 * @brief Ferme la fenetre et quite sdl
 * @param fenetre La fenetre
 * @param renderer Le renderer
 */
void endSDL(SDL_Window* fenetre, SDL_Renderer* renderer);

#endif