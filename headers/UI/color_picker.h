#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "../color.h"
#include "UI_Element.h"
#include "rect.h"
#include "label.h"
#include "slider.h"

//Structure that represent a color picker with three sliders for (r, b, g) color values
typedef struct ColorPicker
{
    //The color picker rect, contains its position and its dimensions
    UI_Element rect;
    //The color rectangle that display the actual picked color
    Rect *color_rect;
    //The labels, in order : Picker Title, red slider label, green slider label, blue slider label
    //Labels after the 4th index won't be allocated and used
    Label **labels;
    //The sliders, in order : red slider, green slider, blue slider
    //Sliders after the 3rd index won't be allocated and used
    Slider **sliders;
    //Tells if the color picker is active or not
    t_uint8 active;
} ColorPicker;

//Set the fields of the color picker with the values passed in
ColorPicker *picker_set_fields(ColorPicker *picker, Rect *color_rect, Label **labels, Slider **sliders, t_uint8 active);
//Color picker init, needs to be called before all picker functions except picker_set_fields()
ColorPicker *picker_init(ColorPicker *picker, float scale_x, float scale_y);
//Updates the color picker passed in
int picker_update(ColorPicker *picker, float scale_x, float scale_y);
//Renders the color picker passed in
void picker_render(ColorPicker *picker, float scale_x, float scale_y);
//Frees the color picker passed in
void picker_free(ColorPicker *picker);
//Frees a color picker's array
void picker_list_free(ColorPicker *pickers[], int size);
//Sets the position of all the elements contains in the color picker
void picker_set_positions(ColorPicker *picker, float scale_x, float scale_y);
//Returns the height of the color picker passed in
int picker_get_height(ColorPicker *picker, float scale_y);
//Returns the width of the color picker passed in
int picker_get_width(ColorPicker *picker, float scale_x);
//updates and render an color picker's array
int picker_list_update_and_render(ColorPicker *pickers[], int count);

#endif