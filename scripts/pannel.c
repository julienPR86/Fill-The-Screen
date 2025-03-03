#include "../main.h"

Panel *panel_init(Panel *panel)
{
    if (NULL == panel)
        return;
    
    panel->button_count = 0;
    panel->label_count = 0;
    return panel;
}

void panel_add_button(Panel *panel, Button *button)
{
    if (NULL == panel || NULL == button)
        return;

    panel->button_count++;
    Button **buttons = (Button **)realloc(panel->buttons, panel->button_count * sizeof(Button *));
    if (NULL == buttons)
    {
        panel->button_count--;
        fprintf(stderr, "Pannel button allocation error\n");
        return;
    }
    panel->buttons = buttons;
    panel->buttons[panel->button_count - 1] = button;
    return;
}

void panel_remove_button(Panel *panel)
{
    if (NULL == panel || NULL == panel->buttons || 0 == panel->button_count)
        return;

    panel->button_count--;
    button_free(panel->buttons[panel->button_count]);
    if (0 == panel->button_count)
    {
        free(panel->buttons);
        panel->buttons = NULL;
        return;
    }
    Button **buttons = (Button **)realloc(panel->buttons, panel->button_count * sizeof(Button *));
    if (NULL == buttons)
    {
        fprintf(stderr, "Pannel button allocation error\n");
        return;
    }
    panel->buttons = buttons;
    return;
}

void panel_add_label(Panel *panel, Label *label)
{
    if (NULL == panel || NULL == label)
        return;

    panel->label_count++;
    Label **labels = (Label **)realloc(panel->labels, panel->label_count * sizeof(Label *));
    if (NULL == labels)
    {
        panel->label_count--;
        fprintf(stderr, "Pannel label allocation error\n");
        return;
    }
    panel->labels = labels;
    panel->labels[panel->label_count - 1] = label;
    return;
}

void panel_remove_label(Panel *panel)
{
    if (NULL == panel || NULL == panel->labels || 0 == panel->label_count)
        return;

    panel->label_count--;
    label_free(panel->labels[panel->label_count]);
    if (0 == panel->label_count)
    {
        free(panel->labels);
        panel->labels = NULL;
        return;
    }
    Label **labels = (Label **)realloc(panel->labels, panel->label_count * sizeof(Button *));
    if (NULL == labels)
    {
        fprintf(stderr, "Pannel label allocation error\n");
        return;
    }
    panel->labels = labels;
    return;
}

void panel_set_active_state(Panel *panel, int state)
{
    panel->active = state;

    for (int i = 0; i < (int)sizeof(panel->buttons)/sizeof(panel->buttons[0]); i++)
    {
        panel->buttons[i]->active = state;
    }

    for (int i = 0; i < (int)sizeof(panel->labels)/sizeof(panel->labels[0]); i++)
    {
        panel->labels[i]->active = state;
    }
    return;
}

void panel_free(Panel *panel)
{
    if (NULL != panel->buttons)
    {
        button_list_free(panel->buttons, (int)sizeof(panel->buttons)/sizeof(panel->buttons[0]));
    }
    if (NULL != panel->labels)
    {
        label_list_free(panel->labels, (int)sizeof(panel->labels)/sizeof(panel->labels[0]));
    }
    return;
}