#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define true 1
#define false 0

enum Returns
{
    RETURN_ZERO,
    RETURN_FAILURE,
    RETURN_EXIT_FULL_GAME,
    RETURN_TO_MAIN_MENU,
    RETURN_TO_GAMEMODE_CHOICE,
    RETURN_TO_GAME,
    RETURN_RESTART_GAME,
};

enum GameMods
{
    NO_ACTIVE_MODE,
    FILL_MODE,
    DISCOVERY_MODE,
    CONSTRAINT_MODE,
    FREE_MODE,
};

enum SquareStats
{
    COLLISION_SQUARE,
    EMPTY_SQUARE,
    LINE_SQUARE,
    PLAYER_SQUARE,
    FAKE_SQUARE,
};

typedef struct Player
{
    int x;
    int y;
    int moves;
    int remaining_moves;
    int frame_move;
} Player;

typedef struct
{
    int height;
    int width;
    int square_size;
    int **map;
} Map;

typedef struct MainColors
{
    SDL_Color menu_background;
    SDL_Color game_mode_background;
    SDL_Color game_background;
    SDL_Color pause_menu_background;
    SDL_Color end_game_background;
} MainColors;

typedef struct TextColors
{
    SDL_Color background;
    SDL_Color foreground;
} TextColors;

typedef struct Theme
{
    MainColors main_colors;
    TextColors text_colors;
    SDL_Color game_colors[5];
} Theme;

typedef struct Button
{
    int x;
    int y;
    int width;
    int height;
    int outline;
    char *text;
    int clicked;
    SDL_Color bg;
    SDL_Color fg;
    SDL_Color text_bg;
    SDL_Color outline_color;
    int (*command)();
} Button;

extern int WIDTH;
extern int HEIGHT;
extern int FPS;
extern int probability;

extern int CENTER_X;
extern int CENTER_Y; 

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern int mouse_button_pressed;

extern int game_mode;

extern Player *player;
extern Map *map;

extern Theme current;
extern const Theme basic;

extern TTF_Font *font;
extern int font_size;

int init();
int map_init();
int player_init();

int exit_main();

int game();
int game_restart();
int game_quit();

Map *map_creation(Map *map);
Map *map_free(Map *map);
Map *map_reset(Map *map, int value);
Map *map_random(Map *map, int value);
void map_print(Map *map);
void map_display(int offset_x, int offset_y);
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
int map_is_filled(Map *map);

int player_move(int x, int y);
void player_reset(Player *player);

int pause_menu();
int back();
int restart();
int main_menu();

int button_update(Button *button);
void button_render(Button *button);
int button_collision(Button *button, int x, int y);
void display_text(char *text, int x, int y, int w, int h, SDL_Color bg, SDL_Color fg);

int mode_choice();
int fill_mode();
int constraint_mode();
int discovery_mode();
int free_mode();

int end_game();
float fill_percent(Map *map);

void mouse_pressed(SDL_Event event);

#endif