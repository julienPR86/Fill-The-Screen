#include "../../../main.h"

Label pause_menu_title_label;
Label pause_menu_back_button_label;
Label pause_menu_restart_button_label;
Label pause_menu_main_menu_button_label;

Button pause_menu_back_button;
Button pause_menu_restart_button;
Button pause_menu_main_menu_button;

Label *pause_menu_labels[1];
Button *pause_menu_buttons[3];

void pause_menu_data_ui_init()
{
    UI_Element_set_fields(&pause_menu_title_label.rect, WINDOW_WIDTH/2, 0, 0, 0, outlines[0], inlines[0], 1.0, TOP_CENTER);
    label_set_fields(&pause_menu_title_label, "Game Paused", 100, RED, false, 1.0, true);
    label_init(&pause_menu_title_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&pause_menu_back_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&pause_menu_back_button_label, "Back", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&pause_menu_restart_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&pause_menu_restart_button_label, "Restart", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&pause_menu_main_menu_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&pause_menu_main_menu_button_label, "Main menu", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&pause_menu_back_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 150, 50, outlines[2], inlines[1], 1.0, CENTER);
    button_set_fields(&pause_menu_back_button, NORMAL, &pause_menu_back_button_label, &button_style, &game_state_game, true);
    button_init(&pause_menu_back_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&pause_menu_restart_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 150, 50, outlines[2], inlines[1], 1.0, CENTER);
    button_set_fields(&pause_menu_restart_button, NORMAL, &pause_menu_restart_button_label, &button_style, &restart_game, true);
    button_init(&pause_menu_restart_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&pause_menu_main_menu_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 150, 50, outlines[2], inlines[1], 1.0, CENTER);
    button_set_fields(&pause_menu_main_menu_button, NORMAL, &pause_menu_main_menu_button_label, &button_style, &game_state_main_menu, true);
    button_init(&pause_menu_main_menu_button, SCALE_X, SCALE_Y);

    pause_menu_labels[0] = &pause_menu_title_label;

    pause_menu_buttons[0] = &pause_menu_back_button;
    pause_menu_buttons[1] = &pause_menu_restart_button;
    pause_menu_buttons[2] = &pause_menu_main_menu_button;

    debug_log("Pause menu data initialised\n");
    return;
}