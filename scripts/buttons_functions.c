#include "../main.h"

int game_state_main_menu()
{
    switch (game_state)
    {
        case GAME_STATE_OPTIONS:
            theme.game_colors.fake_square_color = theme.game_colors.empty_square_color;
            break;
        case GAME_STATE_GAME:
            game_state_exit_game();
            break;
        case GAME_STATE_PAUSE_MENU:
            game_state_exit_game();
            break;
        case GAME_STATE_GAME_STATS:
            game_state_exit_game();
            break;
        case GAME_STATE_MODE_SELECTION:
            break;
        default:
            break;
    }
    game_mode = NO_ACTIVE_MODE;
    game_state = GAME_STATE_MAIN_MENU;
    debug_log("Main menu opened.");
    return 0;
}

int game_state_exit_main_menu()
{
    game_state = GAME_STATE_EXIT_GAME;
    return 0;
}

int game_state_options()
{
    game_state = GAME_STATE_OPTIONS;
    debug_log("Options menu opened.");
    return 0;
}

int game_state_mode_selection()
{
    game_state = GAME_STATE_MODE_SELECTION;
    debug_log("Mode selection menu opened.");
    return 0;
}

int game_state_game()
{
    switch (game_state)
    {
		case GAME_STATE_NEW_GAME:
			if (map_init())
            {
                error_log("Could not initialised the map.");
                return -1;
            }
            if (player_init())
            {
                error_log("Could not initialised the player.");
                map_free(map);
                free(map);
                map = NULL;
                return -1;
            }
			debug_log("New game started.");
			break;
        default:
        	break;
    }
    game_state = GAME_STATE_GAME;
    return 0;
}

int game_state_exit_game()
{
    game_quit();
	game_stats_data_ui_free();
    game_state = GAME_STATE_MAIN_MENU;
    return 0;
}

int game_state_pause_menu()
{
    game_state = GAME_STATE_PAUSE_MENU;
    debug_log("Pause menu opened.");
    return 0;
}

int game_state_game_stats()
{
    game_stats_data_ui_init();
    game_state = GAME_STATE_GAME_STATS;
    debug_log("Game stats menu opened.");
    return 0;
}

int restart_game()
{
    debug_log("Restarted a new game.");
    game_state_exit_game();
	game_state = GAME_STATE_NEW_GAME;
    game_state_game();
    return 0;
}

int fill_mode()
{
    game_mode = FILL_MODE;
	game_state = GAME_STATE_NEW_GAME;
    debug_log("Game mode set to fill mode.");
    game_state_game();
    return 0;
}

int discovery_mode()
{
    game_mode = DISCOVERY_MODE;
	game_state = GAME_STATE_NEW_GAME;
    debug_log("Game mode set to discovery mode.");
    game_state_game();
    return 0;
}

int constraint_mode()
{
    game_mode = CONSTRAINT_MODE;
	game_state = GAME_STATE_NEW_GAME;
    debug_log("Game mode set to constraint mode.");
    game_state_game();
    return 0;
}

int free_mode()
{
    game_mode = FREE_MODE;
	game_state = GAME_STATE_NEW_GAME;
    debug_log("Game mode set to free mode.");
    game_state_game();
    return 0;
}

int option_open_panel_gameplay()
{
    options_gameplay_panel.active = true;
    options_colors_panel.active = false;
    options_video_panel.active = false;
    options_audio_panel.active = false;
    debug_log("Switched to gameplay panel.");
    return 0;
}

int option_open_panel_color()
{
    options_gameplay_panel.active = false;
    options_colors_panel.active = true;
    options_video_panel.active = false;
    options_audio_panel.active = false;
    debug_log("Switched to color panel.");
    return 0;
}

int option_open_panel_video()
{
    options_gameplay_panel.active = false;
    options_colors_panel.active = false;
    options_video_panel.active = true;
    options_audio_panel.active = false;
    debug_log("Switched to video panel.");
    return 0;
}

int option_open_panel_audio()
{
    options_gameplay_panel.active = false;
    options_colors_panel.active = false;
    options_video_panel.active = false;
    options_audio_panel.active = true;
    debug_log("Switched to audio panel.");
    return 0;
}

int option_window_fullscreen()
{
    if (true != SDL_SetWindowFullscreen(window, true))
    {
        error_log("Failed to set window to fullscreen mode : %s.", SDL_GetError());
        return -1;
    }
    debug_log("Windows set to fullscreen mode.");
    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
    update_scale();
    return 0;
}

int option_window_floating()
{
    if (true != SDL_SetWindowFullscreen(window, false))
    {
        error_log("Failed to set window to floating mode : %s.", SDL_GetError());
        return -1;
    }
    debug_log("Windows set to floating mode.");
    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
    update_scale();
    return 0;
}