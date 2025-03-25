#ifndef _UI_H_
#define _UI_H_

#include "theme.h"

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

typedef struct Rect
{
    SDL_Rect rect;
    Color color;
} Rect;

typedef struct Label
{
    int x;
    int y;
    int w;
    int h;
    float scale;
    char *text;
    TTF_Font *font;
    Color text_color;
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
    int *value;
    int min;
    int max;
    int step;
    Label *label;
    SliderCursor *cursor;
    SliderStyle *style;
    int active;
} Slider;

typedef struct Panel
{
    Button **buttons;
    int button_count;
    Toogle **toogles;
    int toogle_count;
    Slider **sliders;
    int slider_count;
    Label **labels;
    int label_count;
    SDL_Rect **rects;
    int rect_count;
    int active;
} Panel;

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
void slider_free(Slider *slider);
void slider_list_free(Slider *sliders[], int size);
int slider_height(Slider *slider);
int slider_width(Slider *slider);

Panel *panel_init(Panel *panel);
int panel_update(Panel *panel);
void panel_render(Panel *panel);
void panel_free(Panel *panel);
void panel_list_free(Panel *panels[], int count);

#endif