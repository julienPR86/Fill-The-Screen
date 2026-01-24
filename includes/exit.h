#ifndef EXIT_H
#define EXIT_H

//Destroys all allocated ressources
void exit_full_game();

//Destroys the renderer and the window
void destroy_window_and_renderer();

//Close all the opened fonts in list and frees the list itself
void close_font_list(TTF_Font **list, int count);

//Frees FPS label and FPS text
void free_FPS_label();

#endif