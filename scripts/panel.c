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

void panel_update(Panel *panel)
{
    if (NULL == panel || !panel->active)
        return;

    if (NULL != panel->buttons)
    {
        for (int i = 0; i < panel->button_count; i++)
        {
            button_update(panel->buttons[i]);
        }
    }
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_update(panel->labels[i]);
        }
    }
    return;
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
    if (NULL != panel->labels)
    {
        for (int i = 0; i < panel->label_count; i++)
        {
            label_render(panel->labels[i]);
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
        free(panel->buttons);
    }
    if (NULL != panel->labels)
    {
        label_list_free(panel->labels, panel->label_count);
        free(panel->labels);
    }
    return;
}