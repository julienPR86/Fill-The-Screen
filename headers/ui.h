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

enum Anchors
{
    CENTER,
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    MID_LEFT,
    MID_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
};

//UI_Element struct, it represent the base of an UI element, which contains an x and y position, a width and a height
typedef struct UI_Element
{
    //x position
    int x;
    //y position
    int y;
    //width
    int width;
    //height
    int height;
} UI_Element;

//Rect struture
typedef struct Rect
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
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
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
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
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
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

//toggle structure
typedef struct Toggle
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
    //toggle state
    int state;
    //toggle label
    Label *label;
    //toggle style
    ButtonStyle *style;
    //toggle command, is called when the toggle is clicked
    int (*command)();
    //is active parameter
    int active;
} Toggle;

//toggle group structure
typedef struct ToggleGroup
{
    //toggle group
    Toggle **toggles;
    //toggle count
    int count;
    //the selected index
    int selected;
    //is active parameter
    int active;
} ToggleGroup;

//slider cursor structure
typedef struct SliderCursor
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
    //cursor state
    int state;
    //cursor style
    SliderCursorStyle *style;
} SliderCursor;

//slider structure
typedef struct Slider
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
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

//Color picker structure
typedef struct ColorPicker
{
    //The element The element rect, contains the x, y, width and height values
    UI_Element rect;
    //The color rect which display the picked color
    Rect *color_rect;
    //The labels, in order : Picker Title, red slider label, green slider label, blue slider label
    //Labels after the 4th index won't be allocated and used
    Label **labels;
    //The sliders, in order : red slider, green slider, blue slider
    //Sliders after the 3rd index won't be allocated and used
    Slider **sliders;
} ColorPicker;

//panel structure
typedef struct Panel
{
    //buttons
    Button **buttons;
    //buttons count
    int button_count;
    //toggles
    Toggle **toggles;
    //toggles count
    int toggle_count;
    //sliders
    Slider **sliders;
    //sliders count
    int slider_count;
    //color pickers
    ColorPicker **pickers;
    //Color picker count
    int picker_count;
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
void rect_render(Rect *element, float scale);

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

//toggle init, needs to be called before all toggle functions
Toggle *toggle_init(Toggle *toggle);
//update a toggle
int toggle_update(Toggle *toggle);
//render a toggle
void toggle_render(Toggle *toggle, float scale);
//free the toggle's label
void toggle_free(Toggle *toggle);
//free a toggle's list
void toggle_list_free(Toggle *toggle[], int size);
//return the toggle height
int toggle_height(Toggle *toggle, float scale);
//return the toggle width
int toggle_width(Toggle *toggle, float scale);

//toggle group init, needs to be called before all toggle group functions
ToggleGroup *group_init(ToggleGroup *group);
//update a toggle group
int group_update(ToggleGroup *group);
//render a toggle group
void group_render(ToggleGroup *group);
//set all toggles states to normal
void group_clear_selected(ToggleGroup *group);
//free the toggle group
void group_free(ToggleGroup *group);

//label init, needs to be called before all label functions
Label *label_init(Label *label);
//update label
void label_update(Label *label);
//render label
void label_render(Label *label);
//free a label
void label_free(Label *label);
//free a label list
void label_list_free(Label *labels[], int size);

//slider cursor init, needs to be called before all slider cursor functions
SliderCursor *slider_cursor_init(SliderCursor *cursor);
//update slider cursor
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
//free a list of sliders
void slider_list_free(Slider *sliders[], int size);
//Clamp the value of the cursor based on the min and max value
void slider_clamp_value(Slider *slider);
//Updates the slider's cursor position
void slider_set_cursor_position(Slider *slider, float scale);
//Check if the slider cursor is at the right position
int slider_check_cursor_position(Slider * slider, float scale);
//Limits the cursor position
void slider_clamp_cursor_position(Slider *slider, float scale);
//Updates the slider label text based on the slider value
Slider *slider_label_text_update(Slider *slider);
//Updates the slider's label position
void slider_set_label_position(Slider *slider, float scale);
//Calculate the slider value based on the cursor position and the slider step
int slider_get_value(Slider *slider, float scale);
//get slider height
int slider_height(Slider *slider, float scale);
//get slider width
int slider_width(Slider *slider, float scale);

//Color picker init, needs to be called before all picker functions
ColorPicker *picker_init(ColorPicker *picker, float scale);
//update picker
int picker_update(ColorPicker *picker, float scale);
//render picker
void picker_render(ColorPicker *picker, float scale);
//free a picker
void picker_free(ColorPicker *picker);
//free a picker list
void picker_list_free(ColorPicker *pickers[], int size);
//update all picker elements position
void picker_set_positions(ColorPicker *picker, int scale);
//get picker height
int picker_height(ColorPicker *picker, float scale);
//get picker width
int picker_width(ColorPicker *picker, float scale);

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

//Set the position of UI element based on the given position and anchor
void set_UI_element_position(UI_Element *element, int x, int y, float scale, int anchor);

#endif