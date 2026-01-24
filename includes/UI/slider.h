#ifndef SLIDER_H
#define SLIDER_H

#include "../color.h"
#include "UI_Element.h"
#include "label.h"
#include "slider_cursor.h"

//Structures that represents a slider, with a cursor that can be moved to change a value
typedef struct Slider
{
    //The slider rect, contains the position and dimensions
    UI_Element rect;
    //The pointer to the value to change
    int *value;
    //Stores the last value of value
    int cache_value;
    //The minimum value of value
    int min;
    //The maximum value of value
    int max;
    //The increment value for each step of the slider
    int step;
    //The slider label to display the slider value
    Label *label;
    //The slider cursor that can be controlled to change the slider value
    SliderCursor *cursor;
    //The slider style, contains the background color
    SliderStyle *style;
    //Tells if the slider is active or not
    t_uint8 active;
} Slider;

//Set the fields of the slider with the values passed in
Slider *slider_set_fields(Slider *slider, int *value, int min, int max, int step, Label *label, SliderCursor *cursor, SliderStyle *style, t_uint8 active);
//slider init, needs to be called before all slider functions except for slider_set_fields()
Slider *slider_init(Slider *slider, float scale_x, float scale_y);
//Updates the slider passed in 
int slider_update(Slider *slider, float scale_x, float scale_y);
//Renders the slider passed in
void slider_render(Slider *slider, float scale_x, float scale_y);
//Fress the allocated ressources of the slider passed in
void slider_free(Slider *slider);
//Frees an array of sliders
void slider_list_free(Slider *sliders[], t_uint size);
//Clamp the value of the cursor based on the min and max value
void slider_clamp_value(Slider *slider);
//Updates the slider's cursor position
void slider_set_cursor_position(Slider *slider);
//Check if the slider cursor is at the right position
t_uint8 slider_check_cursor_position(Slider * slider);
//Limits the cursor position to the borders of the slider
void slider_clamp_cursor_position(Slider *slider);
//Updates the slider label text based on the slider value
Slider *slider_label_text_update(Slider *slider);
//Updates the slider's label position
void slider_set_label_position(Slider *slider, float scale_x, float scale_y);
//Calculate the slider value based on the cursor position and the slider step
int slider_get_value(Slider *slider);
//Returns the slider height
int slider_get_height(Slider *slider, float scale_y);
//Returns the slider width 
int slider_get_width(Slider *slider, float scale_x);
//Updates and renders an array of sliders
int slider_list_update_and_render(Slider *sliders[], t_uint count);

#endif