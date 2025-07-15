#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "../color.h"
#include "UI_Element.h"
#include "label.h"
#include "slider_cursor.h"

//slider structure
typedef struct Slider
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
    //current value
    int *value;
    //Caches the last value of value
    int cache_value;
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

//Set the fields of the slider passed in
Slider *slider_set_fields(Slider *slider, int *value, int min, int max, int step, Label *label, SliderCursor *cursor, SliderStyle *style, int active);
//slider init, needs to be called before all slider functions
Slider *slider_init(Slider *slider, float scale_x, float scale_y);
//update slider
int slider_update(Slider *slider, float scale_x, float scale_y);
//render slider
void slider_render(Slider *slider, float scale_x, float scale_y);
//free a slider
void slider_free(Slider *slider);
//free a list of sliders
void slider_list_free(Slider *sliders[], int size);
//Clamp the value of the cursor based on the min and max value
void slider_clamp_value(Slider *slider);
//Updates the slider's cursor position
void slider_set_cursor_position(Slider *slider);
//Check if the slider cursor is at the right position
int slider_check_cursor_position(Slider * slider);
//Limits the cursor position
void slider_clamp_cursor_position(Slider *slider);
//Updates the slider label text based on the slider value
Slider *slider_label_text_update(Slider *slider);
//Updates the slider's label position
void slider_set_label_position(Slider *slider, float scale_x, float scale_y);
//Calculate the slider value based on the cursor position and the slider step
int slider_get_value(Slider *slider);
//get slider height
int slider_get_height(Slider *slider, float scale_y);
//get slider width
int slider_get_width(Slider *slider, float scale_x);

int slider_list_update_and_render(Slider *sliders[], int count);

#endif