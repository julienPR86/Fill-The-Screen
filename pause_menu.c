#include <stdio.h>
#include "consts.c"
#include "button.c"

#ifndef PAUSE_MENU
#define PAUSE_MENU

void back();
void restart();
void main_menu();

void pause_menu()
{

    Button back_button = {10,10,100,25,0, {255,128,0,255},{255,0,0,255}, {255,0,0,255}, (void (*))(&back)};
    Button restart_button = {10,50,100,25,0, {255,128,0,255},{255,0,0,255}, {255,0,0,255}, (void (*))(&restart)};
    Button main_menu_button = {10,90,100,25,0, {255,128,0,255},{255,0,0,255}, {255,0,0,255}, (void (*))(&main_menu)};

    Button buttons[] = {back_button, restart_button, main_menu_button};

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

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            Button *button = &buttons[i];
            button_update(button);
            button_render(button);
        }

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    OUTPUT_PAUSE_MENU = 0;
    return;
}

void back()
{

}

void restart()
{

}

void main_menu()
{

}

#endif