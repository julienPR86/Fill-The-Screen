#include "main.h"

int main()
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }
    Label title_label = {{WIDTH/2, 10 * SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_CENTER}, "Fill The Screen", 100, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&title_label, SCALE);

    Label play_button_label = {{0, 0, 0, 0, NO_OUTLINE, NO_INLINE, CENTER}, "PLAY", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    Label options_button_label = {EMPTY_UI_ELEMENT, "Options", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    Label exit_button_label = {EMPTY_UI_ELEMENT, "Quit", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};

    Button play_button = {{WIDTH/2, HEIGHT/2, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &play_button_label, &button_style, &mode_choice, true};
    button_init(&play_button, SCALE);

    Button options_button = {{WIDTH/2, HEIGHT/2 + 100 * SCALE, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &options_button_label, &button_style, &options, true};
    button_init(&options_button, SCALE);

    Button exit_button = {{WIDTH/2, HEIGHT/2 + 200 * SCALE, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &exit_button_label, &button_style, &exit_game, true};
    button_init(&exit_button, SCALE);
    
    Label *labels[] = {&title_label, &FPS_label};
    Button *buttons[] = {&play_button, &options_button, &exit_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_state.delta_x, &mouse_state.delta_y);
        SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        
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
            out = button_update(buttons[i], SCALE);
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
            button_render(buttons[i], SCALE);
        }

        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i], SCALE);
            label_render(labels[i], SCALE);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderLine(renderer, 0, HEIGHT/2, WIDTH, HEIGHT/2);
        SDL_RenderLine(renderer, WIDTH/2, 0, WIDTH/2, HEIGHT);

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
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

    free(inlines);
    free(outlines);
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
