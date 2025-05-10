CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDLFLAGS = -lSDL3 -lSDL3_ttf
EXEC = main
OBJ = $(TMP)main.o $(TMP)panel.o $(TMP)rect.o $(TMP)slider.o $(TMP)slider_cursor.o $(TMP)options.o $(TMP)toogle_group.o $(TMP)toogle.o $(TMP)button.o $(TMP)label.o $(TMP)game.o $(TMP)init.o $(TMP)map.o $(TMP)pause_menu.o $(TMP)player.o $(TMP)game_mode.o $(TMP)game_stats.o $(TMP)utils.o $(TMP)buttons_functions.o
TMP = tmp/

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(SDLFLAGS)

$(TMP)main.o : main.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(TMP)*.o *.exe