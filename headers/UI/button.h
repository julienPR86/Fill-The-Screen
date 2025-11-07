#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../color.h"
#include "UI_Element.h"
#include "label.h"

//button structure
typedef struct Button
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
    //button state
    int state;
    //button label
    Label *label;
    //button style
    ButtonStyle *style;
    //button command, is called when the button is clicked
    int (*command)();
    //is active parameter
    int active;
} Button;

//Set the fields of button based on the values passed in
Button *button_set_fields(Button *button, int state, Label *label, ButtonStyle *style, int (*command)(), int active);
//button init, needs to be called before all button functions
Button *button_init(Button *button, float scale_x, float scale_y);
//update a button
int button_update(Button *button, float scale_x, float scale_y);
//render a button
void button_render(Button *button, float scale_x, float scale_y);
//free the button's label
void button_free(Button *button);
//free a button's list
void button_list_free(Button *buttons[], int size);

//Update and render a list of buttons
int button_list_update_and_render(Button *buttons[], int count);

#endif