#include "../main.h"

int end_game()
{
    printf("moves : %d\n", player->moves);
    printf("fill : %f%%\n", fill_percent(map));

    Button restart_button = {10,10,100,25,0, SDL_LoadBMP("ressources/buttons/button_restart/button_restart_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_restart/button_restart_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_restart/button_restart_unpressed.bmp"), &restart};
    Button main_menu_button = {10,50,100,25,0, SDL_LoadBMP("ressources/buttons/button_main_menu/button_main_menu_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_main_menu/button_main_menu_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_main_menu/button_main_menu_unpressed.bmp"), &main_menu};
    
    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, current.menu_background.r, current.menu_background.g, current.menu_background.b, current.menu_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_MOUSEBUTTONDOWN == event.type && !mouse_button_pressed)
            {
                mouse_button_pressed = event.button.button;
            }
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                if (event.button.button == mouse_button_pressed)
                {
                    mouse_button_pressed = 0;
                }
            }
        }

        out = button_update(&restart_button);
        switch (out)
        {
            case RETURN_RESTART_GAME:
                return RETURN_RESTART_GAME;
            default:
                break;
        }
        button_render(&restart_button);

        out = button_update(&main_menu_button);
        switch (out)
        {
            case RETURN_TO_MAIN_MENU:
                return RETURN_TO_MAIN_MENU;
            default:
                break;
        }
        button_render(&main_menu_button);

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