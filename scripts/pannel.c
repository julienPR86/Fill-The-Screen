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
