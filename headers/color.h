#ifndef _COLOR_H_
#define _COLOR_H_

//Color struct which use int, because of slider which uses ints, not int_8
typedef struct Color
{
    int r;
    int g;
    int b;
    int a;
} Color;

//button style structure
typedef struct ButtonStyle
{
    //background color
    Color background;
    //foreground color
    Color foreground;
    //hover color
    Color hover_color;
} ButtonStyle;

//Slider cursor structure
typedef struct SliderCursorStyle
{
    //background color
    Color bg;
    //background foreground
    Color fg;
    //hover color
    Color hover_color;
} SliderCursorStyle;

//Slider style
typedef struct SliderStyle
{
    //background color
    Color background;
} SliderStyle;

//Squares color
typedef struct GameColors
{
    //collision square color
    Color collision_square_color;
    //empty square color
    Color empty_square_color;
    //line square color
    Color line_square_color;
    //player square color
    Color player_square_color;
    //fake square color
    Color fake_square_color;
} GameColors;

//Menus color
typedef struct MainColors
{
    //main menu color
    Color menu_background;
    //option menu color
    Color options_background;
    //game mode menu color
    Color game_mode_background;
    //game menu color
    Color game_background;
    //pause menu color
    Color pause_menu_background;
    //game stats menu color
    Color game_stats_background;
} MainColors;

//color structure
typedef struct Theme
{
    //menus colors
    MainColors main_colors;
    //square colors
    GameColors game_colors;
} Theme;

//The color
extern Theme theme;

//the button style
extern ButtonStyle button_style;
//the toggle style
extern ButtonStyle toggle_style;
//the slider style
extern SliderStyle slider_style;
//the slider cursor style
extern SliderCursorStyle slider_cursor_style;

extern const Color DARK;
extern const Color WHITE;
extern const Color RED;
extern const Color ORANGE;
extern const Color YELLOW;
extern const Color GREEN;
extern const Color BLUE;
extern const Color PURPLE;

//Roboto_regular font array
extern TTF_Font **roboto_regular_fonts;
//Roboto_regular array size
extern int max_font_size;

#endif