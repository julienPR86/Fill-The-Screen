#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

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
} Player;

typedef struct
{
    int height;
    int width;
    int square_size;
    int **map;
} Map;

typedef struct Theme
{
    SDL_Color menu_background;
    SDL_Color game_mode_background;
    SDL_Color game_background;
    SDL_Color colors[5];
} Theme;

typedef struct Button
{
    int x;
    int y;
    int width;
    int height;
    int clicked;
    SDL_Surface *img_unpressed;
    SDL_Surface *img_pressed;
    SDL_Surface *img;
    int (*command)();
} Button;

extern int WIDTH;
extern int HEIGHT;
extern int FPS;
extern int probability;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern int mouse_button_pressed;

extern Player *player;
extern Map *map;

extern Theme current;
extern const Theme basic;

int init();
int map_init(int mode);
int player_init();

int exit_main();

int restart(int mode);
int game(int mode);
int quit_game();

Map *map_creation(Map *map);
Map *map_free(Map *map);
Map *map_reset(Map *map, int value);
Map *map_random(Map *map, int value);
void map_print(Map *map);
void map_display(int offset_x, int offset_y);
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
int map_is_filled(Map *map);

int player_move(int x, int y, int mode);
void player_reset(Player *player);

int pause_menu();
int back();
int _restart();
int main_menu();

int button_update(Button *button);
void button_render(Button *button);
int button_collision(Button *button, int x, int y);

int mode_choice();
int fill_mode();
int constraint_mode();
int discovery_mode();
int free_mode();

int end_game();
float fill_percent(Map *map);

#endif