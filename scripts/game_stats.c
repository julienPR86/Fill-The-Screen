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

    Label title_label = {0, 0, 0, 0, "Game over", 100, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&title_label))
    {
        set_label_anchor(&title_label, CENTER_X, 0, 0);
    }

    Label congrats = {0, 0, 0, 0, "Congratulation", 100, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&congrats))
    {
        set_label_anchor(&congrats, CENTER_X, 0, 0);
    }

    Label percent_label = {0, 150, 0, 0, percent_text, 35, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&percent_label))
    {
        set_label_anchor(&percent_label, CENTER_X, 0, 0);
    }

    Label moves_label = {0, 200, 0, 0, moves_text, 35, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&moves_label))
    {
        set_label_anchor(&moves_label, CENTER_X, 0, 0);
    }

    Label square_ratio_label = {0, 250, 0, 0, square_ratio_text, 35, {255, 0, 0, 255}, NULL, NULL, NULL, false, true};
    if (NULL != label_init(&square_ratio_label))
    {
        set_label_anchor(&square_ratio_label, CENTER_X, 0, 0);
    }

    Label back_button_label = {0, 0, 0, 0, "Back", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};
    Label restart_button_label = {0, 0, 0, 0, "Restart", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};
    Label main_menu_button_label = {0, 0, 0, 0, "Main menu", 30, {0, 0, 0, 255}, NULL, NULL, NULL, false, true};

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
        set_button_anchor(&main_menu_button, CENTER, 0, button_height(&back_button)+button_height(&restart_button)+(10 * SCALEY)*2);
    }
    
    Label *labels[] = {&percent_label, &moves_label, &square_ratio_label, &FPS_label};
    Button *buttons[] = {&back_button, &restart_button, &main_menu_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_delta_x, &mouse_delta_y);
        SDL_GetMouseState(&mouse_x, &mouse_y);
        
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
            out = button_update(buttons[i]);
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
            button_render(buttons[i]);
        }

        if (percent >= 100.0)
            label_render(&congrats);
        else
            label_render(&title_label);
        
        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_reset();
    }
    label_list_free(labels, 4);
    button_list_free(buttons, 3);
    return RETURN_TO_MAIN_MENU;
}
