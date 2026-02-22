#ifndef MAIN_H
#define MAIN_H

//C libraries includes
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

//locals headers includes
#include "animation_manager.h"
#include "buttons_functions.h"
#include "game.h"
#include "init.h"
#include "exit.h"
#include "map.h"
#include "options.h"
#include "player.h"
#include "color.h"
#include "definitions.h"
#include "UI/ui.h"
#include "utils.h"
#include "variables.h"

//Animations
#include "animations/constant_animation.h"

//UI data
#include "../data/UI/includes/data_ui_main_menu.h"
#include "../data/UI/includes/data_ui_mode_selection.h"
#include "../data/UI/includes/data_ui_game_stats.h"
#include "../data/UI/includes/data_ui_pause_menu.h"
#include "../data/UI/includes/data_ui_options.h"

//booleans definitions
#define true 1
#define false 0

//If defined, DEBUG_LOG will tells the program to print in the stdout logs messages
// #ifndef DEBUG_LOGS
// # define DEBUG_LOGS
// #endif

//If defined, ERROR_LOGS will tells the program to print in the stderr error messages
#ifndef ERROR_LOGS
# define ERROR_LOGS
#endif

//Macros definition 
//Get the center between a and b
#define CENTERED(a, b) ((a - b) / 2)

//Get max value between a and b
#define MAX(a, b) ((a > b) ? a : b)
//Get min value between a and b
#define MIN(a, b) ((a < b) ? a : b)

#endif