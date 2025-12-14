CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBRARIES = -lSDL3 -lSDL3_ttf -lm
EXEC = FillTheScreen
TMP = tmp/

OBJ = 	$(TMP)main.o $(TMP)init.o $(TMP)game.o \
		$(TMP)array.o $(TMP)UI_Element.o $(TMP)color_picker.o $(TMP)panel.o $(TMP)rect.o $(TMP)slider.o $(TMP)slider_cursor.o $(TMP)toggle_group.o $(TMP)toggle.o $(TMP)button.o $(TMP)label.o \
		$(TMP)animation_manager.o $(TMP)exit.o $(TMP)map.o $(TMP)player.o $(TMP)utils.o $(TMP)buttons_functions.o \
		$(TMP)constant_animation.o \
		$(TMP)data_ui_main_menu.o $(TMP)data_ui_mode_selection.o $(TMP)data_ui_game_stats.o $(TMP)data_ui_pause_menu.o $(TMP)data_ui_options.o

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LIBRARIES)

$(TMP)main.o : main.c | $(TMP)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : data/UI/scripts/%.c | $(TMP)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/%.c | $(TMP)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/UI/%.c | $(TMP)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP)%.o : scripts/animations/%.c | $(TMP)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TMP) :
	mkdir -p tmp

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re : fclean all