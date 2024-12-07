#include "../main.h"

int button_update(Button *button)
{
    int x, y, out = -1; // returns -1 if the button isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        if (mouse_button_pressed == 1)
        {
            button->color = button->color_on_click;
            button->clicked = 1;
        }
        else if (mouse_button_pressed == 0 && button->clicked)
        {
            button->clicked = 0;
            button->color = button->color_out;
            out = button->command();
        }
        else
        {
            button->color = button->color_out;
        }
    }
    else
    {
        if (button->clicked){button->clicked = 0;}
        button->color = button->color_out;
    }
    return out;
}

void button_render(Button *button)
{
    SDL_SetRenderDrawColor(renderer, button->color.r, button->color.g, button->color.b, button->color.a);
    SDL_Rect button_rect = {button->x, button->y, button->width, button->height};
    SDL_RenderFillRect(renderer, &button_rect);
}

int button_collision(Button *button, int x, int y)
{
    if (x >= button->x && x <= button->x+button->width && y >= button->y && y <= button->y+button->height)
    {
        return 1;
    }
    return 0;
}
