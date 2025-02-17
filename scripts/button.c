#include "../main.h"

Button *button_init(Button *button)
{
    label_init(&button->label);
    button->label.x = button->x + (button->width - button->label.w * button->label.scale)/2;
    button->label.y = button->y + (button->height - button->label.h * button->label.scale)/2;
    return button;
}

int button_update(Button *button)
{
    int x, y, out = -1; // returns -1 if the button isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        if (mouse_button_pressed == 1)
        {
            button->state = CLICKED;
        }
        else if (mouse_button_pressed == 0 && button->state == CLICKED)
        {
            button->state = NORMAL;
            out = button->command();
        }
        else
        {
            button->state = HOVERED;
        }
    }
    else
    {
        if (button->state)
        {
            button->state = NORMAL;
        }
    }
    label_update(&button->label);
    return out;
}

void button_render(Button *button)
{
    SDL_Color color;
    color = button->outline_color;
    SDL_Rect button_rect = {button->x, button->y, button->width, button->height};
    SDL_Rect outline_rect = {button->x-button->outline, button->y-button->outline, button->width+button->outline*2, button->height+button->outline*2};
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    if (button->state == CLICKED)
        color = button->fg;
    else if (button->state == HOVERED)
        color = button->hover;
    else
        color = button->bg;
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &button_rect);
    
    label_render(&button->label);
    return;
}