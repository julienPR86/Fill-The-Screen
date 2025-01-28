#include "../main.h"

int end_game()
{
    int moves = player->moves;
    float square_ratio = 0;
    if (moves)
    {
        if (CONSTRAINT_MODE == game_mode)
            square_ratio = (float)(map->height*map->width-(map_get_squares_number(map, EMPTY_SQUARE)+map_get_squares_number(map, COLLISION_SQUARE)))/moves;
        else
            square_ratio = (float)(map->height*map->width-map_get_squares_number(map, EMPTY_SQUARE))/moves;
    }
    float percent = fill_percent(map);

    char percent_text[50];
    snprintf(percent_text, sizeof(percent_text), "You filled %.2f%% of the map", percent);
    char moves_text[50];
    snprintf(moves_text, sizeof(moves_text), "You made %d moves", moves);
    char square_ratio_text[50];
    snprintf(square_ratio_text, sizeof(square_ratio_text), "Your average filled squares per move is %.2f", square_ratio);

    Label title = {10, 0, 0.3, "Game over", roboto_regular, {255,255,255,255}, {255,40,0,255}};
    Label congrats = {10, 0, 0.3, "Congratulation", roboto_regular, {255,255,255,255}, {255,40,0,255}};
    Label percent_label = {10, 150, 0.1, percent_text, roboto_light, {255,255,255,255}, {255,40,0,255}};
    Label moves_label = {10, 200, 0.1, moves_text, roboto_light, {255,255,255,255}, {255,40,0,255}};
    Label square_ratio_label = {10, 250, 0.1, square_ratio_text, roboto_light, {255,255,255,255}, {255,40,0,255}};
    
    Button restart_button = {10, HEIGHT/2, 150, 50, 1, 0, 0, false, false, NORMAL, "Restart", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &restart};
    Button main_menu_button = {10, HEIGHT/2+66, 150, 50, 1, 0, 0, false, false, NORMAL, "Main menu", roboto_light, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, {0,0,0,255}, &main_menu};
    
    Label labels[] = {percent_label, moves_label, square_ratio_label};
    Button buttons[] = {restart_button, main_menu_button};

    int running = true, out;
    Uint64 last_time = SDL_GetTicks64();
    while (running)
    {
        delta_time = (SDL_GetTicks64() - last_time) * 0.001;
        last_time = SDL_GetTicks64();
        
        SDL_SetRenderDrawColor(renderer, current.main_colors.end_game_background.r, current.main_colors.end_game_background.g, current.main_colors.end_game_background.b, current.main_colors.end_game_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                return RETURN_EXIT_FULL_GAME;
            }
            mouse_pressed(event);
        }

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            out = button_update(&buttons[i]);
            switch (out)
            {
                case RETURN_RESTART_GAME:
                    return RETURN_RESTART_GAME;
                case RETURN_TO_MAIN_MENU:
                    return RETURN_TO_MAIN_MENU;
                default:
                    break;
            }
            button_render(&buttons[i]);
        }

        if (percent >= 100.0)
            label_render(&congrats);
        else
            label_render(&title);
        
        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_render(&labels[i]);
        }

        SDL_RenderPresent(renderer);
    }
    return RETURN_TO_MAIN_MENU;
}

float fill_percent(Map *map)
{
    int count = map_get_squares_number(map, EMPTY_SQUARE)+map_get_squares_number(map, COLLISION_SQUARE);
    float result = 0;
    result = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
    return result;
}