#include "../../../main.h"

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

void options_data_ui_init()
{
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
    return;
}