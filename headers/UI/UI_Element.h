#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "inline.h"
#include "outline.h"

//UI_Element struct, it represent the base of an UI object.
//It contains an x and y position, a width, a height, an outline, an inline, a scale and an anchor
typedef struct UI_Element
{
    //The x position of the element
    int	x;
    //The y position of the element
    int	y;
    //The element width
    int	width;
    //The element height
    int	height;
    //The element outline
    Outline outline;
    //the elements inline
    Inline inline_;
    //The element local scale
    double scale;
    //The element anchor
    t_uint8 anchor;
} UI_Element;

//Set the fields of element to the values passed in
UI_Element *UI_Element_set_fields(UI_Element *element, int x, int y, int width, int height, Outline outline, Inline inline_, double scale, t_uint8 anchor);
//Set the size of element to the size of frame if it's smaller
//!! Do not put a label rect for element, only for frame if necessary !!
//!! Set scale_x and scale_y to 1 except if frame is a label !!
void UI_Element_match_size(UI_Element *element, UI_Element *frame, float scale_x, float scale_y);
//Returns true if (x, y) is in element, false otherwise
int UI_element_collision(UI_Element *element, int x, int y, float scale_x, float scale_y);
//Positions the element at (x, y) based on the anchor and the scales
void UI_Element_set_position(UI_Element *element, int x, int y, int x_position_factor, int y_position_factor, float scale_x, float scale_y, int anchor);
//Draws the element inline
void UI_Element_render_inline(UI_Element *element, float scale_x, float scale_y);
//Draws the element outline
void UI_Element_render_outline(UI_Element *element, float scale_x, float scale_y);
//Returns the element height
int UI_Element_get_height(UI_Element *element, float scale_y);
//Returns the element width
int UI_Element_get_width(UI_Element *element, float scale_x);

#endif