#include "../main.h"

Button *button_init(Button *button)
{
    if (NULL == button)
        return NULL;

    button->label = label_init(button->label);

    if (NULL != button->label)
    {
        button->width = MAX(button->width, button->label->w);
        button->height = MAX(button->height, button->label->h);

        button->label->x = button->x + CENTERED(button->width, button->label->w);
        button->label->y = button->y + CENTERED(button->height, button->label->h);
    }
    return button;
}

int button_update(Button *button)
{
    if (NULL == button || !button->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the button isn't clicked
    if (button_collision(button, mouse_x, mouse_y, SCALE))
    {
        if (mouse_button_pressed == MOUSE_STATE_LEFT_CLICK)
        {
            button->state = CLICKED;
        }
        else if (mouse_button_pressed == MOUSE_STATE_NONE && button->state == CLICKED)
        {
            if (NULL != button->command)
                out = button->command();
            button->state = HOVERED;
        }
        else
        {
            button->state = HOVERED;
        }
    }
    else
    {
        button->state = NORMAL;
    }
    if (NULL != button->label)
        label_update(button->label);

    return out;
}

void button_render(Button *button, float scale)
{
    if (NULL == button || !button->active)
        return;
        
    Color button_color;
    SDL_FRect button_rect = {button->x + button->style->inline_ * scale, button->y + button->style->inline_ * scale, (button->width - button->style->inline_ * 2) * scale, (button->height - button->style->inline_ * 2) * scale};
    SDL_FRect inline_rect = {button->x, button->y, button->width * scale, button->height * scale};
    SDL_FRect outline_rect = {button->x - button->style->outline * scale, button->y - button->style->outline * scale, (button->width + button->style->outline * 2) * scale, (button->height + button->style->outline * 2) * scale};

    switch (button->state)
    {
        case NORMAL:
            button_color = button->style->background;
            break;
        case CLICKED:
            button_color = button->style->foreground;
            break;
        case HOVERED:
            button_color = button->style->hover_color;
            break;
        default:
            break;
    }

    SDL_SetRenderDrawColor(renderer, button->style->outline_color.r, button->style->outline_color.g, button->style->outline_color.b, button->style->outline_color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    SDL_SetRenderDrawColor(renderer, button->style->inline_color.r, button->style->inline_color.g, button->style->inline_color.b, button->style->inline_color.a);
    SDL_RenderFillRect(renderer, &inline_rect);

    SDL_SetRenderDrawColor(renderer, button_color.r, button_color.g, button_color.b, button_color.a);
    SDL_RenderFillRect(renderer, &button_rect);
    
    if (NULL != button->label)
        label_render(button->label);
    return;
}

void button_free(Button *button)
{
    if (NULL == button)
        return;
        
    label_free(button->label);
    return;
}

void button_list_free(Button *buttons[], int size)
{
    if (NULL == buttons)
        return;

    for (int i = 0; i < size; i++)
    {   
        if (NULL == buttons[i])
            continue;
            
        button_free(buttons[i]);
    }
    return;
}

int button_height(Button *button, float scale)
{
    return (button->height + button->style->outline * 2) * scale;
}

int button_width(Button *button, float scale)
{
    return (button->width + button->style->outline * 2) * scale;
}
