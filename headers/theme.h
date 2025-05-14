#ifndef _THEME_H_
#define _THEME_H_

//Color structe which use int, because of slider which uses ints, not int_8
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
    //outline thickness
    int outline;
    //inline thickness
    int inline_;
    //background color
    Color background;
    //foreground color
    Color foreground;
    //hover color
    Color hover_color;
    //outline color
    Color outline_color;
    //inline_color
    Color inline_color;
} ButtonStyle;

//Slider cursor structure
typedef struct SliderCursorStyle
{
    //outline thickness
    int outline;
    //background color
    Color bg;
    //background foreground
    Color fg;
    //hover color
    Color hover_color;
    //outline color
    Color outline_color;
} SliderCursorStyle;

//Slider style
typedef struct SliderStyle
{
    //outline thickness
    int outline;
    //background color
    Color background;
    //outline color
    Color outline_color;
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

//theme structure
typedef struct Theme
{
    //menus colors
    MainColors main_colors;
    //square colors
    GameColors game_colors;
} Theme;

//The theme
extern Theme theme;

//the button style
extern ButtonStyle button_style;
//the toogle style
extern ButtonStyle toogle_style;
//the slider style
extern SliderStyle slider_style;
//the slider cursor style
extern SliderCursorStyle slider_cursor_style;

//Roboto regular font
extern TTF_Font *roboto_regular;
//font size
extern int font_size;

#endif