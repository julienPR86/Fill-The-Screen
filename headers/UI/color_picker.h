#ifndef _COLOR_PICKER_H_
#define _COLOR_PICKER_H_

#include "../color.h"
#include "UI_Element.h"
#include "rect.h"
#include "label.h"
#include "slider.h"

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
    //is active parameter
    int active;
} ColorPicker;

//Set the fields of the color picker passed in
ColorPicker *picker_set_fields(ColorPicker *picker, Rect *color_rect, Label **labels, Slider **sliders, int active);
//Color picker init, needs to be called before all picker functions
ColorPicker *picker_init(ColorPicker *picker, float scale_x, float scale_y);
//update picker
int picker_update(ColorPicker *picker, float scale_x, float scale_y);
//render picker
void picker_render(ColorPicker *picker, float scale_x, float scale_y);
//free a picker
void picker_free(ColorPicker *picker);
//free a picker list
void picker_list_free(ColorPicker *pickers[], int size);
//update all picker elements position
void picker_set_positions(ColorPicker *picker, float scale_x, float scale_y);
//get picker height
int picker_get_height(ColorPicker *picker, float scale_y);
//get picker width
int picker_get_width(ColorPicker *picker, float scale_x);

#endif