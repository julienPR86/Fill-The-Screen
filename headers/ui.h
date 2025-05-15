#ifndef _UI_H_
#define _UI_H_

#include "theme.h"

//Buttons state
enum ButtonStates
{
    //normal, isn't clicked
    NORMAL,
    //the button is clicked
    CLICKED,
    //the button is hovered
    HOVERED,
};

typedef struct UI_Element
{
    int x;
    int y;
    int width;
    int height;
} UI_Element;

//Rect struture
typedef struct Rect
{
    //x position
    int x;
    //y position
    int y;
    //width
    int w;
    //height
    int h;
    //outline thickness
    int outline;
    //rect color
    Color *rect_color;
    //outline color
    Color outline_color;
} Rect;

//label structure
typedef struct Label
{
    //x position
    int x;
    //y position
    int y;
    //widht
    int w;
    //height
    int h;
    //label text
    char *text;
    //label font
    int font_size;
    //text color
    Color text_color;
    //label surface, needs to be null at declaration, will update in label_init
    SDL_Surface *surface;
    //label texture, needs to be null at declaration, will update in label_init
    SDL_Texture *texture;
    //tells if the surface and textures needs to be updated, if the text changed for example
    int update;
    //is active parameter
    int active;
} Label;

//button structure
typedef struct Button
{
    //x position
    int x;
    //y position
    int y;
    //width
    int width;
    //height
    int height;
    //button state
    int state;
    //button label
    Label *label;
    //button style
    ButtonStyle *style;
    //button command, is called when the button is clicked
    int (*command)();
    //is active parameter
    int active;
} Button;

//toogle structure
typedef struct Toogle
{
    //x position
    int x;
    //y position
    int y;
    //width
    int width;
    //height
    int height;
    //toogle state
    int state;
    //toogle label
    Label *label;
    //toogle style
    ButtonStyle *style;
    //toogle command, is called when the toogle is clicked
    int (*command)();
    //is active parameter
    int active;
} Toogle;

//toogle group structure
typedef struct ToogleGroup
{
    //toogle group
    Toogle **toogles;
    //toogle count
    int count;
    //the selected index
    int selected;
    //is active parameter
    int active;
} ToogleGroup;

//slider cursor structure
typedef struct SliderCursor
{
    //x position
    int x;
    //y position
    int y;
    //square size
    int size;
    //cursor state
    int state;
    //cursor style
    SliderCursorStyle *style;
} SliderCursor;

//slider structure
typedef struct Slider
{
    //x position
    int x;
    // y position
    int y;
    //width
    int w;
    //height
    int h;
    //current value
    int *value;
    //min value
    int min;
    //max value
    int max;
    //step value
    int step;
    //slider label
    Label *label;
    //slider cursor
    SliderCursor *cursor;
    //slider style
    SliderStyle *style;
    //is active parameter
    int active;
} Slider;

//panel structure
typedef struct Panel
{
    //buttons
    Button **buttons;
    //buttons count
    int button_count;
    //toogles
    Toogle **toogles;
    //toogles count
    int toogle_count;
    // sliders
    Slider **sliders;
    //sldiers count
    int slider_count;
    // labels
    Label **labels;
    //labels count
    int label_count;
    //rects
    Rect **rects;
    //rects count
    int rect_count;
    //is active parameter
    int active;
} Panel;

//render a rectangle
void rect_render(Rect *rect, float scale);

//button init, needs to be called before all button functions
Button *button_init(Button *button);
//update a button
int button_update(Button *button);
//render a button
void button_render(Button *button, float scale);
//free the button's label
void button_free(Button *button);
//free a button's list
void button_list_free(Button *button[], int size);
//return the button height
int button_height(Button *button, float scale);
//return the button width
int button_width(Button *button, float scale);

//toogle init, needs to be called before all toogle functions
Toogle *toogle_init(Toogle *toogle);
//update a toogle
int toogle_update(Toogle *toogle);
//render a toogle
void toogle_render(Toogle *toogle, float scale);
//free the toogle's label
void toogle_free(Toogle *toogle);
//free a toogle's list
void toogle_list_free(Toogle *toogle[], int size);
//return the toogle height
int toogle_height(Toogle *toogle, float scale);
//return the toogle width
int toogle_width(Toogle *toogle, float scale);

//toogle group init, needs to be called before all toogle group functions
ToogleGroup *group_init(ToogleGroup *group);
//update a toogle group
int group_update(ToogleGroup *group);
//render a toogle group
void group_render(ToogleGroup *group);
//set all toogles states to normal
void group_clear_selected(ToogleGroup *group);
//free the toogle group
void group_free(ToogleGroup *group);

//label init, needs to be called before all label functions
Label *label_init(Label *label);
//update label
void label_update(Label *label);
//render label
void label_render(Label *label);
//free a label
void label_free(Label *label);
//freea label list
void label_list_free(Label *labels[], int size);

//slider cursor init, needs to be called before all slider cursor functions
SliderCursor *slider_cursor_init(SliderCursor *cursor);
//updaye slider cursor
int slider_cursor_update(SliderCursor *cursor);
//render slider cursor
void slider_cursor_render(SliderCursor *cursor, float scale);

//slider init, needs to be called before all slider functions
Slider *slider_init(Slider *slider, float scale);
//update slider
int slider_update(Slider *slider, float scale);
//render slider
void slider_render(Slider *slider, float scale);
//free a slider
void slider_free(Slider *slider);
//free a slider list
void slider_list_free(Slider *sliders[], int size);
//get slider height
int slider_height(Slider *slider, float scale);
//get slider width
int slider_width(Slider *slider, float scale);

//panel init, needs to be called before all panel functions
Panel *panel_init(Panel *panel);
//update panel
int panel_update(Panel *panel);
//render panel
void panel_render(Panel *panel);
//free a panel
void panel_free(Panel *panel);
//free a panel list
void panel_list_free(Panel *panels[], int count);

#endif