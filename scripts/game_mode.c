#include "../main.h"

int mode_choice()
{
    Label title_label = {{WIDTH/2, 20 * SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_CENTER}, "Game mode Choice", 100, {255, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&title_label, SCALE);
    
    Label back_label = {{WIDTH/2, HEIGHT - 10*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, BOTTOM_CENTER}, "Press Escape to go back", 30, {255, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&back_label, SCALE);

    Label fill_mode_button_label = {EMPTY_UI_ELEMENT, "Fill", 30, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label discovery_mode_button_label = {EMPTY_UI_ELEMENT, "Discovery", 30, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label constraint_mode_button_label = {EMPTY_UI_ELEMENT, "Constraint", 30, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label free_mode_button_label = {EMPTY_UI_ELEMENT, "Free", 30, {0, 0, 0, 255}, NULL, NULL, false, true};

    Button fill_mode_button = {{WIDTH/2, HEIGHT/2 - 100*SCALE, 200, 50, outlines[2], inlines[1], CENTER}, NORMAL, &fill_mode_button_label, &button_style, &fill_mode, true};
    button_init(&fill_mode_button, SCALE);

    Button discovery_mode_button = {{WIDTH/2, HEIGHT/2, 200, 50, outlines[2], inlines[1], CENTER}, NORMAL, &discovery_mode_button_label, &button_style, &discovery_mode, true};
    button_init(&discovery_mode_button, SCALE);

    Button constraint_mode_button = {{WIDTH/2, HEIGHT/2 + 100*SCALE, 200, 50, outlines[2], inlines[1], CENTER}, NORMAL, &constraint_mode_button_label, &button_style, &constraint_mode, true};
    button_init(&constraint_mode_button, SCALE);

    Button free_mode_button = {{WIDTH/2, HEIGHT/2 + 200*SCALE, 200, 50, outlines[2], inlines[1], CENTER}, NORMAL, &free_mode_button_label, &button_style, &free_mode, true};
    button_init(&free_mode_button, SCALE);

    Label *labels[] = {&title_label, &back_label, &FPS_label};
    Button *buttons[] = {&fill_mode_button, &discovery_mode_button, &constraint_mode_button, &free_mode_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_state.delta_x, &mouse_state.delta_y);
        SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        
        SDL_SetRenderDrawColor(renderer, theme.main_colors.game_mode_background.r, theme.main_colors.game_mode_background.g, theme.main_colors.game_mode_background.b, theme.main_colors.game_mode_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_EVENT_QUIT == event.type)
            {
                label_list_free(labels, 3);
                button_list_free(buttons, 4);
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_EVENT_KEY_DOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.key)
                {
                    running = false;
                }
            }
            mouse_event(event);
        }

        for (int i = 0; i < (int)(sizeof(buttons)/sizeof(buttons[0])); i++)
        {
            out = button_update(buttons[i], SCALE);
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
            button_render(buttons[i], SCALE);
        }

        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i], SCALE);
            label_render(labels[i], SCALE);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    label_list_free(labels, 3);
    button_list_free(buttons, 4);
    return RETURN_SUCCESS;
}
