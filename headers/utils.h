#ifndef _UTILS_H_
#define _UTILS_H_

int get_fps();
void cap_fps(Uint64 start_time);
void mouse_pressed(SDL_Event event);
void get_mouse_delta(int *x, int *y);
int button_collision(Button *button, int x, int y);
int toogle_collision(Toogle *toogle, int x, int y);
int slider_cursor_collision(SliderCursor *cursor, int x, int y);
int get_number_digits(int number);

#endif