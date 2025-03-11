#include "../main.h"

Panel *panel_init(Panel *panel)
{
    if (NULL == panel)
        return NULL;
    
    if (panel->button_count != 0)
    {    
        panel->buttons = (Button **)malloc(sizeof(Button *) * panel->button_count);
        if (NULL == panel->buttons)
        {
            fprintf(stderr, "Failed to init panel : memory allocation error\n");
            return NULL;
        }
        for (int i = 0; i < panel->button_count; i++)
        {
            panel->buttons[i] = NULL;
        }
    }
    if (panel->slider_count != 0)
    {    
        panel->sliders = (Slider **)malloc(sizeof(Slider *) * panel->slider_count);
        if (NULL == panel->sliders)
        {
            panel_free(panel);
            fprintf(stderr, "Failed to init panel : memory allocation error\n");
            return NULL;
        }
        for (int i = 0; i < panel->slider_count; i++)
        {
            panel->sliders[i] = NULL;
        }
    }
    if (panel->label_count != 0)
    {
        panel->labels = (Label **)malloc(sizeof(Label *) * panel->label_count);
        if (NULL == panel->labels)
        {
            panel_free(panel);
            fprintf(stderr, "Failed to init panel : memory allocation error\n");
            return NULL;
        }
        for (int i = 0; i < panel->label_count; i++)
        {
            panel->labels[i] = NULL;
        }
    }
    return panel;
}

int panel_update(Panel *panel)
{
    if (NULL == panel || !panel->active)
        return RETURN_NONE;

    int out = RETURN_NONE, final_out = out;
    if (NULL != panel->buttons)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            out = button_update(panel->buttons[i]);
            if (RETURN_NONE != out)
                final_out = out;
        }
    }
    if (NULL != panel->sliders)
    {
        for (int i = 0; i < panel->slider_count; i++)
        {
            out = slider_update(panel->sliders[i]);
            if (RETURN_NONE != out)
                final_out = out;
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_update(panel->labels[i]);
        }
    }
    return final_out;
}

void panel_render(Panel *panel)
{
    if (NULL == panel || !panel->active)
        return;
    
    if (NULL != panel->buttons)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            button_render(panel->buttons[i]);
        }
    }
    if (NULL != panel->sliders)
    {
        for (int i = 0; i < panel->slider_count; i++)
        {
            slider_render(panel->sliders[i]);
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_render(panel->labels[i]);
        }
    }
    return;
}

int panel_set_button_at_index(Panel *panel, Button *button, int index)
{
    if (NULL == panel || NULL == panel->buttons || index < 0 || index >= panel->button_count)
        return RETURN_FAILURE;

    panel->buttons[index] = button;
    return RETURN_SUCCESS;
}

int panel_set_slider_at_index(Panel *panel, Slider *slider, int index)
{
    if (NULL == panel || NULL == panel->sliders || index < 0 || index >= panel->slider_count)
        return RETURN_FAILURE;

    panel->sliders[index] = slider;
    return RETURN_SUCCESS;
}

int panel_set_label_at_index(Panel *panel, Label *label, int index)
{
    if (NULL == panel || NULL == panel->labels || index < 0 || index >= panel->label_count)
        return RETURN_FAILURE;

    panel->labels[index] = label;
    return RETURN_SUCCESS;
}

void panel_free(Panel *panel)
{
    if (NULL == panel)
        return;
    
    if (NULL != panel->buttons)
    {
        button_list_free(panel->buttons, panel->button_count);
        free(panel->buttons);
    }
    if (NULL != panel->sliders)
    {
        free(panel->sliders);
    }
    if (NULL != panel->labels)
    {
        label_list_free(panel->labels, panel->label_count);
        free(panel->labels);
    }
    return;
}