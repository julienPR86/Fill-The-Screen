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
    SDL_Color color1;
    SDL_Color color2;
} Button;

Button *button_update(Button *button)
{
    return button;
}

void button_render(Button *button)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        SDL_SetRenderDrawColor(renderer, button->color1.r, button->color1.g, button->color1.b, button->color1.a);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, button->color2.r, button->color2.g, button->color2.b, button->color2.a);
    }
    SDL_Rect button_rect = {button->x, button->y, button->width, button->height};
    SDL_RenderFillRect(renderer, &button_rect);
}

int button_collision(Button *button, int x, int y)
{
    if (x > button->x && x < button->x+button->width && y > button->y && y < button->y+button->height)
    {
        return 1;
    }
    return 0;
}

#endif