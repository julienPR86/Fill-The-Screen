CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDL_FLAGS = -lSDL3 -lSDL3_ttf
EXEC = build/main
TMP = tmp/

OBJ = 	$(TMP)main.o $(TMP)init.o $(TMP)game_loop.o \
		$(TMP)UI_Element.o $(TMP)color_picker.o $(TMP)panel.o $(TMP)rect.o $(TMP)slider.o $(TMP)slider_cursor.o $(TMP)toggle_group.o $(TMP)toggle.o $(TMP)button.o $(TMP)label.o \
		$(TMP)game.o $(TMP)exit.o $(TMP)map.o $(TMP)player.o $(TMP)utils.o $(TMP)buttons_functions.o\
		$(TMP)data_ui_main_menu.o $(TMP)data_ui_mode_selection.o $(TMP)data_ui_game_stats.o $(TMP)data_ui_pause_menu.o $(TMP)data_ui_options.o

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(SDL_FLAGS)

$(TMP)main.o : main.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : data/UI/scripts/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/UI/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(TMP)*.o *.exe build/*.exe