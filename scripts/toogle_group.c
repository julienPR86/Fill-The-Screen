#include "../main.h"

ToogleGroup *group_init(ToogleGroup *group)
{
    if (NULL == group || 0 == group->count)
        return NULL;

    if (NULL == group->toogles && group->count != 0)
        group->count = 0;

    group->selected = 0;
    return group;
}

int group_update(ToogleGroup *group)
{
    if (NULL == group || NULL == group->toogles)
        return RETURN_NONE;

    int out = RETURN_NONE, final_out = out;
    for (int i = 0; i < group->count; i++)
    {
        out = toogle_update(group->toogles[i]);
        if (CLICKED == group->toogles[i]->state)
        {
            group_clear_selected(group);
            group->toogles[i]->state = CLICKED;
            group->selected = i;
        }
        if ((NORMAL == group->toogles[i]->state || HOVERED == group->toogles[i]->state) && i == group->selected)
            group->toogles[i]->state = CLICKED;
        
        if (out != RETURN_NONE)
            final_out = out;
        
    }
    return final_out;
}

void group_render(ToogleGroup *group)
{
    if (NULL == group || NULL == group->toogles)
        return;

    for (int i = 0; i < group->count; i++)
    {
        toogle_render(group->toogles[i]);
    }
    return;
}

void group_clear_selected(ToogleGroup *group)
{
    if (NULL == group || NULL == group->toogles)
        return;

    for (int i = 0; i < group->count; i++)
    {
        if (CLICKED == group->toogles[i]->state)
            group->toogles[i]->state = NORMAL;
    }
    return;
}

void group_free(ToogleGroup *group)
{
    if (NULL == group || NULL == group->toogles)
        return;
        
    toogle_list_free(group->toogles, group->count);
    return;
}