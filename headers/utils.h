#ifndef UTILS_H
#define UTILS_H

enum MouseButtonState
{
    //No mouse buttons are pressed
    MOUSE_STATE_NONE,
    //Left mouse button is pressed
    MOUSE_STATE_LEFT_CLICK,
    //Right mouse button is pressed
    MOUSE_STATE_RIGHT_CLICK,
};

//Structure that represent the mouse state
typedef struct MouseState
{
    //Contains the x mouse position
    float x;
    //Contains the y mouse position
    float y;
    //Contains the x mouse delta position since last frame
    float delta_x;
    //Contains the y mouse delta position since last frame
    float delta_y;
    //contains a value which tells which mouse button is pressed
    t_uint8 button_pressed;
    //contains the last button pressed
    t_uint8 previous_button_pressed;
    //equals 1 if a different button has been pressed, 0 otherwise
    t_uint8 frame_input;
    //Contains the mouse wheel input value
    int wheel_value;
} MouseState;

//Returns the current fps value
int get_fps();
//Cap the fps to max_fps
void cap_fps(Uint64 start_time);

//Updates the mouse event
void mouse_event(SDL_Event event);
//Reset the mouse state fields that needs to be reset
void mouse_event_update();
//Returns the mouse x and y delta since last frame
void get_mouse_delta(float *x, float *y);
//Sets the size of the window with the width and height passed in
int set_window_size(SDL_Window *window, int w, int h);
//Updates the size of the window passed in, if the window is being resized
void update_window_size(SDL_Event event, SDL_Window *window);
//Updates the SCALE on X and Y axis, return the min value between them
void update_scale();

//Returns the number of digits in a number
int get_number_digits(int number);
//Do a linear interpolation between a and b based on factor
double lerp(double a, double b, double factor);
//Round a floating point number with a precision of n
double round_to(double number, int n);

//Prints a debug log in the stdout if DEBUG_LOGS is defined
void	debug_log(char *log, ...);
//Prints an error message in the stderr if ERROR_LOGS is defined
void	error_log(char *msg, ...);

#endif