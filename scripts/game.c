#include "../main.h"

int	new_game(void)
{
	default_map = map_create();
	if (map_init(default_map))
	{
		error_log("Could not initialised the map.");
		return (-1);
	}
	default_player = player_create();
	if (player_init(default_player))
	{
		error_log("Could not initialised the player.");
		map_free(default_map);
		return (-1);
	}
	debug_log("New game created.");
	return (0);
}

int game_loop()
{
    main_menu_data_ui_init();
    options_data_ui_init();
    game_mode_data_ui_init();
    pause_menu_data_ui_init();

    game_state = GAME_STATE_MAIN_MENU;

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
                switch (game_state)
                {
                    case GAME_STATE_GAME:
					case GAME_STATE_GAME_STATS:
						game_state_exit_game();
						break;
                    default:
                        break;
                }
                game_state = GAME_STATE_EXIT_GAME;
                break;
            }
            if (SDL_EVENT_KEY_DOWN == event.type)
            {
                debug_log("Key %ld pressed.", event.key.key);
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
                if (GAME_STATE_GAME == game_state && (!default_player->can_move || FREE_MODE == game_mode))
                {
                    switch (event.key.key)
                    {
                        case SDLK_RIGHT:
                        case SDLK_D:
                            player_set_move_direction(default_player, 1, 0);
                            break;
                        case SDLK_LEFT:
                        case SDLK_Q:
                            player_set_move_direction(default_player, -1, 0);
                            break;
                        case SDLK_UP:
                        case SDLK_Z:
                            player_set_move_direction(default_player, 0, -1);
                            break;
                        case SDLK_DOWN:
                        case SDLK_S:
                            player_set_move_direction(default_player, 0, 1);
                            break;
                        case SDLK_R:
                            restart_game();
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
                background = theme.main_colors.menu_background;
                button_list_update_and_render(main_menu_buttons, 3);
                label_list_update_and_render(main_menu_labels, 1);
                break;

            case GAME_STATE_OPTIONS:
                background = theme.main_colors.options_background;
                label_list_update_and_render(options_labels, 1);
                group_update(&options_group, SCALE_X, SCALE_Y);
                group_render(&options_group);
                panel_list_update_and_render(options_panels, 4);
                break;

            case GAME_STATE_MODE_SELECTION:
                background = theme.main_colors.game_mode_background;
                button_list_update_and_render(mode_selection_buttons, 4);
                label_list_update_and_render(mode_selection_labels, 2);
                break;

            case GAME_STATE_GAME:
                background = theme.main_colors.game_background;
                player_move(default_player);
                map_set_offset(default_map);
                default_map->square_size = map_get_square_size(WIDTH, HEIGHT, default_map->width, default_map->height);
                map_display(default_map);

                if (!default_player->can_move && map_is_filled(default_map))
					game_state_game_stats();
                break;

            case GAME_STATE_PAUSE_MENU:
                background = theme.main_colors.pause_menu_background;
                button_list_update_and_render(pause_menu_buttons, 3);
                label_list_update_and_render(pause_menu_labels, 1);
                break;

            case GAME_STATE_GAME_STATS:
                background = theme.main_colors.game_stats_background;
                button_list_update_and_render(game_stats_buttons, 3);
                label_list_update_and_render(game_stats_labels, 4);
                break;

            case GAME_STATE_EXIT_GAME:
                running = false;
                break;

            default:
                break;
        }

        animation_manager_update(&animation_manager);

        label_update(&FPS_label, SCALE_X, SCALE_Y);
        label_render(&FPS_label, SCALE_X, SCALE_Y);

        // SDL_RenderLine(renderer, 0, HEIGHT/2, WIDTH, HEIGHT/2);
        // SDL_RenderLine(renderer, WIDTH/2, 0, WIDTH/2, HEIGHT);

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    return 0;
}

int game_quit()
{
    map_destroy(default_map);
	player_destroy(default_player);
    debug_log("Quit current game.");
    return 0;
}
