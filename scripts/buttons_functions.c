#include "../main.h"

int game_state_main_menu()
{
    switch (game_state)
    {
        case GAME_STATE_OPTIONS:
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
    debug_log("Opened main menu\n");
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
    debug_log("Opened options\n");
    return 0;
}

int game_state_mode_selection()
{
    game_state = GAME_STATE_MODE_SELECTION;
    debug_log("Opened mode selection\n");
    return 0;
}

int game_state_game()
{
    switch (game_state)
    {
        case GAME_STATE_MODE_SELECTION:
            if (map_init())
            {
                fprintf(stderr, "Could not initialised the map\n");
                return -1;
            }
            if (player_init())
            {
                fprintf(stderr, "Could not initialised the player\n");
                map_free(map);
                free(map);
                map = NULL;
                return -1;
            }
            break;
        
        default:
            break;
    }
    game_state = GAME_STATE_GAME;
    debug_log("Started a game\n");
    return 0;
}

int game_state_exit_game()
{
    game_quit();
    game_state = GAME_STATE_MODE_SELECTION;
    return 0;
}

int game_state_pause_menu()
{
    game_state = GAME_STATE_PAUSE_MENU;
    debug_log("Opened pause menu\n");
    return 0;
}

int game_state_game_stats()
{
    game_stats_data_ui_init();
    game_state = GAME_STATE_GAME_STATS;
    debug_log("Opened game stats\n");
    return 0;
}

int restart_game()
{
    game_state_exit_game();
    game_state_game();
    debug_log("Restarted game\n");
    return 0;
}

int fill_mode()
{
    game_mode = FILL_MODE;
    game_state_game();
    return 0;
}

int discovery_mode()
{
    game_mode = DISCOVERY_MODE;
    game_state_game();
    return 0;
}

int constraint_mode()
{
    game_mode = CONSTRAINT_MODE;
    game_state_game();
    return 0;
}

int free_mode()
{
    game_mode = FREE_MODE;
    game_state_game();
    return 0;
}

int option_open_panel_gameplay()
{
    options_gameplay_panel.active = true;
    options_colors_panel.active = false;
    options_video_panel.active = false;
    options_audio_panel.active = false;
    return 0;
}

int option_open_panel_color()
{
    options_gameplay_panel.active = false;
    options_colors_panel.active = true;
    options_video_panel.active = false;
    options_audio_panel.active = false;
    return 0;
}

int option_open_panel_video()
{
    options_gameplay_panel.active = false;
    options_colors_panel.active = false;
    options_video_panel.active = true;
    options_audio_panel.active = false;
    return 0;
}

int option_open_panel_audio()
{
    options_gameplay_panel.active = false;
    options_colors_panel.active = false;
    options_video_panel.active = false;
    options_audio_panel.active = true;
    return 0;
}

int option_window_fullscreen()
{
    if (true != SDL_SetWindowFullscreen(window, true))
    {
        fprintf(stderr, "Failed to set window to fullscreen : %s\n", SDL_GetError());
        return -1;
    }
    debug_log("Windows set to fullscreen mode\n");
    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
    update_scale();
    return 0;
}

int option_window_floating()
{
    if (true != SDL_SetWindowFullscreen(window, false))
    {
        fprintf(stderr, "Failed to set window to floating : %s\n", SDL_GetError());
        return -1;
    }
    debug_log("Windows set to floating mode\n");
    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
    update_scale();
    return 0;
}