#include "../main.h"

Button *button_init(Button *button)
{
    if (NULL == button)
        return NULL;

    button->label = label_init(button->label);

    if (NULL != button->label)
    {
        button->rect.width = MAX(button->rect.width, button->label->rect.width);
        button->rect.height = MAX(button->rect.height, button->label->rect.height);

        button->label->rect.x = button->rect.x + CENTERED(button->rect.width, button->label->rect.width);
        button->label->rect.y = button->rect.y + CENTERED(button->rect.height, button->label->rect.height);
    }
    return button;
}

int button_update(Button *button)
{
    if (NULL == button || !button->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the button isn't clicked
    if (UI_element_collision(&button->rect, mouse_state.x, mouse_state.y, SCALE))
    {
        if (mouse_state.button_pressed == MOUSE_STATE_LEFT_CLICK)
        {
            button->state = CLICKED;
        }
        else if (mouse_state.button_pressed == MOUSE_STATE_NONE && button->state == CLICKED)
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
    label_update(button->label);
    return out;
}

void button_render(Button *button, float scale)
{
    if (NULL == button || !button->active)
        return;
        
    Color button_color;
    SDL_FRect button_rect = {button->rect.x + button->style->inline_ * scale, button->rect.y + button->style->inline_ * scale, (button->rect.width - button->style->inline_ * 2) * scale, (button->rect.height - button->style->inline_ * 2) * scale};
    SDL_FRect inline_rect = {button->rect.x, button->rect.y, button->rect.width * scale, button->rect.height * scale};
    SDL_FRect outline_rect = {button->rect.x - button->style->outline * scale, button->rect.y - button->style->outline * scale, (button->rect.width + button->style->outline * 2) * scale, (button->rect.height + button->style->outline * 2) * scale};

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

int button_get_height(Button *button, float scale)
{
    return (button->rect.height + button->style->outline * 2) * scale;
}

int button_get_width(Button *button, float scale)
{
    return (button->rect.width + button->style->outline * 2) * scale;
}
