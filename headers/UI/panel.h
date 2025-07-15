#ifndef _PANEL_H_
#define _PANEL_H_

#include "button.h"
#include "color_picker.h"
#include "label.h"
#include "rect.h"
#include "slider.h"
#include "toggle_group.h"
#include "toggle.h"

//panel structure
typedef struct Panel
{
    //buttons
    Button **buttons;
    //buttons count
    int button_count;
    //toggles
    Toggle **toggles;
    //toggles count
    int toggle_count;
    //sliders
    Slider **sliders;
    //sliders count
    int slider_count;
    //color pickers
    ColorPicker **pickers;
    //Color picker count
    int picker_count;
    //toggle group
    ToggleGroup **groups;
    //toggles group count
    int groups_count;
    // labels
    Label **labels;
    //labels count
    int label_count;
    //rects
    Rect **rects;
    //rects count
    int rect_count;
    //is active parameter
    int active;
} Panel;

//Set the fields of the panel passed in
Panel *panel_set_fields(Panel* panel, Button **buttons, int button_count, Toggle **toggles, int toggle_count, Slider **sliders, int slider_count, ColorPicker **pickers, int picker_count, ToggleGroup **groups, int group_count, Label **labels, int label_count, Rect **rects, int rect_count, int active);
//panel init, needs to be called before all panel functions
Panel *panel_init(Panel *panel);
//update panel
int panel_update(Panel *panel);
//render panel
void panel_render(Panel *panel);
//free a panel
void panel_free(Panel *panel);
//free a panel list
void panel_list_free(Panel *panels[], int count);

int panel_list_update_and_render(Panel *panels[], int count);

#endif