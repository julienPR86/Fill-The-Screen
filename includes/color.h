#ifndef COLOR_H
#define COLOR_H

//Structure that represents a color with (r, g, b, a) fields
typedef struct Color
{
    int r;
    int g;
    int b;
    int a;
} Color;

//Structure that represents a button style, contains the background, foreground and hover colors
typedef struct ButtonStyle
{
    //Background color
    Color background;
    //Foreground color
    Color foreground;
    //Hover color
    Color hover_color;
} ButtonStyle;

//Structure that represents a slider cursor style, contains the background, foreground and hover colors
typedef struct SliderCursorStyle
{
    //Background color
    Color bg;
    //Background foreground
    Color fg;
    //Hover color
    Color hover_color;
} SliderCursorStyle;

//Structure that represents a slider style, contains the background color
typedef struct SliderStyle
{
    //Background color
    Color background;
} SliderStyle;

//Structure that represents the different squares colors
typedef struct GameColors
{
    //Collision square color
    Color collision_square_color;
    //Empty square color
    Color empty_square_color;
    //Line square color
    Color line_square_color;
    //Player square color
    Color player_square_color;
    //Fake square color
    Color fake_square_color;
} GameColors;

//Structure that represent the colors of each game menus
typedef struct MainColors
{
    //Main menu color
    Color menu_background;
    //Options menu color
    Color options_background;
    //Game mode menu color
    Color game_mode_background;
    //Game background color
    Color game_background;
    //Pause menu color
    Color pause_menu_background;
    //Game stats menu color
    Color game_stats_background;
} MainColors;

//Structure that represent a theme, which is used to color the entire game
typedef struct Theme
{
    //menus colors
    MainColors main_colors;
    //square colors
    GameColors game_colors;
} Theme;

//The default color theme
extern Theme theme;

//The default button style
extern ButtonStyle button_style;
//The default toggle style
extern ButtonStyle toggle_style;
//The default slider style
extern SliderStyle slider_style;
//The default slider cursor style
extern SliderCursorStyle slider_cursor_style;

extern const Color DARK;
extern const Color WHITE;
extern const Color RED;
extern const Color ORANGE;
extern const Color YELLOW;
extern const Color GREEN;
extern const Color BLUE;
extern const Color PURPLE;

//Fonts list
extern TTF_Font **roboto_regular_fonts;
//The max font size used to create the fonts list
extern t_uint max_font_size;

#endif