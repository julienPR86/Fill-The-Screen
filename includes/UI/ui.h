#ifndef UI_H
#define UI_H

#include "array.h"
#include "button.h"
#include "color_picker.h"
#include "inline.h"
#include "label.h"
#include "outline.h"
#include "panel.h"
#include "rect.h"
#include "slider_cursor.h"
#include "slider.h"
#include "toggle_group.h"
#include "toggle.h"
#include "UI_Element.h"

//Buttons state
enum ButtonStates
{
    //normal, isn't clicked
    NORMAL,
    //the button is clicked
    CLICKED,
    //the button is hovered
    HOVERED,
};

enum Anchors
{
    NONE,
    CENTER,
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    MID_LEFT,
    MID_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
};

//The global outline list that contains outlines with different sizes
extern Outline *outlines;

//The global inline list that contains inlines with different sizes
extern Inline *inlines;

#endif