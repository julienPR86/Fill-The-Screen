#ifndef _EXIT_H_
#define _EXIT_H_

//function that deallocate the used memory
void exit_full_game();

//destroy the renderer and the window, then set them to NULL
void destroy_window_and_renderer();

//Close all the fonts in list
//list needs to be allocated, it's freed at the end of the function
void close_font_list(TTF_Font **list);

//freed the FPS label, and the FPS text variables, then it's set to NLL
void free_FPS_label();

#endif