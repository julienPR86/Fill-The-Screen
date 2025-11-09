#include "../main.h"

void exit_full_game()
{
    animation_manager_destroy(&animation_manager);

	main_menu_data_ui_free();
	options_data_ui_free();
	game_mode_data_ui_free();
	pause_menu_data_ui_free();

    free_FPS_label();

    //free the outlines and inlines list
    free(inlines);
    free(outlines);

    close_font_list(roboto_regular_fonts, max_font_size);

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

void close_font_list(TTF_Font **list, int count)
{
    for (int i = 0; i < count; i++)
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