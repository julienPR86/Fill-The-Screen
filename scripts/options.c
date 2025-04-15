#include "../main.h"

int options()
{
    Label gameplay_toogle_label = {0, 0, 0, 0, 0.12, "Gameplay", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label colors_toogle_label = {0, 0, 0, 0, 0.12, "Colors", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label video_toogle_label = {0, 0, 0, 0, 0.12, "Video", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    Label audio_toogle_label = {0, 0, 0, 0, 0.12, "Audio", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};

    Toogle gameplay_toogle = {0, 0, WIDTH/SCALEX/4, HEIGHT/10, NORMAL, &gameplay_toogle_label, &toogle_style, &option_gameplay, true};
    toogle_init(&gameplay_toogle);
    Toogle colors_toogle = {toogle_width(&gameplay_toogle), 0, WIDTH/SCALEX/4, HEIGHT/10, NORMAL, &colors_toogle_label, &toogle_style, &option_label, true};
    toogle_init(&colors_toogle);
    Toogle video_toogle = {colors_toogle.x + toogle_width(&colors_toogle), 0, WIDTH/SCALEX/4, HEIGHT/10, NORMAL, &video_toogle_label, &toogle_style, &option_video, true};
    toogle_init(&video_toogle);
    Toogle audio_toogle = {video_toogle.x + toogle_width(&video_toogle), 0, WIDTH/SCALEX/4, HEIGHT/10, NORMAL, &audio_toogle_label, &toogle_style, &option_audio, true};
    toogle_init(&audio_toogle);

    Toogle *options_toogle_list[] = {&gameplay_toogle, &colors_toogle, &video_toogle, &audio_toogle};
    ToogleGroup options_group = {options_toogle_list, 4, 0, true};
    group_init(&options_group);

    // Gameplay panel ----------------------------------------------------------------
    
    Label probability_silder_description_label = {20, 150*SCALEY, 0, 0, 0.075, "Blocks spawn probability", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&probability_silder_description_label);

    Label probability_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor probability_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider probability_slider = {20, probability_silder_description_label.y + probability_silder_description_label.h * probability_silder_description_label.scale, 200, 20, &probability, 1, 100, 1, &probability_slider_label, &probability_slider_cursor, &slider_style, true};
    slider_init(&probability_slider);


    Label map_width_slider_description_label = {20, 225*SCALEY, 0, 0, 0.075, "Map width", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&map_width_slider_description_label);

    Label map_width_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor map_width_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider map_width_slider = {20, map_width_slider_description_label.y + map_width_slider_description_label.h * map_width_slider_description_label.scale, 200, 20, &map_width, 2, 100, 1, &map_width_slider_label, &map_width_slider_cursor, &slider_style, true};
    slider_init(&map_width_slider);


    Label map_height_slider_description_label = {20, 300*SCALEY, 0, 0, 0.075, "Map height", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&map_height_slider_description_label);

    Label map_height_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor map_height_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider map_height_slider = {20, map_height_slider_description_label.y + map_height_slider_description_label.h * map_height_slider_description_label.scale, 200, 20, &map_height, 2, 100, 1, &map_height_slider_label, &map_height_slider_cursor, &slider_style, true};
    slider_init(&map_height_slider);


    Label game_speed_slider_description = {20, 375*SCALEY, 0, 0, 0.075, "Game speed", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&game_speed_slider_description);

    Label game_speed_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor game_speed_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider game_speed_slider = {20, game_speed_slider_description.y + game_speed_slider_description.h * game_speed_slider_description.scale, 300, 20, &game_speed, 1, 300, 1, &game_speed_slider_label, &game_speed_slider_cursor, &slider_style, true};
    slider_init(&game_speed_slider);


    Button *gameplay_button_list[] = {};
    Toogle *gameplay_toogle_list[] = {};
    Slider *gameplay_slider_list[] = {&probability_slider, &map_width_slider, &map_height_slider, &game_speed_slider};
    Label *gameplay_label_list[] = {&probability_silder_description_label, &map_width_slider_description_label, &map_height_slider_description_label, &game_speed_slider_description};
    Rect *gameplay_rect_list[] = {};
    Panel gameplay_panel = {gameplay_button_list, 0, gameplay_toogle_list, 0, gameplay_slider_list, 4, gameplay_label_list, 4, gameplay_rect_list, 0, true};
    panel_init(&gameplay_panel);

    // colors panel --------------------------------------------------------------------------

    Label player_red_slider_title_label = {20, 120*SCALEY, 0, 0, 0.1, "Player color", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&player_red_slider_title_label);

    Rect player_color_rect = {player_red_slider_title_label.x + player_red_slider_title_label.w * player_red_slider_title_label.scale + 15*SCALEX, player_red_slider_title_label.y - 5 * SCALEY, 50*SCALEX, 50*SCALEY, 2, &theme.game_colors.player_square_color, {0, 0, 0, 255}};

    Label player_red_slider_description_label = {20, 150*SCALEY, 0, 0, 0.075, "Red", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&player_red_slider_description_label);

    Label player_red_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor player_red_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider player_red_slider = {20, player_red_slider_description_label.y + player_red_slider_description_label.h * player_red_slider_description_label.scale, 256, 20, (int *)&theme.game_colors.player_square_color.r, 0, 255, 1, &player_red_slider_label, &player_red_slider_cursor, &slider_style, true};
    slider_init(&player_red_slider);

    Label player_green_slider_description_label = {20, 200*SCALEY, 0, 0, 0.075, "Green", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&player_green_slider_description_label);

    Label player_green_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor player_green_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider player_green_slider = {20, player_green_slider_description_label.y + player_green_slider_description_label.h * player_green_slider_description_label.scale, 256, 20, (int *)&theme.game_colors.player_square_color.g, 0, 255, 1, &player_green_slider_label, &player_green_slider_cursor, &slider_style, true};
    slider_init(&player_green_slider);

    Label player_blue_slider_description_label = {20, 250*SCALEY, 0, 0, 0.075, "Blue", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&player_blue_slider_description_label);

    Label player_blue_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor player_blue_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider player_blue_slider = {20, player_blue_slider_description_label.y + player_blue_slider_description_label.h * player_blue_slider_description_label.scale, 256, 20, (int *)&theme.game_colors.player_square_color.b, 0, 255, 1, &player_blue_slider_label, &player_blue_slider_cursor, &slider_style, true};
    slider_init(&player_blue_slider);


    Label collision_square_red_slider_title_label = {350, 120*SCALEY, 0, 0, 0.1, "Blocks color", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&collision_square_red_slider_title_label);

    Rect collision_square_color_rect = {collision_square_red_slider_title_label.x + collision_square_red_slider_title_label.w * collision_square_red_slider_title_label.scale + 15*SCALEX, collision_square_red_slider_title_label.y - 5 * SCALEY, 50*SCALEX, 50*SCALEY, 2, &theme.game_colors.collision_square_color, {0, 0, 0, 255}};

    Label collision_square_red_slider_description_label = {350, 150*SCALEY, 0, 0, 0.075, "Red", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&collision_square_red_slider_description_label);

    Label collision_square_red_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor collision_square_red_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider collision_square_red_slider = {350, collision_square_red_slider_description_label.y + collision_square_red_slider_description_label.h * collision_square_red_slider_description_label.scale, 256, 20, &theme.game_colors.collision_square_color.r, 0, 255, 1, &collision_square_red_slider_label, &collision_square_red_slider_cursor, &slider_style, true};
    slider_init(&collision_square_red_slider);

    Label collision_square_green_slider_description_label = {350, 200*SCALEY, 0, 0, 0.075, "Green", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&collision_square_green_slider_description_label);

    Label collision_square_green_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor collision_square_green_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider collision_square_green_slider = {350, collision_square_green_slider_description_label.y + collision_square_green_slider_description_label.h * collision_square_green_slider_description_label.scale, 256, 20, &theme.game_colors.collision_square_color.g, 0, 255, 1, &collision_square_green_slider_label, &collision_square_green_slider_cursor, &slider_style, true};
    slider_init(&collision_square_green_slider);

    Label collision_square_blue_slider_description_label = {350, 250*SCALEY, 0, 0, 0.075, "Blue", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&collision_square_blue_slider_description_label);

    Label collision_square_blue_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor collision_square_blue_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider collision_square_blue_slider = {350, collision_square_blue_slider_description_label.y + collision_square_blue_slider_description_label.h * collision_square_blue_slider_description_label.scale, 256, 20, &theme.game_colors.collision_square_color.b, 0, 255, 1, &collision_square_blue_slider_label, &collision_square_blue_slider_cursor, &slider_style, true};
    slider_init(&collision_square_blue_slider);


    Label line_square_red_slider_title_label = {700, 120*SCALEY, 0, 0, 0.1, "Line color", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&line_square_red_slider_title_label);

    Rect line_square_color_rect = {line_square_red_slider_title_label.x + line_square_red_slider_title_label.w * line_square_red_slider_title_label.scale + 15*SCALEX, line_square_red_slider_title_label.y - 5 * SCALEY, 50*SCALEX, 50*SCALEY, 2, &theme.game_colors.line_square_color, {0, 0, 0, 255}};

    Label line_square_red_slider_description_label = {700, 150*SCALEY, 0, 0, 0.075, "Red", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&line_square_red_slider_description_label);

    Label line_square_red_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor line_square_red_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider line_square_red_slider = {700, line_square_red_slider_description_label.y + line_square_red_slider_description_label.h * line_square_red_slider_description_label.scale, 256, 20, &theme.game_colors.line_square_color.r, 0, 255, 1, &line_square_red_slider_label, &line_square_red_slider_cursor, &slider_style, true};
    slider_init(&line_square_red_slider);

    Label line_square_green_slider_description_label = {700, 200*SCALEY, 0, 0, 0.075, "Green", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&line_square_green_slider_description_label);

    Label line_square_green_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor line_square_green_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider line_square_green_slider = {700, line_square_green_slider_description_label.y + line_square_green_slider_description_label.h * line_square_green_slider_description_label.scale, 256, 20, &theme.game_colors.line_square_color.g, 0, 255, 1, &line_square_green_slider_label, &line_square_green_slider_cursor, &slider_style, true};
    slider_init(&line_square_green_slider);

    Label line_square_blue_slider_description_label = {700, 250*SCALEY, 0, 0, 0.075, "Blue", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&line_square_blue_slider_description_label);

    Label line_square_blue_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor line_square_blue_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider line_square_blue_slider = {700, line_square_blue_slider_description_label.y + line_square_blue_slider_description_label.h * line_square_blue_slider_description_label.scale, 256, 20, &theme.game_colors.line_square_color.b, 0, 255, 1, &line_square_blue_slider_label, &line_square_blue_slider_cursor, &slider_style, true};
    slider_init(&line_square_blue_slider);


    Label empty_square_red_slider_title_label = {20, 370*SCALEY, 0, 0, 0.1, "Background color", roboto_regular, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&empty_square_red_slider_title_label);

    Rect empty_square_color_rect = {empty_square_red_slider_title_label.x + empty_square_red_slider_title_label.w * empty_square_red_slider_title_label.scale + 15*SCALEX, empty_square_red_slider_title_label.y - 5 * SCALEY, 50*SCALEX, 50*SCALEY, 2, &theme.game_colors.empty_square_color, {0, 0, 0, 255}};

    Label empty_square_red_slider_description_label = {20, 400*SCALEY, 0, 0, 0.075, "Red", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&empty_square_red_slider_description_label);

    Label empty_square_red_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor empty_square_red_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider empty_square_red_slider = {20, empty_square_red_slider_description_label.y + empty_square_red_slider_description_label.h * empty_square_red_slider_description_label.scale, 256, 20, &theme.game_colors.empty_square_color.r, 0, 255, 1, &empty_square_red_slider_label, &empty_square_red_slider_cursor, &slider_style, true};
    slider_init(&empty_square_red_slider);

    Label empty_square_green_slider_description_label = {20, 450*SCALEY, 0, 0, 0.075, "Green", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&empty_square_green_slider_description_label);

    Label empty_square_green_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor empty_square_green_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider empty_square_green_slider = {20, empty_square_green_slider_description_label.y + empty_square_green_slider_description_label.h * empty_square_green_slider_description_label.scale, 256, 20, &theme.game_colors.empty_square_color.g, 0, 255, 1, &empty_square_green_slider_label, &empty_square_green_slider_cursor, &slider_style, true};
    slider_init(&empty_square_green_slider);

    Label empty_square_blue_slider_description_label = {20, 500*SCALEY, 0, 0, 0.075, "Blue", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&empty_square_blue_slider_description_label);

    Label empty_square_blue_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor empty_square_blue_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider empty_square_blue_slider = {20, empty_square_blue_slider_description_label.y + empty_square_blue_slider_description_label.h * empty_square_blue_slider_description_label.scale, 256, 20, &theme.game_colors.empty_square_color.b, 0, 255, 1, &empty_square_blue_slider_label, &empty_square_blue_slider_cursor, &slider_style, true};
    slider_init(&empty_square_blue_slider);


    Button *colors_button_list[] = {};
    Toogle *colors_toogle_list[] = {};
    Slider *colors_slider_list[] = {&player_red_slider, &player_green_slider, &player_blue_slider, &collision_square_red_slider, &collision_square_green_slider, &collision_square_blue_slider, &line_square_red_slider, &line_square_green_slider, &line_square_blue_slider, &empty_square_red_slider, &empty_square_green_slider, &empty_square_blue_slider};
    Label *colors_label_list[] = {&player_red_slider_title_label, &player_red_slider_description_label, &player_green_slider_description_label, &player_blue_slider_description_label, &collision_square_red_slider_title_label, &collision_square_red_slider_description_label, &collision_square_green_slider_description_label, &collision_square_blue_slider_description_label, &line_square_red_slider_title_label, &line_square_red_slider_description_label, &line_square_green_slider_description_label, &line_square_blue_slider_description_label, &empty_square_red_slider_title_label, &empty_square_red_slider_description_label, &empty_square_green_slider_description_label, &empty_square_blue_slider_description_label};
    Rect *color_rect_list[] = {&player_color_rect, &collision_square_color_rect, &line_square_color_rect , &empty_square_color_rect};
    Panel colors_panel = {colors_button_list, 0, colors_toogle_list, 0, colors_slider_list, 12, colors_label_list, 16, color_rect_list, 4, false};
    panel_init(&colors_panel);

    // Video panel --------------------------------------------------------------------

    Label max_fps_silder_description_label = {20, 150*SCALEY, 0, 0, 0.075, "Max FPS", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&max_fps_silder_description_label);

    Label max_fps_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor max_fps_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider max_fps_slider = {20, max_fps_silder_description_label.y + max_fps_silder_description_label.h * max_fps_silder_description_label.scale, 200, 20, &MAX_FPS, 30, 240, 1, &max_fps_slider_label, &max_fps_slider_cursor, &slider_style, true};
    slider_init(&max_fps_slider);

    Button *video_button_list[] = {};
    Toogle *video_toogle_list[] = {};
    Slider *video_slider_list[] = {&max_fps_slider};
    Label *video_label_list[] = {&max_fps_silder_description_label};
    Rect *video_rect_list[] = {};
    Panel video_panel = {video_button_list, 0, video_toogle_list, 0, video_slider_list, 1, video_label_list, 1, video_rect_list, 0, false};
    panel_init(&video_panel);

    // Audio panel --------------------------------------------------------------------

    Label master_audio_silder_description_label = {20, 150*SCALEY, 0, 0, 0.075, "Master volume", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&master_audio_silder_description_label);

    Label master_audio_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor master_audio_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider master_audio_slider = {20, master_audio_silder_description_label.y + master_audio_silder_description_label.h * master_audio_silder_description_label.scale, 200, 20, NULL, 30, 240, 1, &master_audio_slider_label, &master_audio_slider_cursor, &slider_style, true};
    slider_init(&master_audio_slider);


    Label music_audio_silder_description_label = {20, 225*SCALEY, 0, 0, 0.075, "Music volume", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&music_audio_silder_description_label);

    Label music_audio_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor music_audio_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider music_audio_slider = {20, music_audio_silder_description_label.y + music_audio_silder_description_label.h * music_audio_silder_description_label.scale, 200, 20, NULL, 30, 240, 1, &music_audio_slider_label, &music_audio_slider_cursor, &slider_style, true};
    slider_init(&music_audio_slider);


    Label effects_audio_silder_description_label = {20, 300*SCALEY, 0, 0, 0.075, "Effects volume", roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    label_init(&effects_audio_silder_description_label);

    Label effects_audio_slider_label = {0, 0, 0, 0, 0.06, NULL, roboto_light, {0, 0, 0, 255}, NULL, NULL, false, true};
    SliderCursor effects_audio_slider_cursor = {0, 0, 0, NORMAL, &slider_cursor_style};
    Slider effects_audio_slider = {20, effects_audio_silder_description_label.y + effects_audio_silder_description_label.h * effects_audio_silder_description_label.scale, 200, 20, NULL, 30, 240, 1, &effects_audio_slider_label, &effects_audio_slider_cursor, &slider_style, true};
    slider_init(&effects_audio_slider);


    Button *audio_button_list[] = {};
    Toogle *audio_toogle_list[] = {};
    Slider *audio_slider_list[] = {&master_audio_slider, &music_audio_slider, &effects_audio_slider};
    Label *audio_label_list[] = {&master_audio_silder_description_label, &music_audio_silder_description_label, &effects_audio_silder_description_label};
    Rect *audio_rect_list[] = {};
    Panel audio_panel = {audio_button_list, 0, audio_toogle_list, 0, audio_slider_list, 3, audio_label_list, 3, audio_rect_list, 0, false};
    panel_init(&audio_panel);

    // panels end ---------------------

    Label *labels[] = {&FPS_label};
    Panel *panels[] = {&gameplay_panel, &colors_panel, &video_panel, &audio_panel};

    int running = true, out;
    Uint64 start_time;
    while (running)
    {
        start_time = SDL_GetTicks64();
        FPS = get_fps();

        get_mouse_delta(&mouse_delta_x, &mouse_delta_y);
        SDL_GetMouseState(&mouse_x, &mouse_y);
        
        SDL_SetRenderDrawColor(renderer, theme.main_colors.options_background.r, theme.main_colors.options_background.g, theme.main_colors.options_background.b, theme.main_colors.options_background.a);
        SDL_RenderClear(renderer);//background

        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                panel_list_free(panels, 4);
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
            mouse_event(event);
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
            label_update(labels[i]);
            label_render(labels[i]);
        }

        SDL_RenderPresent(renderer);
        cap_fps(start_time);
        mouse_event_reset();
    }
    panel_list_free(panels, 4);
    group_free(&options_group);
    label_list_free(labels, 1);
    return RETURN_TO_MAIN_MENU;
}
