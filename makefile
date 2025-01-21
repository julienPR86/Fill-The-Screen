CC = gcc
CFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -Wall -Werror -Wextra
EXEC = main
OBJ = $(TMP)main.o $(TMP)ui.o $(TMP)game.o $(TMP)init.o $(TMP)map.o $(TMP)pause_menu.o $(TMP)player.o $(TMP)game_mode.o $(TMP)end_game.o $(TMP)utils.o $(TMP)buttons_functions.o
TMP = tmp/

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

$(TMP)main.o : main.c
	$(CC) -o $@ -c $<

$(TMP)%.o : scripts/%.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(TMP)*.o