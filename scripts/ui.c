#include "../main.h"

int button_update(Button *button)
{
    int x, y, out = -1; // returns -1 if the button isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        if (mouse_button_pressed == 1)
        {
            button->clicked = 1;
        }
        else if (mouse_button_pressed == 0 && button->clicked)
        {
            button->clicked = 0;
            out = button->command();
        }
        else
        {
        }
    }
    else
    {
        if (button->clicked){button->clicked = 0;}
    }
    return out;
}

void button_render(Button *button)
{
    SDL_Rect button_rect = {button->x, button->y, button->width, button->height};
    if (button->clicked)
        SDL_SetRenderDrawColor(renderer, button->pressed_color.r, button->pressed_color.g, button->pressed_color.b, button->pressed_color.a);
    else
        SDL_SetRenderDrawColor(renderer, button->unpressed_color.r, button->unpressed_color.g, button->unpressed_color.b, button->unpressed_color.a);
    SDL_RenderFillRect(renderer, &button_rect);
    return;
}

int button_collision(Button *button, int x, int y)
{
    if (x >= button->x && x <= button->x+button->width && y >= button->y && y <= button->y+button->height)
    {
        return true;
    }
    return false;
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