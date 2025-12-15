#ifndef BUTTONS_FUNCS_H
#define BUTTONS_FUNCS_H

//Exits current menu and open the main menu
int game_state_main_menu();
//Exit the main menu, means to quit the game
int game_state_exit_main_menu();
//Open game mode selection
int game_state_mode_selection();
//Open game options
int game_state_options();
//Open gameplay menu
int game_state_game();
//Exit the game menu
int game_state_exit_game();
//Open the pause menu
int game_state_pause_menu();
//Open the stats menu
int game_state_game_stats();

//Restart a new game
int restart_game();

//Starts a new game in fill mode
int fill_mode();
//Starts a new game in constraint mode
int constraint_mode();
//Starts a new game in discovery mode
int discovery_mode();
//Starts a new game in free mode
int free_mode();

//Switches to the gameplay panel in options
int option_open_panel_gameplay();
//Switches to the color panel in options
int option_open_panel_color();
//Switches to the video panel in options
int option_open_panel_video();
//Switches to the audio panel in options
int option_open_panel_audio();
//Sets the window to fullscreen mode
int option_window_fullscreen();
//Sets the window to floating mode
int option_window_floating();

#endif