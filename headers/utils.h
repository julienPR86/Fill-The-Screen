#ifndef _UTILS_H_
#define _UTILS_H_

enum WindowState
{
    FULLSCREEN,
    FULLSCREEN_BORDERLESS,
    BORDERLESS,
};

enum MouseButtonState
{
    //no buttons are pressed
    MOUSE_STATE_NONE,
    //left mouse button pressed
    MOUSE_STATE_LEFT_CLICK,
    //right mouse button pressed
    MOUSE_STATE_RIGHT_CLICK,
};

typedef struct MouseState
{
    //contains the x mouse position
    float x;
    //contains the y mouse position
    float y;
    //contains the x mouse delta position since the last frame
    float delta_x;
    //contains the y mouse delta position since the last frame
    float delta_y;
    //contains a value which tells which mouse button is pressed
    int button_pressed;
    //contains the last button pressed
    int previous_button_pressed;
    //equals 1 if a different button has been pressed, 0 otherwise
    int frame_input;
    //contains a value between -1 and 1 that tells the wheel rotation value
    int wheel_value;
} MouseState;

//return the current fps value
int get_fps();
//cap the fps to max_fps
void cap_fps(Uint64 start_time);

//do the mouse events
void mouse_event(SDL_Event event);
//reset mouse events
void mouse_event_update();
//return the mouse x and y delta
void get_mouse_delta(float *x, float *y);
//Set the size of the window passed in
int set_window_size(SDL_Window *window, int w, int h);
//Update the size of the window passed in, if the window is being resized
void update_window_size(SDL_Event event, SDL_Window *window);
//Update the SCALE on X and Y axis, return the min value between them
void update_scale();

//return the number of digits in number
int get_number_digits(int number);
//do a linear interpolation between a and b based on the factor passed in
double lerpf(double a, double b, double factor);
//round a double to n number after the comma
double round_to(double number, int n);

//Prints a debug log in the stdout if DEBUG_LOGS is defined
void	debug_log(char *log, ...);
//Prints an error message in the stderr if ERROR_LOGS is defined
void	error_log(char *msg, ...);

#endif