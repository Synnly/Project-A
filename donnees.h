#ifndef DONNEES_H
#define DONNEES_H

#define EPSILON 1e-2
#define FPS 60
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BLOC_TYPE 0
#define PLAYER_SIZE 40
#define PLAYER_LIFE 100
#define PLAYER_SPEED 200
#define BULLET_SIZE 10
#define PISTOL_TYPE 0
#define NB_ENNEMIS 5

#include <SDL2/SDL.h>

/* ---------- Structures de donnees ---------- */

struct sprite_t{
    float posX;
    float posY;
    int height;
    int width;
    SDL_Texture* texture;
};

typedef struct sprite_t sprite;

struct bloc_t{    // Structure d'un bloc obstacle
    sprite sprite;
    int type;   //0 bloc classique, 1 bloc 
    int isObstacle;     // 1 si le bloc est un obstacle, 0 sinon
};

typedef struct bloc_t bloc;

struct listBloc_t{
    bloc Bloc;
    struct listBloc_t* next;
};

typedef struct listBloc_t listBloc;

struct player_t{      //Structure du joueur
    sprite sprite;
    int life;
    int speed;
    int weaponType;
    int money;
};

typedef struct player_t player;

struct enemy_t{       //Structure d'un ennemi
    sprite sprite;
    int life;
    int speed;
    int type;
};

typedef struct enemy_t enemy;

struct listEnemy_t{
    enemy Enemy;
    struct listEnemy_t * next;
};

typedef struct listEnemy_t listEnemy;

struct bullet_t{
    sprite sprite;
    int xspeed;
    int yspeed;
    int type;
};

typedef struct bullet_t bullet;

struct listBullet_t{
    bullet Bullet;
    struct listBullet_t* next;
};

typedef struct listBullet_t listBullet;

/* ---------- Getter / Setter ---------- */

/* ----- Sprite ----- */

/**
 * @brief Retourne la coordonnée x du sprite
 * @param Sprite Le sprite
 * @return La coordonnée x;
 */
float getSpritePosX(sprite* Sprite);

/**
 * @brief Retourne la coordonnée y du sprite
 * @param Sprite Le sprite
 * @return La coordonnée y;
 */
float getSpritePosY(sprite* Sprite);

/**
 * @brief Retourne la hauteur du sprite
 * @param Sprite Le sprite
 * @return La hauteur;
 */
int getSpriteHeight(sprite* Sprite);

/**
 * @brief Retourne la largeur du sprite
 * @param Sprite Le sprite
 * @return La largeur;
 */
int getSpriteWidth(sprite* Sprite);

/**
 * @brief Retourne la texture du sprite
 * @param Sprite Le sprite
 * @return La texture
 */
SDL_Texture* getSpriteTexture(sprite* Sprite);

/**
 * @brief Modifie la coordonnée X du joueur
 * @param Sprite Le sprite
 * @param posX Sa coordonnée X
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpritePosX(sprite* Sprite, float posX);

/**
 * @brief Modifie la coordonnée Y du joueur
 * @param Sprite Le sprite
 * @param posY Sa coordonnée Y
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpritePosY(sprite* Sprite, float posY);

/**
 * @brief Modifie la hauteur du sprite
 * @param Sprite Le sprite
 * @param height Sa hauteur
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpriteHeight(sprite* Sprite, int height);

/**
 * @brief Modifie la largeur du sprite
 * @param Sprite Le sprite
 * @param height Sa largeur
 * @return -1 en cas d'échec, 0 sinon
*/
int setSpriteWidth(sprite* Sprite, int width);

/**
 * @brief Met à jour la texture du sprite
 * @param Sprite Le sprite
 * @param texture la texture
 */
void setSpriteTexture(sprite* Sprite, SDL_Texture* texture);

/* ----- Bloc ----- */

/* 
    @brief Retourne la coordonne X du bloc
    @param Bloc Le bloc
    @return La coordonnée X
*/ 
float getBlocPosX(bloc * Bloc);

/* 
    @brief Retourne la coordonne Y du bloc
    @param Bloc Le bloc
    @return La coordonnée Y
*/ 
float getBlocPosY(bloc * Bloc);

/* 
    @brief Retourne le type du bloc
    @param Bloc Le bloc
    @return 0 = Mur, 1 = Entrée d'ennemis, 2 = Zone de soin
*/ 
int getBlocType(bloc * Bloc);

/* 
    @brief Retourne si le bloc est obstacle ou non
    @param Bloc Le bloc
    @return 1 si le bloc est un obstacle, 0 sinon
*/ 
int getBlocIsObstacle(bloc * Bloc);

/**
 * @brief Retourne la texture du bloc
 * @param Bloc le bloc
 */
SDL_Texture* getBlocTexture(bloc* Bloc);

/**
 * @brief Retourne le sprite
 * @param Bloc Le bloc
 * @return Le sprite
 */
sprite* getBlocSprite(bloc* Bloc);

/* 
    @brief Modifie la coordonnée X du bloc
    @param Bloc Le bloc
    @param posX Sa nouvelle coordonnée X
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocPosX(bloc * Bloc, float posX);

/* 
    @brief Modifie la coordonnée Y du bloc
    @param Bloc Le bloc
    @param posY Sa nouvelle coordonnée Y
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocPosY(bloc * Bloc, float posY);

/* 
    @brief Modifie le type du bloc
    @param Bloc Le bloc
    @param type Son nouveau type
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocType(bloc * Bloc, int type);

/* 
    @brief Rend le bloc obstacle
    @param Bloc Le bloc
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocObstacle(bloc * Bloc);

/* 
    @brief Rend le bloc non-obstacle
    @param Bloc Le bloc
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocNotObstacle(bloc * Bloc);

/**
 *@brief Met la texture du bloc
 * @param Bloc Le bloc
 *@param texture La texture
 */
void setBlocTexture(bloc* Bloc, SDL_Texture* texture);

/**
 * @brief Modifie le sprite
 * @param Bloc Le bloc
 * @param Sprite Le sprite
 */
void setBlocSprite(bloc* Bloc, sprite* Sprite);

/* ----- listBloc -----*/

/**
 * @brief Retourne le bloc de la liste chainée
 * @param ListeBlocs La liste
 * @return L'ennemi
 */
bloc* getBloc(listBloc * ListeBlocs);

/**
 * @brief Retourne la liste chainee suivante
 * @param ListeBlocs La liste
 * @return La liste suivante
 */
listBloc* getNextB(listBloc * ListeBlocs);

/**
 * @brief Modifie le bloc de la liste chainée
 * @param ListeBlocs La liste
 * @param Bloc Le bloc
 */
void setBloc(listBloc * ListeBlocs, bloc Bloc);

/**
 * @brief Modifie la liste chainee suivante
 * @param ListeBlocs La liste
 * @param ListeBlocNext La liste suivante
 * @return -1 en cas d'échec, 0 sinon
 */
int setNextB(listBloc * ListeBlocs, listBloc * ListeBlocNext);

/**
 * @brief Indique si la liste est vide
 * @param ListeBlocs La liste
 * @return 1 si la liste est vide, 0 sinon
 */
int isEmptyLB(listBloc* ListeBlocs);

/**
 * @brief Libere la liste
 * @param ListeBlocs La liste de blocs
 */
void freeListBloc(listBloc* ListeBlocs);



/* ----- Player ----- */

/*
    @brief Retourne la coordonnée X du joueur
    @param Player Le joueur
    @return Sa coordonnée X
*/
float getPlayerPosX(player * Player);

/*
    @brief Retourne la coordonnée Y du joueur
    @param Player Le joueur
    @return Sa coordonnée Y
*/
float getPlayerPosY(player * Player);

/*
    @brief Retourne la vie restante du joueur
    @param Player Le joueur
    @return Sa quatitié de vie restante
*/
int getPlayerLife(player * Player);

/*
    @brief Retourne la vitesse du joueur
    @param Player Le joueur
    @return Sa vitesse
*/
int getPlayerSpeed(player * Player);

/*
    @brief Retourne le type de l'arme du joueur
    @param Player Le joueur
    @return Le type de son arme
*/
int getPlayerWeaponType(player * Player);

/*
    @brief Retourne la quatité d'argent du joueur
    @param Player Le joueur
    @return Sa quatité d'argent
*/
int getPlayerMoney(player * Player);

/**
 * @brief Retourne la texture du sprite du joueur
 * @param player le joueur
 * @return la texture
 */
SDL_Texture* getPlayerTexture(player* Player);

/**
 * @brief Retourne le sprite
 * @param Player Le joueur
 * @return Le sprite
 */
sprite* getPlayerSprite(player* PLayer);

/*
    @brief Modifie la coordonnée X du joueur
    @param Player Le joueur
    @param posX Sa coordonnée X
    @return -1 en cas d'échec, 0 sinon
*/
int setPlayerPosX(player * Player, float posX);

/*
    @brief Modifie la coordonnée Y du joueur
    @param Player Le joueur
    @param posY Sa coordonnée Y
    @return -1 en cas d'échec, 0 sinon
*/
int setPlayerPosY(player * Player, float posY);

/*
    @brief Modifie la vie restante du joueur
    @param Player Le joueur
    @param life Sa vie restante
    @return -1 en cas d'échec, 0 sinon
*/
int setPlayerLife(player * Player, int life);

/*
    @brief Modifie la vitesse du joueur
    @param Player Le joueur
    @param speed Sa vitesse
    @return -1 en cas d'échec, 0 sinon
*/
int setPlayerSpeed(player * Player, int speed);

/*
    @brief Modifie le type de l'arme du joueur
    @param Player Le joueur
    @param weaponType Le type de son arme
    @return -1 en cas d'échec, 0 sinon
*/
int setPlayerWeaponType(player * Player, int weaponType);

/*
    @brief Modifie le montant de l'argent du joueur
    @param Player le joueur
    @param money le nouveau montant de l'argent du joueur
    @return -1 en cas d'échec, 0 sinon
*/
int setPlayerMoney(player* Player, int money);

/**
 * @brief Met à jour la texture du sprite du joueur
 * @param player le joueur
 * @param texture la texture
 */
void setPlayerTexture(player* Player, SDL_Texture* texture);

/**
 * @brief Modifie le sprite
 * @param Player Le joueur
 * @param Sprite Le sprite
 */
void setPlayerSprite(player* Player, sprite* Sprite);

/* ----- Enemy ----- */

/*
    @brief Retourne la coordonnée X de l'ennemi
    @param Enemy L'ennemi
    @return Sa coordonnée X
*/
float getEnemyPosX(enemy * Enemy);

/*
    @brief Retourne la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @return Sa coordonnée Y
*/
float getEnemyPosY(enemy * Enemy);

/*
    @brief Retourne la vie restante de l'ennemi
    @param Enemy L'ennemi
    @return Sa quatitié de vie restante
*/
int getEnemyLife(enemy * Enemy);

/*
    @brief Retourne la vitesse de l'ennemi
    @param Enemy L'ennemi
    @return Sa vitesse
*/
int getEnemySpeed(enemy * Enemy);

/*
    @brief Retourne le type de l'ennemi
    @param Enemy L'ennemi
    @return Son type
*/
int getEnemyType(enemy * Enemy);

/**
 * @brief Retourne la texture du sprite de l'ennemi
 * @param Enemy l'ennemi
 * @return la texture
 */
SDL_Texture* getEnemyTexture(enemy* Enemy);

/**
 * @brief Retourne le sprite
 * @param Enemy L'ennemi
 * @return Le sprite
 */
sprite* getEnemySprite(enemy* Enemy);


/*
    @brief Modifie la coordonnée X de l'ennemi
    @param Enemy L'ennemi
    @param posX Sa coordonnée X
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyPosX(enemy * Enemy, float posX);

/*
    @brief Modifie la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @param posY Sa coordonnée Y
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyPosY(enemy * Enemy, float posY);

/*
    @brief Modifie la vie restante de l'ennemi
    @param Enemy L'ennemi
    @param life Sa vie restante
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyLife(enemy * Enemy, int life);

/*
    @brief Modifie la vitesse de l'ennemi
    @param Enemy L'ennemi
    @param speed Sa vitesse
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemySpeed(enemy * Enemy, int speed);

/*
    @brief Modifie le type de l'ennemi
    @param Enemy L'ennemi
    @param type Son type
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyType(enemy * Enemy, int type);

/**
 * @brief Met à jour la texture du sprite de l'ennemi
 * @param Enemy l'ennemi
 * @param texture la texture
 */
void setEnemyTexture(enemy* Enemy, SDL_Texture* texture);

/**
 * @brief Modifie le sprite
 * @param Enemy L'ennemi
 * @param Sprite Le sprite
 * @return Le sprite
 */
void setEnemySprite(enemy* Enemy, sprite* Sprite);

/* ----- listEnemy ----- */

/**
 * @brief Retourne l'ennemi de la liste chainée
 * @param ListEnemy La liste
 * @return L'ennemi
 */
enemy* getEnemy(listEnemy * ListEnemy);

/**
 * @brief Retourne la liste chainee suivante
 * @param ListEnemy La liste
 * @return La liste suivante
 */
listEnemy* getNextE(listEnemy * ListEnemy);

/**
 * @brief Modifie l'ennemi de la liste chainée
 * @param ListEnemy La liste
 * @param Enemy L'ennemi
 */
void setEnemy(listEnemy * ListEnemy, enemy Enemy);

/**
 * @brief Modifie la liste chainee suivante
 * @param ListEnemy La liste
 * @param ListEnemyNext La liste suivante
 * @return -1 en cas d'échec, 0 sinon
 */
int setNextE(listEnemy * ListEnemy, listEnemy * ListEnemyNext);

/**
 * @brief Indique si la liste est vide
 * @param ListEnnemy La liste
 * @return 1 si la liste est vide, 0 sinon
 */
int isEmptyLE(listEnemy* ListEnnemy);

/**
 * @brief Libere la liste
 * @param ListeEnnemis La liste d'ennemis
 */
void freeListEnemy(listEnemy* ListeEnnemis);

/* ----- bullet ----- */

/**
 * @brief donne le sprite de la balle
 * @param Balle la balle
 */
sprite* getBulletSprite(bullet* Balle);

/**
 * @brief donne la coordonnée en x de la balle
 * @param Balle la balle
 */
float getBulletPosX(bullet* Balle);

/**
 * @brief donne la coordonnée en y de la balle
 * @param Balle la balle
 */
float getBulletPosY(bullet* Balle);

/**
 * @brief donne la hauteur du sprite de la balle
 * @param Balle la balle
 */
int getBulletHeight(bullet* Balle);

/**
 * @brief donne la largeur du sprite de la balle
 * @param Balle la balle
 */
int getBulletWidth(bullet* Balle);

/**
 * @brief donne la vitesse en x de la balle
 * @param Balle la balle
 */
int getBulletXSpeed(bullet* Balle);

/**
 * @brief donne la vitesse en y de la balle
 * @param Balle la balle
 */
int getBulletYSpeed(bullet* Balle);

/**
 * @brief donne le type de la balle
 * @param Balle la balle
 */
int getBulletType(bullet* Balle);

/**
 * @brief donne la texture du sprite de la balle
 * @param Balle la balle
 */
SDL_Texture* getBulletTexture(bullet* Balle);

/**
 * @brief met à jour le sprite de la balle
 * @param Sprite le sprite
 * @param Balle la balle
 */
void setBulletSprite(sprite* Sprite, bullet* Balle);

/**
 * @brief Met à jour la position x de la balle
 * @param Balle la balle
 * @param posX la position en x
 * @return 1 si réussite 0 sinon
 */
int setBulletPosX(bullet* Balle, float posX);

/**
 * @brief Met à jour la coordonnée y de la balle
 * @param Balle la balle
 * @param posY la position en y
 * @return 1 si réussite 0 sinon
 */
int setBulletPosY(bullet* Balle, float posY);

/**
 * @brief Met à jour la vitesse en x de la balle
 * @param Balle la balle
 * @param xSpeed la vitesse en x
 * @return 1 si réussite 0 sinon
 */
int setBulletXSpeed(bullet* Balle, int xSpeed);

/**
 * @brief Met à jour la vitesse y de la balle
 * @param Balle la balle
 * @param ySpeed la vitesse en y
 * @return 1 si réussite 0 sinon
 */
int setBulletYSpeed(bullet* Balle, int ySpeed);

/**
 * @brief Met à jour le type de la balle
 * @param Balle la balle
 * @param type le type
 * @return 1 si réussite 0 sinon
 */
int setBulletType(bullet* Balle, int type);

/**
 * @brief Met à jour la texture de la balle
 * @param Balle la balle 
 * @param texture la texture
 */
void setBulletTexture(bullet* Balle, SDL_Texture* texture);

/* ------ listBullet -------*/

/**
 * @brief Renvoie la balle
 * @param ListeBalles la liste de balles
 * @return la balle
 */
bullet* getBullet(listBullet * ListeBalles);

/**
 * @brief Renvoie la liste de balles suivante
 * 
 * @param ListeBalles la liste de balles
 * @return la prochaine liste de balles
 */
listBullet* getNextBullet(listBullet * ListeBalles);

/**
 * @brief Met à jour la balle de la liste
 * @param ListeBalles la liste de balles 
 * @param Balle la balle
 */
void setBullet(listBullet *ListeBalles, bullet Balle);

/**
 * @brief 
 * @param ListeBalles 
 * @param ListeBallesNext 
 * @return int 
 */
int setNextBullet(listBullet * ListeBalles, listBullet * ListeBallesNext);

/**
 * @brief Retourne l'etat de la liste de balles
 * @param ListeBalles la liste de balles
 * @return 1 si vide 0 sinon
 */
int isEmptyListBullet(listBullet* ListeBalles);

/**
 * @brief Libère la mémoire reservée par la liste de balles
 * @param ListeBalles la liste de balles
 */
void freeListBullet(listBullet* ListeBalles);

/* ---------- Fonctions ---------- */

/* ----- Initialisation ----- */

/**
 * @brief Initialise un sprite
 * @param posX Sa position X
 * @param posY Sa position Y
 * @param height Sa hauteur
 * @param width Sa largeur
 * @return
 */
sprite initSprite(float posX, float posY, int height, int width);

/*
    @brief Initialise un bloc non-obstacle
    @param posX Sa coordonnée X
    @param posY Sa coordonnée Y
    @param type Son type
    @return Le bloc
*/
bloc initBloc(int posX, int posY, int type);

/**
 * @brief Initialise la liste des blocs
 */
 listBloc initListBloc();

/*
    @brief Initialise un joueur
    @return Le joueur
*/
player initPLayer();

/*
    @brief Initialise un ennemi
    @param posX Sa coordonnée X
    @param posY Sa coordonnée Y
    @param type Son type
*/
enemy initEnemy(float posX, float posY, int type);

/*
    @brief Initialise une liste chainée de nb ennemis
    @param nb Le nombre d'ennemis
    @return La liste chainées des ennemis
*/
listEnemy initListEnemy(int nb);

/* ----- FPS ----- */

/**
 * @brief Donne le nombre de fps
 * @param fps le nombre d'image par seconde
 * @param fpstimer l'image de la dernière seconde
 */
void fpsCounter(int* fps, int* fpstimer);

/**
 * @brief Limite le nombre de fps à 60
 * @param start le tick de départ
 * @param end le tick actuel
 * @return 1 si on depasse les 60 fps et 0 sinon
 */
int fpsCap(Uint32 start, Uint32* end);

/* ----- Autres ----- */

/**
 * @brief Gere les entrees clavier, souris et fenetre
 * @param event Les evenements
 * @param is_playing Variable qui traque si le jeu est en cours ou non
 * @param player Le joueur
 * @param ListeBlocs la liste des blocs
 * @param dt intervalle de temps
 */
void handleEvents(SDL_Event* event, int* is_playing, player* player, listBloc* ListeBlocs, double dt);

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
 * @brief Déplace l'ennemi vers le joueur
 * @param enemy L'ennemi
 * @param player Le joueur
 * @param dt L'intervalle de temps
 */
void moveToPlayer(enemy* enemy, player* player, double dt);

/**
 * @brief Deplace tous les ennemis vers le joueur
 * @param ListeEnnemis La liste des ennemis
 * @param player Le joueur
 * @param dt L'intervalle de temps
 */
void moveListEnemyToPlayer(listEnemy* ListeEnnemis, player* player, double dt);

/**
 * @brief Indique si deux sprites sont en collision
 * @param Sprite1 Le premier sprite
 * @param Sprite2 LE deuxième sprite
 * @return 1 si ils sont en collision, 0 sinon
 */
int inCollision(sprite* Sprite1, sprite* Sprite2);

/**
 * @brief Indique si f1 et f2 sont égaux à epsilon pès
 * @param f1 Le premier réel
 * @param f2 Le deuxième réel
 * @return 1 si ils sont égaux, 0 sinon
 */
int floatEquals(float f1, float f2);

/**
 * @brief Indique si un sprite et un bloc obstacle sont en collision
 * @param Sprite Le sprite
 * @param ListeBlocs la liste des blocs
 * @return 1 si collision 0 sinon
 */
int spriteCollidesWalls(sprite* Sprite, listBloc* ListeBlocs);

/**
 * @brief Ajoute une balle dans la liste de balles
 * @param ListeBalles La liste de balles
 * @param Balle la balle à ajouter
 */
void addBullet(listBullet* ListeBalles, bullet* Balle);

/**
 * @brief Compare deux balles
 * @param Balle1 la première balle
 * @param Balle2 la deuxième balle
 * @return 1 si les deux balles sont les mêmes 0 sinon
 */
int isSameBullet(bullet* Balle1, bullet* Balle2);

/**
 * @brief Supprime une balle de la liste de balles
 * @param ListeBalles la liste de balles
 * @param Balle la balle à supprimer
 * @return 1 si la balle a été supprimée, 0 si la balle n'est pas dans la liste, -1 si la liste ou la balle est vide
 */
int deleteBullet(listBullet* ListeBalles, bullet* Balle);

#endif