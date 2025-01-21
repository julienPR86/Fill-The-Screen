#include "../main.h"

int pause_menu()
{
    Button back_button = {10, 10, 100, 25, 0, "back", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &back};
    Button restart_button = {10, 50, 100, 25, 0, "Restart", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &restart};
    Button main_menu_button = {10, 90, 100, 25, 0, "Main menu", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &main_menu};

    int running = true, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, current.main_colors.pause_menu_background.r,current.main_colors.pause_menu_background.g,current.main_colors.pause_menu_background.b,current.main_colors.pause_menu_background.a);
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
                    running = false;
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
