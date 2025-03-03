#include "../main.h"

int mode_choice()
{
    Label title_label = {0, 0, 0, 0, 0.3, "Game mode Choice", roboto_regular, {255, 0, 0, 255}, NULL, NULL, false, true};
    if (NULL != label_init(&title_label))
    {
        set_label_anchor(&title_label, CENTER_X, 0, 0);
    }
    
    Label back_label = {0, 0, 0, 0, 0.1, "Press Escape to go back", roboto_light, {255, 0, 0, 255}, NULL, NULL, false, true};
    if (NULL != label_init(&back_label))
    {
        set_label_anchor(&back_label, BOTTOM_LEFT, 0, 10);
        set_label_anchor(&back_label, CENTER_X, 0, 0);
    }

    Label fill_mode_button_label = {0, 0, 0, 0, 0.1, "Fill", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label discovery_mode_button_label = {0, 0, 0, 0, 0.1, "Discovery", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label constraint_mode_button_label = {0, 0, 0, 0, 0.1, "Constraint", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label free_mode_button_label = {0, 0, 0, 0, 0.1, "Free", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};

    Button fill_mode_button = {0, 0, 200, 50, NORMAL, fill_mode_button_label, &current_button_style, &fill_mode, true};
    if (NULL != button_init(&fill_mode_button))
    {
        set_button_anchor(&fill_mode_button, CENTER, 0, -99 * SCALEY);
    }

    Button discovery_mode_button = {0, 0, 200, 50, NORMAL, discovery_mode_button_label, &current_button_style, &discovery_mode, true};
    if (NULL != button_init(&discovery_mode_button))
    {
        set_button_anchor(&discovery_mode_button, CENTER, 0, -33 * SCALEY);
    }

    Button constraint_mode_button = {0, 0, 200, 50, NORMAL, constraint_mode_button_label, &current_button_style, &constraint_mode, true};
    if (NULL != button_init(&constraint_mode_button))
    {
        set_button_anchor(&constraint_mode_button, CENTER, 0, 33 * SCALEY);
    }

    Button free_mode_button = {0, 0, 200, 50, NORMAL, free_mode_button_label, &current_button_style, &free_mode, true};
    if (NULL != button_init(&free_mode_button))
    {
        set_button_anchor(&free_mode_button, CENTER, 0, 99 * SCALEY);
    }

    Label *labels[] = {&title_label, &back_label, &FPS_label};
    Button *buttons[] = {&fill_mode_button, &discovery_mode_button, &constraint_mode_button, &free_mode_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current_theme.main_colors.game_mode_background.r, current_theme.main_colors.game_mode_background.g, current_theme.main_colors.game_mode_background.b, current_theme.main_colors.game_mode_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                label_list_free(labels, 3);
                button_list_free(buttons, 4);
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

        for (int i = 0; i < (int)(sizeof(buttons)/sizeof(buttons[0])); i++)
        {
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_FAILURE:
                    break;
                case RETURN_EXIT_FULL_GAME:
                    label_list_free(labels, 3);
                    button_list_free(buttons, 4);
                    return RETURN_EXIT_FULL_GAME;
                case RETURN_TO_MAIN_MENU:
                    label_list_free(labels, 3);
                    button_list_free(buttons, 4);
                    return RETURN_TO_MAIN_MENU;
                default:
                    break;
            }
            button_render(buttons[i]);
        }

        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    label_list_free(labels, 3);
    button_list_free(buttons, 4);
    return RETURN_ZERO;
}
