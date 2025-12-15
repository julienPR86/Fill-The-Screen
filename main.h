#ifndef _MAIN_H_
#define _MAIN_H_

//C libraries includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

//locals headers includes
#include "headers/animation_manager.h"
#include "headers/buttons_functions.h"
#include "headers/game.h"
#include "headers/init.h"
#include "headers/exit.h"
#include "headers/map.h"
#include "headers/options.h"
#include "headers/player.h"
#include "headers/color.h"
#include "headers/types.h"
#include "headers/UI/ui.h"
#include "headers/utils.h"
#include "headers/variables.h"

//Animations
#include "headers/animations/constant_animation.h"

//UI data
#include "data/UI/headers/data_ui_main_menu.h"
#include "data/UI/headers/data_ui_mode_selection.h"
#include "data/UI/headers/data_ui_game_stats.h"
#include "data/UI/headers/data_ui_pause_menu.h"
#include "data/UI/headers/data_ui_options.h"

//booleans definitions
#define true 1
#define false 0

//If defined, DEBUG_LOG will tells the program to print in the stdout logs messages
//#define DEBUG_LOGS

//If defined, ERROR_LOGS will tells the program to print in the stderr error messages
#define ERROR_LOGS

//Macros definition 
//Get the center between a and b
#define CENTERED(a, b) ((a - b) / 2)

//Get max value between a and b
#define MAX(a, b) ((a > b) ? a : b)
//Get min value between a and b
#define MIN(a, b) ((a < b) ? a : b)

#endif