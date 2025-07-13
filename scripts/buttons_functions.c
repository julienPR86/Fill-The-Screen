#include "../main.h"

int game_state_main_menu()
{
    game_state = GAME_STATE_MAIN_MENU;
    return 0;
}

int game_state_options()
{
    game_state = GAME_STATE_MODE_SELECTION;
    return 0;
}

int game_state_mode_selection()
{
    game_state = GAME_STATE_MODE_SELECTION;
    return 0;
}

int game_state_game()
{
    game_state = GAME_STATE_GAME;
    return 0;
}

int game_state_pause_menu()
{
    game_state = GAME_STATE_PAUSE_MENU;
    return 0;
}

int game_state_game_stats()
{
    game_state = GAME_STATE_GAME_STATS;
    return 0;
}

int exit_game()
{
    return RETURN_EXIT_FULL_GAME;
}

int fill_mode()
{
    game_mode = FILL_MODE;
    return game();
}

int discovery_mode()
{
    game_mode = DISCOVERY_MODE;
    return game();
}

int constraint_mode()
{
    game_mode = CONSTRAINT_MODE;
    return game();
}

int free_mode()
{
    game_mode = FREE_MODE;
    return game();
}

int back()
{
    return RETURN_TO_GAME;
}

int restart()
{
    return RETURN_RESTART_GAME;
}

int main_menu()
{
    return RETURN_TO_MAIN_MENU;
}

int option_gameplay()
{
    return RETURN_OPTION_GAMEPLAY_PANEL;
}

int option_color_label()
{
    return RETURN_OPTION_COLOR_PANEL;
}

int option_video()
{
    return RETURN_OPTION_VIDEO_PANEL;
}

int option_audio()
{
    return RETURN_OPTION_AUDIO_PANEL;
}

int option_window_fullscreen()
{
    if (true != SDL_SetWindowFullscreen(window, true))
    {
        fprintf(stderr, "Failed to set window to fullscreen : %s\n", SDL_GetError());
        return RETURN_FAILURE;
    }
    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
    update_scale();
    return RETURN_SUCCESS;
}

int option_window_floating()
{
    if (true != SDL_SetWindowFullscreen(window, false))
    {
        fprintf(stderr, "Failed to set window to floating : %s\n", SDL_GetError());
        return RETURN_FAILURE;
    }
    SDL_GetWindowSize(window, &WIDTH, &HEIGHT);
    update_scale();
    return RETURN_SUCCESS;
}