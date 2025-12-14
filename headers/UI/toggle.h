#ifndef TOGGLE_H
#define TOGGLE_H

#include "../color.h"
#include "UI_Element.h"
#include "label.h"

//Structure that represent a toggle, that can be on or off
typedef struct Toggle
{
    //The toggle rect, contains its position and its dimensions
    UI_Element rect;
    //The toggle state, see ButtonStates enum
    t_uint8 state;
    //The toggle label, contains some text which is displayed on top of the toggle
    Label *label;
    //The toggle style, contains the background, foreground and hover colors
    ButtonStyle *style;
    //The function to call when the toggle is on
    int (*command)();
    //Tells if the toggle is active or not
    t_uint8 active;
} Toggle;

//Set the fields of toggle based on the values passed in
Toggle *toggle_set_fields(Toggle *toggle, t_uint8 state, Label *label, ButtonStyle *style, int (*command)(), t_uint8 active);
//Toggle initialisation, needs to be called before all toggle functions, except for toggle_set_fields()
Toggle *toggle_init(Toggle *toggle, float scale_x, float scale_y);
//Updates the toggle passed in
int toggle_update(Toggle *toggle, float scale_x, float scale_y);
//Renders the toggle passed in
void toggle_render(Toggle *toggle, float scale_x, float scale_y);
//Frees the allocated ressources of the toggle passed in
void toggle_free(Toggle *toggle);
//Frees an array of toggles
void toggle_list_free(Toggle *toggle[], int size);
//Updates and renders an array of toggles
int toggle_list_update_and_render(Toggle **toggles, int count);

#endif