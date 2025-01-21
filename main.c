#include "main.h"

int main(int argc, char **argv)
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }

    Label title = {500, 100, 500, 100, 0, "Fill The Screen", roboto_regular, {255,255,255,255}, {255,40,0,255}, {0,0,0,255}};

    Button play_button = {10, 10, 100, 25, 1, "PLAY", 0, roboto_light, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &mode_choice};
    Button exit_button = {10, 50 ,100, 25, 1, "QUIT", 0, roboto_light, {255,0,0,255}, {255,128,0,255}, {0,0,0,255}, {0,0,0,255}, &exit_game};

    Button buttons[] = {play_button, exit_button};

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

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            out = button_update(&buttons[i]);
            switch (out)
            {
                case RETURN_ZERO:
                    break;
                case RETURN_TO_MAIN_MENU:
                    break;
                case RETURN_EXIT_FULL_GAME:
                    exit_full_game();
                    return RETURN_ZERO;
                default:
                    break;
            }
            button_render(&buttons[i]);
        }

        label_render(&title);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    exit_full_game();
    return RETURN_ZERO;
}

void exit_full_game()
{
    TTF_CloseFont(roboto_regular);
    roboto_regular = NULL;
    TTF_CloseFont(roboto_light);
    roboto_light = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    TTF_Quit();
    SDL_Quit();
    printf("exit ok\n");
    return;
}
