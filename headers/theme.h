#ifndef _THEME_H_
#define _THEME_H_

typedef struct ButtonStyle
{
    int outline;
    int inline_;
    SDL_Color background;
    SDL_Color foreground;
    SDL_Color hover_color;
    SDL_Color outline_color;
    SDL_Color inline_color;
} ButtonStyle;

typedef struct SliderCursorStyle
{
    int outline;
    SDL_Color bg;
    SDL_Color fg;
    SDL_Color hover_color;
    SDL_Color outline_color;
} SliderCursorStyle;

typedef struct SliderStyle
{
    int outline;
    SDL_Color background;
    SDL_Color outline_color;
} SliderStyle;

typedef struct GameColors
{
    SDL_Color collision_square_color;
    SDL_Color empty_square_color;
    SDL_Color line_square_color;
    SDL_Color player_square_color;
    SDL_Color fake_square_color;
} GameColors;

typedef struct MainColors
{
    SDL_Color menu_background;
    SDL_Color options_background;
    SDL_Color game_mode_background;
    SDL_Color game_background;
    SDL_Color pause_menu_background;
    SDL_Color end_game_background;
} MainColors;

typedef struct Theme
{
    MainColors main_colors;
    GameColors game_colors;
} Theme;

extern Theme theme;

extern ButtonStyle current_button_style;
extern ButtonStyle current_toogle_style;
extern SliderStyle current_slider_style;
extern SliderCursorStyle current_slider_cursor_style;

#endif