#include "../main.h"

int options()
{
    Label gameplay_toogle_label = {0, 0, 0, 0, 0.12, "Gameplay", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label toogle_label = {0, 0, 0, 0, 0.12, "label", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label video_toogle_label = {0, 0, 0, 0, 0.12, "Video", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label audio_toogle_label = {0, 0, 0, 0, 0.12, "Audio", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};

    Toogle gameplay_toogle = {0, 0, WIDTH/4, HEIGHT/10, NORMAL, &gameplay_toogle_label, &current_toogle_style, &option_gameplay, true};
    toogle_init(&gameplay_toogle);
    Toogle toogle = {toogle_width(&gameplay_toogle), 0, WIDTH/4, HEIGHT/10, NORMAL, &toogle_label, &current_toogle_style, &option_label, true};
    toogle_init(&toogle);
    Toogle video_toogle = {toogle.x + toogle_width(&toogle), 0, WIDTH/4, HEIGHT/10, NORMAL, &video_toogle_label, &current_toogle_style, &option_video, true};
    toogle_init(&video_toogle);
    Toogle audio_toogle = {video_toogle.x + toogle_width(&video_toogle), 0, WIDTH/4, HEIGHT/10, NORMAL, &audio_toogle_label, &current_toogle_style, &option_audio, true};
    toogle_init(&audio_toogle);

    ToogleGroup options_group = {NULL, 4, 0, true};
    group_init(&options_group);
    group_set_toogle_at_index(&options_group, &gameplay_toogle, 0);
    group_set_toogle_at_index(&options_group, &toogle, 1);
    group_set_toogle_at_index(&options_group, &video_toogle, 2);
    group_set_toogle_at_index(&options_group, &audio_toogle, 3);

    Panel gameplay_panel = {NULL, 0, NULL, 0, NULL, 0, true};
    panel_init(&gameplay_panel);
    Panel panel = {NULL, 0, NULL, 0, NULL, 0, false};
    panel_init(&panel);
    Panel video_panel = {NULL, 0, NULL, 0, NULL, 0, false};
    panel_init(&video_panel);
    Panel audio_panel = {NULL, 0, NULL, 0, NULL, 0, false};
    panel_init(&audio_panel);

    Label *labels[] = {&FPS_label};
    Panel *panels[] = {&gameplay_panel, &panel, &video_panel, &audio_panel};

    int running = true, out;
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
                panel_free(&panel);
                group_free(&options_group);
                label_list_free(labels, 1);
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

        for (int i = 0; i < (int)(sizeof(panels)/sizeof(panels[0])); i++)
        {
            panels[i]->active = false;
        }
        out = group_update(&options_group);
        switch (out)
        {
            case RETURN_OPTION_GAMEPLAY_PANEL:
                gameplay_panel.active = true;
                break;
            case RETURN_OPTION_PANEL:
                panel.active = true;
                break;
            case RETURN_OPTION_VIDEO_PANEL:
                video_panel.active = true;
                break;
            case RETURN_OPTION_AUDIO_PANEL:
                audio_panel.active = true;
                break;
            default:
                break;
        }
        group_render(&options_group);

        for (int i = 0; i < (int)(sizeof(panels)/sizeof(panels[0])); i++)
        {
            out = panel_update(panels[i]);
            panel_render(panels[i]);
        }

        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
    }
    panel_free(&panel);
    group_free(&options_group);
    label_list_free(labels, 1);
    return RETURN_TO_MAIN_MENU;
}