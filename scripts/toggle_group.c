#include "../main.h"

ToggleGroup *group_set_fields(ToggleGroup *group, Toggle *toggles[], int count, int selected, int active)
{
    group->toggles = toggles;
    group->count = count;
    group->selected = selected;
    group->active = active;
    return group;
}

ToggleGroup *group_init(ToggleGroup *group)
{
    if (NULL == group || 0 == group->count)
        return NULL;

    if (NULL == group->toggles && group->count != 0)
        group->count = 0;

    group->selected = 0;
    return group;
}

int group_update(ToggleGroup *group, float scale_x, float scale_y)
{
    if (NULL == group || NULL == group->toggles)
        return RETURN_NONE;

    int out = RETURN_NONE, final_out = out;
    for (int i = 0; i < group->count; i++)
    {
        out = toggle_update(group->toggles[i], scale_x, scale_y);
        if (CLICKED == group->toggles[i]->state)
        {
            group_clear_selected(group);
            group->toggles[i]->state = CLICKED;
            group->selected = i;
        }
        if ((NORMAL == group->toggles[i]->state || HOVERED == group->toggles[i]->state) && i == group->selected)
            group->toggles[i]->state = CLICKED;
        
        if (out != RETURN_NONE)
            final_out = out;
        
    }
    return final_out;
}

void group_render(ToggleGroup *group)
{
    if (NULL == group || NULL == group->toggles)
        return;

    for (int i = 0; i < group->count; i++)
    {
        toggle_render(group->toggles[i], SCALE_X, SCALE_Y);
    }
    return;
}

void group_clear_selected(ToggleGroup *group)
{
    if (NULL == group || NULL == group->toggles)
        return;

    for (int i = 0; i < group->count; i++)
    {
        if (CLICKED == group->toggles[i]->state)
            group->toggles[i]->state = NORMAL;
    }
    return;
}

void group_free(ToggleGroup *group)
{
    if (NULL == group || NULL == group->toggles)
        return;
        
    toggle_list_free(group->toggles, group->count);
    return;
}

void group_list_free(ToggleGroup **groups, int count)
{
    if (NULL == groups)
        return;
    
    for (int i = 0; i < count; i++)
    {
        if (NULL == groups[i])
            continue;
            
        group_free(groups[i]);
    }
    return;
}