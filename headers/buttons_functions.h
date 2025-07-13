#ifndef _BUTTONS_FUNCS_H_
#define _BUTTONS_FUNCS_H_

int game_state_mode_selection();

//button function which tells to exit the game
int exit_game();
//button function which tells to return to game
int back();
//button function which tells to restart the game
int restart();
//button function which tells to return to the main menu
int main_menu();
//button function which tells to launch a game in fill mode
int fill_mode();
//button function which tells to launch a game in constraint mode
int constraint_mode();
//button function which tells to launch a game in discovery mode
int discovery_mode();
//button function which tells to launch a game in free mode
int free_mode();

//button function which tells to active the gameplay panel in the options
int option_gameplay();
//button function which tells to active the color panel in the options
int option_color_label();
//button function which tells to active the video panel in the options
int option_video();
//button function which tells to active the audio panel in the options
int option_audio();
//toggle function to set the window to fullscreen mode
int option_window_fullscreen();
//toggle function to set the window to floating mode
int option_window_floating();

#endif