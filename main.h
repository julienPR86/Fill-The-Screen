#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define true 1
#define false 0

#define CENTERED(a, b) ((a - b) / 2)

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

// Enums ---------------------------------

enum Returns
{
    RETURN_NONE = -1,
    RETURN_SUCCESS,
    RETURN_FAILURE,
    RETURN_EXIT_FULL_GAME,
    RETURN_TO_MAIN_MENU,
    RETURN_TO_GAMEMODE_CHOICE,
    RETURN_TO_GAME,
    RETURN_RESTART_GAME,
    RETURN_OPTION_GAMEPLAY_PANEL,
    RETURN_OPTION_PANEL,
    RETURN_OPTION_VIDEO_PANEL,
    RETURN_OPTION_AUDIO_PANEL,
    RETURN_OPTION_GAMEPLAY_PROBABILITY,
};

enum GameMods
{
    NO_ACTIVE_MODE,
    FILL_MODE,
    DISCOVERY_MODE,
    CONSTRAINT_MODE,
    FREE_MODE,
};

enum SquareStates
{
    COLLISION_SQUARE,
    EMPTY_SQUARE,
    LINE_SQUARE,
    PLAYER_SQUARE,
    FAKE_SQUARE,
};

enum ButtonStates
{
    NORMAL,
    CLICKED,
    HOVERED,
};

enum Anchors
{
    CENTER,
    CENTER_X,
    CENTER_Y,
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
};

// Structs ---------------------------------

typedef struct Player
{
    double x;
    double y;
    int moves;
    int can_move;
    int frame_move;
} Player;

typedef struct
{
    int height;
    int width;
    int square_size;
    int **map;
    int **start_map;
} Map;

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


typedef struct Label
{
    int x;
    int y;
    int w;
    int h;
    float scale;
    char *text;
    TTF_Font *font;
    SDL_Color text_color;
    SDL_Surface *surface;
    SDL_Texture *texture;
    int update;
    int active;
} Label;

typedef struct Button
{
    int x;
    int y;
    int width;
    int height;
    int state;
    Label *label;
    ButtonStyle *style;
    int (*command)();
    int active;
} Button;

typedef struct Toogle
{
    int x;
    int y;
    int width;
    int height;
    int state;
    Label *label;
    ButtonStyle *style;
    int (*command)();
    int active;
} Toogle;

typedef struct ToogleGroup
{
    Toogle **toogles;
    int count;
    int selected;
    int active;
} ToogleGroup;

typedef struct SliderCursor
{
    int x;
    int y;
    int size;
    int state;
    SliderCursorStyle *style;
} SliderCursor;

typedef struct Slider
{
    int x;
    int y;
    int w;
    int h;
    int value;
    int min;
    int max;
    int step;
    SliderCursor *cursor;
    SliderStyle *style;
    int active;
} Slider;

typedef struct Panel
{
    Button **buttons;
    int button_count;
    Slider **sliders;
    int slider_count;
    Label **labels;
    int label_count;
    int active;
} Panel;

// Variables ---------------------------------

extern int WIDTH;
extern int HEIGHT;
extern float SCALEX;
extern float SCALEY;
extern int FPS;
extern int MAX_FPS;
extern double delta_time;
extern int game_speed;
extern int probability;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;

extern int mouse_x;
extern int mouse_y;
extern int mouse_delta_x;
extern int mouse_delta_y;
extern int mouse_button_pressed;

extern int game_mode;

extern Player *player;
extern Map *map;

extern Theme current_theme;
extern Theme basic_theme;
extern const GameColors basic_game_colors;
extern const MainColors basic_main_colors;

extern ButtonStyle current_button_style;
extern ButtonStyle current_toogle_style;
extern SliderStyle current_slider_style;
extern SliderCursorStyle current_slider_cursor_style;

extern const ButtonStyle basic_button_style;
extern const ButtonStyle basic_toogle_style;
extern const SliderCursorStyle basic_slider_cursor_style;
extern const SliderStyle basic_slider_style;


extern TTF_Font *roboto_light;
extern TTF_Font *roboto_regular;
extern int font_size;


extern char *FPS_text;
extern Label FPS_label;

// Functions ---------------------------------

int init();
int map_init();
int player_init();

int exit_game();
void exit_full_game();

int game();
int game_restart();
int game_quit();

Map *map_creation(Map *map);
Map *map_free(Map *map);
Map *map_reset(Map *map, int value);
Map *map_random(Map *map, int value);
void map_print(Map *map);
void map_display(Map *map, int offset_x, int offset_y);
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
int map_get_squares_number(Map *map, int type);
int map_is_filled(Map *map);

void player_move(int x, int y);
void player_reset(Player *player);

int pause_menu();
int back();
int restart();
int main_menu();
int mode_choice();
int fill_mode();
int constraint_mode();
int discovery_mode();
int free_mode();
int option_gameplay();
int option_label();
int option_video();
int option_audio();

Button *button_init(Button *button);
int button_update(Button *button);
void button_render(Button *button);
void button_free(Button *button);
void button_list_free(Button *button[], int size);
void set_button_anchor(Button *button, int anchor, int offset_x, int offset_y);
int button_height(Button *button);
int button_width(Button *button);

Toogle *toogle_init(Toogle *toogle);
int toogle_update(Toogle *toogle);
void toogle_render(Toogle *toogle);
void toogle_free(Toogle *toogle);
void toogle_list_free(Toogle *toogle[], int size);
int toogle_height(Toogle *toogle);
int toogle_width(Toogle *toogle);

ToogleGroup *group_init(ToogleGroup *group);
int group_update(ToogleGroup *group);
void group_render(ToogleGroup *group);
int group_set_toogle_at_index(ToogleGroup *group, Toogle *toogle, int index);
void group_clear_selected(ToogleGroup *group);
void group_free(ToogleGroup *group);

Label *label_init(Label *label);
void label_update(Label *label);
void label_render(Label *label);
void label_free(Label *label);
void label_list_free(Label *labels[], int size);
void set_label_anchor(Label *label, int anchor, int offset_x, int offset_y);

SliderCursor *slider_cursor_init(SliderCursor *cursor);
int slider_cursor_update(SliderCursor *cursor);
void slider_cursor_render(SliderCursor *cursor);

Slider *slider_init(Slider *slider);
int slider_update(Slider *slider);
void slider_render(Slider *slider);
int slider_height(Slider *slider);
int slider_width(Slider *slider);

Panel *panel_init(Panel *panel);
int panel_update(Panel *panel);
void panel_render(Panel *panel);
int panel_set_button_at_index(Panel *panel, Button *button, int index);
int panel_set_label_at_index(Panel *panel, Label *label, int index);
void panel_free(Panel *panel);

int options();

int end_game();

int get_fps();
void cap_fps(Uint64 start_time);
void mouse_pressed(SDL_Event event);
void get_mouse_delta(int *x, int *y);
int button_collision(Button *button, int x, int y);
int toogle_collision(Toogle *toogle, int x, int y);
int slider_cursor_collision(SliderCursor *cursor, int x, int y);

#endif