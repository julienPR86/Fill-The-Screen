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
    Label *labels[] = {&FPS_label};
    
    int YOFFSET = CENTERED(HEIGHT, (map->height*map->square_size));
    int XOFFSET = CENTERED(WIDTH, (map->width*map->square_size));

    int direction[2] = {0,0};

    int running = true, out, end = false, back_to_map = false;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();

        SDL_SetRenderDrawColor(renderer, theme.main_colors.game_background.r, theme.main_colors.game_background.g, theme.main_colors.game_background.b, theme.main_colors.game_background.a);
        SDL_RenderClear(renderer);//background

        if (!player->can_move && (direction[0] || direction[1]))
        {
            direction[0] = 0;
            direction[1] = 0;
        }
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                game_quit();
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (!player->can_move || FREE_MODE == game_mode)
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                        case SDLK_d:
                            direction[0] = 1;
                            direction[1] = 0;
                            player->can_move = true;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_LEFT:
                        case SDLK_q:
                            direction[0] = RETURN_NONE;
                            direction[1] = 0;
                            player->can_move = true;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_UP:
                        case SDLK_z:
                            direction[0] = 0;
                            direction[1] = RETURN_NONE;
                            player->can_move = true;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            direction[0] = 0;
                            direction[1] = 1;
                            player->can_move = true;
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
                            case RETURN_SUCCESS:
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
                        end = true;
                        back_to_map = false;
                        break;
                    default:
                        break;
                }
            }
        }
        player_move(direction[0], direction[1]);
        map_display(map, XOFFSET, YOFFSET);
        if (((!player->can_move && map_is_filled(map)) || end) && !back_to_map)
        {
            end = false;
            out = end_game();
            switch (out)
            {
                case RETURN_SUCCESS:
                    break;
                case RETURN_TO_GAME:
                    back_to_map = true;
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
        
        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
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
    return RETURN_SUCCESS;
}

int game_quit()
{
    free(player);
    player = NULL;
    map_free(map);
    free(map);
    map = NULL;
    game_mode = NO_ACTIVE_MODE;
    return RETURN_SUCCESS;
}
