#include "../main.h"

int end_game()
{
    int moves = player->moves;
    float square_ratio = 0;
    if (moves)
        square_ratio = (float)(map->height*map->width-fill_squares(map))/moves;
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
    while (running)
    {
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

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    return RETURN_TO_MAIN_MENU;
}

float fill_percent(Map *map)
{
    int count = fill_squares(map);
    float result = 0;
    result = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
    return result;
}

int fill_squares(Map *map)
{
    int count = 0;
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == EMPTY_SQUARE)
                count++;
        }
    }
    return count;
}