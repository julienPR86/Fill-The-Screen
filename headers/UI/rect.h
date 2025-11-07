#ifndef _RECT_H_
#define _RECT_H_

#include "../color.h"
#include "UI_Element.h"

//Rect struture
typedef struct Rect
{
    //The element rect, contains the x, y, width, height, outline and inline values
    UI_Element rect;
    //rect color
    Color *rect_color;
} Rect;

//Set the fields of the rect passed in
void rect_set_fields(Rect *rect, Color *color);
//render a rectangle
void rect_render(Rect *element, float scale_x, float scale_y);

int rect_list_update_and_render(Rect *rects[], int count);

#endif