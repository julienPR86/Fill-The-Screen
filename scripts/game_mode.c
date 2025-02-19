#include "../main.h"

int mode_choice()
{
    Label title_label = {0, 0, 0, 0, 0.3, "Game mode Choice", roboto_regular, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&title_label);
    set_label_anchor(&title_label, CENTER_X, 0, 0);
    
    Label back_label = {0, 0, 0, 0, 0.1, "Press Escape to go back", roboto_light, {255,255,255,255}, {250,40,0,255}, NULL, NULL, false};
    label_init(&back_label);
    set_label_anchor(&back_label, BOTTOM_LEFT, 0, 10);
    set_label_anchor(&back_label, CENTER_X, 0, 0);

    Label fill_mode_button_label = {0, 0, 0, 0, 0.1, "Fill", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label discovery_mode_button_label = {0, 0, 0, 0, 0.1, "Discovery", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label constraint_mode_button_label = {0, 0, 0, 0, 0.1, "Constraint", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label free_mode_button_label = {0, 0, 0, 0, 0.1, "Free", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};

    Button fill_mode_button = {10, HEIGHT/2-99, 200, 50, NORMAL, fill_mode_button_label, basic_button_style, &fill_mode};
    button_init(&fill_mode_button);
    Button discovery_mode_button = {10, HEIGHT/2-33, 300, 50, NORMAL, discovery_mode_button_label, basic_button_style, &discovery_mode};
    button_init(&discovery_mode_button);
    Button constraint_mode_button = {10, HEIGHT/2+33, 300, 50, NORMAL, constraint_mode_button_label, basic_button_style, &constraint_mode};
    button_init(&constraint_mode_button);
    Button free_mode_button = {10, HEIGHT/2+99, 200, 50, NORMAL, free_mode_button_label, basic_button_style, &free_mode};
    button_init(&free_mode_button);

    Label *labels[] = {&title_label, &back_label, &FPS_label};
    Button *buttons[] = {&fill_mode_button, &discovery_mode_button, &constraint_mode_button, &free_mode_button};

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
                label_list_free(labels, 3);
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
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_FAILURE:
                    break;
                case RETURN_EXIT_FULL_GAME:
                    label_list_free(labels, 3);
                    return RETURN_EXIT_FULL_GAME;
                case RETURN_TO_MAIN_MENU:
                    label_list_free(labels, 3);
                    return RETURN_TO_MAIN_MENU;
                default:
                    break;
            }
            button_render(buttons[i]);
        }

        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    label_list_free(labels, 3);
    return RETURN_ZERO;
}
