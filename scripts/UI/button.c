#include "../../main.h"

Button *button_set_fields(Button *button, int state, Label *label, ButtonStyle *style, int (*command)(), int active)
{
    button->state = state;
    button->label = label;
    button->style = style;
    button->command = command;
    button->active = active;
    return button;
}

Button *button_init(Button *button, float scale_x, float scale_y)
{
    if (NULL == button)
        return NULL;

    button->label = label_init(button->label, scale_x, scale_y);

    if (NULL != button->label)
    {
        button->label->rect.anchor = NONE;

        UI_Element_match_size(&button->rect, &button->label->rect, scale_x, scale_y);

        label_center(button->label, &button->rect, scale_x, scale_y);
    }
    return button;
}

int button_update(Button *button, float scale_x, float scale_y)
{
    if (NULL == button || !button->active)
        return 0;
    
    int out = 0; // returns 0 if the button isn't clicked
    if (UI_element_collision(&button->rect, mouse_state.x, mouse_state.y, SCALE_X, SCALE_Y))
    {
        if (mouse_state.button_pressed == MOUSE_STATE_LEFT_CLICK)
        {
            button->state = CLICKED;
        }
        else if (mouse_state.button_pressed == MOUSE_STATE_NONE && button->state == CLICKED)
        {
            if (NULL != button->command)
            {
                button->command();
                out = 1;
            }
            button->state = HOVERED;
        }
        else
        {
            button->state = HOVERED;
            animation_manager_add_constant_animation(&animation_manager, constant_animation_create(&button->rect.scale, 1.05, 0.02, true));
        }
    }
    else
    {
        button->state = NORMAL;
        animation_manager_add_constant_animation(&animation_manager, constant_animation_create(&button->rect.scale, 1, 0.02, true));
    }
    if (NULL != button->label)
    {
        label_update(button->label, scale_x, scale_y);
    }
    return out;
}

void button_render(Button *button, float scale_x, float scale_y)
{
    if (NULL == button || !button->active)
        return;

    UI_Element anchored_rect = button->rect;
    UI_Element_set_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);
    
    if (NULL != button->label)
    {
        UI_Element_match_size(&anchored_rect, &button->label->rect, scale_x, scale_y);
    }
        
    Color button_color;
    SDL_FRect button_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale_x * anchored_rect.scale, anchored_rect.height * scale_y * anchored_rect.scale};
    
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

    UI_Element_render_outline(&anchored_rect, scale_x, scale_y);
    UI_Element_render_inline(&anchored_rect, scale_x, scale_y);

    label_center(button->label, &anchored_rect, scale_x, scale_y);
    label_render(button->label, 1.0, 1.0);
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

int button_list_update_and_render(Button *buttons[], int count)
{
    int out = 0;
    for (int i = 0; i < count; i++)
    {
        out = button_update(buttons[i], SCALE_X, SCALE_Y);
        button_render(buttons[i], SCALE_X, SCALE_Y);
    }
    return out;
}