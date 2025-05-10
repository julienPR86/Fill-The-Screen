#ifndef _UTILS_H_
#define _UTILS_H_

//return the current fps value
int get_fps();
//cap the fps to max_fps
void cap_fps(Uint64 start_time);

//do the mouse events
void mouse_event(SDL_Event event);
//reset mouse events
void mouse_event_reset();
//return the mouse x and y delta
void get_mouse_delta(float *x, float *y);

//return 1 if (x,y) is in button, 0 otherwise
int button_collision(Button *button, int x, int y);
//return 1 if (x,y) is in toogle, 0 otherwise
int toogle_collision(Toogle *toogle, int x, int y);
//return 1 if (x,y) is in slider, 0 otherwise
int slider_collision(Slider *slider, int x, int y);
//return 1 if (x,y) is in slider cursor, 0 otherwise
int slider_cursor_collision(SliderCursor *cursor, int x, int y);

//return the number of digits in number
int get_number_digits(int number);

#endif