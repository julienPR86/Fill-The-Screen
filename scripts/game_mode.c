#include "../main.h"

int mode_choice()
{
    Label title = {10, 0, 0, 0, 0.3, "Game mode Choice", roboto_regular, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    Label back_label = {10, HEIGHT-50, 0, 0, 0.1, "Press Escape to go back", roboto_light, {255,255,255,255}, {250,40,0,255}, NULL, NULL, false};

    Button fill_mode_button = {10, HEIGHT/2-99, 200, 50, 1, 0, 0, NORMAL, "Fill mode", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &fill_mode};
    Button discovery_mode_button = {10, HEIGHT/2-33, 300, 50, 1, 0, 0, NORMAL, "Discovery mode", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &discovery_mode};
    Button constraint_mode_button = {10, HEIGHT/2+33, 300, 50, 1, 0, 0, NORMAL, "Constraint mode", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &constraint_mode};
    Button free_mode_button = {10, HEIGHT/2+99, 200, 50, 1, 0, 0, NORMAL, "Free mode", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &free_mode};

    Label labels[] = {title, back_label, FPS_label};
    Button buttons[] = {fill_mode_button, discovery_mode_button, constraint_mode_button, free_mode_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current.main_colors.game_mode_background.r,current.main_colors.game_mode_background.g,current.main_colors.game_mode_background.b,current.main_colors.game_mode_background.a);
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
                }
            }
            mouse_pressed(event);
        }

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            out = button_update(&buttons[i]);
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
            button_render(&buttons[i]);
        }

        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_render(&labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    return RETURN_ZERO;
}
