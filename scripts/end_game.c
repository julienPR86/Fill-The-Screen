#include "../main.h"

int end_game()
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

    Label title_label = {0, 0, 0, 0, 0.3, "Game over", roboto_regular, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&title_label);
    set_label_anchor(&title_label, CENTER_X, 0, 0);

    Label congrats = {0, 0, 0, 0, 0.3, "Congratulation", roboto_regular, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&congrats);
    set_label_anchor(&congrats, CENTER_X, 0, 0);

    Label percent_label = {0, 150, 0, 0, 0.1, percent_text, roboto_light, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&percent_label);
    set_label_anchor(&percent_label, CENTER_X, 0, 0);

    Label moves_label = {0, 200, 0, 0, 0.1, moves_text, roboto_light, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&moves_label);
    set_label_anchor(&moves_label, CENTER_X, 0, 0);

    Label square_ratio_label = {0, 250, 0, 0, 0.1, square_ratio_text, roboto_light, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&square_ratio_label);
    set_label_anchor(&square_ratio_label, CENTER_X, 0, 0);

    Label restart_button_label = {0, 0, 0, 0, 0.1, "Restart", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label main_menu_button_label = {0, 0, 0, 0, 0.1, "Main menu", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};

    Button restart_button = {0, 0, 150, 50, NORMAL, restart_button_label, basic_button_style, &restart};
    button_init(&restart_button);
    set_button_anchor(&restart_button, CENTER, 0, 0);

    Button main_menu_button = {0, 0, 150, 50, NORMAL, main_menu_button_label, basic_button_style, &main_menu};
    button_init(&main_menu_button);
    set_button_anchor(&main_menu_button, CENTER, 0, button_height(&restart_button)+10*SCALEY);
    
    Label *labels[] = {&percent_label, &moves_label, &square_ratio_label, &FPS_label};
    Button *buttons[] = {&restart_button, &main_menu_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current.main_colors.end_game_background.r, current.main_colors.end_game_background.g, current.main_colors.end_game_background.b, current.main_colors.end_game_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                label_list_free(labels, 4);
                return RETURN_EXIT_FULL_GAME;
            }
            mouse_pressed(event);
        }

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_RESTART_GAME:
                    label_list_free(labels, 4);
                    return RETURN_RESTART_GAME;
                case RETURN_TO_MAIN_MENU:
                    label_list_free(labels, 4);
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
        
        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    label_list_free(labels, 4);
    return RETURN_TO_MAIN_MENU;
}
