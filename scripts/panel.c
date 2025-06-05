#include "../main.h"

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

    if (NULL == panel->rects && panel->rect_count != 0)
        panel->label_count = 0;
    
    return panel;
}

int panel_update(Panel *panel)
{
    if (NULL == panel || !panel->active)
        return RETURN_NONE;

    int out = RETURN_NONE;
    if (NULL != panel->buttons && RETURN_NONE == out)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            if (RETURN_NONE != out)
                return out;

            out = button_update(panel->buttons[i], SCALE);
        }
    }
    if (NULL != panel->toggles && RETURN_NONE == out)
    {
        for (int i = 0; i < panel->toggle_count; i++)
        {
            if (RETURN_NONE != out)
                return out;

            out = toggle_update(panel->toggles[i], SCALE);
        }
    }
    if (NULL != panel->sliders && RETURN_NONE == out)
    {
        for (int i = 0; i < panel->slider_count; i++)
        {
            if (RETURN_NONE != out)
                return out;

            out = slider_update(panel->sliders[i], SCALE);
        }
    }
    if (NULL != panel->pickers && RETURN_NONE == out)
    {
        for (int i = 0; i < panel->picker_count; i++)
        {
            if (RETURN_NONE != out)
                return out;

            out = picker_update(panel->pickers[i], SCALE);
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_update(panel->labels[i], SCALE);
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
            rect_render(panel->rects[i], SCALE);
        }
    }
    if (NULL != panel->buttons)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            button_render(panel->buttons[i], SCALE);
        }
    }
    if (NULL != panel->toggles)
    {
        for (int i = 0; i < panel->toggle_count; i++)
        {
            toggle_render(panel->toggles[i], SCALE);
        }
    }
    if (NULL != panel->sliders)
    {
        for (int i = 0; i < panel->slider_count; i++)
        {
            slider_render(panel->sliders[i], SCALE);
        }
    }
    if (NULL != panel->pickers)
    {
        for (int i = 0; i < panel->picker_count; i++)
        {
            picker_render(panel->pickers[i], SCALE);
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_render(panel->labels[i], SCALE);
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
    if (NULL != panel->sliders)
    {
        picker_list_free(panel->pickers, panel->picker_count);
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