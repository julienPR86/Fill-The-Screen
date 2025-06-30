#include "../main.h"

int game_stats()
{
    int moves = player->moves;
    float percent = 1.0/(map->height*map->width) * 100;
    float square_ratio = 0;
    if (moves)
    {
        if (CONSTRAINT_MODE == game_mode)
        {
            int count = map_get_squares_number(map, EMPTY_SQUARE) + map_get_squares_number(map, COLLISION_SQUARE);
            percent = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
            square_ratio = (float)(map->height*map->width-(map_get_squares_number(map, EMPTY_SQUARE)+map_get_squares_number(map, COLLISION_SQUARE)))/moves;
        }
        else if (DISCOVERY_MODE == game_mode)
        {
            int count = map_get_squares_number(map, EMPTY_SQUARE) + map_get_squares_number(map, FAKE_SQUARE);
            percent = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
            square_ratio = (float)(map->height*map->width-(map_get_squares_number(map, EMPTY_SQUARE)+map_get_squares_number(map, FAKE_SQUARE)))/moves;
        }
        else
        {
            int count = map_get_squares_number(map, EMPTY_SQUARE);
            percent = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
            square_ratio = (float)(map->height*map->width-map_get_squares_number(map, EMPTY_SQUARE))/moves;
        }
    }

    char percent_text[50];
    snprintf(percent_text, sizeof(percent_text), "You filled %.2f%% of the map", percent);
    char moves_text[50];
    snprintf(moves_text, sizeof(moves_text), "You made %d moves", moves);
    char square_ratio_text[50];
    snprintf(square_ratio_text, sizeof(square_ratio_text), "Your average filled squares per move is %.2f", square_ratio);

    Label title_label = {{WIDTH/2, 50 * SCALE_Y, 0, 0, NO_OUTLINE, NO_INLINE, TOP_CENTER}, "Game over", 100, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&title_label, SCALE_X, SCALE_Y);

    Label congrats = {{WIDTH/2, 50 * SCALE_Y, 0, 0, NO_OUTLINE, NO_INLINE, TOP_CENTER}, "Congratulation", 100, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&congrats, SCALE_X, SCALE_Y);

    Label percent_label = {{WIDTH/2, 180 * SCALE_Y, 0, 0, NO_OUTLINE, NO_INLINE, CENTER}, percent_text, 35, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&percent_label, SCALE_X, SCALE_Y);

    Label moves_label = {{WIDTH/2, 230 * SCALE_Y, 0, 0, NO_OUTLINE, NO_INLINE, CENTER}, moves_text, 35, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&moves_label, SCALE_X, SCALE_Y);

    Label square_ratio_label = {{WIDTH/2, 280 * SCALE_Y, 0, 0, NO_OUTLINE, NO_INLINE, CENTER}, square_ratio_text, 35, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&square_ratio_label, SCALE_X, SCALE_Y);

    Label back_button_label = {EMPTY_UI_ELEMENT, "Back", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    Label restart_button_label = {EMPTY_UI_ELEMENT, "Restart", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    Label main_menu_button_label = {EMPTY_UI_ELEMENT, "Main menu", 30, {0, 0, 0, 255}, NULL, NULL, false, 1.0, true};

    Button back_button = {{WIDTH/2, HEIGHT/2, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &back_button_label, &button_style, &back, true};
    button_init(&back_button, SCALE_X, SCALE_Y);

    Button restart_button = {{WIDTH/2, HEIGHT/2 + 100 * SCALE_Y, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &restart_button_label, &button_style, &restart, true};
    button_init(&restart_button, SCALE_X, SCALE_Y);

    Button main_menu_button = {{WIDTH/2, HEIGHT/2 + 200 * SCALE_Y, 150, 50, outlines[2], inlines[1], CENTER}, NORMAL, &main_menu_button_label, &button_style, &main_menu, true};
    button_init(&main_menu_button, SCALE_X, SCALE_Y);
    
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

        if (percent >= 100.0)
            label_render(&congrats, SCALE_X, SCALE_Y);
        else
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
