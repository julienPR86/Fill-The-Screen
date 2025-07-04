#include "../main.h"

int pause_menu()
{
    Label title_label = {{WINDOW_WIDTH/2, 0, 0, 0, NO_OUTLINE, NO_INLINE, TOP_CENTER}, "Game Paused", 100, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&title_label, SCALE_X, SCALE_Y);

    Label back_button_label = {EMPTY_UI_ELEMENT, "Back", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    Label restart_button_label = {EMPTY_UI_ELEMENT, "Restart", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    Label main_menu_button_label = {EMPTY_UI_ELEMENT, "Main menu", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};

    Button back_button = {{WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &back_button_label, &button_style, &back, true};
    button_init(&back_button, SCALE_X, SCALE_Y);

    Button restart_button = {{WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &restart_button_label, &button_style, &restart, true};
    button_init(&restart_button, SCALE_X, SCALE_Y);

    Button main_menu_button = {{WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &main_menu_button_label, &button_style, &main_menu, true};
    button_init(&main_menu_button, SCALE_X, SCALE_Y);

    Label *labels[] = {&title_label, &FPS_label};
    Button *buttons[] = {&back_button, &restart_button, &main_menu_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_state.delta_x, &mouse_state.delta_y);
        SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        
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
            update_window_size(event, window);
            mouse_event(event);
        }

        for (int i = 0; i < (int)(sizeof(buttons)/sizeof(buttons[0])); i++)
        {
            out = button_update(buttons[i], SCALE_X, SCALE_Y);
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
            button_render(buttons[i], SCALE_X, SCALE_Y);
        }

        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i], SCALE_X, SCALE_Y);
            label_render(labels[i], SCALE_X, SCALE_Y);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    label_list_free(labels, 2);
    button_list_free(buttons, 3);
    return RETURN_SUCCESS;
}
