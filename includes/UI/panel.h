#ifndef PANEL_H
#define PANEL_H

#include "button.h"
#include "color_picker.h"
#include "label.h"
#include "rect.h"
#include "slider.h"
#include "toggle_group.h"
#include "toggle.h"

//Structure that represent a panel that contains all sort of UI objects
typedef struct Panel
{
    //The buttons list
    Button **buttons;
    //The number of buttons in the button list
    t_uint button_count;
    //The toggles list
    Toggle **toggles;
    //The number of toggles in the button list
    t_uint toggle_count;
    //The sliders list
    Slider **sliders;
    //The number of sliders in the button list
    t_uint slider_count;
	//The color picker list
    ColorPicker **pickers;
    //The number of color picker in the button list
    t_uint picker_count;
    //The toggle groups list
    ToggleGroup **groups;
    //The number of toggle groups in the button list
    t_uint groups_count;
    //The labels list
    Label **labels;
    //The number of labels in the button list
    t_uint label_count;
    //The rects list
    Rect **rects;
    //The number of rects in the button list
    t_uint rect_count;
    //Tells if the panel is active or not
    t_uint8 active;
} Panel;

//Set the fields of the panel with the values passed in
Panel *panel_set_fields(Panel* panel, Button **buttons, t_uint button_count, Toggle **toggles, t_uint toggle_count, Slider **sliders, t_uint slider_count, ColorPicker **pickers, t_uint picker_count, ToggleGroup **groups, t_uint group_count, Label **labels, t_uint label_count, Rect **rects, t_uint rect_count, t_uint8 active);
//Initialise the panel passed in, needs to be called before all panel functions, except for panel_set_fields()
Panel *panel_init(Panel *panel);
//Updates the panel passed in
int panel_update(Panel *panel);
//Renders the panel passed in
void panel_render(Panel *panel);
//Frees allocated ressources of the panel passed in
void panel_free(Panel *panel);
//Frees an array of panels
void panel_list_free(Panel *panels[], t_uint count);
//Updates and renders an array of panels
int panel_list_update_and_render(Panel *panels[], t_uint count);

#endif