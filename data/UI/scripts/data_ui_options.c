#include "../../../main.h"

Label options_back_label;

Label options_gameplay_toggle_label;
Label options_colors_toggle_label;
Label options_video_toggle_label;
Label options_audio_toggle_label;

Toggle options_gameplay_toggle;
Toggle options_colors_toggle;
Toggle options_video_toggle;
Toggle options_audio_toggle;

Array options_toggles_array;

Toggle *options_toggle_list[4];
ToggleGroup options_group;

//Gameplay panel -------

Label options_probability_slider_description_label;
Label options_probability_slider_label;
SliderCursor options_probability_slider_cursor;
Slider options_probability_slider;

Label options_map_width_slider_description_label;
Label options_map_width_slider_label;
SliderCursor options_map_width_slider_cursor;
Slider options_map_width_slider;

Label options_map_height_slider_description_label;
Label options_map_height_slider_label;
SliderCursor options_map_height_slider_cursor;
Slider options_map_height_slider;

Label options_game_speed_slider_description;
Label options_game_speed_slider_label;
SliderCursor options_game_speed_slider_cursor;
Slider options_game_speed_slider;

Slider *options_gameplay_slider_list[4];
Label *options_gameplay_label_list[4];
Panel options_gameplay_panel;

//Color panel ------------------

Rect options_player_color_rect;

Label options_player_red_slider_title_label;
Label options_player_red_slider_description_label;
Label options_player_green_slider_description_label;
Label options_player_blue_slider_description_label;

Label options_player_red_slider_label;
SliderCursor options_player_red_slider_cursor;
Slider options_player_red_slider;

Label options_player_green_slider_label;
SliderCursor options_player_green_slider_cursor;
Slider options_player_green_slider;

Label options_player_blue_slider_label;
SliderCursor options_player_blue_slider_cursor;
Slider options_player_blue_slider;

Label *options_player_picker_label_list[4];
Slider *options_player_picker_slider_list[3];

ColorPicker options_player_picker;


Rect options_collision_square_color_rect;

Label options_collision_square_red_slider_title_label;
Label options_collision_square_red_slider_description_label;
Label options_collision_square_green_slider_description_label;
Label options_collision_square_blue_slider_description_label;

Label options_collision_square_red_slider_label;
SliderCursor options_collision_square_red_slider_cursor;
Slider options_collision_square_red_slider;

Label options_collision_square_green_slider_label;
SliderCursor options_collision_square_green_slider_cursor;
Slider options_collision_square_green_slider;

Label options_collision_square_blue_slider_label;
SliderCursor options_collision_square_blue_slider_cursor;
Slider options_collision_square_blue_slider;

Label *options_collision_square_picker_label_list[4];
Slider *options_collision_square_picker_slider_list[3];

ColorPicker options_collision_square_picker;


Rect options_line_square_color_rect;

Label options_line_square_slider_title_label;
Label options_line_square_red_slider_description_label;
Label options_line_square_green_slider_description_label;
Label options_line_square_blue_slider_description_label;

Label options_line_square_red_slider_label;
SliderCursor options_line_square_red_slider_cursor;
Slider options_line_square_red_slider;

Label options_line_square_green_slider_label;
SliderCursor options_line_square_green_slider_cursor;
Slider options_line_square_green_slider;

Label options_line_square_blue_slider_label;
SliderCursor options_line_square_blue_slider_cursor;
Slider options_line_square_blue_slider;

Label *options_options_line_square_picker_label_list[4];
Slider *options_options_line_square_picker_slider_list[3];

ColorPicker options_line_square_picker;


Rect options_empty_square_color_rect;
    
Label options_empty_square_slider_title_label;
Label options_empty_square_red_slider_description_label;
Label options_empty_square_green_slider_description_label;
Label options_empty_square_blue_slider_description_label;

Label options_empty_square_red_slider_label;
SliderCursor options_empty_square_red_slider_cursor;
Slider options_empty_square_red_slider;

Label options_empty_square_green_slider_label;
SliderCursor options_empty_square_green_slider_cursor;
Slider options_empty_square_green_slider;

Label options_empty_square_blue_slider_label;
SliderCursor options_empty_square_blue_slider_cursor;
Slider options_empty_square_blue_slider;

Label *options_empty_square_picker_label_list[4];
Slider *options_empty_square_picker_slider_list[3];

ColorPicker options_empty_square_picker;

ColorPicker *options_color_picker_list[4];
Panel options_colors_panel;

//Video panel

Label options_fullscreen_toggle_label;
Label options_floating_toggle_label;

Toggle options_fullscreen_toggle;
Toggle options_floating_toggle;

Toggle *options_window_state_toggle_list[2];
ToggleGroup options_window_state_group;

Label options_max_fps_slider_description_label;

Label options_max_fps_slider_label;
SliderCursor options_max_fps_slider_cursor;
Slider options_max_fps_slider;

Slider *options_video_slider_list[1];
ToggleGroup *options_video_group_list[1];
Label *options_video_label_list[1];
Panel options_video_panel;

//Audio panel

Label options_master_audio_slider_description_label;

Label options_master_audio_slider_label;
SliderCursor options_master_audio_slider_cursor ;
Slider options_master_audio_slider;

Label options_music_audio_slider_description_label;

Label options_music_audio_slider_label;
SliderCursor options_music_audio_slider_cursor ;
Slider options_music_audio_slider;

Label options_effects_audio_slider_description_label;

Label options_effects_audio_slider_label;
SliderCursor options_effects_audio_slider_cursor;
Slider options_effects_audio_slider;

Slider *options_audio_slider_list[3];
Label *options_audio_label_list[3];
Panel options_audio_panel;


Label *options_labels[1];
Panel *options_panels[4];


void options_data_ui_init()
{   
    UI_Element_set_fields(&options_back_label.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT - 10, 0, 0, outlines[0], inlines[0], 1.0, BOTTOM_CENTER);
    label_set_fields(&options_back_label, "Press Escape to go back", 30, RED, false, 1.0, true);
    label_init(&options_back_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_gameplay_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_gameplay_toggle_label, "Gameplay", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_colors_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_colors_toggle_label, "Colors", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_video_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_video_toggle_label, "Video", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_audio_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_audio_toggle_label, "Audio", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_gameplay_toggle.rect, 0, 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], 1.0, NONE);
    toggle_set_fields(&options_gameplay_toggle, NORMAL, &options_gameplay_toggle_label, &toggle_style, &option_open_panel_gameplay, true);
    toggle_init(&options_gameplay_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_colors_toggle.rect, 0, 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], 1.0, NONE);
    toggle_set_fields(&options_colors_toggle, NORMAL, &options_colors_toggle_label, &toggle_style, &option_open_panel_color, true);
    toggle_init(&options_colors_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_video_toggle.rect, 0, 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], 1.0, NONE);
    toggle_set_fields(&options_video_toggle, NORMAL, &options_video_toggle_label, &toggle_style, &option_open_panel_video, true);
    toggle_init(&options_video_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_audio_toggle.rect, 0, 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], 1.0, NONE);
    toggle_set_fields(&options_audio_toggle, NORMAL, &options_audio_toggle_label, &toggle_style, &option_open_panel_audio, true);
    toggle_init(&options_audio_toggle, SCALE_X, SCALE_Y);

    UI_Element *toggles_elements_list[4] = {&options_gameplay_toggle.rect, &options_colors_toggle.rect, &options_video_toggle.rect, &options_audio_toggle.rect};
    UI_Element_set_fields(&options_toggles_array.rect, 0, 0, 0, 0, outlines[1], inlines[0], 1, TOP_LEFT);
    array_set_fields(&options_toggles_array, toggles_elements_list, 4, 4, 0, CENTER);
    array_init(&options_toggles_array);

    options_toggle_list[0] = &options_gameplay_toggle;
    options_toggle_list[1] = &options_colors_toggle;
    options_toggle_list[2] = &options_video_toggle;
    options_toggle_list[3] = &options_audio_toggle;
    group_set_fields(&options_group, options_toggle_list, 4, PANEL_STATE_GAMEPLAY, true);
    group_init(&options_group);


    //Gameplay panel ------------------------------------------------------------

    UI_Element_set_fields(&options_probability_slider_description_label.rect, 20, 150, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_probability_slider_description_label, "Blocks spawn probability", 20, DARK, false, 1.0, true);
    label_init(&options_probability_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_probability_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_probability_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_probability_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_probability_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&options_probability_slider.rect, 20, options_probability_slider_description_label.rect.y + options_probability_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_probability_slider, &probability, 1, 100, 1, &options_probability_slider_label, &options_probability_slider_cursor, &slider_style, true);
    slider_init(&options_probability_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_map_width_slider_description_label.rect, 20, 225, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_map_width_slider_description_label, "Map width", 20, DARK, false, 1.0, true);
    label_init(&options_map_width_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_map_width_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_map_width_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_map_width_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_map_width_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&options_map_width_slider.rect, 20, options_map_width_slider_description_label.rect.y + options_map_width_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_map_width_slider, &map_width, 2, 100, 1, &options_map_width_slider_label, &options_map_width_slider_cursor, &slider_style, true);
    slider_init(&options_map_width_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_map_height_slider_description_label.rect, 20, 300, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_map_height_slider_description_label, "Map height", 20, DARK, false, 1.0, true);
    label_init(&options_map_height_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_map_height_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_map_height_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_map_height_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_map_height_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&options_map_height_slider.rect, 20, options_map_height_slider_description_label.rect.y + options_map_height_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_map_height_slider, &map_height, 2, 100, 1, &options_map_height_slider_label, &options_map_height_slider_cursor, &slider_style, true);
    slider_init(&options_map_height_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_game_speed_slider_description.rect, 20, 375, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_game_speed_slider_description, "Game speed", 20, DARK, false, 1.0, true);
    label_init(&options_game_speed_slider_description, SCALE_X, SCALE_Y);
    
    UI_Element_set_fields(&options_game_speed_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_game_speed_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_game_speed_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_game_speed_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&options_game_speed_slider.rect, 20, options_game_speed_slider_description.rect.y + options_game_speed_slider_description.rect.height, 300, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_game_speed_slider, &game_speed, 1, 300, 1, &options_game_speed_slider_label, &options_game_speed_slider_cursor, &slider_style, true);
    slider_init(&options_game_speed_slider, SCALE_X, SCALE_Y);


    options_gameplay_slider_list[0] = &options_probability_slider;
    options_gameplay_slider_list[1] = &options_map_width_slider;
    options_gameplay_slider_list[2] = &options_map_height_slider;
    options_gameplay_slider_list[3] = &options_game_speed_slider;

    options_gameplay_label_list[0] = &options_probability_slider_description_label;
    options_gameplay_label_list[1] = &options_map_width_slider_description_label;
    options_gameplay_label_list[2] = &options_map_height_slider_description_label;
    options_gameplay_label_list[3] = &options_game_speed_slider_description;

    panel_set_fields(&options_gameplay_panel, NULL, 0, NULL, 0, options_gameplay_slider_list, 4, NULL, 0, NULL, 0, options_gameplay_label_list, 4, NULL, 0, true);
    panel_init(&options_gameplay_panel);


    //Color panel ------------------------------------------------------------

    UI_Element_set_fields(&options_player_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], 1.0, TOP_LEFT);
    rect_set_fields(&options_player_color_rect, &theme.game_colors.player_square_color);

    UI_Element_set_fields(&options_player_red_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_red_slider_title_label, "Player color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_player_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_player_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_player_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);
    
    UI_Element_set_fields(&options_player_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_player_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_player_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_player_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_player_red_slider, (int *)&theme.game_colors.player_square_color.r, 0, 255, 1, &options_player_red_slider_label, &options_player_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_player_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_player_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_player_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_player_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_player_green_slider, (int *)&theme.game_colors.player_square_color.g, 0, 255, 1, &options_player_green_slider_label, &options_player_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_player_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_player_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_player_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_player_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_player_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_player_blue_slider, (int *)&theme.game_colors.player_square_color.b, 0, 255, 1, &options_player_blue_slider_label, &options_player_blue_slider_cursor, &slider_style, true);

    options_player_picker_label_list[0] = &options_player_red_slider_title_label;
    options_player_picker_label_list[1] = &options_player_red_slider_description_label;
    options_player_picker_label_list[2] = &options_player_green_slider_description_label;
    options_player_picker_label_list[3] = &options_player_blue_slider_description_label;

    options_player_picker_slider_list[0] = &options_player_red_slider;
    options_player_picker_slider_list[1] = &options_player_green_slider;
    options_player_picker_slider_list[2] = &options_player_blue_slider;

    UI_Element_set_fields(&options_player_picker.rect, 20, 150, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    picker_set_fields(&options_player_picker, &options_player_color_rect, options_player_picker_label_list, options_player_picker_slider_list, true);
    picker_init(&options_player_picker, SCALE_X, SCALE_Y);


    UI_Element_set_fields(&options_collision_square_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], 1.0, TOP_LEFT);
    rect_set_fields(&options_collision_square_color_rect, &theme.game_colors.collision_square_color);

    UI_Element_set_fields(&options_collision_square_red_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_red_slider_title_label, "Blocks color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_collision_square_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_collision_square_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_collision_square_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_collision_square_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_collision_square_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_collision_square_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_collision_square_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_collision_square_red_slider, &theme.game_colors.collision_square_color.r, 0, 255, 1, &options_collision_square_red_slider_label, &options_collision_square_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_collision_square_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_collision_square_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_collision_square_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_collision_square_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_collision_square_green_slider, &theme.game_colors.collision_square_color.g, 0, 255, 1, &options_collision_square_green_slider_label, &options_collision_square_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_collision_square_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_collision_square_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_collision_square_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_collision_square_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_collision_square_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_collision_square_blue_slider, &theme.game_colors.collision_square_color.b, 0, 255, 1, &options_collision_square_blue_slider_label, &options_collision_square_blue_slider_cursor, &slider_style, true);

    options_collision_square_picker_label_list[0] = &options_collision_square_red_slider_title_label;
    options_collision_square_picker_label_list[1] = &options_collision_square_red_slider_description_label;
    options_collision_square_picker_label_list[2] = &options_collision_square_green_slider_description_label;
    options_collision_square_picker_label_list[3] = &options_collision_square_blue_slider_description_label;

    options_collision_square_picker_slider_list[0] = &options_collision_square_red_slider;
    options_collision_square_picker_slider_list[1] = &options_collision_square_green_slider;
    options_collision_square_picker_slider_list[2] = &options_collision_square_blue_slider;

    UI_Element_set_fields(&options_collision_square_picker.rect, 370, 150, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    picker_set_fields(&options_collision_square_picker, &options_collision_square_color_rect, options_collision_square_picker_label_list, options_collision_square_picker_slider_list, true);
    picker_init(&options_collision_square_picker, SCALE_X, SCALE_Y);


    UI_Element_set_fields(&options_line_square_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], 1.0, TOP_LEFT);
    rect_set_fields(&options_line_square_color_rect, &theme.game_colors.line_square_color);

    UI_Element_set_fields(&options_line_square_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_slider_title_label, "Line color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_line_square_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_line_square_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_line_square_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_line_square_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_line_square_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_line_square_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_line_square_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_line_square_red_slider, &theme.game_colors.line_square_color.r, 0, 255, 1, &options_line_square_red_slider_label, &options_line_square_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_line_square_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_line_square_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_line_square_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_line_square_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_line_square_green_slider, &theme.game_colors.line_square_color.g, 0, 255, 1, &options_line_square_green_slider_label, &options_line_square_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_line_square_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_line_square_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_line_square_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_line_square_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_line_square_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_line_square_blue_slider, &theme.game_colors.line_square_color.b, 0, 255, 1, &options_line_square_blue_slider_label, &options_line_square_blue_slider_cursor, &slider_style, true);

    options_options_line_square_picker_label_list[0] = &options_line_square_slider_title_label;
    options_options_line_square_picker_label_list[1] = &options_line_square_red_slider_description_label;
    options_options_line_square_picker_label_list[2] = &options_line_square_green_slider_description_label;
    options_options_line_square_picker_label_list[3] = &options_line_square_blue_slider_description_label;

    options_options_line_square_picker_slider_list[0] = &options_line_square_red_slider;
    options_options_line_square_picker_slider_list[1] = &options_line_square_green_slider;
    options_options_line_square_picker_slider_list[2] = &options_line_square_blue_slider;

    UI_Element_set_fields(&options_line_square_picker.rect, 700, 150, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    picker_set_fields(&options_line_square_picker, &options_line_square_color_rect, options_options_line_square_picker_label_list, options_options_line_square_picker_slider_list, true);
    picker_init(&options_line_square_picker, SCALE_X, SCALE_Y);



    UI_Element_set_fields(&options_empty_square_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], 1.0, TOP_LEFT);
    rect_set_fields(&options_empty_square_color_rect, &theme.game_colors.empty_square_color);
    
    UI_Element_set_fields(&options_empty_square_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_slider_title_label, "Background color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_empty_square_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_empty_square_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_empty_square_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_empty_square_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_empty_square_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_empty_square_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_empty_square_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_empty_square_red_slider, &theme.game_colors.empty_square_color.r, 0, 255, 1, &options_empty_square_red_slider_label, &options_empty_square_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_empty_square_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_empty_square_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_empty_square_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_empty_square_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_empty_square_green_slider, &theme.game_colors.empty_square_color.g, 0, 255, 1, &options_empty_square_green_slider_label, &options_empty_square_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&options_empty_square_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_empty_square_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_empty_square_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_empty_square_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_empty_square_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_empty_square_blue_slider, &theme.game_colors.empty_square_color.b, 0, 255, 1, &options_empty_square_blue_slider_label, &options_empty_square_blue_slider_cursor, &slider_style, true);

    options_empty_square_picker_label_list[0] = &options_empty_square_slider_title_label;
    options_empty_square_picker_label_list[1] = &options_empty_square_red_slider_description_label;
    options_empty_square_picker_label_list[2] = &options_empty_square_green_slider_description_label;
    options_empty_square_picker_label_list[3] = &options_empty_square_blue_slider_description_label;

    options_empty_square_picker_slider_list[0] = &options_empty_square_red_slider;
    options_empty_square_picker_slider_list[1] = &options_empty_square_green_slider;
    options_empty_square_picker_slider_list[2] = &options_empty_square_blue_slider;

    UI_Element_set_fields(&options_empty_square_picker.rect, 20, 400, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    picker_set_fields(&options_empty_square_picker, &options_empty_square_color_rect, options_empty_square_picker_label_list, options_empty_square_picker_slider_list, true);
    picker_init(&options_empty_square_picker, SCALE_X, SCALE_Y);


    options_color_picker_list[0] = &options_player_picker;
    options_color_picker_list[1] = &options_collision_square_picker;
    options_color_picker_list[2] = &options_line_square_picker;
    options_color_picker_list[3] = &options_empty_square_picker;

    panel_set_fields(&options_colors_panel, NULL, 0, NULL, 0, NULL, 0, options_color_picker_list, 4, NULL, 0, NULL, 0, NULL, 0, false);
    panel_init(&options_colors_panel);

    //Video panel ------------------------------------------

    UI_Element_set_fields(&options_fullscreen_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_fullscreen_toggle_label, "Fullscreen", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_floating_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_floating_toggle_label, "Floating", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&options_fullscreen_toggle.rect, 20, 150, 0, 0, outlines[1], inlines[0], 1.0, TOP_LEFT);
    toggle_set_fields(&options_fullscreen_toggle, NORMAL, &options_fullscreen_toggle_label, &toggle_style, &option_window_fullscreen, true);
    toggle_init(&options_fullscreen_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_floating_toggle.rect, 20, 200, 0, 0, outlines[1], inlines[0], 1.0, TOP_LEFT);
    toggle_set_fields(&options_floating_toggle, NORMAL, &options_floating_toggle_label, &toggle_style, &option_window_floating, true);
    toggle_init(&options_floating_toggle, SCALE_X, SCALE_Y);

    options_window_state_toggle_list[0] = &options_floating_toggle;
    options_window_state_toggle_list[1] = &options_fullscreen_toggle;
    group_set_fields(&options_window_state_group, options_window_state_toggle_list, 2, 0, true);

    UI_Element_set_fields(&options_max_fps_slider_description_label.rect, 20, 350, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_max_fps_slider_description_label, "Max FPS", 20, DARK, false, 1.0, true);
    label_init(&options_max_fps_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_max_fps_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_max_fps_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_max_fps_slider_cursor.rect,0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_max_fps_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_max_fps_slider.rect, 20, options_max_fps_slider_description_label.rect.y + options_max_fps_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_max_fps_slider, &MAX_FPS, 60, 240, 1, &options_max_fps_slider_label, &options_max_fps_slider_cursor, &slider_style, true);
    slider_init(&options_max_fps_slider, SCALE_X, SCALE_Y);

    options_video_slider_list[0] = &options_max_fps_slider;
    options_video_group_list[0] = &options_window_state_group;
    options_video_label_list[0] = &options_max_fps_slider_description_label;
    panel_set_fields(&options_video_panel, NULL, 0, NULL, 0, options_video_slider_list, 1, NULL, 0, options_video_group_list, 1, options_video_label_list, 1, NULL, 0, false);
    panel_init(&options_video_panel);

    //Audio panel

    UI_Element_set_fields(&options_master_audio_slider_description_label.rect, 20, 150, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_master_audio_slider_description_label, "Master volume", 20, DARK, false, 1.0, true);
    label_init(&options_master_audio_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_master_audio_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_master_audio_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_master_audio_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_master_audio_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_master_audio_slider.rect, 20, options_master_audio_slider_description_label.rect.y + options_master_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_master_audio_slider, NULL, 0, 200, 1, &options_master_audio_slider_label, &options_master_audio_slider_cursor, &slider_style, true);
    slider_init(&options_master_audio_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_music_audio_slider_description_label.rect, 20, 225, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_music_audio_slider_description_label, "Music volume", 20, DARK, false, 1.0, true);
    label_init(&options_music_audio_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_music_audio_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_music_audio_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_music_audio_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_music_audio_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_music_audio_slider.rect, 20, options_music_audio_slider_description_label.rect.y + options_music_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_music_audio_slider, NULL, 0, 200, 1, &options_music_audio_slider_label, &options_music_audio_slider_cursor, &slider_style, true);
    slider_init(&options_music_audio_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_effects_audio_slider_description_label.rect, 20, 300, 0, 0, outlines[0], inlines[0], 1.0, TOP_LEFT);
    label_set_fields(&options_effects_audio_slider_description_label, "Effects volume", 20, DARK, false, 1.0, true);
    label_init(&options_effects_audio_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_effects_audio_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&options_effects_audio_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&options_effects_audio_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_cursor_set_fields(&options_effects_audio_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&options_effects_audio_slider.rect, 20, options_effects_audio_slider_description_label.rect.y + options_effects_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], 1.0, TOP_LEFT);
    slider_set_fields(&options_effects_audio_slider, NULL, 0, 200, 1, &options_effects_audio_slider_label, &options_effects_audio_slider_cursor, &slider_style, true);
    slider_init(&options_effects_audio_slider, SCALE_X, SCALE_Y);

    options_audio_slider_list[0] = &options_master_audio_slider;
    options_audio_slider_list[1] = &options_music_audio_slider;
    options_audio_slider_list[2] = &options_effects_audio_slider;

    options_audio_label_list[0] = &options_master_audio_slider_description_label;
    options_audio_label_list[1] = &options_music_audio_slider_description_label;
    options_audio_label_list[2] = &options_effects_audio_slider_description_label;

    panel_set_fields(&options_audio_panel, NULL, 0, NULL, 0, options_audio_slider_list, 3, NULL, 0, NULL, 0, options_audio_label_list, 3, NULL, 0, false);
    panel_init(&options_audio_panel);

    options_labels[0] = &options_back_label;

    options_panels[0] = &options_gameplay_panel;
    options_panels[1] = &options_colors_panel;
    options_panels[2] = &options_video_panel;
    options_panels[3] = &options_audio_panel;

    debug_log("Options data initialised.");
    return;
}

void options_data_ui_free()
{
	panel_list_free(options_panels, 4);
	toggle_list_free(options_toggle_list, 4);
	label_free(&options_back_label);
	debug_log("options data freed.");
	return;
}