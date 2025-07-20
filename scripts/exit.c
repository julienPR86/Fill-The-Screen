#include "../main.h"

void exit_full_game()
{
    free_FPS_label();

    //free the outlines and inlines list
    free(inlines);
    free(outlines);

    close_font_list(roboto_regular_fonts);

    destroy_window_and_renderer();

    //quit TTF and SDL
    TTF_Quit();
    SDL_Quit();
    return;
}

void free_FPS_label()
{
    label_free(&FPS_label);
    free(FPS_text);
    FPS_text = NULL;
    return;
}

void close_font_list(TTF_Font **list)
{
    for (int i = 0; i < max_font_size; i++)
    {
        TTF_CloseFont(list[i]);
    }
    free(list);
    return;
}

void destroy_window_and_renderer()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    return;
}