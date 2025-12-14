#ifndef _VARIABLES_H_
#define _VARIABLES_H_

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

//Basic window width, 1080
extern const int WINDOW_WIDTH;
//Basic window height, 720
extern const int WINDOW_HEIGHT;

//window width
extern int WIDTH;
//window height
extern int HEIGHT;

//Scale on X axis
extern float SCALE_X;
//Scale on y axis
extern float SCALE_Y;

extern MouseState mouse_state;

//contains the current fps number
extern int FPS;
//contains the max fps value
extern int MAX_FPS;
//contains the current delta time
extern double delta_time;

//SDL window
extern SDL_Window *window;
//SDL renderer
extern SDL_Renderer *renderer;
//SDL event container
extern SDL_Event event;

extern int game_state;

//contains the fps value in string
extern char *FPS_text;
//fps label to display fps value
extern Label FPS_label;

#endif