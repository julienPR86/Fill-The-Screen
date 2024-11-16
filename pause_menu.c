#include <stdio.h>
#include "consts.c"

#ifndef PAUSE_MENU
#define PAUSE_MENU

void pause_menu()
{
    int running = 1;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                OUTPUT_PAUSE_MENU = 1;
                return;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.keysym.sym)
                {
                    running = 0;
                    break;
                }
            }
        }
        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
}

#endif