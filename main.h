#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define true 1
#define false 0

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

// Enums ---------------------------------

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

enum SquareStates
{
    COLLISION_SQUARE,
    EMPTY_SQUARE,
    LINE_SQUARE,
    PLAYER_SQUARE,
    FAKE_SQUARE,
};

enum ButtonStates
{
    NORMAL,
    CLICKED,
    HOVERED,
};

// Structs ---------------------------------

typedef struct Player
{
    double x;
    double y;
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

typedef struct Theme
{
    MainColors main_colors;
    SDL_Color game_colors[5];
} Theme;


typedef struct Label
{
    int x;
    int y;
    int w;
    int h;
    float scale;
    char *text;
    TTF_Font *font;
    SDL_Color bg;
    SDL_Color text_color;
    SDL_Surface *surface;
    SDL_Texture *texture;
    int update;
} Label;

typedef struct Button
{
    int x;
    int y;
    int width;
    int height;
    int outline;
    int padx;
    int pady;
    int state;
    Label label;
    SDL_Color bg;
    SDL_Color fg;
    SDL_Color hover;
    SDL_Color outline_color;
    int (*command)();
} Button;

// Variables ---------------------------------

extern int WIDTH;
extern int HEIGHT;
extern int FPS;
extern int MAX_FPS;
extern double delta_time;
extern int game_speed;
extern int probability;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern int mouse_button_pressed;

extern int game_mode;

extern Player *player;
extern Map *map;

extern Theme current;
extern const Theme basic;

extern TTF_Font *roboto_light;
extern TTF_Font *roboto_regular;
extern int font_size;


extern char *FPS_text;
extern Label FPS_label;

// Functions ---------------------------------

int init();
int map_init();
int player_init();

int exit_game();
void exit_full_game();

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
int map_get_squares_number(Map *map, int type);
int map_is_filled(Map *map);

int player_move(int x, int y);
void player_reset(Player *player);

int pause_menu();
int back();
int restart();
int main_menu();

Button *button_init(Button *button);
int button_update(Button *button);
void button_render(Button *button);

Label *label_init(Label *label);
void label_update(Label *label);
void label_render(Label *label);
void label_free(Label *label);
void label_list_free(Label *labels[], int size);

int mode_choice();
int fill_mode();
int constraint_mode();
int discovery_mode();
int free_mode();

int end_game();
float fill_percent(Map *map);

int get_fps();
void cap_fps(Uint64 start_time);
void mouse_pressed(SDL_Event event);
int button_collision(Button *button, int x, int y);
int get_button_height(Button *button);
int get_button_width(Button *button);

#endif