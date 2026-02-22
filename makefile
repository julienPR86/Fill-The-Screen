CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g -O1 -fsanitize=address -fno-omit-frame-pointer -DDEBUG_LOGS

LIBRARIES = -lSDL3 -lSDL3_ttf -lm

VPATH = sources:sources/UI:sources/animations:data/UI/sources
OBJDIR = objects/

OBJS = 	$(OBJDIR)main.o $(OBJDIR)init.o $(OBJDIR)game.o \
		$(OBJDIR)array.o $(OBJDIR)UI_Element.o $(OBJDIR)color_picker.o $(OBJDIR)panel.o $(OBJDIR)rect.o $(OBJDIR)slider.o $(OBJDIR)slider_cursor.o $(OBJDIR)toggle_group.o $(OBJDIR)toggle.o $(OBJDIR)button.o $(OBJDIR)label.o \
		$(OBJDIR)animation_manager.o $(OBJDIR)exit.o $(OBJDIR)map.o $(OBJDIR)player.o $(OBJDIR)utils.o $(OBJDIR)buttons_functions.o \
		$(OBJDIR)constant_animation.o \
		$(OBJDIR)data_ui_main_menu.o $(OBJDIR)data_ui_mode_selection.o $(OBJDIR)data_ui_game_stats.o $(OBJDIR)data_ui_pause_menu.o $(OBJDIR)data_ui_options.o

NAME = FillTheScreen

all : $(NAME)

debug : CFLAGS += $(DEBUG_FLAGS)
debug : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBRARIES)

$(OBJDIR)%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR) :
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
