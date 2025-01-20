#include "../main.h"

int pause_menu()
{
    Button back_button = {10,10,100,25,0, current.button_color[0],current.button_color[1], &back};
    Button restart_button = {10,50,100,25,0, current.button_color[0],current.button_color[1], &restart};
    Button main_menu_button = {10,90,100,25,0, current.button_color[0],current.button_color[1], &main_menu};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, current.menu_background.r,current.menu_background.g,current.menu_background.b,current.menu_background.a);
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

        out = button_update(&back_button);
        switch (out)
        {
            case RETURN_TO_GAME:
                return RETURN_TO_GAME;
            default:
                break;
        }
        button_render(&back_button);

        out = button_update(&restart_button);
        switch (out)
        {
            case RETURN_RESTART_GAME:
                return RETURN_RESTART_GAME;
            default:
                break;
        }
        button_render(&restart_button);

        out = button_update(&main_menu_button);
        switch (out)
        {
            case RETURN_TO_MAIN_MENU:
                return RETURN_TO_MAIN_MENU;
            default:
                break;
        }
        button_render(&main_menu_button);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    return RETURN_ZERO;
}

int back()
{
    return RETURN_TO_GAME;
}

int restart()
{
    return RETURN_RESTART_GAME;
}

int main_menu()
{
    return RETURN_TO_MAIN_MENU;
}
