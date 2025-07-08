#include "../main.h"

int options()
{
    options_data_ui_init();

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks();
        FPS = get_fps();

        get_mouse_delta(&mouse_state.delta_x, &mouse_state.delta_y);
        SDL_GetMouseState(&mouse_state.x, &mouse_state.y);
        
        SDL_SetRenderDrawColor(renderer, theme.main_colors.options_background.r, theme.main_colors.options_background.g, theme.main_colors.options_background.b, theme.main_colors.options_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_EVENT_QUIT == event.type)
            {
                panel_list_free(options_panels, 4);
                group_free(&options_group);
                label_list_free(options_labels, 1);
                return RETURN_EXIT_FULL_GAME;
            }
            if (SDL_EVENT_KEY_DOWN == event.type)
            {
                if (SDLK_ESCAPE == event.key.key)
                {
                    running = false;
                }
            }
            update_window_size(event, window);
            mouse_event(event);
        }

        out = group_update(&options_group, SCALE_X, SCALE_Y);
        switch (out)
        {
            case RETURN_OPTION_GAMEPLAY_PANEL:
                options_gameplay_panel.active = true;
                options_colors_panel.active = false;
                options_video_panel.active = false;
                options_audio_panel.active = false;
                break;
            case RETURN_OPTION_COLOR_PANEL:
                options_gameplay_panel.active = false;
                options_colors_panel.active = true;
                options_video_panel.active = false;
                options_audio_panel.active = false;
                break;
            case RETURN_OPTION_VIDEO_PANEL:
                options_gameplay_panel.active = false;
                options_colors_panel.active = false;
                options_video_panel.active = true;
                options_audio_panel.active = false;
                break;
            case RETURN_OPTION_AUDIO_PANEL:
                options_gameplay_panel.active = false;
                options_colors_panel.active = false;
                options_video_panel.active = false;
                options_audio_panel.active = true;
                break;
            default:
                break;
        }
        group_render(&options_group);
        for (int i = 0; i < (int)(sizeof(options_panels)/sizeof(options_panels[0])); i++)
        {
            out = panel_update(options_panels[i]);
            switch (out)
            {
                case RETURN_NONE:
                    break;
                
                default:
                    break;
            }
            panel_render(options_panels[i]);
        }
        for (int i = 0; i < (int)(sizeof(options_labels)/sizeof(options_labels[0])); i++)
        {
            label_update(options_labels[i], SCALE_X, SCALE_Y);
            label_render(options_labels[i], SCALE_X, SCALE_Y);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    panel_list_free(options_panels, 4);
    group_free(&options_group);
    label_list_free(options_labels, 1);
    update_scale();
    set_window_size(window, WIDTH, HEIGHT);
    return RETURN_TO_MAIN_MENU;
}
