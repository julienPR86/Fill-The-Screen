#include "main.h"

int main(int argc, char **argv)
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }
    Label title_label = {0, 0, 0, 0, 0.3, "Fill The Screen", &current_label_style, roboto_regular, NULL, NULL, false};
    if (NULL != label_init(&title_label))
    {
        set_label_anchor(&title_label, CENTER_X, 0, 10);
    }

    Label play_button_label = {0, 0, 0, 0, 0.1, "PLAY", &current_button_label_style, roboto_light, NULL, NULL, false};
    Label exit_button_label = {0, 0, 0, 0, 0.1, "Quit", &current_button_label_style, roboto_light, NULL, NULL, false};

    Button play_button = {0, 0, 150, 50, NORMAL, play_button_label, &current_button_style, &mode_choice};
    if (NULL != button_init(&play_button))
    {
        set_button_anchor(&play_button, CENTER, 0, 0);
    }

    Button exit_button = {0, 0, 150, 50, NORMAL, exit_button_label, &current_button_style, &exit_game};
    if (NULL != button_init(&exit_button))
    {
        set_button_anchor(&exit_button, CENTER, 0, button_height(&play_button)+10 * SCALEY);
    }
    
    Label *labels[] = {&title_label, &FPS_label};
    Button *buttons[] = {&play_button, &exit_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
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
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_ZERO:
                    break;
                case RETURN_TO_MAIN_MENU:
                    break;
                case RETURN_EXIT_FULL_GAME:
                    label_list_free(labels, 2);
                    button_list_free(buttons, 2);
                    exit_full_game();
                    return RETURN_ZERO;
                default:
                    break;
            }
            button_render(buttons[i]);
        }

        for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    label_list_free(labels, 2);
    button_list_free(buttons, 2);
    exit_full_game();
    return RETURN_ZERO;
}

void exit_full_game()
{
    label_free(&FPS_label);
    free(FPS_text);
    FPS_text = NULL;

    TTF_CloseFont(roboto_light);
    roboto_light = NULL;
    TTF_CloseFont(roboto_regular);
    roboto_regular = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    TTF_Quit();
    SDL_Quit();
    printf("exit ok\n");
    return;
}
