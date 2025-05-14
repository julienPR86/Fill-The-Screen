#include "../main.h"

int pause_menu()
{
    Label title_label = {0, 0, 0, 0, 1, "Game Paused", 100, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&title_label))
    {
        set_label_anchor(&title_label, CENTER_X, 0, 0);
    }

    Label back_button_label = {0, 0, 0, 0, 1, "Back", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};
    Label restart_button_label = {0, 0, 0, 0, 1, "Restart", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};
    Label main_menu_button_label = {0, 0, 0, 0, 1, "Main menu", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};

    Button back_button = {0, 0, 150, 50, NORMAL, &back_button_label, &button_style, &back, true};
    if (NULL != button_init(&back_button))
    {
        set_button_anchor(&back_button, CENTER, 0, 0);
    }

    Button restart_button = {0, 0, 150, 50, NORMAL, &restart_button_label, &button_style, &restart, true};
    if (NULL != button_init(&restart_button))
    {
        set_button_anchor(&restart_button, CENTER, 0, button_height(&back_button)+10 * SCALEY);
    }

    Button main_menu_button = {0, 0, 150, 50, NORMAL, &main_menu_button_label, &button_style, &main_menu, true};
    if (NULL != button_init(&main_menu_button))
    {
        set_button_anchor(&main_menu_button, CENTER, 0, button_height(&back_button) + button_height(&restart_button)+(10 * SCALEY)*2);
    }

    Label *labels[] = {&title_label, &FPS_label};
    Button *buttons[] = {&back_button, &restart_button, &main_menu_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_delta_x, &mouse_delta_y);
        SDL_GetMouseState(&mouse_x, &mouse_y);
        
        SDL_SetRenderDrawColor(renderer, theme.main_colors.pause_menu_background.r, theme.main_colors.pause_menu_background.g, theme.main_colors.pause_menu_background.b, theme.main_colors.pause_menu_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_EVENT_QUIT == event.type)
            {
                label_list_free(labels, 2);
                button_list_free(buttons, 3);
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_EVENT_KEY_DOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.key)
                {
                    running = false;
                    break;
                }
            }
            mouse_event(event);
        }

        for (int i = 0; i < (int)(sizeof(buttons)/sizeof(buttons[0])); i++)
        {
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_TO_GAME:
                    label_list_free(labels, 2);
                    button_list_free(buttons, 3);
                    return RETURN_TO_GAME;
                case RETURN_RESTART_GAME:
                    label_list_free(labels, 2);
                    button_list_free(buttons, 3);
                    return RETURN_RESTART_GAME;
                case RETURN_TO_MAIN_MENU:
                    label_list_free(labels, 2);
                    button_list_free(buttons, 3);
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
        mouse_event_reset();
    }
    label_list_free(labels, 2);
    button_list_free(buttons, 3);
    return RETURN_SUCCESS;
}
