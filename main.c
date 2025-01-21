#include "main.h"

int main(int argc, char **argv)
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }

    Button play_button = {10, 10, 100, 25, 0, "PLAY", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &mode_choice};
    Button exit_button = {10, 50 ,100, 25, 0, "QUIT", 0, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &exit_main};

    int running = true, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, current.main_colors.menu_background.r,current.main_colors.menu_background.g,current.main_colors.menu_background.b,current.main_colors.menu_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                running = false;
                break;
            }
            mouse_pressed(event);
        }

        out = button_update(&play_button);
        switch (out)
        {
            case RETURN_ZERO:
                break;
            case RETURN_EXIT_FULL_GAME:
                exit_main();
                return RETURN_ZERO;
            case RETURN_TO_MAIN_MENU:
                break;
            default:
                break;
        }
        button_render(&play_button);

        out = button_update(&exit_button);
        switch (out)
        {
            case RETURN_EXIT_FULL_GAME:
                return RETURN_ZERO;
            default:
                break;
        }
        button_render(&exit_button);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    exit_main();
    return RETURN_ZERO;
}

int exit_main()
{
    TTF_CloseFont(font);
    font = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    TTF_Quit();
    SDL_Quit();
    printf("exit ok\n");
    return RETURN_EXIT_FULL_GAME;
}
