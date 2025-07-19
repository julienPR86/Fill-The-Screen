#include "../main.h"

void exit_full_game()
{
    //free the FPS label
    label_free(&FPS_label);
    free(FPS_text);
    FPS_text = NULL;

    //free the outlines and inlines list
    free(inlines);
    free(outlines);

    //Close all the fonts
    for (int i = 0; i < max_font_size; i++)
    {
        TTF_CloseFont(roboto_regular_fonts[i]);
    }
    //free the fonts list
    free(roboto_regular_fonts);

    //destroy the renderer and the window
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    //quit TTF and SDL
    TTF_Quit();
    SDL_Quit();
    return;
}