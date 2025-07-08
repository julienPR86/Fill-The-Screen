#include "../main.h"

int options()
{
    options_data_ui_init();

    // Audio panel --------------------------------------------------------------------

    Label master_audio_slider_description_label = {{20, 150, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Master volume", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&master_audio_slider_description_label, SCALE_X, SCALE_Y);

    Label master_audio_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor master_audio_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider master_audio_slider = {{20, master_audio_slider_description_label.rect.y + master_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, NULL, 0, 0, 200, 1, &master_audio_slider_label, &master_audio_slider_cursor, &slider_style, true};
    slider_init(&master_audio_slider, SCALE_X, SCALE_Y);


    Label music_audio_slider_description_label = {{20, 225, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Music volume", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&music_audio_slider_description_label, SCALE_X, SCALE_Y);

    Label music_audio_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor music_audio_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider music_audio_slider = {{20, music_audio_slider_description_label.rect.y + music_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, NULL, 0, 0, 200, 1, &music_audio_slider_label, &music_audio_slider_cursor, &slider_style, true};
    slider_init(&music_audio_slider, SCALE_X, SCALE_Y);


    Label effects_audio_slider_description_label = {{20, 300, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Effects volume", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&effects_audio_slider_description_label, SCALE_X, SCALE_Y);

    Label effects_audio_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor effects_audio_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider effects_audio_slider = {{20, effects_audio_slider_description_label.rect.y + effects_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, NULL, 0, 0, 200, 1, &effects_audio_slider_label, &effects_audio_slider_cursor, &slider_style, true};
    slider_init(&effects_audio_slider, SCALE_X, SCALE_Y);


    Slider *audio_slider_list[] = {&master_audio_slider, &music_audio_slider, &effects_audio_slider};
    Label *audio_label_list[] = {&master_audio_slider_description_label, &music_audio_slider_description_label, &effects_audio_slider_description_label};
    Panel audio_panel = {NULL, 0, NULL, 0, audio_slider_list, 3, NULL, 0, NULL, 0, audio_label_list, 3, NULL, 0, false};
    panel_init(&audio_panel);

    // panels end ---------------------

    Label *labels[] = {&FPS_label, &back_label};
    Panel *panels[] = {&gameplay_panel, &colors_panel, &video_panel, &audio_panel};

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
                panel_list_free(panels, 4);
                group_free(&options_group);
                label_list_free(labels, 1);
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
                gameplay_panel.active = true;
                colors_panel.active = false;
                video_panel.active = false;
                audio_panel.active = false;
                break;
            case RETURN_OPTION_COLOR_PANEL:
                gameplay_panel.active = false;
                colors_panel.active = true;
                video_panel.active = false;
                audio_panel.active = false;
                break;
            case RETURN_OPTION_VIDEO_PANEL:
                gameplay_panel.active = false;
                colors_panel.active = false;
                video_panel.active = true;
                audio_panel.active = false;
                break;
            case RETURN_OPTION_AUDIO_PANEL:
                gameplay_panel.active = false;
                colors_panel.active = false;
                video_panel.active = false;
                audio_panel.active = true;
                break;
            default:
                break;
        }
        group_render(&options_group);
        for (int i = 0; i < (int)(sizeof(panels)/sizeof(panels[0])); i++)
        {
            out = panel_update(panels[i]);
            switch (out)
            {
                case RETURN_NONE:
                    break;
                
                default:
                    break;
            }
            panel_render(panels[i]);
        }
        for (int i = 0; i < (int)(sizeof(labels)/sizeof(labels[0])); i++)
        {
            label_update(labels[i], SCALE_X, SCALE_Y);
            label_render(labels[i], SCALE_X, SCALE_Y);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    panel_list_free(panels, 4);
    group_free(&options_group);
    label_list_free(labels, 1);
    update_scale();
    set_window_size(window, WIDTH, HEIGHT);
    return RETURN_TO_MAIN_MENU;
}
