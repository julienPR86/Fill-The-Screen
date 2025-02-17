#include "main.h"

int main(int argc, char **argv)
{
    if (RETURN_FAILURE == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return RETURN_FAILURE;
    }
    Label title_label = {20, 10, 0, 0, 0.3, "Fill The Screen", roboto_regular, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&title_label);
    Label play_button_label = {0, 0, 0, 0, 0.1, "PLAY", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label exit_button_label = {0, 0, 0, 0, 0.1, "Quit", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};

    Button play_button = {10, HEIGHT/2, 150, 50, 1, 0, 0, NORMAL, play_button_label, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, &mode_choice};
    button_init(&play_button);
    Button exit_button = {10, HEIGHT/2+get_button_height(&play_button)+11, 150, 50, 1, 0, 0, NORMAL, exit_button_label, {255,0,0,255}, {255,128,0,255}, {230,0,0,255}, {0,0,0,255}, &exit_game};
    button_init(&exit_button);

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
