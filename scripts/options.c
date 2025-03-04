#include "../main.h"

int options()
{
    Label options_label = {0, 0, 0, 0, 0.3, "Options", roboto_regular, {255, 0, 0, 255}, NULL, NULL, false, false};
    if (NULL != label_init(&options_label))
    {
        set_label_anchor(&options_label, CENTER_X, 0, 10);
    }

    Label *labels[] = {&options_label, &FPS_label};
    // Button *buttons[] = {&toogle};

    int running = true;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current_theme.main_colors.options_background.r, current_theme.main_colors.options_background.g, current_theme.main_colors.options_background.b, current_theme.main_colors.options_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                label_list_free(labels, 2);
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.keysym.sym)
                {
                    running = false;
                }
            }
            mouse_pressed(event);
        }

        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    label_list_free(labels, 2);
    return RETURN_TO_MAIN_MENU;
}