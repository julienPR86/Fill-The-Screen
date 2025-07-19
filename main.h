#ifndef _MAIN_H_
#define _MAIN_H_

//C libraries includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>

//locals headers includes
#include "headers/buttons_functions.h"
#include "headers/game.h"
#include "headers/init.h"
#include "headers/map.h"
#include "headers/options.h"
#include "headers/player.h"
#include "headers/color.h"
#include "headers/UI/ui.h"
#include "headers/utils.h"

//UI data
#include "data/UI/headers/data_ui_main_menu.h"
#include "data/UI/headers/data_ui_mode_selection.h"
#include "data/UI/headers/data_ui_game_stats.h"
#include "data/UI/headers/data_ui_pause_menu.h"
#include "data/UI/headers/data_ui_options.h"

//booleans definitions
#define true 1
#define false 0

//Macros definition 
//Get the center between a and b
#define CENTERED(a, b) ((a - b) / 2)

//Get max value between a and b
#define MAX(a, b) ((a > b) ? a : b)
//Get min value between a and b
#define MIN(a, b) ((a < b) ? a : b)

enum GameState
{
    GAME_STATE_NONE,
    GAME_STATE_MAIN_MENU,
    GAME_STATE_OPTIONS,
    GAME_STATE_MODE_SELECTION,
    GAME_STATE_GAME,
    GAME_STATE_PAUSE_MENU,
    GAME_STATE_GAME_STATS,
    GAME_STATE_EXIT_GAME,
};

//Basic window width, 1080
extern const int WINDOW_WIDTH;
//Basic window height, 720
extern const int WINDOW_HEIGHT;

//window width
extern int WIDTH;
//window height
extern int HEIGHT;

//Scale on X axis
extern float SCALE_X;
//Scale on y axis
extern float SCALE_Y;

extern MouseState mouse_state;

//contains the current fps number
extern int FPS;
//contains the max fps value
extern int MAX_FPS;
//contains the current delta time
extern double delta_time;

//SDL window
extern SDL_Window *window;
//SDL renderer
extern SDL_Renderer *renderer;
//SDL event container
extern SDL_Event event;

//contains the fps value in string
extern char *FPS_text;
//fps label to display fps value
extern Label FPS_label;

//function that exit the whole game
void exit_full_game();

#endif