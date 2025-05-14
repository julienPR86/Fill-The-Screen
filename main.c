#include "main.h"

int main()
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }
    Label title_label = {0, 0, 0, 0, 1, "Fill The Screen", 100, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&title_label))
    {
        set_label_anchor(&title_label, CENTER_X, 0, 10);
    }

    Label play_button_label = {0, 0, 0, 0, 1, "PLAY", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};
    Label options_button_label = {0, 0, 0, 0, 1, "Options", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};
    Label exit_button_label = {0, 0, 0, 0, 1, "Quit", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};

    Button play_button = {0, 0, 150, 50, NORMAL, &play_button_label, &button_style, &mode_choice, true};
    if (NULL != button_init(&play_button))
    {
        set_button_anchor(&play_button, CENTER, 0, 0);
    }

    Button options_button = {0, 0, 150, 50, NORMAL, &options_button_label, &button_style, &options, true};
    if (NULL != button_init(&options_button))
    {
        set_button_anchor(&options_button, CENTER, 0, button_height(&play_button)+10 * SCALEY);
    }

    Button exit_button = {0, 0, 150, 50, NORMAL, &exit_button_label, &button_style, &exit_game, true};
    if (NULL != button_init(&exit_button))
    {
        set_button_anchor(&exit_button, CENTER, 0, button_height(&options_button) + button_height(&play_button)+(10 * SCALEY)*2);
    }
    
    Label *labels[] = {&title_label, &FPS_label};
    Button *buttons[] = {&play_button, &options_button, &exit_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_delta_x, &mouse_delta_y);
        SDL_GetMouseState(&mouse_x, &mouse_y);
        
        SDL_SetRenderDrawColor(renderer, theme.main_colors.menu_background.r, theme.main_colors.menu_background.g, theme.main_colors.menu_background.b, theme.main_colors.menu_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_EVENT_QUIT == event.type)
            {
                running = false;
                break;
            }
            mouse_event(event);
        }

        for (int i = 0; i < (int)(sizeof(buttons)/sizeof(buttons[0])); i++)
        {
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_SUCCESS:
                    break;
                case RETURN_TO_MAIN_MENU:
                    break;
                case RETURN_EXIT_FULL_GAME:
                    label_list_free(labels, 2);
                    button_list_free(buttons, 3);
                    exit_full_game();
                    return RETURN_SUCCESS;
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
    exit_full_game();
    return RETURN_SUCCESS;
}

void exit_full_game()
{
    label_free(&FPS_label);
    free(FPS_text);
    FPS_text = NULL;

    for (int i = 0; i < max_font_size; i++)
    {
        TTF_CloseFont(roboto_regular_fonts[i]);
    }
    free(roboto_regular_fonts);
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    TTF_Quit();
    SDL_Quit();
    printf("exit ok\n");
    return;
}
