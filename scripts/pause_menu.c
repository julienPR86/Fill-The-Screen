#include "../main.h"

int pause_menu()
{
    Label title = {10, 0, 0.3, "Game Paused", roboto_regular, {255,255,255,255}, {255,40,0,255}};

    Button back_button = {10, HEIGHT/2, 150, 50, 1, 0, 0, false, false, NORMAL, "back", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &back};
    Button restart_button = {10, HEIGHT/2+66, 150, 50, 1, 0, 0, false, false, NORMAL, "Restart", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &restart};
    Button main_menu_button = {10, HEIGHT/2+132, 150, 50, 1, 0, 0, false, false, NORMAL, "Main menu", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &main_menu};

    Label labels[] = {title};
    Button buttons[] = {back_button, restart_button, main_menu_button};

    int running = true, out;
    Uint64 last_time = SDL_GetTicks64();
    while (running)
    {
        delta_time = (SDL_GetTicks64() - last_time) * 0.001;
        last_time = SDL_GetTicks64();
        
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

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            out = button_update(&buttons[i]);
            switch (out)
            {
                case RETURN_TO_GAME:
                    return RETURN_TO_GAME;
                case RETURN_RESTART_GAME:
                    return RETURN_RESTART_GAME;
                case RETURN_TO_MAIN_MENU:
                    return RETURN_TO_MAIN_MENU;
                default:
                    break;
            }
            button_render(&buttons[i]);
        }

        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_render(&labels[i]);
        }

        SDL_RenderPresent(renderer);
    }
    return RETURN_ZERO;
}
