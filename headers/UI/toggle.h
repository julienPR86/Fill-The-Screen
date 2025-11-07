#ifndef _TOGGLE_H_
#define _TOGGLE_H_

#include "../color.h"
#include "UI_Element.h"
#include "label.h"

//toggle structure
typedef struct Toggle
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
    //toggle state
    int state;
    //toggle label
    Label *label;
    //toggle style
    ButtonStyle *style;
    //toggle command, is called when the toggle is clicked
    int (*command)();
    //is active parameter
    int active;
} Toggle;

//Set the fields of toggle based on the values passed in
Toggle *toggle_set_fields(Toggle *toggle, int state, Label *label, ButtonStyle *style, int (*command)(), int active);
//toggle init, needs to be called before all toggle functions
Toggle *toggle_init(Toggle *toggle, float scale_x, float scale_y);
//update a toggle
int toggle_update(Toggle *toggle, float scale_x, float scale_y);
//render a toggle
void toggle_render(Toggle *toggle, float scale_x, float scale_y);
//free the toggle's label
void toggle_free(Toggle *toggle);
//free a toggle's list
void toggle_list_free(Toggle *toggle[], int size);

int toggle_list_update_and_render(Toggle **toggles, int count);

#endif