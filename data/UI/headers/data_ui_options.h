#include "../../../headers/ui.h"

extern Label gameplay_toggle_label;
extern Label back_label;
extern Label colors_toggle_label;
extern Label video_toggle_label;
extern Label audio_toggle_label;

extern Toggle gameplay_toggle;
extern Toggle colors_toggle;
extern Toggle video_toggle;
extern Toggle audio_toggle;

extern Toggle *options_toggle_list[4];
extern ToggleGroup options_group;

//Gameplay panel -------

extern Label probability_slider_description_label;
extern Label probability_slider_label;
extern SliderCursor probability_slider_cursor;
extern Slider probability_slider;

extern Label map_width_slider_description_label;
extern Label map_width_slider_label;
extern SliderCursor map_width_slider_cursor;
extern Slider map_width_slider;

extern Label map_height_slider_description_label;
extern Label map_height_slider_label;
extern SliderCursor map_height_slider_cursor;
extern Slider map_height_slider;

extern Label game_speed_slider_description;
extern Label game_speed_slider_label;
extern SliderCursor game_speed_slider_cursor;
extern Slider game_speed_slider;

extern Slider *gameplay_slider_list[4];
extern Label *gameplay_label_list[4];
extern Panel gameplay_panel;

//Color panel ------------------

extern Rect player_color_rect;

extern Label player_red_slider_title_label;
extern Label player_red_slider_description_label;
extern Label player_green_slider_description_label;
extern Label player_blue_slider_description_label;

extern Label player_red_slider_label;
extern SliderCursor player_red_slider_cursor;
extern Slider player_red_slider;

extern Label player_green_slider_label;
extern SliderCursor player_green_slider_cursor;
extern Slider player_green_slider;

extern Label player_blue_slider_label;
extern SliderCursor player_blue_slider_cursor;
extern Slider player_blue_slider;

extern Label *player_picker_label_list[4];
extern Slider *player_picker_slider_list[3];

extern ColorPicker player_picker;


extern Rect collision_square_color_rect;

extern Label collision_square_red_slider_title_label;
extern Label collision_square_red_slider_description_label;
extern Label collision_square_green_slider_description_label;
extern Label collision_square_blue_slider_description_label;

extern Label collision_square_red_slider_label;
extern SliderCursor collision_square_red_slider_cursor;
extern Slider collision_square_red_slider;

extern Label collision_square_green_slider_label;
extern SliderCursor collision_square_green_slider_cursor;
extern Slider collision_square_green_slider;

extern Label collision_square_blue_slider_label;
extern SliderCursor collision_square_blue_slider_cursor;
extern Slider collision_square_blue_slider;

extern Label *collision_square_picker_label_list[4];
extern Slider *collision_square_picker_slider_list[3];

extern ColorPicker collision_square_picker;


extern Rect line_square_color_rect;

extern Label line_square_slider_title_label;
extern Label line_square_red_slider_description_label;
extern Label line_square_green_slider_description_label;
extern Label line_square_blue_slider_description_label;

extern Label line_square_red_slider_label;
extern SliderCursor line_square_red_slider_cursor;
extern Slider line_square_red_slider;

extern Label line_square_green_slider_label;
extern SliderCursor line_square_green_slider_cursor;
extern Slider line_square_green_slider;

extern Label line_square_blue_slider_label;
extern SliderCursor line_square_blue_slider_cursor;
extern Slider line_square_blue_slider;

extern Label *line_square_picker_label_list[4];
extern Slider *line_square_picker_slider_list[3];

extern ColorPicker line_square_picker;


extern Rect empty_square_color_rect;
    
extern Label empty_square_slider_title_label;
extern Label empty_square_red_slider_description_label;
extern Label empty_square_green_slider_description_label;
extern Label empty_square_blue_slider_description_label;

extern Label empty_square_red_slider_label;
extern SliderCursor empty_square_red_slider_cursor;
extern Slider empty_square_red_slider;

extern Label empty_square_green_slider_label;
extern SliderCursor empty_square_green_slider_cursor;
extern Slider empty_square_green_slider;

extern Label empty_square_blue_slider_label;
extern SliderCursor empty_square_blue_slider_cursor;
extern Slider empty_square_blue_slider;

extern Label *empty_square_picker_label_list[4];

extern ColorPicker empty_square_picker;

extern ColorPicker *color_picker_list[4];
extern Panel colors_panel;

//Video panel

void options_data_ui_init();