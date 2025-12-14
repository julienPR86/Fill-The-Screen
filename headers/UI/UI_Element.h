#ifndef _UI_ELEMENT_H_
#define _UI_ELEMENT_H_

#include "inline.h"
#include "outline.h"

//UI_Element struct, it represent the base of an UI element, which contains an x and y position, a width and a height
typedef struct UI_Element
{
    //x position
    float x;
    //y position
    float y;
    //width
    int width;
    //height
    int height;
    //element outline
    Outline outline;
    //element inline
    Inline inline_;
    //element local scale
    double scale;
    //define the element anchor
    int anchor;
} UI_Element;

//Set the fields of element to the values passed in
UI_Element *UI_Element_set_fields(UI_Element *element, float x, float y, int width, int height, Outline outline, Inline inline_, float scale, int anchor);

//Set the size of element to the size of frame if it's smaller
//!! Do not put a label rect for element, only for frame if necessary !!
//!! Set scale_x and scale_y to 1 except if frame is a label !!
void UI_Element_match_size(UI_Element *element, UI_Element *frame, float scale_x, float scale_y);

//return true if (x, y) is in element, false otherwise
int UI_element_collision(UI_Element *element, float x, float y, float scale_x, float scale_y);
//Positions the element at (x, y) based on the anchor and the scales
void UI_Element_set_position(UI_Element *element, float x, float y, float x_position_factor, float y_position_factor, float scale_x, float scale_y, int anchor);

//Draw the element inline
void UI_Element_render_inline(UI_Element *element, float scale_x, float scale_y);
//Draw the element outline
void UI_Element_render_outline(UI_Element *element, float scale_x, float scale_y);

//return the height of the element
int UI_Element_get_height(UI_Element *element, float scale_y);
//return the width of the element
int UI_Element_get_width(UI_Element *element, float scale_x);

#endif