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
    
    int Y_OFFSET, X_OFFSET;
    map_set_offset(&X_OFFSET, &Y_OFFSET);

    int direction[2] = {0,0};

    int running = true, out, end = false, back_to_map = false;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
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
            if (SDL_EVENT_QUIT == event.type)
            {
                game_quit();
                return RETURN_EXIT_FULL_GAME;
            }
            update_window_size(event, window);
            
            if (SDL_EVENT_KEY_DOWN == event.type)
            {
                if (!player->can_move || FREE_MODE == game_mode)
                {
                    switch (event.key.key)
                    {
                        case SDLK_RIGHT:
                        case SDLK_D:
                            direction[0] = 1;
                            direction[1] = 0;
                            player->can_move = true;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_LEFT:
                        case SDLK_Q:
                            direction[0] = RETURN_NONE;
                            direction[1] = 0;
                            player->can_move = true;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_UP:
                        case SDLK_Z:
                            direction[0] = 0;
                            direction[1] = RETURN_NONE;
                            player->can_move = true;
                            player->moves++;
                            player->frame_move = 1;
                            break;
                        case SDLK_DOWN:
                        case SDLK_S:
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
                switch (event.key.key)
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
                    case SDLK_R:
                        game_restart();
                        break;
                    case SDLK_E:
                        end = true;
                        back_to_map = false;
                        break;
                    default:
                        break;
                }
            }
        }
        player_move(direction[0], direction[1]);
        map_set_offset(&X_OFFSET, &Y_OFFSET);
        map->square_size = map_get_square_size(WIDTH, HEIGHT, map->width, map->height);
        map_display(map, X_OFFSET, Y_OFFSET);
        if (((!player->can_move && map_is_filled(map)) || end) && !back_to_map)
        {
            end = false;
            out = game_stats();
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
            label_update(labels[i], SCALE_X, SCALE_Y);
            label_render(labels[i], SCALE_X, SCALE_Y);
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
