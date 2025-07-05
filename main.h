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
#include "headers/game_stats.h"
#include "headers/mode_selection.h"
#include "headers/game.h"
#include "headers/init.h"
#include "headers/map.h"
#include "headers/options.h"
#include "headers/pause_menu.h"
#include "headers/player.h"
#include "headers/theme.h"
#include "headers/ui.h" 
#include "headers/utils.h"

//UI data
#include "data/UI/headers/data_ui_main_menu.h"
#include "data/UI/headers/data_ui_mode_selection.h"
#include "data/UI/headers/data_ui_game_stats.h"

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

//Init values for UI_element
#define EMPTY_UI_ELEMENT {0, 0, 0, 0, NO_OUTLINE, NO_INLINE, NONE}

//Returns values enum
enum Returns
{
    //return state for UI elements like buttons or toggles, when they're not pressed
    RETURN_NONE = -1,
    //return 0 if function exit successfully
    RETURN_SUCCESS,
    //return 1 if function exit unsuccessfully
    RETURN_FAILURE,
    //tells to quit the whole game
    RETURN_EXIT_FULL_GAME,
    //tells to go back to main menu
    RETURN_TO_MAIN_MENU,
    //tell to return to game mode choice menu
    RETURN_TO_GAMEMODE_CHOICE,
    //tells to go back to the game
    RETURN_TO_GAME,
    //tells to restart the current game
    RETURN_RESTART_GAME,
    //UI states
    //active option gameplay panel
    RETURN_OPTION_GAMEPLAY_PANEL,
    //active option color panel
    RETURN_OPTION_COLOR_PANEL,
    //active option video panel
    RETURN_OPTION_VIDEO_PANEL,
    //active option audio panel
    RETURN_OPTION_AUDIO_PANEL,
    //UI state which tells to update slider
    RETURN_SLIDER_UPDATE,
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