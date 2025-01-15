#include "../main.h"

int game(int mode)
{
    if (map_init(mode))
    {
        fprintf(stderr, "Could not initialised the map\n");
        return RETURN_FAILURE;
    }
    if (player_init())
    {
        fprintf(stderr, "Could not initialised the player\n");
        map_free(map);
        free(map);
        map = NULL;
        return RETURN_FAILURE;
    }
    
    int YOFFSET = HEIGHT/2 - (map->height*map->square_size)/2;
    int XOFFSET = WIDTH/2 - (map->width*map->square_size)/2;

    int direction[2] = {0,0};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);//background

        if (!player->remaining_moves)
        {
            direction[0] = 0;
            direction[1] = 0;
        }
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                quit_game();
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (!player->remaining_moves || FREE_MODE == mode)
                {
                    if (SDLK_d == event.key.keysym.sym)
                    {
                        direction[0] = 1;
                        direction[1] = 0;
                        player->remaining_moves = map->width;
                    }
                    if (SDLK_q == event.key.keysym.sym)
                    {
                        direction[0] = -1;
                        direction[1] = 0;
                        player->remaining_moves = map->width;
                    }
                    if (SDLK_z == event.key.keysym.sym)
                    {
                        direction[0] = 0;
                        direction[1] = -1;
                        player->remaining_moves = map->height;
                    }
                    if (SDLK_s == event.key.keysym.sym)
                    {
                        direction[0] = 0;
                        direction[1] = 1;
                        player->remaining_moves = map->height;
                    }
                }
                
                if (SDLK_r == event.key.keysym.sym)
                {
                    restart(mode);
                }

                if (SDLK_ESCAPE == event.key.keysym.sym)
                {
                    out = pause_menu();
                    switch (out)
                    {
                        case RETURN_ZERO:
                            break;
                        case RETURN_TO_GAME:
                            break;
                        case RETURN_RESTART_GAME:
                            restart(mode);
                            break;
                        case RETURN_TO_MAIN_MENU:
                            quit_game();
                            return RETURN_TO_MAIN_MENU;
                        case RETURN_EXIT_FULL_GAME:
                            quit_game();
                            return RETURN_EXIT_FULL_GAME;
                        default:
                            break;
                    }
                }
            }
        }
        player_move(direction[0], direction[1], mode);
        map_display(XOFFSET, YOFFSET);
        if (map_is_filled(map))
        {
            restart(mode);
        }
        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    quit_game();
    return RETURN_TO_MAIN_MENU;
}

int restart(int mode)
{
    map_reset(map, 1);
    switch (mode)
    {
        case DISCOVERY_MODE:
            map_random(map, 4);
            break;
        case CONSTRAINT_MODE:
            map_random(map, 0);
            break;
        default:
            break;
    }
    map->map[0][0] = 3;
    player_reset(player);
    return RETURN_ZERO;
}

int quit_game()
{
    free(player);
    player = NULL;
    printf("free player ok\n");
    map_free(map);
    free(map);
    map = NULL;
    printf("free map ok\n");
    return RETURN_ZERO;
}
