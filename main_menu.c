#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "const.c"
#include "button.c"
#include "game.c"

#ifndef MAIN_MENU
#define MAIN_MENU

void quit(SDL_Window *, SDL_Renderer *);

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

    Button button = {10,10,100,25, {255,128,0,255},{255,0,0,255}, {255,0,0,255}};

    SDL_Event event;
    int running = 1;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderClear(renderer);//background
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                running = 0;
                break;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_RETURN == event.key.keysym.sym)
                {
                    int output = start_game();
                    if (output < 0)
                    {
                        fprintf(stderr, "Could not run the game\n");
                    }
                    else if (output > 0)
                    {
                        running = 0;
                        break;
                    }
                }
            }
        }

        button_update(&button);
        button_render(&button);

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
    printf("quit ok\n");
}

#endif