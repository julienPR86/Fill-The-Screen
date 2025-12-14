#include "../../main.h"

Toggle *toggle_set_fields(Toggle *toggle, t_uint8 state, Label *label, ButtonStyle *style, int (*command)(), t_uint8 active)
{
    toggle->state = state;
    toggle->label = label;
    toggle->style = style;
    toggle->command = command;
    toggle->active = active;
    return toggle;
}

Toggle *toggle_init(Toggle *toggle, float scale_x, float scale_y)
{
    if (NULL == toggle)
        return NULL;

    toggle->label = label_init(toggle->label, scale_x, scale_y);

    if (NULL != toggle->label)
    {
        toggle->label->rect.anchor = NONE;

        UI_Element_match_size(&toggle->rect, &toggle->label->rect, scale_x, scale_y);

        label_center(toggle->label, &toggle->rect, scale_x, scale_y);
    }
    return toggle;
}

int toggle_update(Toggle *toggle, float scale_x, float scale_y)
{
    if (NULL == toggle || !toggle->active)
        return 0;
    
    int out = 0; // returns 0 if the toggle isn't clicked
    if (UI_element_collision(&toggle->rect, mouse_state.x, mouse_state.y, scale_x, scale_y))
    {
        animation_manager_add_constant_animation(&animation_manager, constant_animation_create(&toggle->rect.scale, 1.05, 0.02, true));
        if (mouse_state.button_pressed == MOUSE_STATE_LEFT_CLICK && mouse_state.frame_input)
        {
            switch (toggle->state)
            {
                case NORMAL:
                case HOVERED:
                    toggle->state = CLICKED;
                    if (NULL != toggle->command)
                        out = toggle->command();
                    break;
                case CLICKED:
                    toggle->state = HOVERED;
                    break;
                default:
                    break;
            }
        }
        else if (mouse_state.button_pressed == MOUSE_STATE_NONE && toggle->state != CLICKED)
        {
            toggle->state = HOVERED;
        }
    }
    else
    {
        if (HOVERED == toggle->state)
        {
            toggle->state = NORMAL;
        }
        animation_manager_add_constant_animation(&animation_manager, constant_animation_create(&toggle->rect.scale, 1, 0.02, true));
    }
    if (NULL != toggle->label)
    {
        label_update(toggle->label, scale_x, scale_y);
    }
    return out;
}

void toggle_render(Toggle *toggle, float scale_x, float scale_y)
{
    if (NULL == toggle || !toggle->active)
        return;

    UI_Element anchored_rect = toggle->rect;
    UI_Element_set_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);

    if (NULL != toggle->label)
    {
        UI_Element_match_size(&anchored_rect, &toggle->label->rect, scale_x, scale_y);
    }
        
    Color toggle_color;
    SDL_FRect toggle_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale_x * anchored_rect.scale, anchored_rect.height * scale_y * anchored_rect.scale};

    switch (toggle->state)
    {
        case NORMAL:
            toggle_color = toggle->style->background;
            break;
        case CLICKED:
            toggle_color = toggle->style->foreground;
            break;
        case HOVERED:
            toggle_color = toggle->style->hover_color;
            break;
        default:
            break;
    }

    SDL_SetRenderDrawColor(renderer, toggle_color.r, toggle_color.g, toggle_color.b, toggle_color.a);
    SDL_RenderFillRect(renderer, &toggle_rect);

    UI_Element_render_outline(&anchored_rect, scale_x, scale_y);
    UI_Element_render_inline(&anchored_rect, scale_x, scale_y);
    
    label_center(toggle->label, &anchored_rect, scale_x, scale_y);
    label_render(toggle->label, 1, 1);
    return;
}

void toggle_free(Toggle *toggle)
{
    if (NULL == toggle || NULL == toggle->label)
        return;
        
    label_free(toggle->label);
    return;
}

void toggle_list_free(Toggle *toggles[], int size)
{
    if (NULL == toggles)
        return;

    for (int i = 0; i < size; i++)
    {
        if (NULL == toggles[i])
            continue;

        toggle_free(toggles[i]);
    }
    return;
}

int toggle_list_update_and_render(Toggle **toggles, int count)
{
    int out = 0;
    for (int i = 0; i < count; i++)
    {
        out = toggle_update(toggles[i], SCALE_X, SCALE_Y);
        toggle_render(toggles[i], SCALE_X, SCALE_Y);
    }
    return out;
}