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
        SDL_SetRenderDrawColor(renderer, basic.game_background.r,basic.game_background.g,basic.game_background.b,basic.game_background.a);
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
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                        case SDLK_d:
                            direction[0] = 1;
                            direction[1] = 0;
                            player->remaining_moves = map->width;
                            break;
                        case SDLK_LEFT:
                        case SDLK_q:
                            direction[0] = -1;
                            direction[1] = 0;
                            player->remaining_moves = map->width;
                            break;
                        case SDLK_UP:
                        case SDLK_z:
                            direction[0] = 0;
                            direction[1] = -1;
                            player->remaining_moves = map->height;
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            direction[0] = 0;
                            direction[1] = 1;
                            player->remaining_moves = map->width;
                            break;
                        case SDLK_ESCAPE:
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
                            break;
                        case SDLK_r:
                            restart(mode);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        player_move(direction[0], direction[1], mode);
        map_display(XOFFSET, YOFFSET);
        if (!player->remaining_moves && map_is_filled(map))
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
    map_reset(map, EMPTY_SQUARE);
    switch (mode)
    {
        case DISCOVERY_MODE:
            map_random(map, FAKE_SQUARE);
            break;
        case CONSTRAINT_MODE:
            map_random(map, COLLISION_SQUARE);
            break;
        default:
            break;
    }
    map->map[0][0] = PLAYER_SQUARE;
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
