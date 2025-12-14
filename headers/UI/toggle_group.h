#ifndef TOGGLE_GROUP_H
#define TOGGLE_GROUP_H

#include "toggle.h"

//Structure that represent a group of toggle, only one can be pressed at a time
typedef struct ToggleGroup
{
    //The toggles list
    Toggle **toggles;
    //The number of toggles in the toggles list
    int count;
    //The index of the actual selected toggle
    int selected;
    //Tells if the toggle group is active or not
    t_uint8 active;
} ToggleGroup;

//Set the fields of the toggle group based on the values passed in
ToggleGroup *group_set_fields(ToggleGroup *group, Toggle *toggles[], int count, int selected, t_uint8 active);
//Initialise the toggle group passed in, needs to be called before all toggle group functions, except for group_set_fields()
ToggleGroup *group_init(ToggleGroup *group);
//Updates a toggle group
int group_update(ToggleGroup *group, float scale_x, float scale_y);
//Renders a toggle group
void group_render(ToggleGroup *group);
//Set the state of all toggles in the toggles list to normal
void group_clear_selected(ToggleGroup *group);
//Frees the allocated ressources of the toggle group passed in
void group_free(ToggleGroup *group);
//Frees an array of toggle groups
void group_list_free(ToggleGroup **groups, int count);
//Updates and renders an array of toggle groups
int group_list_update_and_render(ToggleGroup *groups[], int count);

#endif