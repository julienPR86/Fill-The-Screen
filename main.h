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
#include "headers/game_mode.h"
#include "headers/game.h"
#include "headers/init.h"
#include "headers/map.h"
#include "headers/options.h"
#include "headers/pause_menu.h"
#include "headers/player.h"
#include "headers/theme.h"
#include "headers/ui.h" 
#include "headers/utils.h"

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

//Returns values enum
enum Returns
{
    //return state for UI elements like buttons or toogles, when they're not pressed
    RETURN_NONE = -1,
    //return 0 if function exit successfully
    RETURN_SUCCESS,
    //return 1 if function exit successfully
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

enum MouseState
{
    //no buttons are pressed
    MOUSE_STATE_NONE,
    //left mouse button pressed
    MOUSE_STATE_LEFT_CLICK,
    //right mouse button pressed
    MOUSE_STATE_RIGHT_CLICK,
};

//window width
extern int WIDTH;
//window height
extern int HEIGHT;

//window scale on x axis
extern float SCALEX;
//window scale on y axis
extern float SCALEY;
//window scale is based on the actual resolution and the basic window resolution, which is 1080x720

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

//contains the x mouse position
extern float mouse_x;
//contains the y mouse position
extern float mouse_y;
//contains the x mouse delta position since the last frame
extern float mouse_delta_x;
//contains the y mouse delta position since the last frame
extern float mouse_delta_y;
//contains a value which tells which mouse button is pressed
extern int mouse_button_pressed;
//contains a value between -1 and 1 that tells the wheel rotation value
extern int mouse_wheel_value;

//contains the fps value in string
extern char *FPS_text;
//fps label to display fps value
extern Label FPS_label;

//function that exit the whole game
void exit_full_game();

#endif