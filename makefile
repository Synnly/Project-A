CC = gcc
CFLAGS = -Wall -W -std=c99 -g
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf -lm
INCLUDES = -I./SDL2_ttf
EXEC = main
SRC = main.c Bloc/bloc.c Bloc/listBloc.c Bullet/bullet.c Bullet/listBullet.c Donnees/donnees.c Donnees/maths.c Enemy/enemy.c Enemy/listEnemy.c Graphismes/graphismes.c Player/player.c Sprite/sprite.c Files/files.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)
main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o */*.o *~
mrproper: clean
	rm -rf $(EXEC)