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

//return 1 if (x,y) is in element, 0 otherwise
int UI_element_collision(UI_Element *element, int x, int y, float scale);

//return the number of digits in number
int get_number_digits(int number);

#endif