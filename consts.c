#include <SDL2/SDL.h>

#ifndef CONST
#define CONST

int WIDTH = 1080;
int HEIGHT = 720;
int FPS = 60;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

int mouse_button_pressed;

int OUTPUT_START_GAME = 0;
int OUTPUT_QUIT = 0;
int OUTPUT_PAUSE_MENU = 0;

#endif