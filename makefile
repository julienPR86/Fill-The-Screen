CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g -O1 -fsanitize=address -fno-omit-frame-pointer -DDEBUG_LOGS

LIBRARIES = -lSDL3 -lSDL3_ttf -lm

VPATH = sources:sources/UI:sources/animations:data/UI/sources
SRCS =	main.c \
		init.c \
		game.c \
		exit.c \
		map.c \
		player.c \
		utils.c \
		buttons_functions.c \
		animation_manager.c constant_animation.c \
		data_ui_main_menu.c data_ui_mode_selection.c data_ui_game_stats.c data_ui_pause_menu.c data_ui_options.c \
		array.c UI_Element.c color_picker.c panel.c rect.c slider.c slider_cursor.c toggle_group.c toggle.c button.c label.c

BUILD_DIR ?= build/release/

ifeq (debug, $(filter debug, $(MAKECMDGOALS)))
	BUILD_DIR = build/debug/
	CFLAGS += $(DEBUG_FLAGS)
endif

OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.c=.o))

NAME = FillTheScreen

all : $(NAME)

debug : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBRARIES)

$(BUILD_DIR)%.o : %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) :
	mkdir -p $(BUILD_DIR)

clean :
	rm -rf build

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re debug
