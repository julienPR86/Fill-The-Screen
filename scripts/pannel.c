#include "../main.h"

Panel *panel_init(Panel *panel)
{

    return panel;
}

void panel_add_button(Panel *panel, Button *button)
{
    return;
}

void panel_remove_button(Panel *panel, Button *button)
{
    return;
}

void panel_add_label(Panel *panel, Label *label)
{
    return;
}

void panel_remove_label(Panel *panel, Label *label)
{
    return;
}

void panel_set_active_state(Panel *panel, int state)
{
    panel->active = state;

    for (int i = 0; i < (int)sizeof(panel->buttons)/sizeof(panel->buttons[0]); i++)
    {
        panel->buttons[i].active = state;
    }

    for (int i = 0; i < (int)sizeof(panel->labels)/sizeof(panel->labels[0]); i++)
    {
        panel->labels[i].active = state;
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
   
}