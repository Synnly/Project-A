#ifndef DONNEES_H
#define DONNEES_H

#define EPSILON 0.0000001
#define FPS 60
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_SIZE 40
#define PLAYER_LIFE 100
#define PLAYER_SPEED 200
#define PISTOL_TYPE 0

#include <SDL2/SDL.h>

/* ---------- Structures de donnees ---------- */

struct bloc_t{    // Structure d'un bloc obstacle
    int posX;
    int posY;
    int type;   //0 bloc classique, 1 bloc 
    int isObstacle;     // 1 si le bloc est un obstacle, 0 sinon
};

typedef struct bloc_t bloc;

struct player_t{      //Structure du joueur
    float posX;
    float posY;
    int life;
    int speed;
    int weaponType;
    int money;
};

typedef struct player_t player;

struct enemy_t{       //Structure d'un ennemi
    int posX;
    int posY;
    int life;
    int speed;
    int type;
};

typedef struct enemy_t enemy;

struct listEnemy_t{
    enemy* Enemy;
    struct listEnemy_t * next;
};

typedef struct listEnemy_t listEnemy;

/* ---------- Getter / Setter ---------- */

/* ----- Bloc ----- */

/* 
    @brief Retourne la coordonne X du bloc
    @param Bloc Le bloc
    @return La coordonnée X
*/ 
int getBlocPosX(bloc * Bloc);

/* 
    @brief Retourne la coordonne Y du bloc
    @param Bloc Le bloc
    @return La coordonnée Y
*/ 
int getBlocPosY(bloc * Bloc);

/* 
    @brief Retourne le type du bloc
    @param Bloc Le bloc
    @return 0 = Mur; 1 = Entrée d'ennemis; 2 = Zone de soin
*/ 
int getBlocType(bloc * Bloc);

/* 
    @brief Retourne si le bloc est obstacle ou non
    @param Bloc Le bloc
    @return 1 si le bloc est un obstacle, 0 sinon
*/ 
int getBlocIsObstacle(bloc * Bloc);

/* 
    @brief Modifie la coordonnée X du bloc
    @param Bloc Le bloc
    @param posX Sa nouvelle coordonnée X
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocPosX(bloc * Bloc, int posX);

/* 
    @brief Modifie la coordonnée Y du bloc
    @param Bloc Le bloc
    @param posY Sa nouvelle coordonnée Y
    @return -1 en cas d'echec, 0 sinon
*/
int setBlocPosY(bloc * Bloc, int posY);

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

/* ----- Enemy ----- */

/*
    @brief Retourne la coordonnée X de l'ennemi
    @param Enemy L'ennemi
    @return Sa coordonnée X
*/
int getEnemyPosX(enemy * Enemy);

/*
    @brief Retourne la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @return Sa coordonnée Y
*/
int getEnemyPosY(enemy * Enemy);

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

/*
    @brief Modifie la coordonnée X de l'ennemi
    @param Enemy L'ennemi
    @param posX Sa coordonnée X
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyPosX(enemy * Enemy, int posX);

/*
    @brief Modifie la coordonnée Y de l'ennemi
    @param Enemy L'ennemi
    @param posY Sa coordonnée Y
    @return -1 en cas d'échec, 0 sinon
*/
int setEnemyPosY(enemy * Enemy, int posY);

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

/* ----- listEnemy ----- */

/**
 * @brief Retourne l'ennemi de la liste chainée
 * @param ListEnemy La liste
 * @return L'ennemi
 */
int getEnemy(listEnemy * ListEnemy);

/**
 * @brief Retourne la liste chainee suivante
 * @param ListEnemy La liste
 * @return La liste suivante
 */
int getNext(listEnemy * ListEnemy);

/**
 * @brief Modifie l'ennemi de la liste chainée
 * @param ListEnemy La liste
 * @param Enemy L'ennemi
 * @return L'ennemi
 */
int setEnemy(listEnemy * ListEnemy, enemy * Enemy);

/**
 * @brief Modifie la liste chainee suivante
 * @param ListEnemy La liste
 * @param ListEnemyNext La liste suivante
 * @return L'ennemi
 */
int setNext(listEnemy * ListEnemy, listEnemy * ListEnemyNext);


/* ---------- Fonctions ---------- */

/*
    @brief Initialise un bloc non-obstacle
    @param posX Sa coordonnée X
    @param posY Sa coordonnée Y
    @param type Son type
    @return Le bloc
*/
bloc initBloc(int posX, int posY, int type);

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
enemy initEnemy(int posX, int posY, int life);

/*
    @brief Initialise une liste chainée de nb ennemis
    @param nb Le nombre d'ennemis
    @return La liste chainées des ennemis
*/
listEnemy initListEnemy(int nb);

/**
 * @brief Donne le nombre de fps
 * @param fps le nombre d'image par seconde
 * @param fpstimer l'image de la dernière seconde
 * @return le nombre de fps
 */
int fpsCounter(int* fps, int* fpstimer);

/**
 * @brief Limite le nombre de fps à 60
 * @param start le tick de départ
 * @param end le tick actuel
 * @return 1 si on depasse les 60 fps et 0 sinon
 */
int fpsCap(Uint32 start, Uint32* end);

/**
 * @brief Gere les entrees clavier, souris et fenetre
 * @param event Les evenements
 * @param is_playing Variable qui traque si le jeu est en cours ou non
 * @param player Le joueur
 * @param dt intervalle de temps
 */
void handleEvents(SDL_Event* event, int* is_playing, player* player, double dt);

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


#endif