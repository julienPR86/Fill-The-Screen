#include "../../../headers/UI/ui.h"

extern Label options_back_label;

extern Label options_gameplay_toggle_label;
extern Label options_colors_toggle_label;
extern Label options_video_toggle_label;
extern Label options_audio_toggle_label;

extern Toggle options_gameplay_toggle;
extern Toggle options_colors_toggle;
extern Toggle options_video_toggle;
extern Toggle options_audio_toggle;

extern Array options_toggles_array;

extern Toggle *options_toggle_list[4];
extern ToggleGroup options_group;

//Gameplay panel -------

extern Label options_probability_slider_description_label;
extern Label options_probability_slider_label;
extern SliderCursor options_probability_slider_cursor;
extern Slider options_probability_slider;

extern Label options_map_width_slider_description_label;
extern Label options_map_width_slider_label;
extern SliderCursor options_map_width_slider_cursor;
extern Slider options_map_width_slider;

extern Label options_map_height_slider_description_label;
extern Label options_map_height_slider_label;
extern SliderCursor options_map_height_slider_cursor;
extern Slider options_map_height_slider;

extern Label options_game_speed_slider_description;
extern Label options_game_speed_slider_label;
extern SliderCursor options_game_speed_slider_cursor;
extern Slider options_game_speed_slider;

extern Slider *options_gameplay_slider_list[4];
extern Label *options_gameplay_label_list[4];
extern Panel options_gameplay_panel;

//Color panel ------------------

extern Rect options_player_color_rect;

extern Label options_player_red_slider_title_label;
extern Label options_player_red_slider_description_label;
extern Label options_player_green_slider_description_label;
extern Label options_player_blue_slider_description_label;

extern Label options_player_red_slider_label;
extern SliderCursor options_player_red_slider_cursor;
extern Slider options_player_red_slider;

extern Label options_player_green_slider_label;
extern SliderCursor options_player_green_slider_cursor;
extern Slider options_player_green_slider;

extern Label options_player_blue_slider_label;
extern SliderCursor options_player_blue_slider_cursor;
extern Slider options_player_blue_slider;

extern Label *options_player_picker_label_list[4];
extern Slider *options_player_picker_slider_list[3];

extern ColorPicker options_player_picker;


extern Rect options_collision_square_color_rect;

extern Label options_collision_square_red_slider_title_label;
extern Label options_collision_square_red_slider_description_label;
extern Label options_collision_square_green_slider_description_label;
extern Label options_collision_square_blue_slider_description_label;

extern Label options_collision_square_red_slider_label;
extern SliderCursor options_collision_square_red_slider_cursor;
extern Slider options_collision_square_red_slider;

extern Label options_collision_square_green_slider_label;
extern SliderCursor options_collision_square_green_slider_cursor;
extern Slider options_collision_square_green_slider;

extern Label options_collision_square_blue_slider_label;
extern SliderCursor options_collision_square_blue_slider_cursor;
extern Slider options_collision_square_blue_slider;

extern Label *options_collision_square_picker_label_list[4];
extern Slider *options_collision_square_picker_slider_list[3];

extern ColorPicker options_collision_square_picker;


extern Rect options_line_square_color_rect;

extern Label options_line_square_slider_title_label;
extern Label options_line_square_red_slider_description_label;
extern Label options_line_square_green_slider_description_label;
extern Label options_line_square_blue_slider_description_label;

extern Label options_line_square_red_slider_label;
extern SliderCursor options_line_square_red_slider_cursor;
extern Slider options_line_square_red_slider;

extern Label options_line_square_green_slider_label;
extern SliderCursor options_line_square_green_slider_cursor;
extern Slider options_line_square_green_slider;

extern Label options_line_square_blue_slider_label;
extern SliderCursor options_line_square_blue_slider_cursor;
extern Slider options_line_square_blue_slider;

extern Label *options_options_line_square_picker_label_list[4];
extern Slider *options_options_line_square_picker_slider_list[3];

extern ColorPicker options_line_square_picker;


extern Rect options_empty_square_color_rect;
    
extern Label options_empty_square_slider_title_label;
extern Label options_empty_square_red_slider_description_label;
extern Label options_empty_square_green_slider_description_label;
extern Label options_empty_square_blue_slider_description_label;

extern Label options_empty_square_red_slider_label;
extern SliderCursor options_empty_square_red_slider_cursor;
extern Slider options_empty_square_red_slider;

extern Label options_empty_square_green_slider_label;
extern SliderCursor options_empty_square_green_slider_cursor;
extern Slider options_empty_square_green_slider;

extern Label options_empty_square_blue_slider_label;
extern SliderCursor options_empty_square_blue_slider_cursor;
extern Slider options_empty_square_blue_slider;

extern Label *options_empty_square_picker_label_list[4];
extern Slider *options_empty_square_picker_slider_list[3];

extern ColorPicker options_empty_square_picker;

extern ColorPicker *options_color_picker_list[4];
extern Panel options_colors_panel;

//Video panel

extern Label options_fullscreen_toggle_label;
extern Label options_floating_toggle_label;

extern Toggle options_fullscreen_toggle;
extern Toggle options_floating_toggle;

extern Toggle *options_window_state_toggle_list[2];
extern ToggleGroup options_window_state_group;

extern Label options_max_fps_slider_description_label;

extern Label options_max_fps_slider_label;
extern SliderCursor options_max_fps_slider_cursor;
extern Slider options_max_fps_slider;

extern Slider *options_video_slider_list[1];
extern ToggleGroup *options_video_group_list[1];
extern Label *options_video_label_list[1];
extern Panel options_video_panel;

//Audio panel

extern Label options_master_audio_slider_description_label;

extern Label options_master_audio_slider_label;
extern SliderCursor options_master_audio_slider_cursor ;
extern Slider options_master_audio_slider;

extern Label options_music_audio_slider_description_label;

extern Label options_music_audio_slider_label;
extern SliderCursor options_music_audio_slider_cursor ;
extern Slider options_music_audio_slider;

extern Label options_effects_audio_slider_description_label;

extern Label options_effects_audio_slider_label;
extern SliderCursor options_effects_audio_slider_cursor;
extern Slider options_effects_audio_slider;

extern Slider *options_audio_slider_list[3];
extern Label *options_audio_label_list[3];
extern Panel options_audio_panel;


extern Label *options_labels[1];
extern Panel *options_panels[4];

void options_data_ui_init();