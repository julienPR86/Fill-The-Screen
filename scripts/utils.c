#include "../main.h"

int get_fps()
{
    if (delta_time != 0)
    {
        return (int)(1/delta_time);
    }
    return MAX_FPS;
}

void mouse_pressed(SDL_Event event)
{
    if (SDL_MOUSEBUTTONDOWN == event.type && !mouse_button_pressed)
    {
        mouse_button_pressed = event.button.button;
    }
    if (SDL_MOUSEBUTTONUP == event.type)
    {
        if (event.button.button == mouse_button_pressed)
        {
            mouse_button_pressed = 0;
        }
    }
}

int button_collision(Button *button, int x, int y)
{
    if (x >= button->x && x <= button->x+button->width && y >= button->y && y <= button->y+button->height)
    {
        return true;
    }
    return false;
}

int get_button_height(Button *button)
{
    return button->height+button->outline;
}
int get_button_width(Button *button)
{
    return button->width+button->outline;
}