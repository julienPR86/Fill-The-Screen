#include "../../../main.h"

Label mode_selection_title_label;
Label mode_selection_back_label;
Label mode_selection_fill_mode_button_label;
Label mode_selection_discovery_mode_button_label;
Label mode_selection_constraint_mode_button_label;
Label mode_selection_free_mode_button_label;

Button mode_selection_fill_mode_button;
Button mode_selection_discovery_mode_button;
Button mode_selection_constraint_mode_button;
Button mode_selection_free_mode_button;

Label *mode_selection_labels[2];
Button *mode_selection_buttons[4];

void game_mode_data_ui_init()
{
    UI_Element_set_fields(&mode_selection_title_label.rect, WINDOW_WIDTH/2, 20, 0, 0, outlines[0], inlines[0], TOP_CENTER);
    label_set_fields(&mode_selection_title_label, "Game mode Choice", 100, DARK, false, 1.0, true);
    label_init(&mode_selection_title_label, SCALE_X, SCALE_Y);
        
    UI_Element_set_fields(&mode_selection_back_label.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT - 10, 0, 0, outlines[0], inlines[0], BOTTOM_CENTER);
    label_set_fields(&mode_selection_back_label, "Press Escape to go back", 30, DARK, false, 1.0, true);
    label_init(&mode_selection_back_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&mode_selection_fill_mode_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&mode_selection_fill_mode_button_label, "Fill", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&mode_selection_discovery_mode_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&mode_selection_discovery_mode_button_label, "Discovery", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&mode_selection_constraint_mode_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&mode_selection_constraint_mode_button_label, "Constraint", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&mode_selection_free_mode_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&mode_selection_free_mode_button_label, "Free", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&mode_selection_fill_mode_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 100, 200, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&mode_selection_fill_mode_button, NORMAL, &mode_selection_fill_mode_button_label, &button_style, &fill_mode, true);
    button_init(&mode_selection_fill_mode_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&mode_selection_discovery_mode_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 200, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&mode_selection_discovery_mode_button, NORMAL, &mode_selection_discovery_mode_button_label, &button_style, &discovery_mode, true);
    button_init(&mode_selection_discovery_mode_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&mode_selection_constraint_mode_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 200, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&mode_selection_constraint_mode_button, NORMAL, &mode_selection_constraint_mode_button_label, &button_style, &constraint_mode, true);
    button_init(&mode_selection_constraint_mode_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&mode_selection_free_mode_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 200, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&mode_selection_free_mode_button, NORMAL, &mode_selection_free_mode_button_label, &button_style, &free_mode, true);
    button_init(&mode_selection_free_mode_button, SCALE_X, SCALE_Y);

    mode_selection_labels[0] = &mode_selection_title_label;
    mode_selection_labels[1] = &mode_selection_back_label;

    mode_selection_buttons[0] = &mode_selection_fill_mode_button;
    mode_selection_buttons[1] = &mode_selection_discovery_mode_button;
    mode_selection_buttons[2] = &mode_selection_constraint_mode_button;
    mode_selection_buttons[3] = &mode_selection_free_mode_button;

    return;
}