#include "../main.h"

int toogle_update(Toogle *toogle)
{
    if (!toogle->active)
        return -1;
    
    static int update = 1;
    int x, y, out = -1; // returns -1 if the toogle isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(toogle, x, y))
    {
        if (mouse_button_pressed == 1 && update)
        {
            switch (toogle->state)
            {
                case NORMAL:
                case HOVERED:
                    toogle->state = CLICKED;
                    out = toogle->command();
                    break;
                case CLICKED:
                    toogle->state = HOVERED;
                    break;
                default:
                    break;
            }
            update = 0;
        }
        else if (mouse_button_pressed == 0 && !update)
        {
            update = 1;
        }
        else if (NORMAL == toogle->state)
        {
            toogle->state = HOVERED;
        }
    }
    else
    {
        if (HOVERED == toogle->state)
        {
            toogle->state = NORMAL;
        }
    }
    label_update(&toogle->label);
    return out;
}
