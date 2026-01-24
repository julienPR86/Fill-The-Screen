#ifndef VARIABLES_H
#define VARIABLES_H

enum GameState
{
    GAME_STATE_NONE,
    GAME_STATE_MAIN_MENU,
    GAME_STATE_OPTIONS,
    GAME_STATE_MODE_SELECTION,
    GAME_STATE_GAME,
	GAME_STATE_NEW_GAME,
    GAME_STATE_PAUSE_MENU,
    GAME_STATE_GAME_STATS,
    GAME_STATE_EXIT_GAME,
};

//Initial window width, 1080
extern const int WINDOW_WIDTH;
//Initial window height, 720
extern const int WINDOW_HEIGHT;

//Current window width
extern int WIDTH;
//Current window height
extern int HEIGHT;

//Global scale on X axis
extern float SCALE_X;
//Global scale on y axis
extern float SCALE_Y;

extern MouseState mouse_state;

//Contains the current fps number
extern int FPS;
//Contains the max fps value
extern int MAX_FPS;
//Contains the delta time
extern double delta_time;

//SDL window
extern SDL_Window *window;
//SDL renderer
extern SDL_Renderer *renderer;
//SDL event container
extern SDL_Event event;

//The game state, used to changes dynamicly menus
extern int game_state;

//Contains the fps label text
extern char *FPS_text;
//The fps label used to display current fps
extern Label FPS_label;

#endif