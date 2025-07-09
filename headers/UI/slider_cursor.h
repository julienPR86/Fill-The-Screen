#ifndef _SLIDER_CURSOR_H_
#define _SLIDER_CURSOR_H_

#include "../color.h"
#include "UI_Element.h"

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

//Set the fields of the cursor passed in
SliderCursor *slider_cursor_set_fields(SliderCursor *cursor, int state, SliderCursorStyle *style);
//slider cursor init, needs to be called before all slider cursor functions
SliderCursor *slider_cursor_init(SliderCursor *cursor);
//update slider cursor
int slider_cursor_update(SliderCursor *cursor);
//render slider cursor
void slider_cursor_render(SliderCursor *cursor, float scale_x, float scale_y);

#endif