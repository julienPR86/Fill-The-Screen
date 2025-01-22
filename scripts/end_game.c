#include "../main.h"

int end_game()
{
    int moves = player->moves;
    int square_ratio = fill_squares(map)/moves;
    float percent = fill_percent(map);

    char percent_text[50];
    snprintf(percent_text, sizeof(percent_text), "You filled %.2f%% of the map", percent);
    char moves_text[50];
    snprintf(moves_text, sizeof(moves_text), "You made %d moves", moves);
    char square_ration_text[50];
    snprintf(square_ration_text, sizeof(square_ration_text), "You made %d moves", square_ratio);

    Label title = {CENTER(WIDTH, 500), 0, 500, 83, 0, "Game over", roboto_regular, {255,255,255,255}, {255,40,0,255}, {0,0,0,255}};
    Label congrats = {CENTER(WIDTH, 600), 0, 600, 100, 0, "Congratulation", roboto_regular, {255,255,255,255}, {255,40,0,255}, {0,0,0,255}};
    Label percent_label = {CENTER(WIDTH, 400), 200, 400, 50, 0, percent_text, roboto_light, {255,255,255,255}, {255,40,0,255}, {0,0,0,255}};
    Label moves_label = {CENTER(WIDTH, 300), 260, 300, 50, 0, moves_text, roboto_light, {255,255,255,255}, {255,40,0,255}, {0,0,0,255}};
    
    Button restart_button = {CENTER(WIDTH, 150), CENTER(HEIGHT, 50), 150, 50, 1, 10, 2, "Restart", 0, roboto_light, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &restart};
    Button main_menu_button = {CENTER(WIDTH, 150), CENTER(HEIGHT, 50)+66, 150, 50, 1, 10, 2, "Main menu", 0, roboto_light, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &main_menu};
    
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
        
        label_render(&percent_label);
        label_render(&moves_label);

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