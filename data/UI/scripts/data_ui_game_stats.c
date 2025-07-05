#include "../../../main.h"

Label title_label;
Label congrats_label;
Label percent_label;
Label moves_label;
Label square_ratio_label;
Label back_button_label;
Label restart_button_label;
Label main_menu_button_label;

Button back_button;
Button restart_button;
Button main_menu_button;

void game_stats_data_ui_init()
{
    int moves = player->moves;
    float percent = 1.0/(map->height*map->width) * 100;
    float square_ratio = 0;
    if (moves)
    {
        if (CONSTRAINT_MODE == game_mode)
        {
            int count = map_get_squares_number(map, EMPTY_SQUARE) + map_get_squares_number(map, COLLISION_SQUARE);
            percent = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
            square_ratio = (float)(map->height*map->width-(map_get_squares_number(map, EMPTY_SQUARE)+map_get_squares_number(map, COLLISION_SQUARE)))/moves;
        }
        else if (DISCOVERY_MODE == game_mode)
        {
            int count = map_get_squares_number(map, EMPTY_SQUARE) + map_get_squares_number(map, FAKE_SQUARE);
            percent = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
            square_ratio = (float)(map->height*map->width-(map_get_squares_number(map, EMPTY_SQUARE)+map_get_squares_number(map, FAKE_SQUARE)))/moves;
        }
        else
        {
            int count = map_get_squares_number(map, EMPTY_SQUARE);
            percent = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
            square_ratio = (float)(map->height*map->width-map_get_squares_number(map, EMPTY_SQUARE))/moves;
        }
    }

    char percent_text[50];
    snprintf(percent_text, sizeof(percent_text), "You filled %.2f%% of the map", percent);
    char moves_text[50];
    snprintf(moves_text, sizeof(moves_text), "You made %d moves", moves);
    char square_ratio_text[50];
    snprintf(square_ratio_text, sizeof(square_ratio_text), "Your average filled squares per move is %.2f", square_ratio);

    UI_Element_set_fields(&title_label.rect, WINDOW_WIDTH/2, 0, 0, 0, outlines[0], inlines[0], TOP_CENTER);
    label_set_fields(&title_label, "Game over", 100, DARK, false, 1.0, true);
    label_init(&title_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&congrats_label.rect, WINDOW_WIDTH/2, 0, 0, 0, outlines[0], inlines[0], TOP_CENTER);
    label_set_fields(&congrats_label, "Congratulation", 100, DARK, false, 1.0, true);
    label_init(&congrats_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&percent_label.rect, WINDOW_WIDTH/2, congrats_label.rect.y + congrats_label.rect.height/SCALE_Y + 30, 0, 0, outlines[0], inlines[0], CENTER);
    label_set_fields(&percent_label, percent_text, 35, DARK, false, 1.0, true);
    label_init(&percent_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&moves_label.rect, WINDOW_WIDTH/2, percent_label.rect.y + percent_label.rect.height/SCALE_Y + 10, 0, 0, outlines[0], inlines[0], CENTER);
    label_set_fields(&moves_label, moves_text, 35, DARK, false, 1.0, true);
    label_init(&moves_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&square_ratio_label.rect, WINDOW_WIDTH/2, moves_label.rect.y + moves_label.rect.height/SCALE_Y + 10, 0, 0, outlines[0], inlines[0], CENTER);
    label_set_fields(&square_ratio_label, square_ratio_text, 35, DARK, false, 1.0, true);
    label_init(&square_ratio_label, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&back_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&back_button_label, "Back", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&restart_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&restart_button_label, "Restart", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&main_menu_button_label.rect, 0, 0, 0, 0, outlines[0], inlines[0], NONE);
    label_set_fields(&main_menu_button_label, "Main menu", 30, DARK, false, 1.0, true);

    UI_Element_set_fields(&back_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&back_button, NORMAL, &back_button_label, &button_style, &back, true);
    button_init(&back_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&restart_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 100, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&restart_button, NORMAL, &restart_button_label, &button_style, &restart, true);
    button_init(&restart_button, SCALE_X, SCALE_Y);

    UI_Element_set_fields(&main_menu_button.rect, WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200, 150, 50, outlines[2], inlines[1], CENTER);
    button_set_fields(&main_menu_button, NORMAL, &main_menu_button_label, &button_style, &main_menu, true);
    button_init(&main_menu_button, SCALE_X, SCALE_Y);

    return;
}