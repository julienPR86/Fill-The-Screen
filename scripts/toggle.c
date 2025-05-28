#include "../main.h"

Toggle *toggle_init(Toggle *toggle)
{
    if (NULL == toggle)
        return NULL;

    toggle->label = label_init(toggle->label);

    toggle->rect.width = toggle->rect.width;
    toggle->rect.height = toggle->rect.height;

    if (NULL != toggle->label)
    {
        toggle->rect.width = MAX(toggle->rect.width, toggle->label->rect.width);
        toggle->rect.height = MAX(toggle->rect.height, toggle->label->rect.height);

        toggle->label->rect.x = toggle->rect.x + CENTERED(toggle->rect.width, toggle->label->rect.width);
        toggle->label->rect.y = toggle->rect.y + CENTERED(toggle->rect.height, toggle->label->rect.height);
    }
    return toggle;
}

int toggle_update(Toggle *toggle)
{
    if (NULL == toggle || !toggle->active)
        return RETURN_NONE;
    
    static int update = 1;
    int out = RETURN_NONE; // returns RETURN_NONE if the toggle isn't clicked
    if (UI_element_collision(&toggle->rect, mouse_x, mouse_y, SCALE))
    {
        if (mouse_button_pressed == MOUSE_STATE_LEFT_CLICK && update)
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
        else if (mouse_button_pressed == MOUSE_STATE_NONE && !update)
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
        label_update(toggle->label);
        
    if (NULL != toggle->command && CLICKED == toggle->state)
        out = toggle->command();
    return out;
}

void toggle_render(Toggle *toggle, float scale)
{
    if (NULL == toggle || !toggle->active)
        return;
        
    Color toggle_color;
    SDL_FRect toggle_rect = {toggle->rect.x + toggle->style->inline_ * scale, toggle->rect.y + toggle->style->inline_ * scale, (toggle->rect.width - toggle->style->inline_ * 2) * scale, (toggle->rect.height - toggle->style->inline_ * 2) * scale};
    SDL_FRect inline_rect = {toggle->rect.x, toggle->rect.y, toggle->rect.width * scale, toggle->rect.height * scale};
    SDL_FRect outline_rect = {toggle->rect.x - toggle->style->outline * scale, toggle->rect.y - toggle->style->outline * scale, (toggle->rect.width + toggle->style->outline * 2) * scale, (toggle->rect.height + toggle->style->outline * 2) * scale};

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

    SDL_SetRenderDrawColor(renderer, toggle->style->outline_color.r, toggle->style->outline_color.g, toggle->style->outline_color.b, toggle->style->outline_color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    SDL_SetRenderDrawColor(renderer, toggle->style->inline_color.r, toggle->style->inline_color.g, toggle->style->inline_color.b, toggle->style->inline_color.a);
    SDL_RenderFillRect(renderer, &inline_rect);

    SDL_SetRenderDrawColor(renderer, toggle_color.r, toggle_color.g, toggle_color.b, toggle_color.a);
    SDL_RenderFillRect(renderer, &toggle_rect);
    
    if (NULL != toggle->label)
        label_render(toggle->label);
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

int toggle_get_height(Toggle *toggle, float scale)
{
    return (toggle->rect.height + toggle->style->outline * 2) * scale;
}

int toggle_get_width(Toggle *toggle, float scale)
{
    return (toggle->rect.width + toggle->style->outline * 2) * scale;
}
