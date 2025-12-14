#ifndef SLIDER_CURSOR_H
#define SLIDER_CURSOR_H

#include "../color.h"
#include "UI_Element.h"

//Structure that represent a slider cursor, a simple rectangle
typedef struct SliderCursor
{
    //The cursor rect, contains the position and the dimensions
    UI_Element rect;
    //The state of the cursor, see ButtonStates enum
    t_uint8 state;
    //The cursor style, contains the background, foreground and hover colors
    SliderCursorStyle *style;
} SliderCursor;

//Set the fields of the cursor with the values passed in
SliderCursor *slider_cursor_set_fields(SliderCursor *cursor, t_uint8 state, SliderCursorStyle *style);
//slider cursor init, needs to be called before all slider cursor functions, except for slider_cursor_set_fields()
SliderCursor *slider_cursor_init(SliderCursor *cursor);
//Updates the slider cursor passed in
int slider_cursor_update(SliderCursor *cursor);
//Renders the slider cursor passed in
void slider_cursor_render(SliderCursor *cursor, float scale_x, float scale_y);

#endif