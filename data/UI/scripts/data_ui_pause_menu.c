#include "../../../main.h"

Label pause_menu_title_label;
Label pause_menu_back_button_label;
Label pause_menu_restart_button_label;
Label pause_menu_main_menu_button_label;

Button pause_menu_back_button;
Button pause_menu_restart_button;
Button pause_menu_main_menu_button;

void pause_menu_data_ui_init()
{
    UI_Element_set_fields(&pause_menu_title_label.rect, WINDOW_WIDTH/2, 0, 0, 0, outlines[0], inlines[0], TOP_CENTER);
    label_set_fields(&pause_menu_title_label, "Game Paused", 100, DARK, false, 1.0, true);
    label_init(&pause_menu_title_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&pause_menu_back_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&pause_menu_back_button_label, "Back", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&pause_menu_restart_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&pause_menu_restart_button_label, "Restart", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&pause_menu_main_menu_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&pause_menu_main_menu_button_label, "Main menu", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&pause_menu_back_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&pause_menu_back_button, NORMAL, &pause_menu_back_button_label, &button_style, &back, true);
    button_init(&pause_menu_back_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&pause_menu_restart_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&pause_menu_restart_button, NORMAL, &pause_menu_restart_button_label, &button_style, &restart, true);
    button_init(&pause_menu_restart_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&pause_menu_main_menu_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&pause_menu_main_menu_button, NORMAL, &pause_menu_main_menu_button_label, &button_style, &main_menu, true);
    button_init(&pause_menu_main_menu_button, SCALE_X, SCALE_Y);

    return;
}