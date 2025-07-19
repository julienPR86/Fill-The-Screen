#include "main.h"

int main()
{
    if (-1 == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return -1;
    }

    if (-1 == game_loop())
    {
        fprintf(stderr, "Failed to start game loop\n");
    }

    exit_full_game();
    printf("exit ok\n");
    return 0;
}

void exit_full_game()
{
    label_free(&FPS_label);
    free(FPS_text);
    FPS_text = NULL;

    free(inlines);
    free(outlines);
    for (int i = 0; i < max_font_size; i++)
    {
        TTF_CloseFont(roboto_regular_fonts[i]);
    }
    free(roboto_regular_fonts);

    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    TTF_Quit();
    SDL_Quit();
    return;
}
