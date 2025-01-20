CC = gcc
CFLAGS = -lmingw32 -lSDL2main -lSDL2 -Wall -Werror -Wextra
EXEC = main
OBJ = $(TMP)main.o $(TMP)button.o $(TMP)game.o $(TMP)init.o $(TMP)map.o $(TMP)pause_menu.o $(TMP)player.o $(TMP)game_mode.o $(TMP)end_game.o
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