#ifndef _THEME_H_
#define _THEME_H_

typedef struct Color
{
    int r;
    int g;
    int b;
    int a;
} Color;

typedef struct ButtonStyle
{
    int outline;
    int inline_;
    Color background;
    Color foreground;
    Color hover_color;
    Color outline_color;
    Color inline_color;
} ButtonStyle;

typedef struct SliderCursorStyle
{
    int outline;
    Color bg;
    Color fg;
    Color hover_color;
    Color outline_color;
} SliderCursorStyle;

typedef struct SliderStyle
{
    int outline;
    Color background;
    Color outline_color;
} SliderStyle;

typedef struct GameColors
{
    Color collision_square_color;
    Color empty_square_color;
    Color line_square_color;
    Color player_square_color;
    Color fake_square_color;
} GameColors;

typedef struct MainColors
{
    Color menu_background;
    Color options_background;
    Color game_mode_background;
    Color game_background;
    Color pause_menu_background;
    Color end_game_background;
} MainColors;

typedef struct Theme
{
    MainColors main_colors;
    GameColors game_colors;
} Theme;

extern Theme theme;

extern ButtonStyle button_style;
extern ButtonStyle toogle_style;
extern SliderStyle slider_style;
extern SliderCursorStyle slider_cursor_style;

#endif