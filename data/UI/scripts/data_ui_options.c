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

Rect player_color_rect;

Label player_red_slider_title_label;
Label player_red_slider_description_label;
Label player_green_slider_description_label;
Label player_blue_slider_description_label;

Label player_red_slider_label;
SliderCursor player_red_slider_cursor;
Slider player_red_slider;

Label player_green_slider_label;
SliderCursor player_green_slider_cursor;
Slider player_green_slider;

Label player_blue_slider_label;
SliderCursor player_blue_slider_cursor;
Slider player_blue_slider;

Label *player_picker_label_list[4];
Slider *player_picker_slider_list[3];

ColorPicker player_picker;


Rect collision_square_color_rect;

Label collision_square_red_slider_title_label;
Label collision_square_red_slider_description_label;
Label collision_square_green_slider_description_label;
Label collision_square_blue_slider_description_label;

Label collision_square_red_slider_label;
SliderCursor collision_square_red_slider_cursor;
Slider collision_square_red_slider;

Label collision_square_green_slider_label;
SliderCursor collision_square_green_slider_cursor;
Slider collision_square_green_slider;

Label collision_square_blue_slider_label;
SliderCursor collision_square_blue_slider_cursor;
Slider collision_square_blue_slider;

Label *collision_square_picker_label_list[4];
Slider *collision_square_picker_slider_list[3];

ColorPicker collision_square_picker;


Rect line_square_color_rect;

Label line_square_slider_title_label;
Label line_square_red_slider_description_label;
Label line_square_green_slider_description_label;
Label line_square_blue_slider_description_label;

Label line_square_red_slider_label;
SliderCursor line_square_red_slider_cursor;
Slider line_square_red_slider;

Label line_square_green_slider_label;
SliderCursor line_square_green_slider_cursor;
Slider line_square_green_slider;

Label line_square_blue_slider_label;
SliderCursor line_square_blue_slider_cursor;
Slider line_square_blue_slider;

Label *line_square_picker_label_list[4];
Slider *line_square_picker_slider_list[3];

ColorPicker line_square_picker;


Rect empty_square_color_rect;
    
Label empty_square_slider_title_label;
Label empty_square_red_slider_description_label;
Label empty_square_green_slider_description_label;
Label empty_square_blue_slider_description_label;

Label empty_square_red_slider_label;
SliderCursor empty_square_red_slider_cursor;
Slider empty_square_red_slider;

Label empty_square_green_slider_label;
SliderCursor empty_square_green_slider_cursor;
Slider empty_square_green_slider;

Label empty_square_blue_slider_label;
SliderCursor empty_square_blue_slider_cursor;
Slider empty_square_blue_slider;

Label *empty_square_picker_label_list[4];
Slider *empty_square_picker_slider_list[3];

ColorPicker empty_square_picker;

ColorPicker *color_picker_list[4];
Panel colors_panel;

//Video panel

Label fullscreen_toggle_label;
Label floating_toggle_label;

Toggle fullscreen_toggle;
Toggle floating_toggle;

Toggle *window_state_toggle_list[2];
ToggleGroup window_state_group;

Label max_fps_slider_description_label;

Label max_fps_slider_label;
SliderCursor max_fps_slider_cursor;
Slider max_fps_slider;

Slider *video_slider_list[1];
ToggleGroup *video_group_list[1];
Label *video_label_list[1];
Panel video_panel;

//Audio panel

Label master_audio_slider_description_label;

Label master_audio_slider_label;
SliderCursor master_audio_slider_cursor ;
Slider master_audio_slider;

Label music_audio_slider_description_label;

Label music_audio_slider_label;
SliderCursor music_audio_slider_cursor ;
Slider music_audio_slider;

Label effects_audio_slider_description_label;

Label effects_audio_slider_label;
SliderCursor effects_audio_slider_cursor;
Slider effects_audio_slider;

Slider *audio_slider_list[3];
Label *audio_label_list[3];
Panel audio_panel;


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

    UI_Element_set_fields(&player_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], TOP_LEFT);
    rect_set_fields(&player_color_rect, &theme.game_colors.player_square_color);

    UI_Element_set_fields(&player_red_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_red_slider_title_label, "Player color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&player_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&player_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&player_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);
    
    UI_Element_set_fields(&player_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&player_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&player_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&player_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&player_red_slider, (int *)&theme.game_colors.player_square_color.r, 0, 255, 1, &player_red_slider_label, &player_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&player_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&player_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&player_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&player_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&player_green_slider, (int *)&theme.game_colors.player_square_color.g, 0, 255, 1, &player_green_slider_label, &player_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&player_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&player_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&player_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&player_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&player_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&player_blue_slider, (int *)&theme.game_colors.player_square_color.b, 0, 255, 1, &player_blue_slider_label, &player_blue_slider_cursor, &slider_style, true);

    player_picker_label_list[0] = &player_red_slider_title_label;
    player_picker_label_list[1] = &player_red_slider_description_label;
    player_picker_label_list[2] = &player_green_slider_description_label;
    player_picker_label_list[3] = &player_blue_slider_description_label;

    player_picker_slider_list[0] = &player_red_slider;
    player_picker_slider_list[1] = &player_green_slider;
    player_picker_slider_list[2] = &player_blue_slider;

    UI_Element_set_fields(&player_picker.rect, 20, 150, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    picker_set_fields(&player_picker, &player_color_rect, player_picker_label_list, player_picker_slider_list, true);
    picker_init(&player_picker, SCALE_X, SCALE_Y);


    UI_Element_set_fields(&collision_square_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], TOP_LEFT);
    rect_set_fields(&collision_square_color_rect, &theme.game_colors.collision_square_color);

    UI_Element_set_fields(&collision_square_red_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_red_slider_title_label, "Blocks color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&collision_square_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&collision_square_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&collision_square_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&collision_square_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&collision_square_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&collision_square_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&collision_square_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&collision_square_red_slider, &theme.game_colors.collision_square_color.r, 0, 255, 1, &collision_square_red_slider_label, &collision_square_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&collision_square_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&collision_square_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&collision_square_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&collision_square_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&collision_square_green_slider, &theme.game_colors.collision_square_color.g, 0, 255, 1, &collision_square_green_slider_label, &collision_square_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&collision_square_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&collision_square_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&collision_square_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&collision_square_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&collision_square_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&collision_square_blue_slider, &theme.game_colors.collision_square_color.b, 0, 255, 1, &collision_square_blue_slider_label, &collision_square_blue_slider_cursor, &slider_style, true);

    collision_square_picker_label_list[0] = &collision_square_red_slider_title_label;
    collision_square_picker_label_list[1] = &collision_square_red_slider_description_label;
    collision_square_picker_label_list[2] = &collision_square_green_slider_description_label;
    collision_square_picker_label_list[3] = &collision_square_blue_slider_description_label;

    collision_square_picker_slider_list[0] = &collision_square_red_slider;
    collision_square_picker_slider_list[1] = &collision_square_green_slider;
    collision_square_picker_slider_list[2] = &collision_square_blue_slider;

    UI_Element_set_fields(&collision_square_picker.rect, 370, 150, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    picker_set_fields(&collision_square_picker, &collision_square_color_rect, collision_square_picker_label_list, collision_square_picker_slider_list, true);
    picker_init(&collision_square_picker, SCALE_X, SCALE_Y);


    UI_Element_set_fields(&line_square_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], TOP_LEFT);
    rect_set_fields(&line_square_color_rect, &theme.game_colors.line_square_color);

    UI_Element_set_fields(&line_square_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_slider_title_label, "Line color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&line_square_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&line_square_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&line_square_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&line_square_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&line_square_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&line_square_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&line_square_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&line_square_red_slider, &theme.game_colors.line_square_color.r, 0, 255, 1, &line_square_red_slider_label, &line_square_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&line_square_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&line_square_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&line_square_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&line_square_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&line_square_green_slider, &theme.game_colors.line_square_color.g, 0, 255, 1, &line_square_green_slider_label, &line_square_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&line_square_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&line_square_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&line_square_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&line_square_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&line_square_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&line_square_blue_slider, &theme.game_colors.line_square_color.b, 0, 255, 1, &line_square_blue_slider_label, &line_square_blue_slider_cursor, &slider_style, true);

    line_square_picker_label_list[0] = &line_square_slider_title_label;
    line_square_picker_label_list[1] = &line_square_red_slider_description_label;
    line_square_picker_label_list[2] = &line_square_green_slider_description_label;
    line_square_picker_label_list[3] = &line_square_blue_slider_description_label;

    line_square_picker_slider_list[0] = &line_square_red_slider;
    line_square_picker_slider_list[1] = &line_square_green_slider;
    line_square_picker_slider_list[2] = &line_square_blue_slider;

    UI_Element_set_fields(&line_square_picker.rect, 700, 150, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    picker_set_fields(&line_square_picker, &line_square_color_rect, line_square_picker_label_list, line_square_picker_slider_list, true);
    picker_init(&line_square_picker, SCALE_X, SCALE_Y);



    UI_Element_set_fields(&empty_square_color_rect.rect, 0, 0, 50, 50, outlines[2], inlines[0], TOP_LEFT);
    rect_set_fields(&empty_square_color_rect, &theme.game_colors.empty_square_color);
    
    UI_Element_set_fields(&empty_square_slider_title_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_slider_title_label, "Background color", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&empty_square_red_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_red_slider_description_label, "Red", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&empty_square_green_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_green_slider_description_label, "Green", 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&empty_square_blue_slider_description_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_blue_slider_description_label, "Blue", 20, DARK, false, 1.0, true);

    UI_Element_set_fields(&empty_square_red_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_red_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&empty_square_red_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&empty_square_red_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&empty_square_red_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&empty_square_red_slider, &theme.game_colors.empty_square_color.r, 0, 255, 1, &empty_square_red_slider_label, &empty_square_red_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&empty_square_green_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_green_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&empty_square_green_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&empty_square_green_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&empty_square_green_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&empty_square_green_slider, &theme.game_colors.empty_square_color.g, 0, 255, 1, &empty_square_green_slider_label, &empty_square_green_slider_cursor, &slider_style, true);

    UI_Element_set_fields(&empty_square_blue_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&empty_square_blue_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&empty_square_blue_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&empty_square_blue_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&empty_square_blue_slider.rect, 0, 0, 256, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&empty_square_blue_slider, &theme.game_colors.empty_square_color.b, 0, 255, 1, &empty_square_blue_slider_label, &empty_square_blue_slider_cursor, &slider_style, true);

    empty_square_picker_label_list[0] = &empty_square_slider_title_label;
    empty_square_picker_label_list[1] = &empty_square_red_slider_description_label;
    empty_square_picker_label_list[2] = &empty_square_green_slider_description_label;
    empty_square_picker_label_list[3] = &empty_square_blue_slider_description_label;

    empty_square_picker_slider_list[0] = &empty_square_red_slider;
    empty_square_picker_slider_list[1] = &empty_square_green_slider;
    empty_square_picker_slider_list[2] = &empty_square_blue_slider;

    UI_Element_set_fields(&empty_square_picker.rect, 20, 400, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    picker_set_fields(&empty_square_picker, &empty_square_color_rect, empty_square_picker_label_list, empty_square_picker_slider_list, true);
    picker_init(&empty_square_picker, SCALE_X, SCALE_Y);


    color_picker_list[0] = &player_picker;
    color_picker_list[1] = &collision_square_picker;
    color_picker_list[2] = &line_square_picker;
    color_picker_list[3] = &empty_square_picker;

    panel_set_fields(&colors_panel, NULL, 0, NULL, 0, NULL, 0, color_picker_list, 4, NULL, 0, NULL, 0, NULL, 0, false);
    panel_init(&colors_panel);

    //Video panel ------------------------------------------

    UI_Element_set_fields(&fullscreen_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&fullscreen_toggle_label, "Fullscreen", 30, DARK, false, 1.0, true);
    UI_Element_set_fields(&floating_toggle_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&floating_toggle_label, "Floating", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&fullscreen_toggle.rect, 20, 150, 0, 0, outlines[1], inlines[0], TOP_LEFT);
    toggle_set_fields(&fullscreen_toggle, NORMAL, &fullscreen_toggle_label, &toggle_style, &option_window_fullscreen, true);
    toggle_init(&fullscreen_toggle, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&floating_toggle.rect, 20, 200, 0, 0, outlines[1], inlines[0], TOP_LEFT);
    toggle_set_fields(&floating_toggle, NORMAL, &floating_toggle_label, &toggle_style, &option_window_floating, true);
    toggle_init(&floating_toggle, SCALE_X, SCALE_Y);

    window_state_toggle_list[0] = &floating_toggle;
    window_state_toggle_list[1] = &fullscreen_toggle;
    group_set_fields(&window_state_group, window_state_toggle_list, 2, 0, true);

    UI_Element_set_fields(&max_fps_slider_description_label.rect, 20, 350, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&max_fps_slider_description_label, "Max FPS", 20, DARK, false, 1.0, true);
    label_init(&max_fps_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&max_fps_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&max_fps_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&max_fps_slider_cursor.rect,0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&max_fps_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&max_fps_slider.rect, 20, max_fps_slider_description_label.rect.y + max_fps_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&max_fps_slider, &MAX_FPS, 60, 240, 1, &max_fps_slider_label, &max_fps_slider_cursor, &slider_style, true);
    slider_init(&max_fps_slider, SCALE_X, SCALE_Y);

    video_slider_list[0] = &max_fps_slider;
    video_group_list[0] = &window_state_group;
    video_label_list[0] = &max_fps_slider_description_label;
    panel_set_fields(&video_panel, NULL, 0, NULL, 0, video_slider_list, 1, NULL, 0, video_group_list, 1, video_label_list, 1, NULL, 0, false);
    panel_init(&video_panel);

    //Audio panel

    UI_Element_set_fields(&master_audio_slider_description_label.rect, 20, 150, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&master_audio_slider_description_label, "Master volume", 20, DARK, false, 1.0, true);
    label_init(&master_audio_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&master_audio_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&master_audio_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&master_audio_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&master_audio_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&master_audio_slider.rect, 20, master_audio_slider_description_label.rect.y + master_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&master_audio_slider, NULL, 0, 200, 1, &master_audio_slider_label, &master_audio_slider_cursor, &slider_style, true);
    slider_init(&master_audio_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&music_audio_slider_description_label.rect, 20, 225, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&music_audio_slider_description_label, "Music volume", 20, DARK, false, 1.0, true);
    label_init(&music_audio_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&music_audio_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&music_audio_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&music_audio_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&music_audio_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&music_audio_slider.rect, 20, music_audio_slider_description_label.rect.y + music_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&music_audio_slider, NULL, 0, 200, 1, &music_audio_slider_label, &music_audio_slider_cursor, &slider_style, true);
    slider_init(&music_audio_slider, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&effects_audio_slider_description_label.rect, 20, 300, 0, 0, outlines[0], inlines[0], TOP_LEFT);
    label_set_fields(&effects_audio_slider_description_label, "Effects volume", 20, DARK, false, 1.0, true);
    label_init(&effects_audio_slider_description_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&effects_audio_slider_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&effects_audio_slider_label, NULL, 20, DARK, false, 1.0, true);
    UI_Element_set_fields(&effects_audio_slider_cursor.rect, 0, 0, 20, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_cursor_set_fields(&effects_audio_slider_cursor, NORMAL, &slider_cursor_style);
    UI_Element_set_fields(&effects_audio_slider.rect, 20, effects_audio_slider_description_label.rect.y + effects_audio_slider_description_label.rect.height/SCALE_Y, 200, 20, outlines[1], inlines[0], TOP_LEFT);
    slider_set_fields(&effects_audio_slider, NULL, 0, 200, 1, &effects_audio_slider_label, &effects_audio_slider_cursor, &slider_style, true);
    slider_init(&effects_audio_slider, SCALE_X, SCALE_Y);

    audio_slider_list[0] = &master_audio_slider;
    audio_slider_list[1] = &music_audio_slider;
    audio_slider_list[2] = &effects_audio_slider;

    audio_label_list[0] = &master_audio_slider_description_label;
    audio_label_list[1] = &music_audio_slider_description_label;
    audio_label_list[2] = &effects_audio_slider_description_label;

    panel_set_fields(&audio_panel, NULL, 0, NULL, 0, audio_slider_list, 3, NULL, 0, NULL, 0, audio_label_list, 3, NULL, 0, false);
    panel_init(&audio_panel);
    return;
}