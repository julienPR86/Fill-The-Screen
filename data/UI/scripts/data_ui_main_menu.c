#include "../../../main.h"

Label main_menu_title_label;
Label main_menu_play_button_label;
Label main_menu_options_button_label;
Label main_menu_exit_button_label;

Button main_menu_play_button;
Button main_menu_options_button;
Button main_menu_exit_button;

Array main_menu_buttons_array;

Label *main_menu_labels[1];
Button *main_menu_buttons[3];

void main_menu_data_ui_init()
{
    UI_Element_set_fields(&main_menu_title_label.rect, WINDOW_WIDTH/2, 10, 0, 0, outlines[0], inlines[0], 1.0, TOP_CENTER);
    label_set_fields(&main_menu_title_label, "Fill The Screen", 100, RED, 0, 1.0, 1);
    label_init(&main_menu_title_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&main_menu_play_button_label.rect, 0, 10, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&main_menu_play_button_label, "PLAY", 30, DARK, 0, 1.0, 1);

    UI_Element_set_fields(&main_menu_options_button_label.rect, 0, 10, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&main_menu_options_button_label, "Options", 30, DARK, 0, 1.0, 1);

    UI_Element_set_fields(&main_menu_exit_button_label.rect,0, 10, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&main_menu_exit_button_label, "Quit", 30, DARK, 0, 1.0, 1);


    UI_Element_set_fields(&main_menu_play_button.rect, 0, 0, 150, 50, outlines[2], inlines[1], 1.0, NONE);
    button_set_fields(&main_menu_play_button, NORMAL, &main_menu_play_button_label, &button_style, &game_state_mode_selection, true);
    button_init(&main_menu_play_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&main_menu_options_button.rect, 0, 0, 150, 50, outlines[2], inlines[1], 1.0, NONE);
    button_set_fields(&main_menu_options_button, NORMAL, &main_menu_options_button_label, &button_style, &game_state_options, true);
    button_init(&main_menu_options_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&main_menu_exit_button.rect, 0, 0, 150, 50, outlines[2], inlines[1], 1.0, NONE);
    button_set_fields(&main_menu_exit_button, NORMAL, &main_menu_exit_button_label, &button_style, &game_state_exit_main_menu, true);
    button_init(&main_menu_exit_button, SCALE_X, SCALE_Y);

    UI_Element *button_elements_list[3] = {&main_menu_play_button.rect, &main_menu_options_button.rect, &main_menu_exit_button.rect};
    UI_Element_set_fields(&main_menu_buttons_array.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0, 0, outlines[1], inlines[0], 1, CENTER);
    array_set_fields(&main_menu_buttons_array, button_elements_list, 3, 1, 10, CENTER);
    array_init(&main_menu_buttons_array);

    main_menu_labels[0] = &main_menu_title_label;
    
    main_menu_buttons[0] = &main_menu_play_button;
    main_menu_buttons[1] = &main_menu_options_button;
    main_menu_buttons[2] = &main_menu_exit_button;
    debug_log("Main menu data initialised\n");
    return;
}