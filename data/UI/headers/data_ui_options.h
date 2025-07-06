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

void options_data_ui_init();