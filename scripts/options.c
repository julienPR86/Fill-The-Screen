#include "../main.h"

int options()
{
    Label gameplay_toggle_label = {EMPTY_UI_ELEMENT, "Gameplay", 40, DARK, NULL, NULL, false, 1.0, true};
    Label colors_toggle_label = {EMPTY_UI_ELEMENT, "Colors", 40, DARK, NULL, NULL, false, 1.0, true};
    Label video_toggle_label = {EMPTY_UI_ELEMENT, "Video", 40, DARK, NULL, NULL, false, 1.0, true};
    Label audio_toggle_label = {EMPTY_UI_ELEMENT, "Audio", 40, DARK, NULL, NULL, false, 1.0, true};

    Toggle gameplay_toggle = {{0, 0, WIDTH/SCALE/4, HEIGHT/10, NO_OUTLINE, inlines[1], TOP_LEFT}, NORMAL, &gameplay_toggle_label, &toggle_style, &option_gameplay, 1.0, true};
    toggle_init(&gameplay_toggle, SCALE);
    Toggle colors_toggle = {{get_width(&gameplay_toggle.rect, SCALE), 0, WIDTH/SCALE/4, HEIGHT/10, NO_OUTLINE, inlines[1], TOP_LEFT}, NORMAL, &colors_toggle_label, &toggle_style, &option_color_label, 1.0, true};
    toggle_init(&colors_toggle, SCALE);
    Toggle video_toggle = {{colors_toggle.rect.x + get_width(&colors_toggle.rect, SCALE), 0, WIDTH/SCALE/4, HEIGHT/10, NO_OUTLINE, inlines[1], TOP_LEFT}, NORMAL, &video_toggle_label, &toggle_style, &option_video, 1.0, true};
    toggle_init(&video_toggle, SCALE);
    Toggle audio_toggle = {{video_toggle.rect.x + get_width(&video_toggle.rect, SCALE), 0, WIDTH/SCALE/4, HEIGHT/10, NO_OUTLINE, inlines[1], TOP_LEFT}, NORMAL, &audio_toggle_label, &toggle_style, &option_audio, 1.0, true};
    toggle_init(&audio_toggle, SCALE);

    Toggle *options_toggle_list[] = {&gameplay_toggle, &colors_toggle, &video_toggle, &audio_toggle};
    ToggleGroup options_group = {options_toggle_list, 4, 0, true};
    group_init(&options_group);

    Label back_label = {{WIDTH/2, HEIGHT - 10*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, BOTTOM_CENTER}, "Press Escape to go back", 30, {255, 0, 0, 255}, NULL, NULL, false, 1.0, true};
    label_init(&back_label, SCALE);

    // Gameplay panel ----------------------------------------------------------------
    
    Label probability_slider_description_label = {{20, 150*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Blocks spawn probability", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&probability_slider_description_label, SCALE);

    Label probability_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor probability_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider probability_slider = {{20, probability_slider_description_label.rect.y + probability_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &probability, 1, 100, 1, &probability_slider_label, &probability_slider_cursor, &slider_style, 1.0, true};
    slider_init(&probability_slider, SCALE);


    Label map_width_slider_description_label = {{20, 225*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Map width", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&map_width_slider_description_label, SCALE);

    Label map_width_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor map_width_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider map_width_slider = {{20, map_width_slider_description_label.rect.y + map_width_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &map_width, 2, 100, 1, &map_width_slider_label, &map_width_slider_cursor, &slider_style, 1.0, true};
    slider_init(&map_width_slider, SCALE);


    Label map_height_slider_description_label = {{20, 300*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Map height", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&map_height_slider_description_label, SCALE);

    Label map_height_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor map_height_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider map_height_slider = {{20, map_height_slider_description_label.rect.y + map_height_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &map_height, 2, 100, 1, &map_height_slider_label, &map_height_slider_cursor, &slider_style, 1.0, true};
    slider_init(&map_height_slider, SCALE);


    Label game_speed_slider_description = {{20, 375*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Game speed", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&game_speed_slider_description, SCALE);

    Label game_speed_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor game_speed_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider game_speed_slider = {{20, game_speed_slider_description.rect.y + game_speed_slider_description.rect.height, 300, 20, outlines[1], NO_INLINE, TOP_LEFT}, &game_speed, 1, 300, 1, &game_speed_slider_label, &game_speed_slider_cursor, &slider_style, 1.0, true};
    slider_init(&game_speed_slider, SCALE);


    Button *gameplay_button_list[] = {};
    Toggle *gameplay_toggle_list[] = {};
    Slider *gameplay_slider_list[] = {&probability_slider, &map_width_slider, &map_height_slider, &game_speed_slider};
    ColorPicker *gameplay_picker_list[] = {};
    Label *gameplay_label_list[] = {&probability_slider_description_label, &map_width_slider_description_label, &map_height_slider_description_label, &game_speed_slider_description};
    Rect *gameplay_rect_list[] = {};
    Panel gameplay_panel = {gameplay_button_list, 0, gameplay_toggle_list, 0, gameplay_slider_list, 4, gameplay_picker_list , 0, gameplay_label_list, 4, gameplay_rect_list, 0, true};
    panel_init(&gameplay_panel);

    // colors panel --------------------------------------------------------------------------

    Rect player_color_rect = {{0, 0, 50, 50, outlines[2], NO_INLINE, TOP_LEFT}, &theme.game_colors.player_square_color};

    Label player_red_slider_title_label = {EMPTY_UI_ELEMENT, "Player color", 30, DARK, NULL, NULL, false, 1.0, true};
    Label player_red_slider_description_label = {EMPTY_UI_ELEMENT, "Red", 20, DARK, NULL, NULL, false, 1.0, true};
    Label player_green_slider_description_label = {EMPTY_UI_ELEMENT, "Green", 20, DARK, NULL, NULL, false, 1.0, true};
    Label player_blue_slider_description_label = {EMPTY_UI_ELEMENT, "Blue", 20, DARK, NULL, NULL, false, 1.0, true};

    Label player_red_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor player_red_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider player_red_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, (int *)&theme.game_colors.player_square_color.r, 0, 255, 1, &player_red_slider_label, &player_red_slider_cursor, &slider_style, 1.0, true};

    Label player_green_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor player_green_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider player_green_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, (int *)&theme.game_colors.player_square_color.g, 0, 255, 1, &player_green_slider_label, &player_green_slider_cursor, &slider_style, 1.0, true};

    Label player_blue_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor player_blue_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider player_blue_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, (int *)&theme.game_colors.player_square_color.b, 0, 255, 1, &player_blue_slider_label, &player_blue_slider_cursor, &slider_style, 1.0, true};

    Label *player_picker_label_list[] = {&player_red_slider_title_label, &player_red_slider_description_label, &player_green_slider_description_label, &player_blue_slider_description_label};
    Slider *player_picker_slider_list[] = {&player_red_slider, &player_green_slider, &player_blue_slider};

    ColorPicker player_picker = {{20 * SCALE, 150 * SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, &player_color_rect, player_picker_label_list, player_picker_slider_list};
    picker_init(&player_picker, SCALE);



    Rect collision_square_color_rect = {{0, 0, 50, 50, outlines[2], NO_INLINE, TOP_LEFT}, &theme.game_colors.collision_square_color};

    Label collision_square_red_slider_title_label = {EMPTY_UI_ELEMENT, "Blocks color", 30, DARK, NULL, NULL, false, 1.0, true};
    Label collision_square_red_slider_description_label = {EMPTY_UI_ELEMENT, "Red", 20, DARK, NULL, NULL, false, 1.0, true};
    Label collision_square_green_slider_description_label = {EMPTY_UI_ELEMENT, "Green", 20, DARK, NULL, NULL, false, 1.0, true};
    Label collision_square_blue_slider_description_label = {EMPTY_UI_ELEMENT, "Blue", 20, DARK, NULL, NULL, false, 1.0, true};

    Label collision_square_red_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor collision_square_red_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider collision_square_red_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.collision_square_color.r, 0, 255, 1, &collision_square_red_slider_label, &collision_square_red_slider_cursor, &slider_style, 1.0, true};

    Label collision_square_green_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor collision_square_green_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider collision_square_green_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.collision_square_color.g, 0, 255, 1, &collision_square_green_slider_label, &collision_square_green_slider_cursor, &slider_style, 1.0, true};

    Label collision_square_blue_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor collision_square_blue_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider collision_square_blue_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.collision_square_color.b, 0, 255, 1, &collision_square_blue_slider_label, &collision_square_blue_slider_cursor, &slider_style, 1.0, true};

    Label *collision_square_picker_label_list[] = {&collision_square_red_slider_title_label, &collision_square_red_slider_description_label, &collision_square_green_slider_description_label, &collision_square_blue_slider_description_label};
    Slider *collision_square_picker_slider_list[] = {&collision_square_red_slider, &collision_square_green_slider, &collision_square_blue_slider};

    ColorPicker collision_square_picker = {{370 * SCALE, 150 * SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, &collision_square_color_rect, collision_square_picker_label_list, collision_square_picker_slider_list};
    picker_init(&collision_square_picker, SCALE);



    Rect line_square_color_rect = {{0, 0, 50, 50, outlines[2], NO_INLINE, TOP_LEFT}, &theme.game_colors.line_square_color};

    Label line_square_slider_title_label = {EMPTY_UI_ELEMENT, "Line color", 30, DARK, NULL, NULL, false, 1.0, true};
    Label line_square_red_slider_description_label = {EMPTY_UI_ELEMENT, "Red", 20, DARK, NULL, NULL, false, 1.0, true};
    Label line_square_green_slider_description_label = {EMPTY_UI_ELEMENT, "Green", 20, DARK, NULL, NULL, false, 1.0, true};
    Label line_square_blue_slider_description_label = {EMPTY_UI_ELEMENT, "Blue", 20, DARK, NULL, NULL, false, 1.0, true};

    Label line_square_red_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor line_square_red_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider line_square_red_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.line_square_color.r, 0, 255, 1, &line_square_red_slider_label, &line_square_red_slider_cursor, &slider_style, 1.0, true};

    Label line_square_green_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor line_square_green_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider line_square_green_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.line_square_color.g, 0, 255, 1, &line_square_green_slider_label, &line_square_green_slider_cursor, &slider_style, 1.0, true};

    Label line_square_blue_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor line_square_blue_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider line_square_blue_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.line_square_color.b, 0, 255, 1, &line_square_blue_slider_label, &line_square_blue_slider_cursor, &slider_style, 1.0, true};

    Label *line_square_picker_label_list[] = {&line_square_slider_title_label, &line_square_red_slider_description_label, &line_square_green_slider_description_label, &line_square_blue_slider_description_label};
    Slider *line_square_picker_slider_list[] = {&line_square_red_slider, &line_square_green_slider, &line_square_blue_slider};

    ColorPicker line_square_picker = {{700 * SCALE, 150 * SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, &line_square_color_rect, line_square_picker_label_list, line_square_picker_slider_list};
    picker_init(&line_square_picker, SCALE);



    Rect empty_square_color_rect = {{0, 0, 50, 50, outlines[2], NO_INLINE, TOP_LEFT}, &theme.game_colors.empty_square_color};
    
    Label empty_square_slider_title_label = {EMPTY_UI_ELEMENT, "Background color", 30, DARK, NULL, NULL, false, 1.0, true};
    Label empty_square_red_slider_description_label = {EMPTY_UI_ELEMENT, "Red", 20, DARK, NULL, NULL, false, 1.0, true};
    Label empty_square_green_slider_description_label = {EMPTY_UI_ELEMENT, "Green", 20, DARK, NULL, NULL, false, 1.0, true};
    Label empty_square_blue_slider_description_label = {EMPTY_UI_ELEMENT, "Blue", 20, DARK, NULL, NULL, false, 1.0, true};

    Label empty_square_red_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor empty_square_red_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider empty_square_red_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.empty_square_color.r, 0, 255, 1, &empty_square_red_slider_label, &empty_square_red_slider_cursor, &slider_style, 1.0, true};

    Label empty_square_green_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor empty_square_green_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider empty_square_green_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.empty_square_color.g, 0, 255, 1, &empty_square_green_slider_label, &empty_square_green_slider_cursor, &slider_style, 1.0, true};

    Label empty_square_blue_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor empty_square_blue_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider empty_square_blue_slider = {{0, 0, 256, 20, outlines[1], NO_INLINE, TOP_LEFT}, &theme.game_colors.empty_square_color.b, 0, 255, 1, &empty_square_blue_slider_label, &empty_square_blue_slider_cursor, &slider_style, 1.0, true};

    Label *empty_square_picker_label_list[] = {&empty_square_slider_title_label, &empty_square_red_slider_description_label, &empty_square_green_slider_description_label, &empty_square_blue_slider_description_label};
    Slider *empty_square_picker_slider_list[] = {&empty_square_red_slider, &empty_square_green_slider, &empty_square_blue_slider};

    ColorPicker empty_square_picker = {{20 * SCALE, 400 * SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, &empty_square_color_rect, empty_square_picker_label_list, empty_square_picker_slider_list};
    picker_init(&empty_square_picker, SCALE);


    Button *colors_button_list[] = {};
    Toggle *colors_toggle_list[] = {};
    Slider *colors_slider_list[] = {};
    ColorPicker *color_picker_list[] = {&player_picker, &collision_square_picker, &line_square_picker, &empty_square_picker};
    Label *colors_label_list[] = {};
    Rect *color_rect_list[] = {};
    Panel colors_panel = {colors_button_list, 0, colors_toggle_list, 0, colors_slider_list, 0, color_picker_list , 4, colors_label_list, 0, color_rect_list, 0, false};
    panel_init(&colors_panel);

    // Video panel --------------------------------------------------------------------

    Label max_fps_slider_description_label = {{20, 150*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Max FPS", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&max_fps_slider_description_label, SCALE);

    Label max_fps_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor max_fps_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider max_fps_slider = {{20, max_fps_slider_description_label.rect.y + max_fps_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &MAX_FPS, 60, 240, 1, &max_fps_slider_label, &max_fps_slider_cursor, &slider_style, 1.0, true};
    slider_init(&max_fps_slider, SCALE);

    Label screen_width_slider_description_label = {{20, 250*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Screen Width", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&screen_width_slider_description_label, SCALE);

    Label screen_width_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor screen_width_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider screen_width_slider = {{20, screen_width_slider_description_label.rect.y + screen_width_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &WIDTH, 1080, 1920, 1, &screen_width_slider_label, &screen_width_slider_cursor, &slider_style, 1.0, true};
    slider_init(&screen_width_slider, SCALE);

    Label screen_height_slider_description_label = {{20, 350*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Screen Height", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&screen_height_slider_description_label, SCALE);

    Label screen_height_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor screen_height_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider screen_height_slider = {{20, screen_height_slider_description_label.rect.y + screen_height_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, &HEIGHT, 720, 1080, 1, &screen_height_slider_label, &screen_height_slider_cursor, &slider_style, 1.0, true};
    slider_init(&screen_height_slider, SCALE);

    Button *video_button_list[] = {};
    Toggle *video_toggle_list[] = {};
    Slider *video_slider_list[] = {&max_fps_slider, &screen_width_slider, &screen_height_slider};
    ColorPicker *video_picker_list[] = {};
    Label *video_label_list[] = {&max_fps_slider_description_label, &screen_width_slider_description_label, &screen_height_slider_description_label};
    Rect *video_rect_list[] = {};
    Panel video_panel = {video_button_list, 0, video_toggle_list, 0, video_slider_list, 3, video_picker_list , 0, video_label_list, 3, video_rect_list, 0, false};
    panel_init(&video_panel);

    // Audio panel --------------------------------------------------------------------

    Label master_audio_slider_description_label = {{20, 150*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Master volume", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&master_audio_slider_description_label, SCALE);

    Label master_audio_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor master_audio_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider master_audio_slider = {{20, master_audio_slider_description_label.rect.y + master_audio_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, NULL, 0, 200, 1, &master_audio_slider_label, &master_audio_slider_cursor, &slider_style, 1.0, true};
    slider_init(&master_audio_slider, SCALE);


    Label music_audio_slider_description_label = {{20, 225*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Music volume", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&music_audio_slider_description_label, SCALE);

    Label music_audio_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor music_audio_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider music_audio_slider = {{20, music_audio_slider_description_label.rect.y + music_audio_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, NULL, 0, 200, 1, &music_audio_slider_label, &music_audio_slider_cursor, &slider_style, 1.0, true};
    slider_init(&music_audio_slider, SCALE);


    Label effects_audio_slider_description_label = {{20, 300*SCALE, 0, 0, NO_OUTLINE, NO_INLINE, TOP_LEFT}, "Effects volume", 20, DARK, NULL, NULL, false, 1.0, true};
    label_init(&effects_audio_slider_description_label, SCALE);

    Label effects_audio_slider_label = {EMPTY_UI_ELEMENT, NULL, 20, DARK, NULL, NULL, false, 1.0, true};
    SliderCursor effects_audio_slider_cursor = {{0, 0, 20, 20, outlines[1], NO_INLINE, TOP_LEFT}, NORMAL, &slider_cursor_style};
    Slider effects_audio_slider = {{20, effects_audio_slider_description_label.rect.y + effects_audio_slider_description_label.rect.height, 200, 20, outlines[1], NO_INLINE, TOP_LEFT}, NULL, 0, 200, 1, &effects_audio_slider_label, &effects_audio_slider_cursor, &slider_style, 1.0, true};
    slider_init(&effects_audio_slider, SCALE);


    Button *audio_button_list[] = {};
    Toggle *audio_toggle_list[] = {};
    Slider *audio_slider_list[] = {&master_audio_slider, &music_audio_slider, &effects_audio_slider};
    ColorPicker *audio_picker_list[] = {};
    Label *audio_label_list[] = {&master_audio_slider_description_label, &music_audio_slider_description_label, &effects_audio_slider_description_label};
    Rect *audio_rect_list[] = {};
    Panel audio_panel = {audio_button_list, 0, audio_toggle_list, 0, audio_slider_list, 3, audio_picker_list , 0, audio_label_list, 3, audio_rect_list, 0, false};
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
            mouse_event(event);
        }

        for (int i = 0; i < (int)(sizeof(panels)/sizeof(panels[0])); i++)
        {
            panels[i]->active = false;
        }
        out = group_update(&options_group, SCALE);
        switch (out)
        {
            case RETURN_OPTION_GAMEPLAY_PANEL:
                gameplay_panel.active = true;
                break;
            case RETURN_OPTION_COLOR_PANEL:
                colors_panel.active = true;
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
            label_update(labels[i], SCALE);
            label_render(labels[i], SCALE);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_update();
    }
    panel_list_free(panels, 4);
    group_free(&options_group);
    label_list_free(labels, 1);
    update_scale();
    update_window_size(window, WIDTH, HEIGHT);
    return RETURN_TO_MAIN_MENU;
}
