#include "../main.h"

int mode_choice()
{

    Button fill_mode_button = {10,10,100,25,0, SDL_LoadBMP("ressources/buttons/button_fill_mode/button_fill_mode_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_fill_mode/button_fill_mode_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_fill_mode/button_fill_mode_unpressed.bmp"), &fill_mode};
    Button discovery_mode_button = {10,50,100,25,0, SDL_LoadBMP("ressources/buttons/button_discovery_mode/button_discovery_mode_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_discovery_mode/button_discovery_mode_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_discovery_mode/button_discovery_mode_unpressed.bmp"), &discovery_mode};
    Button constraint_mode_button = {10,100,100,25,0, SDL_LoadBMP("ressources/buttons/button_constraint_mode/button_constraint_mode_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_constraint_mode/button_constraint_mode_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_constraint_mode/button_constraint_mode_unpressed.bmp"), &constraint_mode};
    Button free_mode_button = {10,150,100,25,0, SDL_LoadBMP("ressources/buttons/button_free_mode/button_free_mode_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_free_mode/button_free_mode_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_free_mode/button_free_mode_unpressed.bmp"), &free_mode};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                return RETURN_EXIT_FULL_GAME;
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

        out = button_update(&fill_mode_button);
        switch (out)
        {
            case RETURN_FAILURE:
                break;
            case RETURN_EXIT_FULL_GAME:
                return RETURN_EXIT_FULL_GAME;
            case RETURN_TO_MAIN_MENU:
                return RETURN_TO_MAIN_MENU;
            default:
                break;
        }
        button_render(&fill_mode_button);

        out = button_update(&discovery_mode_button);
        switch (out)
        {
            case RETURN_FAILURE:
                break;
            case RETURN_EXIT_FULL_GAME:
                return RETURN_EXIT_FULL_GAME;
            case RETURN_TO_MAIN_MENU:
                return RETURN_TO_MAIN_MENU;
            default:
                break;
        }
        button_render(&discovery_mode_button);

        out = button_update(&constraint_mode_button);
        switch (out)
        {
            case RETURN_FAILURE:
                break;
            case RETURN_EXIT_FULL_GAME:
                return RETURN_EXIT_FULL_GAME;
            case RETURN_TO_MAIN_MENU:
                return RETURN_TO_MAIN_MENU;
            default:
                break;
        }
        button_render(&constraint_mode_button);

        out = button_update(&free_mode_button);
        switch (out)
        {
            case RETURN_FAILURE:
                break;
            case RETURN_EXIT_FULL_GAME:
                return RETURN_EXIT_FULL_GAME;
            case RETURN_TO_MAIN_MENU:
                return RETURN_TO_MAIN_MENU;
            default:
                break;
        }
        button_render(&free_mode_button);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    return RETURN_ZERO;
}

int fill_mode()
{
    return game(FILL_MODE);
}

int discovery_mode()
{
    return game(DISCOVERY_MODE);
}

int constraint_mode()
{
    return game(CONSTRAINT_MODE);
}

int free_mode()
{
    return game(FREE_MODE);
}