#include "../main.h"

int options()
{
    options_data_ui_init();
    // colors panel --------------------------------------------------------------------------

    

    // Video panel --------------------------------------------------------------------

    Label fullscreen_toggle_label = {EMPTY_UI_ELEMENT, "Fullscreen", 30, DARK, NULL, NULL, false, 1.0, true};
    Label floating_toggle_label = {EMPTY_UI_ELEMENT, "Floating", 30, DARK, NULL, NULL, false, 1.0, true};

    Toggle fullscreen_toggle = {{20, 150, 0, 0, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &fullscreen_toggle_label, &toggle_style, &option_window_fullscreen, true};
    toggle_init(&fullscreen_toggle, SCALE_X, SCALE_Y);

    Toggle floating_toggle = {{20, 200, 0, 0, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &floating_toggle_label, &toggle_style, &option_window_floating, true};
    toggle_init(&floating_toggle, SCALE_X, SCALE_Y);

    Toggle *window_state_toggle_list[] = {&floating_toggle, &fullscreen_toggle};
    ToggleGroup window_state_group = {window_state_toggle_list, 2, 0, true};

    Label max_fps_slider_description_label = {{20, 350, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Max FPS", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&max_fps_slider_description_label, SCALE_X, SCALE_Y);

    Label max_fps_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor max_fps_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider max_fps_slider = {{20, max_fps_slider_description_label.rect.y + max_fps_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &MAX_FPS, 0, 60, 240, 1, &max_fps_slider_label, &max_fps_slider_cursor, &slider_style, true};
    slider_init(&max_fps_slider, SCALE_X, SCALE_Y);

    Button *video_button_list[] = {};
    Toggle *video_toggle_list[] = {};
    Slider *video_slider_list[] = {&max_fps_slider};
    ColorPicker *video_picker_list[] = {};
    ToggleGroup *video_group_list[] = {&window_state_group};
    Label *video_label_list[] = {&max_fps_slider_description_label};
    Rect *video_rect_list[] = {};
    Panel video_panel = {video_button_list, 0, video_toggle_list, 0, video_slider_list, 1, video_picker_list, 0, video_group_list, 1, video_label_list, 1, video_rect_list, 0, false};
    panel_init(&video_panel);

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


    Button *audio_button_list[] = {};
    Toggle *audio_toggle_list[] = {};
    Slider *audio_slider_list[] = {&master_audio_slider, &music_audio_slider, &effects_audio_slider};
    ColorPicker *audio_picker_list[] = {};
    ToggleGroup *audio_group_list[] = {};
    Label *audio_label_list[] = {&master_audio_slider_description_label, &music_audio_slider_description_label, &effects_audio_slider_description_label};
    Rect *audio_rect_list[] = {};
    Panel audio_panel = {audio_button_list, 0, audio_toggle_list, 0, audio_slider_list, 3, audio_picker_list, 0, audio_group_list, 0, audio_label_list, 3, audio_rect_list, 0, false};
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
