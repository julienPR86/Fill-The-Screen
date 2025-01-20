#include "../main.h"

int mode_choice()
{
    Button fill_mode_button = {10,10,100,25,0, current.button_color[0],current.button_color[1], &fill_mode};
    Button discovery_mode_button = {10,50,100,25,0, current.button_color[0],current.button_color[1], &discovery_mode};
    Button constraint_mode_button = {10,100,100,25,0, current.button_color[0],current.button_color[1], &constraint_mode};
    Button free_mode_button = {10,150,100,25,0, current.button_color[0],current.button_color[1], &free_mode};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, current.game_mode_background.r,current.game_mode_background.g,current.game_mode_background.b,current.game_mode_background.a);
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
            mouse_pressed(event);
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
    game_mode = FILL_MODE;
    return game();
}

int discovery_mode()
{
    game_mode = DISCOVERY_MODE;
    return game();
}

int constraint_mode()
{
    game_mode = CONSTRAINT_MODE;
    return game();
}

int free_mode()
{
    game_mode = FREE_MODE;
    return game();
}