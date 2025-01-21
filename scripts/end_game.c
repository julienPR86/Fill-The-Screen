#include "../main.h"

int end_game()
{
    printf("moves : %d\n", player->moves);
    printf("fill : %f%%\n", fill_percent(map));

    Button restart_button = {10, 10, 100, 25, 1, "Restart", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &restart};
    Button main_menu_button = {10, 50, 100, 25, 1, "Main menu", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &main_menu};
    
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

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    return RETURN_TO_MAIN_MENU;
}

float fill_percent(Map *map)
{
    int count = 0;
    float result = 0;
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == EMPTY_SQUARE)
            {
                count++;
            }
        }
    }
    result = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
    return result;
}