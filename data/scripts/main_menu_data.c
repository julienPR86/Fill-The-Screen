#include "../../main.h"

Label title_label;
Label play_button_label;
Label options_button_label;
Label exit_button_label;

Button play_button;
Button options_button;
Button exit_button;

void main_menu_data_init()
{
    UI_Element_set_fields(&title_label.rect, WINDOW_WIDTH/2, 10, 0, 0, outlines[0], inlines[0], TOP_CENTER);
    label_set_fields(&title_label, "FIll The Screen", 100, DARK, 0, 1.0, 1);
    label_init(&title_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&play_button_label.rect, 0, 10, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&play_button_label, "PLAY", 30, DARK, 0, 1.0, 1);

    UI_Element_set_fields(&options_button_label.rect, 0, 10, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&options_button_label, "options", 30, DARK, 0, 1.0, 1);

    UI_Element_set_fields(&exit_button_label.rect,0, 10, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&exit_button_label, "Quit", 30, DARK, 0, 1.0, 1);


    UI_Element_set_fields(&play_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&play_button, NORMAL, &play_button_label, &button_style, &mode_choice, true);
    button_init(&play_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&options_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&options_button, NORMAL, &options_button_label, &button_style, &options, true);
    button_init(&options_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&exit_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&exit_button, NORMAL, &exit_button_label, &button_style, &exit_game, true);
    button_init(&exit_button, SCALE_X, SCALE_Y);

    return;
}