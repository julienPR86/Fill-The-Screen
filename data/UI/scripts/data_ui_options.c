#include "../../../main.h"

Label back_label;

Label gameplay_toggle_label;
Label colors_toggle_label;
Label video_toggle_label;
Label audio_toggle_label;

Toggle gameplay_toggle;
Toggle colors_toggle;
Toggle video_toggle;
Toggle audio_toggle;

Toggle *options_toggle_list[4];
ToggleGroup options_group;

//Gameplay panel -------

Label probability_slider_description_label;
Label probability_slider_label;
SliderCursor probability_slider_cursor;
Slider probability_slider;

Label map_width_slider_description_label;
Label map_width_slider_label;
SliderCursor map_width_slider_cursor;
Slider map_width_slider;

Label map_height_slider_description_label;
Label map_height_slider_label;
SliderCursor map_height_slider_cursor;
Slider map_height_slider;

Label game_speed_slider_description;
Label game_speed_slider_label;
SliderCursor game_speed_slider_cursor;
Slider game_speed_slider;

Slider *gameplay_slider_list[4];
Label *gameplay_label_list[4];
Panel gameplay_panel;

//Color panel ------------------

void options_data_ui_init()
{   
    UI_Element_set_fields(&back_label.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT - 10, 0, 0, outlines[0], inlines[0], BOTTOM_CENTER);
    label_set_fields(&back_label, "Press Escape to go back", 30, DARK, false, 1.0, true);
    label_init(&back_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&gameplay_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&gameplay_toggle_label, "Gameplay", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&colors_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&colors_toggle_label, "Colors", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&video_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&video_toggle_label, "Video", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&audio_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&audio_toggle_label, "Audio", 40, DARK, false, 1.0, true);

    UI_Element_set_fields(&gameplay_toggle.rect, 0, 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], TOP_LEFT);
    toggle_set_fields(&gameplay_toggle, NORMAL, &gameplay_toggle_label, &toggle_style, &option_gameplay, true);
    toggle_init(&gameplay_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&colors_toggle.rect, get_width(&gameplay_toggle.rect, 1.0), 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], TOP_LEFT);
    toggle_set_fields(&colors_toggle, NORMAL, &colors_toggle_label, &toggle_style, &option_color_label, true);
    toggle_init(&colors_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&video_toggle.rect, colors_toggle.rect.x + get_width(&colors_toggle.rect, 1.0), 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], TOP_LEFT);
    toggle_set_fields(&video_toggle, NORMAL, &video_toggle_label, &toggle_style, &option_video, true);
    toggle_init(&video_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&audio_toggle.rect, video_toggle.rect.x + get_width(&video_toggle.rect, 1.0), 0, WINDOW_WIDTH/4, WINDOW_HEIGHT/10, outlines[0], inlines[1], TOP_LEFT);
    toggle_set_fields(&audio_toggle, NORMAL, &audio_toggle_label, &toggle_style, &option_audio, true);
    toggle_init(&audio_toggle, SCALE_X, SCALE_Y);

    options_toggle_list[0] = &gameplay_toggle;
    options_toggle_list[1] = &colors_toggle;
    options_toggle_list[2] = &video_toggle;
    options_toggle_list[3] = &audio_toggle;
    group_set_fields(&options_group, options_toggle_list, 4, 0, true);
    group_init(&options_group);


    //Gameplay panel ------------------------------------------------------------

    UI_Element_set_fields(&probability_slider_description_label.rect, 20, 150, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&probability_slider_description_label, "Blocks spawn probability", 20, DARK, false, 1.0, true);
    label_init(&probability_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&probability_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&probability_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&probability_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&probability_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&probability_slider.rect, 20, probability_slider_description_label.rect.y + probability_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&probability_slider, &probability, 1, 100, 1, &probability_slider_label, &probability_slider_cursor, &slider_style, true);
    slider_init(&probability_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&map_width_slider_description_label.rect, 20, 225, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&map_width_slider_description_label, "Map width", 20, DARK, false, 1.0, true);
    label_init(&map_width_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&map_width_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&map_width_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&map_width_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&map_width_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&map_width_slider.rect, 20, map_width_slider_description_label.rect.y + map_width_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&map_width_slider, &map_width, 2, 100, 1, &map_width_slider_label, &map_width_slider_cursor, &slider_style, true);
    slider_init(&map_width_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&map_height_slider_description_label.rect, 20, 300, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&map_height_slider_description_label, "Map height", 20, DARK, false, 1.0, true);
    label_init(&map_height_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&map_height_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&map_height_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&map_height_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&map_height_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&map_height_slider.rect, 20, map_height_slider_description_label.rect.y + map_height_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&map_height_slider, &map_height, 2, 100, 1, &map_height_slider_label, &map_height_slider_cursor, &slider_style, true);
    slider_init(&map_height_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_speed_slider_description.rect, 20, 375, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&game_speed_slider_description, "Game speed", 20, DARK, false, 1.0, true);
    label_init(&game_speed_slider_description, SCALE_X, SCALE_Y);
    
    UI_Element_set_fields(&game_speed_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&game_speed_slider_label, NULL, 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&game_speed_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&game_speed_slider_cursor, NORMAL, &slider_cursor_style);

    UI_Element_set_fields(&game_speed_slider.rect, 20, game_speed_slider_description.rect.y + game_speed_slider_description.rect.height, 300, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&game_speed_slider, &game_speed, 1, 300, 1, &game_speed_slider_label, &game_speed_slider_cursor, &slider_style, true);
    slider_init(&game_speed_slider, SCALE_X, SCALE_Y);


    gameplay_slider_list[0] = &probability_slider;
    gameplay_slider_list[1] = &map_width_slider;
    gameplay_slider_list[2] = &map_height_slider;
    gameplay_slider_list[3] = &game_speed_slider;

    gameplay_label_list[0] = &probability_slider_description_label;
    gameplay_label_list[1] = &map_width_slider_description_label;
    gameplay_label_list[2] = &map_height_slider_description_label;
    gameplay_label_list[3] = &game_speed_slider_description;

    panel_set_fields(&gameplay_panel, NULL, 0, NULL, 0, gameplay_slider_list, 4, NULL, 0, NULL, 0, gameplay_label_list, 4, NULL, 0, true);
    panel_init(&gameplay_panel);

    //Color panel ------------------------------------------------------------
    return;
}