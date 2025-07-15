#ifndef _TOGGLE_GROUP_H_
#define _TOGGLE_GROUP_H_

#include "toggle.h"

//toggle group structure
typedef struct ToggleGroup
{
    //toggle group
    Toggle **toggles;
    //toggle count
    int count;
    //the selected index
    int selected;
    //is active parameter
    int active;
} ToggleGroup;

//Set the fields of toggle group based on the values passed in
ToggleGroup *group_set_fields(ToggleGroup *group, Toggle *toggles[], int count, int selected, int active);
//toggle group init, needs to be called before all toggle group functions
ToggleGroup *group_init(ToggleGroup *group);
//update a toggle group
int group_update(ToggleGroup *group, float scale_x, float scale_y);
//render a toggle group
void group_render(ToggleGroup *group);
//set all toggles states to normal
void group_clear_selected(ToggleGroup *group);
//free the toggle group
void group_free(ToggleGroup *group);
//free a list of toggles
void group_list_free(ToggleGroup **groups, int count);

int group_list_update_and_render(ToggleGroup *groups[], int count);

#endif