#include "../main.h"

int pause_menu()
{
    Label title_label = {0, 0, 0, 0, 0.3, "Game Paused", &current_label_style, roboto_regular, NULL, NULL, false};
    if (NULL != label_init(&title_label))
    {
        set_label_anchor(&title_label, CENTER_X, 0, 0);
    }

    Label back_button_label = {0, 0, 0, 0, 0.1, "Back", &current_button_label_style, roboto_light, NULL, NULL, false};
    Label restart_button_label = {0, 0, 0, 0, 0.1, "Restart", &current_button_label_style, roboto_light, NULL, NULL, false};
    Label main_menu_button_label = {0, 0, 0, 0, 0.1, "Main menu", &current_button_label_style, roboto_light, NULL, NULL, false};

    Button back_button = {0, 0, 150, 50, NORMAL, back_button_label, &current_button_style, &back};
    if (NULL != button_init(&back_button))
    {
        set_button_anchor(&back_button, CENTER, 0, 0);
    }

    Button restart_button = {0, 0, 150, 50, NORMAL, restart_button_label, &current_button_style, &restart};
    if (NULL != button_init(&restart_button))
    {
        set_button_anchor(&restart_button, CENTER, 0, button_height(&back_button)+10 * SCALEY);
    }

    Button main_menu_button = {0, 0, 150, 50, NORMAL, main_menu_button_label, &current_button_style, &main_menu};
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
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current_theme.main_colors.pause_menu_background.r,current_theme.main_colors.pause_menu_background.g,current_theme.main_colors.pause_menu_background.b,current_theme.main_colors.pause_menu_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                label_list_free(labels, 2);
                button_list_free(buttons, 3);
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

        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    label_list_free(labels, 2);
    button_list_free(buttons, 3);
    return RETURN_ZERO;
}
