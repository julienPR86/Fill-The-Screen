#include <stdio.h>
#include <SDL2/SDL.h>
#include "consts.c"
#include "button.c"
#include "game.c"

#ifndef MAIN_MENU
#define MAIN_MENU

int quit();

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

    Button play_button = {10,10,100,25,0, {255,128,0,255},{255,0,0,255}, {255,0,0,255}, (void (*))(&start_game)};
    Button quit_button = {10,50,100,25,0, {255,128,0,255},{255,0,0,255}, {255,0,0,255}, (void (*))(&quit)};

    int running = 1, out;
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
            if (SDL_MOUSEBUTTONDOWN == event.type && !mouse_button_pressed)
            {
                mouse_button_pressed = event.button.button;
            }
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                if (event.button.button == mouse_button_pressed)
                {
                    mouse_button_pressed = 0;
                }
            }
        }

        out = button_update(&play_button);
        switch (out)
        {
        case 0:
            break;
        case 1:
            quit(window, renderer);
            return 0;
        case -1:
            fprintf(stderr, "Could not run the game\n");
            break;
        }
        button_render(&play_button);

        out = button_update(&quit_button);
        switch (out)
        {
        case 0:
            return 0;
        }
        button_render(&quit_button);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    quit(window, renderer);
    return 0;
}

int quit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("quit ok\n");
    return 0;
}

#endif