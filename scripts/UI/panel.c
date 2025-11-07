#include "../../main.h"

Panel *panel_set_fields(Panel* panel, Button **buttons, int button_count, Toggle **toggles, int toggle_count, Slider **sliders, int slider_count, ColorPicker **pickers, int picker_count, ToggleGroup **groups, int group_count, Label **labels, int label_count, Rect **rects, int rect_count, int active)
{
    panel->buttons = buttons;
    panel->button_count = button_count;
    panel->toggles = toggles;
    panel->toggle_count = toggle_count;
    panel->sliders = sliders;
    panel->slider_count = slider_count;
    panel->pickers = pickers;
    panel->picker_count = picker_count;
    panel->groups = groups;
    panel->groups_count = group_count;
    panel->labels = labels;
    panel->label_count = label_count;
    panel->rects = rects;
    panel->rect_count = rect_count;
    panel->active = active;
    return panel;
}

Panel *panel_init(Panel *panel)
{
    if (NULL == panel)
        return NULL;
    
    if (NULL == panel->buttons && panel->button_count != 0)
        panel->button_count = 0;

    if (NULL == panel->toggles && panel->toggle_count != 0)
        panel->toggle_count = 0;

    if (NULL == panel->sliders && panel->slider_count != 0)
        panel->slider_count = 0;

    if (NULL == panel->labels && panel->label_count != 0)
        panel->label_count = 0;

    if (NULL == panel->pickers && panel->picker_count != 0)
        panel->label_count = 0;

    if (NULL == panel->groups && panel->groups_count != 0)
        panel->groups_count = 0;

    if (NULL == panel->rects && panel->rect_count != 0)
        panel->label_count = 0;
    
    return panel;
}

int panel_update(Panel *panel)
{
    if (NULL == panel || !panel->active)
        return 0;

    int out = 0;
    if (NULL != panel->buttons && 0 == out)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            out = button_update(panel->buttons[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->toggles && 0 == out)
    {
        for (int i = 0; i < panel->toggle_count; i++)
        {
            out = toggle_update(panel->toggles[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->sliders && 0 == out)
    {
        for (int i = 0; i < panel->slider_count; i++)
        {
            out = slider_update(panel->sliders[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->pickers && 0 == out)
    {
        for (int i = 0; i < panel->picker_count; i++)
        {
            out = picker_update(panel->pickers[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->groups && 0 == out)
    {
        for (int i = 0; i < panel->groups_count; i++)
        {
            out = group_update(panel->groups[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_update(panel->labels[i], SCALE_X, SCALE_Y);
        }
    }
    return out;
}

void panel_render(Panel *panel)
{
    if (NULL == panel || !panel->active)
        return;

    if (NULL != panel->rects)
    {
        for (int i = 0; i < panel->rect_count; i++)
        {
            rect_render(panel->rects[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->buttons)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            button_render(panel->buttons[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->toggles)
    {
        for (int i = 0; i < panel->toggle_count; i++)
        {
            toggle_render(panel->toggles[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->sliders)
    {
        for (int i = 0; i < panel->slider_count; i++)
        {
            slider_render(panel->sliders[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->pickers)
    {
        for (int i = 0; i < panel->picker_count; i++)
        {
            picker_render(panel->pickers[i], SCALE_X, SCALE_Y);
        }
    }
    if (NULL != panel->groups)
    {
        for (int i = 0; i < panel->groups_count; i++)
        {
            group_render(panel->groups[i]);
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_render(panel->labels[i], SCALE_X, SCALE_Y);
        }
    }
    return;
}

void panel_free(Panel *panel)
{
    if (NULL == panel)
        return;
    
    if (NULL != panel->buttons)
    {
        button_list_free(panel->buttons, panel->button_count);
    }
    if (NULL != panel->toggles) 
    {
        toggle_list_free(panel->toggles, panel->toggle_count);
    }
    if (NULL != panel->sliders)
    {
        slider_list_free(panel->sliders, panel->slider_count);
    }
    if (NULL != panel->pickers)
    {
        picker_list_free(panel->pickers, panel->picker_count);
    }
    if (NULL != panel->groups)
    {
        group_list_free(panel->groups, panel->groups_count);
    }
    if (NULL != panel->labels)
    {
        label_list_free(panel->labels, panel->label_count);
    }
    return;
}

void panel_list_free(Panel *panels[], int count)
{
    if (NULL == panels)
        return;

    for (int i = 0; i < count; i++)
    {
        if (NULL == panels[i])
            continue;

        panel_free(panels[i]);
    }
    return;
}

int panel_list_update_and_render(Panel *panels[], int count)
{
    int out = 0;
    for (int i = 0; i < count; i++)
    {
        out = panel_update(panels[i]);
        panel_render(panels[i]);
    }
    return out;
}