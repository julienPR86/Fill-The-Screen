CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDLFLAGS = -lSDL3 -lSDL3_ttf
EXEC = main
OBJ = $(TMP)main.o $(TMP)game_loop.o $(TMP)color_picker.o $(TMP)panel.o $(TMP)rect.o $(TMP)slider.o $(TMP)slider_cursor.o $(TMP)toggle_group.o $(TMP)toggle.o $(TMP)button.o $(TMP)label.o $(TMP)game.o $(TMP)init.o $(TMP)exit.o $(TMP)map.o $(TMP)player.o $(TMP)utils.o $(TMP)buttons_functions.o $(TMP)data_ui_main_menu.o $(TMP)data_ui_mode_selection.o $(TMP)data_ui_game_stats.o $(TMP)data_ui_pause_menu.o $(TMP)data_ui_options.o
TMP = tmp/

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(SDLFLAGS)

$(TMP)main.o : main.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : data/UI/scripts/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(TMP)*.o *.exe