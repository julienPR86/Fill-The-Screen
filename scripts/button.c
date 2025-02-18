#include "../main.h"

Button *button_init(Button *button)
{
    label_init(&button->label);

    button->width = MAX(button->width * SCALEX, button->label.w * button->label.scale);
    button->height = MAX(button->height * SCALEY, button->label.h * button->label.scale);

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
    SDL_Color button_color;
    SDL_Rect button_rect = {button->x+button->style.inline_, button->y+button->style.inline_, button->width-button->style.inline_*2, button->height-button->style.inline_*2};
    SDL_Rect inline_rect = {button->x, button->y, button->width, button->height};
    SDL_Rect outline_rect = {button->x-button->style.outline, button->y-button->style.outline, button->width+button->style.outline*2, button->height+button->style.outline*2};

    switch (button->state)
    {
        case NORMAL:
            button_color = button->style.background;
            break;
        case CLICKED:
            button_color = button->style.foreground;
            break;
        case HOVERED:
            button_color = button->style.hover_color;
            break;
        default:
            break;
    }

    SDL_SetRenderDrawColor(renderer, button->style.outline_color.r, button->style.outline_color.g, button->style.outline_color.b, button->style.outline_color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    SDL_SetRenderDrawColor(renderer, button->style.inline_color.r, button->style.inline_color.g, button->style.inline_color.b, button->style.inline_color.a);
    SDL_RenderFillRect(renderer, &inline_rect);

    SDL_SetRenderDrawColor(renderer, button_color.r, button_color.g, button_color.b, button_color.a);
    SDL_RenderFillRect(renderer, &button_rect);
    
    label_render(&button->label);
    return;
}