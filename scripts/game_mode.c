#include "../main.h"

int mode_choice()
{

    Button normal_mode_button = {10,10,100,25,0, SDL_LoadBMP("ressources/buttons/button_play/button_play_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_play/button_play_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_play/button_play_unpressed.bmp"), (void (*))(&game)};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                return RETURN_EXIT_MAIN;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.keysym.sym)
                {
                    running = 0;
                    break;
                }
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

        out = button_update(&normal_mode_button);
        switch (out)
        {
            case RETURN_EXIT_GAME:
                return RETURN_EXIT_GAME_MODE_MENU;
            case RETURN_EXIT_MAIN:
                return RETURN_EXIT_MAIN;
        }
        button_render(&normal_mode_button);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    return RETURN_EXIT_PAUSE_MENU;
}
