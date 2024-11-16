#include <stdio.h>
#include <SDL2/SDL.h>
#include "const.c"

#ifndef BUTTON
#define BUTTON

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    SDL_Color color_on_click;
    SDL_Color color_out;
    SDL_Color color;
} Button;

int button_collision(Button *button, int x, int y);

Button *button_update(Button *button)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y) && mouse_pressed == 1)
    {
        button->color = button->color_on_click;
    }
    else
    {
        button->color = button->color_out;    
    }
    return button;
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

#endif