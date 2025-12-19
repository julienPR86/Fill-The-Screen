#include "../../../main.h"

Label game_stats_title_label;
Label game_stats_congrats_label;
Label game_stats_percent_label;
Label game_stats_moves_label;
Label game_stats_square_ratio_label;
Label game_stats_back_button_label;
Label game_stats_restart_button_label;
Label game_stats_main_menu_button_label;

Button game_stats_back_button;
Button game_stats_restart_button;
Button game_stats_main_menu_button;

Label *game_stats_labels[4];
Button *game_stats_buttons[3];

void game_stats_data_ui_init()
{
    char percent_text[32];
    snprintf(percent_text, sizeof(percent_text), "You filled %.2f%% of the map !", default_player->stats.fill_percent);
    char moves_text[18 + get_number_digits(default_player->stats.moves)];
    snprintf(moves_text, sizeof(moves_text), "You made %u moves", default_player->stats.moves);
    char square_ratio_text[43 + MAX(default_map->width, default_map->height)];
    snprintf(square_ratio_text, sizeof(square_ratio_text), "Your average filled squares per moves is %.2f !", default_player->stats.filled_square_ratio);

    UI_Element_set_fields(&game_stats_title_label.rect, WINDOW_WIDTH/2, 0, 0, 0, outlines[0], inlines[0], 1.0, TOP_CENTER);
    label_set_fields(&game_stats_title_label, "Game over", 100, RED, false, 1.0, true);
    label_init(&game_stats_title_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_congrats_label.rect, WINDOW_WIDTH/2, 0, 0, 0, outlines[0], inlines[0], 1.0, TOP_CENTER);
    label_set_fields(&game_stats_congrats_label, "Congratulation", 100, RED, false, 1.0, true);
    label_init(&game_stats_congrats_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_percent_label.rect, WINDOW_WIDTH/2, game_stats_congrats_label.rect.y + game_stats_congrats_label.rect.height/SCALE_Y + 30, 0, 0, outlines[0], inlines[0], 1.0, CENTER);
    label_set_fields(&game_stats_percent_label, percent_text, 35, RED, false, 1.0, true);
    label_init(&game_stats_percent_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_moves_label.rect, WINDOW_WIDTH/2, game_stats_percent_label.rect.y + game_stats_percent_label.rect.height/SCALE_Y + 10, 0, 0, outlines[0], inlines[0], 1.0, CENTER);
    label_set_fields(&game_stats_moves_label, moves_text, 35, RED, false, 1.0, true);
    label_init(&game_stats_moves_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_square_ratio_label.rect, WINDOW_WIDTH/2, game_stats_moves_label.rect.y + game_stats_moves_label.rect.height/SCALE_Y + 10, 0, 0, outlines[0], inlines[0], 1.0, CENTER);
    label_set_fields(&game_stats_square_ratio_label, square_ratio_text, 35, RED, false, 1.0, true);
    label_init(&game_stats_square_ratio_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_back_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&game_stats_back_button_label, "Back", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&game_stats_restart_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&game_stats_restart_button_label, "Restart", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&game_stats_main_menu_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], 1.0, NONE);
    label_set_fields(&game_stats_main_menu_button_label, "Main menu", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&game_stats_back_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 150, 50, outlines[2], inlines[1], 1.0, CENTER);
    button_set_fields(&game_stats_back_button, NORMAL, &game_stats_back_button_label, &button_style, &game_state_game, true);
    button_init(&game_stats_back_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_restart_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 150, 50, outlines[2], inlines[1], 1.0, CENTER);
    button_set_fields(&game_stats_restart_button, NORMAL, &game_stats_restart_button_label, &button_style, &restart_game, true);
    button_init(&game_stats_restart_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&game_stats_main_menu_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 150, 50, outlines[2], inlines[1], 1.0, CENTER);
    button_set_fields(&game_stats_main_menu_button, NORMAL, &game_stats_main_menu_button_label, &button_style, &game_state_main_menu, true);
    button_init(&game_stats_main_menu_button, SCALE_X, SCALE_Y);

    if (default_player->stats.fill_percent >= 100.0)
	{
        game_stats_labels[0] = &game_stats_congrats_label;
		label_free(&game_stats_title_label);
	}
    else
	{
        game_stats_labels[0] = &game_stats_title_label;
		label_free(&game_stats_congrats_label);
	}

    game_stats_labels[1] = &game_stats_percent_label;
    game_stats_labels[2] = &game_stats_moves_label;
    game_stats_labels[3] = &game_stats_square_ratio_label;

    game_stats_buttons[0] = &game_stats_back_button;
    game_stats_buttons[1] = &game_stats_restart_button;
    game_stats_buttons[2] = &game_stats_main_menu_button;

    debug_log("Game stats data initialised.");
    return;
}

void game_stats_data_ui_free()
{
	button_list_free(game_stats_buttons, 3);
	label_list_free(game_stats_labels, 4);
	debug_log("game stats data ui freed.");
	return;
}