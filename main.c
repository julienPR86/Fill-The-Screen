#include "main.h"

int main(int argc, char **argv)
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }

    Button play_button = {10,10,100,25,0, SDL_LoadBMP("ressources/buttons/button_play/button_play_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_play/button_play_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_play/button_play_unpressed.bmp"), &mode_choice};
    Button exit_button = {10,50,100,25,0, SDL_LoadBMP("ressources/buttons/button_exit/button_exit_unpressed.bmp"), SDL_LoadBMP("ressources/buttons/button_exit/button_exit_pressed.bmp"), SDL_LoadBMP("ressources/buttons/button_exit/button_exit_unpressed.bmp"), &exit_main};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, basic.menu_background.r,basic.menu_background.g,basic.menu_background.b,basic.menu_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                running = 0;
                break;
            }
            if (SDL_MOUSEBUTTONDOWN == event.type && !mouse_button_pressed)
            {
                mouse_button_pressed = event.button.button;
            }
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                if (event.button.button == mouse_button_pressed)
                {
                    mouse_button_pressed = 0;
                }
            }
        }

        out = button_update(&play_button);
        switch (out)
        {
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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("exit ok\n");
    return RETURN_EXIT_FULL_GAME;
}
