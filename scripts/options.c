#include "../main.h"

int options()
{
    Label *labels[] = {&FPS_label};

    int running = true;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current_theme.main_colors.options_background.r,current_theme.main_colors.options_background.g,current_theme.main_colors.options_background.b,current_theme.main_colors.options_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
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
    return RETURN_TO_MAIN_MENU;
}