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

//Set the size of element to the size of frame if it's smaller
//!! Do not put a label rect for element, only for frame if necessary !!
//!! Set scale_x and scale_y to 1 except if frame is a label !!
void match_UI_Element_size(UI_Element *element, UI_Element *frame, float scale_x, float scale_y);

//return true if (x, y) is in element, false otherwise
int UI_element_collision(UI_Element *element, int x, int y, float scale_x, float scale_y);
//return 1 if (x,y) is in element, 0 otherwise
void set_UI_element_position(UI_Element *element, int x, int y, float x_position_factor, float y_position_factor, float scale_x, float scale_y, int anchor);

//return the number of digits in number
int get_number_digits(int number);

#endif