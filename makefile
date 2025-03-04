CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDLFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
EXEC = main
OBJ = $(TMP)main.o $(TMP)panel.o $(TMP)options.o $(TMP)toogle.o $(TMP)button.o $(TMP)label.o $(TMP)game.o $(TMP)init.o $(TMP)map.o $(TMP)pause_menu.o $(TMP)player.o $(TMP)game_mode.o $(TMP)end_game.o $(TMP)utils.o $(TMP)buttons_functions.o
TMP = tmp/

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(SDLFLAGS)

$(TMP)main.o : main.c
	$(CC) -o $@ -c $< -Wall -Werror

$(TMP)%.o : scripts/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(TMP)*.o