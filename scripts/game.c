#include "../main.h"

int game()
{
    if (map_init())
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
    Label labels[] = {FPS_label};
    
    int YOFFSET = HEIGHT/2 - (map->height*map->square_size)/2;
    int XOFFSET = WIDTH/2 - (map->width*map->square_size)/2;

    int direction[2] = {0,0};

    int running = true, out, end = false;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();

        SDL_SetRenderDrawColor(renderer, current.main_colors.game_background.r,current.main_colors.game_background.g,current.main_colors.game_background.b,current.main_colors.game_background.a);
        SDL_RenderClear(renderer);//background

        if (!player->remaining_moves)
        {
            direction[0] = 0;
            direction[1] = 0;
        }
        player->frame_move = 0;
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                game_quit();
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (!player->remaining_moves || FREE_MODE == game_mode)
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                        case SDLK_d:
                            direction[0] = 1;
                            direction[1] = 0;
                            player->remaining_moves = map->width/delta_time * game_speed;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_LEFT:
                        case SDLK_q:
                            direction[0] = -1;
                            direction[1] = 0;
                            player->remaining_moves = map->width/delta_time * game_speed;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_UP:
                        case SDLK_z:
                            direction[0] = 0;
                            direction[1] = -1;
                            player->remaining_moves = map->height/delta_time * game_speed;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            direction[0] = 0;
                            direction[1] = 1;
                            player->remaining_moves = map->width/delta_time * game_speed;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        default:
                            break;
                    }
                }
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        out = pause_menu();
                        switch (out)
                        {
                            case RETURN_ZERO:
                                break;
                            case RETURN_TO_GAME:
                                break;
                            case RETURN_RESTART_GAME:
                                game_restart();
                                break;
                            case RETURN_TO_MAIN_MENU:
                                game_quit();
                                return RETURN_TO_MAIN_MENU;
                            case RETURN_EXIT_FULL_GAME:
                                game_quit();
                                return RETURN_EXIT_FULL_GAME;
                            default:
                                break;
                        }
                        break;
                    case SDLK_r:
                        game_restart();
                        break;
                    case SDLK_e:
                        end = 1;
                        break;
                    default:
                        break;
                }
            }
        }
        player_move(direction[0], direction[1]);
        map_display(XOFFSET, YOFFSET);
        if (!player->remaining_moves && map_is_filled(map) || end)
        {
            end = false;
            out = end_game();
            switch (out)
            {
                case RETURN_ZERO:
                    break;
                case RETURN_RESTART_GAME:
                    game_restart();
                    break;
                case RETURN_TO_MAIN_MENU:
                    game_quit();
                    return RETURN_TO_MAIN_MENU;
                case RETURN_EXIT_FULL_GAME:
                    game_quit();
                    return RETURN_EXIT_FULL_GAME;
                default:
                    break;
            }
        }
        
        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_render(&labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    game_quit();
    return RETURN_TO_MAIN_MENU;
}

int game_restart()
{
    map_reset(map, EMPTY_SQUARE);
    switch (game_mode)
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

int game_quit()
{
    free(player);
    player = NULL;
    printf("free player ok\n");
    map_free(map);
    free(map);
    map = NULL;
    printf("free map ok\n");
    game_mode = NO_ACTIVE_MODE;
    return RETURN_ZERO;
}
