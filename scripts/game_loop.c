#include "../main.h"

int game_loop()
{
    main_menu_data_ui_init();
    options_data_ui_init();
    game_mode_data_ui_init();

    game_state = GAME_STATE_MAIN_MENU;

    int Y_OFFSET, X_OFFSET;

    //background color
    Color background = theme.main_colors.menu_background;

    int running = true;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_state.delta_x, &mouse_state.delta_y);
        SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        
        SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_EVENT_QUIT == event.type)
            {
                game_state = GAME_STATE_EXIT_GAME;
                break;
            }
            if (SDL_EVENT_KEY_DOWN == event.type)
            {
                switch (event.key.key)
                {
                    case SDLK_ESCAPE:
                        switch (game_state)
                        {
                            case GAME_STATE_OPTIONS:
                                game_state_main_menu();
                                break;

                            case GAME_STATE_MODE_SELECTION:
                                game_state_main_menu();
                                break;
                            
                            case GAME_STATE_PAUSE_MENU:
                            case GAME_STATE_GAME_STATS:
                                game_state_game();
                                break;

                            case GAME_STATE_GAME:
                                game_state_pause_menu();
                                break;

                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
                if (GAME_STATE_GAME == game_state && (!player->can_move || FREE_MODE == game_mode))
                {
                    switch (event.key.key)
                    {
                        case SDLK_RIGHT:
                        case SDLK_D:
                            player_set_move_direction(1, 0);
                            break;
                        case SDLK_LEFT:
                        case SDLK_Q:
                            player_set_move_direction(-1, 0);
                            break;
                        case SDLK_UP:
                        case SDLK_Z:
                            player_set_move_direction(0, -1);
                            break;
                        case SDLK_DOWN:
                        case SDLK_S:
                            player_set_move_direction(0, 1);
                            break;
                        
                        case SDLK_E:
                            game_state_game_stats();
                            break;
                        default:
                            break;
                    }
                }
            }
            update_window_size(event, window);
            mouse_event(event);
        }

        switch (game_state)
        {
            case GAME_STATE_MAIN_MENU:
                button_list_update_and_render(main_menu_buttons, 3);
                label_list_update_and_render(main_menu_labels, 1);
                break;

            case GAME_STATE_OPTIONS:
                label_list_update_and_render(options_labels, 1);
                group_update(&options_group, SCALE_X, SCALE_Y);
                group_render(&options_group);
                panel_list_update_and_render(options_panels, 4);
                break;

            case GAME_STATE_MODE_SELECTION:
                button_list_update_and_render(mode_selection_buttons, 4);
                label_list_update_and_render(mode_selection_labels, 2);
                break;

            case GAME_STATE_GAME:
                player_move(player);
                map_set_offset(&X_OFFSET, &Y_OFFSET);
                map->square_size = map_get_square_size(WIDTH, HEIGHT, map->width, map->height);
                map_display(map, X_OFFSET, Y_OFFSET);

                if (!player->can_move && map_is_filled(map))
                {
                    game_state = GAME_STATE_GAME_STATS;
                }
                break;

            case GAME_STATE_PAUSE_MENU:
                button_list_update_and_render(pause_menu_buttons, 3);
                label_list_update_and_render(pause_menu_labels, 1);
                break;

            case GAME_STATE_GAME_STATS:
                button_list_update_and_render(game_stats_buttons, 3);
                label_list_update_and_render(game_stats_labels, 4);
                break;

            case GAME_STATE_EXIT_GAME:
                running = false;
                break;

            default:
                break;
        }

        label_update(&FPS_label, SCALE_X, SCALE_Y);
        label_render(&FPS_label, SCALE_X, SCALE_Y);

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    return 0;
}