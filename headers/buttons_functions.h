#ifndef _BUTTONS_FUNCS_H_
#define _BUTTONS_FUNCS_H_

//go to main menu
int game_state_main_menu();
//exit the main menu, equals to exit the full game
int game_state_exit_main_menu();
//go to mode selection menu
int game_state_mode_selection();
//go to options menu
int game_state_options();
//go to gameplay menu
int game_state_game();
//exit the current game
int game_state_exit_game();
//go to pause menu
int game_state_pause_menu();
//go to game stats menu
int game_state_game_stats();

//function to restart the current game
int restart_game();

//button function which tells to launch a game in fill mode
int fill_mode();
//button function which tells to launch a game in constraint mode
int constraint_mode();
//button function which tells to launch a game in discovery mode
int discovery_mode();
//button function which tells to launch a game in free mode
int free_mode();

//button function which tells to active the gameplay panel in the options
int option_open_panel_gameplay();
//button function which tells to active the color panel in the options
int option_open_panel_color();
//button function which tells to active the video panel in the options
int option_open_panel_video();
//button function which tells to active the audio panel in the options
int option_open_panel_audio();
//toggle function to set the window to fullscreen mode
int option_window_fullscreen();
//toggle function to set the window to floating mode
int option_window_floating();

#endif