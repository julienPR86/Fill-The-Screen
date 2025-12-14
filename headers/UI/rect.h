#ifndef RECT_H
#define RECT_H

#include "../color.h"
#include "UI_Element.h"

//Structure that represent a rectangle with an unique color
typedef struct Rect
{
    //The rectangle rect, contains position and dimensions
    UI_Element rect;
    //The rectangle color
    Color *rect_color;
} Rect;

//Set the fields of the rectangle with the values passed in
void rect_set_fields(Rect *rect, Color *color);
//Renders the rectangle passed in
void rect_render(Rect *element, float scale_x, float scale_y);
//Updates and renders an array of rectangles
int rect_list_update_and_render(Rect *rects[], int count);

#endif