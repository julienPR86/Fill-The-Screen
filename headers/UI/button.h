#ifndef BUTTON_H
#define BUTTON_H

#include "../color.h"
#include "UI_Element.h"
#include "label.h"

//Structure that represent a button, which can be pressed and execute an action
typedef struct Button
{
    //The button rect, contains its position and its dimensions
    UI_Element rect;
    //The state in which the button is, see ButtonStates enum
    t_uint8 state;
    //The button label, contains some text which is display on top of the button
    Label *label;
    //The button style, contains the background, foreground and hover colors
    ButtonStyle *style;
    //The command that is called when the button is pressed
    int (*command)();
    //Tells if the button is active or not
    t_uint8 active;
} Button;

//Set the fields of button based on the values passed in
Button *button_set_fields(Button *button, t_uint8 state, Label *label, ButtonStyle *style, int (*command)(), t_uint8 active);
//Initialised the button passed in, needs to be called before all button functions except button_set_fields()
Button *button_init(Button *button, float scale_x, float scale_y);
//Updates the button passed in
int button_update(Button *button, float scale_x, float scale_y);
//Displays the button passed in on screen
void button_render(Button *button, float scale_x, float scale_y);
//Frees the allocated ressources for the button passed in
void button_free(Button *button);
//Frees a list of buttons
void button_list_free(Button *buttons[], int size);
//Updates and renders an array of buttons
int button_list_update_and_render(Button *buttons[], int count);

#endif