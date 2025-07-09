#ifndef _UI_H_
#define _UI_H_

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

//Outlines
extern Outline *outlines;

//inlines
extern Inline *inlines;

#endif