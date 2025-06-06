#include "../main.h"

Button *button_init(Button *button, float scale)
{
    if (NULL == button)
        return NULL;

    button->label = label_init(button->label, scale);

    if (NULL != button->label)
    {
        button->rect.width = MAX(button->rect.width, button->label->rect.width);
        button->rect.height = MAX(button->rect.height, button->label->rect.height);
    }
    return button;
}

int button_update(Button *button, float scale)
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
    label_update(button->label, scale);
    return out;
}

void button_render(Button *button, float scale)
{
    if (NULL == button || !button->active)
        return;

    UI_Element anchored_rect = button->rect;
    set_UI_element_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale, anchored_rect.anchor);
        
    Color button_color;
    SDL_FRect button_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale, anchored_rect.height * scale};
    
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

    SDL_SetRenderDrawColor(renderer, button_color.r, button_color.g, button_color.b, button_color.a);
    SDL_RenderFillRect(renderer, &button_rect);

    render_outline(&anchored_rect, scale);
    render_inline(&anchored_rect, scale);
    
    if (NULL != button->label)
        label_render(button->label, scale);
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

void button_center_label(Button *button, float scale)
{
    if (NULL == button || NULL == button->label)
        return;

    button->label->rect.x = button->rect.x + CENTERED(button->rect.width, button->label->rect.width);
    button->label->rect.y = button->rect.y + CENTERED(button->rect.height, button->label->rect.height);
    return;
}