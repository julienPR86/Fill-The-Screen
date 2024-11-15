#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "game.c"

#ifndef MENU
#define MENU

int WIDTH = 1080, HEIGHT = 720, FPS = 60;
SDL_Window *window;
SDL_Renderer *renderer;

int main(int argc, char **argv)
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Could not initialize SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    window = SDL_CreateWindow("Fill The Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        fprintf(stderr, "Could not create the window : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer)
    {
        fprintf(stderr, "Could not create the renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


    SDL_Event event;
    int running = 1;
    while (running)
    {
        if (SDL_QUIT == event.type)
        {
            running = 0;
        }
        if (SDL_KEYDOWN == event.type)
        {
            if (SDLK_RETURN == event.key.keysym.sym)
            {
                if (start_game(window, renderer, WIDTH, HEIGHT, FPS))
                {
                    fprintf(stderr, "Could not run the game\n");
                    running = 0;
                    break;
                }
            }
        }
        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    quit(window, renderer);
    printf("end ok\n");
    return 0;
}

void quit(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

#endif