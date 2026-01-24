#ifndef BUTTONS_FUNCS_H
#define BUTTONS_FUNCS_H

//Exits current menu and open the main menu
int	game_state_main_menu(void);
//Exit the main menu, means to quit the game
int	game_state_exit_main_menu(void);
//Open game mode selection
int	game_state_mode_selection(void);
//Open game options
int	game_state_options(void);
//Open gameplay menu
int	game_state_game(void);
//Exit the game menu
int	game_state_exit_game(void);
//Open the pause menu
int	game_state_pause_menu(void);
//Open the stats menu
int	game_state_game_stats(void);

//Restart a new game
int	restart_game(void);

//Starts a new game in fill mode
int	fill_mode(void);
//Starts a new game in constraint mode
int	constraint_mode(void);
//Starts a new game in discovery mode
int	discovery_mode(void);
//Starts a new game in free mode
int	free_mode(void);

//Switches to the gameplay panel in options
int	option_open_panel_gameplay(void);
//Switches to the color panel in options
int	option_open_panel_color(void);
//Switches to the video panel in options
int	option_open_panel_video(void);
//Switches to the audio panel in options
int	option_open_panel_audio(void);
//Sets the window to fullscreen mode
int	option_window_fullscreen(void);
//Sets the window to floating mode
int	option_window_floating(void);

#endif