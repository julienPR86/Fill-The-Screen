#include "../main.h"

int button_update(Button *button)
{
    int x, y, out = -1; // returns -1 if the button isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        if (mouse_button_pressed == 1)
        {
            button->img = button->img_pressed;
            button->clicked = 1;
        }
        else if (mouse_button_pressed == 0 && button->clicked)
        {
            button->clicked = 0;
            button->img = button->img_unpressed;
            out = button->command();
        }
        else
        {
            button->img = button->img_unpressed;
        }
    }
    else
    {
        if (button->clicked){button->clicked = 0;}
        button->img = button->img_unpressed;
    }
    return out;
}

void button_render(Button *button)
{
    SDL_Rect button_rect = {button->x, button->y, button->width, button->height};
    SDL_Texture *img = SDL_CreateTextureFromSurface(renderer, button->img);
    SDL_RenderCopy(renderer, img, NULL, &button_rect);
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