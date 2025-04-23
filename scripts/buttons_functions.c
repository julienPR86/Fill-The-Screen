#include "../main.h"
//quit button in main
int exit_game()
{
    return RETURN_EXIT_FULL_GAME;
}

//buttons in game mode
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

//buttons in pause menu + end game menu
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

//Toogles in option menu
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
