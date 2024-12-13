#include "../main.h"

int pause_menu()
{
    Button back_button = {10,10,100,25,0, SDL_LoadBMP("ressources/buttons/button_back/button_back_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_back/button_back_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_back/button_back_unpressed.bmp"), (void (*))(&back)};
    Button restart_button = {10,50,100,25,0, SDL_LoadBMP("ressources/buttons/button_restart/button_restart_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_restart/button_restart_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_restart/button_restart_unpressed.bmp"), (void (*))(&_restart)};
    Button main_menu_button = {10,90,100,25,0, SDL_LoadBMP("ressources/buttons/button_main_menu/button_main_menu_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_main_menu/button_main_menu_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_main_menu/button_main_menu_unpressed.bmp"), (void (*))(&main_menu)};

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

        out = button_update(&back_button);
        switch (out)
        {
            case RETURN_:
                running = 0;
                break;
        }
        button_render(&back_button);

        out = button_update(&restart_button);
        switch (out)
        {
            case RETURN_:
                return RETURN_RESTART_GAME;
        }
        button_render(&restart_button);

        out = button_update(&main_menu_button);
        switch (out)
        {
            case RETURN_:
                return RETURN_BACK_MAIN_MENU;
        }
        button_render(&main_menu_button);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    return RETURN_EXIT_PAUSE_MENU;
}

int back()
{
    return RETURN_;
}

int _restart()
{
    return RETURN_;
}

int main_menu()
{
    return RETURN_;
}
