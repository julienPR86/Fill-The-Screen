#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

typedef struct
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

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    int clicked;
    SDL_Color color_on_click;
    SDL_Color color_out;
    SDL_Color color;
    int (*command)();
} Button;

extern int WIDTH;
extern int HEIGHT;
extern int FPS;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern int mouse_button_pressed;

extern Player *player;
extern Map *map;
extern SDL_Color colors[4];

int init();
int map_init();
int player_init();

int exit_game();

int restart();
int start_game();
int quit_game();

Map *map_creation(Map *map);
Map *map_free(Map *map);
Map *map_reset(Map *map, int value);
void map_print(Map *map);
void map_display(int offset_x, int offset_y);
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
int map_is_filled(Map *map);

int player_move(int x, int y);
void player_reset(Player *player);

int pause_menu();
int back();
int _restart();
int main_menu();

int button_update(Button *button);
void button_render(Button *button);
int button_collision(Button *button, int x, int y);


#endif