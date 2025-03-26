#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "headers/buttons_functions.h"
#include "headers/end_game.h"
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

#define true 1
#define false 0

#define CENTERED(a, b) ((a - b) / 2)

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

enum Returns
{
    RETURN_NONE = -1,
    RETURN_SUCCESS,
    RETURN_FAILURE,
    RETURN_EXIT_FULL_GAME,
    RETURN_TO_MAIN_MENU,
    RETURN_TO_GAMEMODE_CHOICE,
    RETURN_TO_GAME,
    RETURN_RESTART_GAME,
    RETURN_OPTION_GAMEPLAY_PANEL,
    RETURN_OPTION_PANEL,
    RETURN_OPTION_VIDEO_PANEL,
    RETURN_OPTION_AUDIO_PANEL,
    RETURN_SLIDER_UPDATE,
};

extern int WIDTH;
extern int HEIGHT;
extern float SCALEX;
extern float SCALEY;

extern int FPS;
extern int MAX_FPS;
extern double delta_time;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern int mouse_x;
extern int mouse_y;
extern int mouse_delta_x;
extern int mouse_delta_y;
extern int mouse_button_pressed;
extern int mouse_wheel_value;

extern char *FPS_text;
extern Label FPS_label;

#endif