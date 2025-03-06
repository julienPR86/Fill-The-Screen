#include "../main.h"

ToogleGroup *group_init(ToogleGroup *group)
{
    if (NULL == group || 0 == group->count)
        return NULL;

    group->toogles = (Toogle **)malloc(sizeof(Toogle *) * group->count);
    if (NULL == group->toogles)
    {
        fprintf(stderr, "Failed to init ToogleGroup : Memory allocation error\n");
        return NULL;
    }
    for (int i = 0; i < group->count; i++)
    {
        group->toogles[i] = NULL;
    }
    group->selected = 0;
    return group;
}

void group_update(ToogleGroup *group)
{
    if (NULL == group || NULL == group->toogles)
        return;

    for (int i = 0; i < group->count; i++)
    {
        toogle_update(group->toogles[i]);
        if (CLICKED == group->toogles[i]->state)
        {
            group_clear_selected(group);
            group->toogles[i]->state = CLICKED;
            group->selected = i;
        }
        if ((NORMAL == group->toogles[i]->state || HOVERED == group->toogles[i]->state) && i == group->selected)
            group->toogles[i]->state = CLICKED;
    }
    return;
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

int group_set_toogle_at_index(ToogleGroup *group, Toogle *toogle, int index)
{
    if (NULL == group || NULL == group->toogles || index < 0 || index >= group->count)
        return RETURN_FAILURE;

    group->toogles[index] = toogle;
    if (index == 0)
        group->toogles[index]->state = CLICKED;
    return RETURN_ZERO;
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
        
    for (int i = 0; i < group->count; i++)
    {
        toogle_free(group->toogles[i]);
    }
    free(group->toogles);
    return;
}