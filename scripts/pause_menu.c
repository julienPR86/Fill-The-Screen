#include "../main.h"

int pause_menu()
{
    Label title_label = {0, 0, 0, 0, 0.3, "Game Paused", roboto_regular, {255,255,255,255}, {255,40,0,255}, NULL, NULL, false};
    label_init(&title_label);
    set_label_anchor(&title_label, CENTER_X, 0, 0);

    Label back_button_label = {0, 0, 0, 0, 0.1, "Back", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label restart_button_label = {0, 0, 0, 0, 0.1, "Restart", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};
    Label main_menu_button_label = {0, 0, 0, 0, 0.1, "Main menu", roboto_light, {0,0,0,0}, {0,0,0,255}, NULL, NULL, false};

    Button back_button = {CENTERED(WIDTH, 150*SCALEX), CENTERED(HEIGHT, 50*SCALEY), 150, 50, NORMAL, back_button_label, basic_button_style, &back};
    button_init(&back_button);
    Button restart_button = {CENTERED(WIDTH, 150*SCALEX), back_button.y+button_height(&back_button)+10*SCALEY, 150, 50, NORMAL, restart_button_label, basic_button_style, &restart};
    button_init(&restart_button);
    Button main_menu_button = {CENTERED(WIDTH, 150*SCALEX), restart_button.y+button_height(&restart_button)+10*SCALEY, 150, 50, NORMAL, main_menu_button_label, basic_button_style, &main_menu};
    button_init(&main_menu_button);

    Label *labels[] = {&title_label, &FPS_label};
    Button *buttons[] = {&back_button, &restart_button, &main_menu_button};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();
        
        SDL_SetRenderDrawColor(renderer, current.main_colors.pause_menu_background.r,current.main_colors.pause_menu_background.g,current.main_colors.pause_menu_background.b,current.main_colors.pause_menu_background.a);
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
                    break;
                }
            }
            mouse_pressed(event);
        }

        for (int i = 0; i < sizeof(buttons)/sizeof(buttons[0]); i++)
        {
            out = button_update(buttons[i]);
            switch (out)
            {
                case RETURN_TO_GAME:
                    label_list_free(labels, 2);
                    return RETURN_TO_GAME;
                case RETURN_RESTART_GAME:
                    label_list_free(labels, 2);
                    return RETURN_RESTART_GAME;
                case RETURN_TO_MAIN_MENU:
                    label_list_free(labels, 2);
                    return RETURN_TO_MAIN_MENU;
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
    return RETURN_ZERO;
}
