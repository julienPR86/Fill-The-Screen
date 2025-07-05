#include "../../../headers/ui.h"

extern Label gameplay_toggle_label;
extern Label colors_toggle_label;
extern Label video_toggle_label;
extern Label audio_toggle_label;

extern Toggle gameplay_toggle;
extern Toggle colors_toggle;
extern Toggle video_toggle;
extern Toggle audio_toggle;

extern Toggle *options_toggle_list[4];

extern ToggleGroup options_group;

void options_data_ui_init();