#include "../main.h"

Toggle *toggle_init(Toggle *toggle, float scale)
{
    if (NULL == toggle)
        return NULL;

    toggle->label = label_init(toggle->label, scale);

    if (NULL != toggle->label)
    {
        toggle->label->rect.anchor = NONE;

        toggle->rect.width = MAX(toggle->rect.width, toggle->label->rect.width/scale);
        toggle->rect.height = MAX(toggle->rect.height, toggle->label->rect.height/scale);

        label_center(toggle->label, &toggle->rect, scale);
    }
    return toggle;
}

int toggle_update(Toggle *toggle, float scale)
{
    if (NULL == toggle || !toggle->active)
        return RETURN_NONE;
    
    static int update = 1;
    int out = RETURN_NONE; // returns RETURN_NONE if the toggle isn't clicked
    if (UI_element_collision(&toggle->rect, mouse_state.x, mouse_state.y, SCALE, SCALE_X, SCALE_Y))
    {
        if (mouse_state.button_pressed == MOUSE_STATE_LEFT_CLICK && update)
        {
            switch (toggle->state)
            {
                case NORMAL:
                case HOVERED:
                    toggle->state = CLICKED;
                    break;
                case CLICKED:
                    toggle->state = HOVERED;
                    break;
                default:
                    break;
            }
            update = 0;
        }
        else if (mouse_state.button_pressed == MOUSE_STATE_NONE && !update)
        {
            update = 1;
        }
        else if (NORMAL == toggle->state)
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
    }
    if (NULL != toggle->label)
        label_update(toggle->label, scale);
        
    if (NULL != toggle->command && CLICKED == toggle->state)
        out = toggle->command();
    return out;
}

void toggle_render(Toggle *toggle, float scale)
{
    if (NULL == toggle || !toggle->active)
        return;

    UI_Element anchored_rect = toggle->rect;
    set_UI_element_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale, SCALE_X, SCALE_Y, anchored_rect.anchor);
        
    Color toggle_color;
    SDL_FRect toggle_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale, anchored_rect.height * scale};

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

    render_outline(&anchored_rect, scale);
    render_inline(&anchored_rect, scale);
    
    label_center(toggle->label, &anchored_rect, scale);
    label_render(toggle->label, scale);
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
