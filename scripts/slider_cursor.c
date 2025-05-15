#include "../main.h"

SliderCursor *slider_cursor_init(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return NULL;

    return cursor;
}

int slider_cursor_update(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return RETURN_NONE;
    
    int out = RETURN_NONE;

    if (slider_cursor_collision(cursor, mouse_x, mouse_y, SCALE) || cursor->state == CLICKED)
    {
        if (mouse_button_pressed == 1)
        {
            cursor->state = CLICKED;
            cursor->x += mouse_delta_x;
            out = RETURN_SLIDER_UPDATE;
        }
        else
        {
            cursor->state = HOVERED;
        }
    }
    else
    {
        cursor->state = NORMAL;
    }
    return out;
}

void slider_cursor_render(SliderCursor *cursor, float scale)
{
    if (NULL == cursor || NULL == cursor->style)
        return;

    Color color;
    SDL_FRect cursor_rect = {cursor->x, cursor->y, cursor->size * scale, cursor->size * scale};
    SDL_FRect outline_rect = {cursor->x - cursor->style->outline * scale, cursor->y - cursor->style->outline * scale, (cursor->size + cursor->style->outline * 2) * scale, (cursor->size + cursor->style->outline * 2) * scale};

    color = cursor->style->outline_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    switch (cursor->state)
    {
        case NORMAL:
            color = cursor->style->bg;
            break;
        case HOVERED:
            color = cursor->style->hover_color;
            break;
        case CLICKED:
            color = cursor->style->fg;
            break;
        default:
            break;
    }
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &cursor_rect);
    return;
}