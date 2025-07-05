#include "../main.h"

int game_stats()
{
    game_stats_data_ui_init();
    
    Label *labels[] = {&percent_label, &moves_label, &square_ratio_label, &FPS_label};
    Button *buttons[] = {&back_button, &restart_button, &main_menu_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_state.delta_x, &mouse_state.delta_y);
        SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        
        SDL_SetRenderDrawColor(renderer, theme.main_colors.game_stats_background.r, theme.main_colors.game_stats_background.g, theme.main_colors.game_stats_background.b, theme.main_colors.game_stats_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_EVENT_QUIT == event.type)
            {
                label_list_free(labels, 4);
                button_list_free(buttons, 3);
                return RETURN_EXIT_FULL_GAME;
            }
            update_window_size(event, window);
            mouse_event(event);
        }

        for (int i = 0; i < (int)(sizeof(buttons)/sizeof(buttons[0])); i++)
        {
            out = button_update(buttons[i], SCALE_X, SCALE_Y);
            switch (out)
            {
                case RETURN_TO_GAME:
                    label_list_free(labels, 4);
                    button_list_free(buttons, 3);
                    return RETURN_TO_GAME;
                case RETURN_RESTART_GAME:
                    label_list_free(labels, 4);
                    button_list_free(buttons, 3);
                    return RETURN_RESTART_GAME;
                case RETURN_TO_MAIN_MENU:
                    label_list_free(labels, 4);
                    button_list_free(buttons, 3);
                    return RETURN_TO_MAIN_MENU;
                default:
                    break;
            }
            button_render(buttons[i], SCALE_X, SCALE_Y);
        }

        label_update(&title_label, SCALE_X, SCALE_Y);
        label_render(&title_label, SCALE_X, SCALE_Y);
        
        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i], SCALE_X, SCALE_Y);
            label_render(labels[i], SCALE_X, SCALE_Y);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    label_list_free(labels, 4);
    button_list_free(buttons, 3);
    return RETURN_TO_MAIN_MENU;
}
