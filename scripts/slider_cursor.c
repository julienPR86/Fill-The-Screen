#include "../main.h"

SliderCursor *slider_cursor_init(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return NULL;
    
    cursor->size *= SCALEY;
    cursor->style->outline *= SCALEY;

    return cursor;
}

int slider_cursor_update(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return RETURN_NONE;
    
    int out = RETURN_NONE;

    if (slider_cursor_collision(cursor, mouse_x, mouse_y) || cursor->state == CLICKED)
    {
        if (mouse_button_pressed == 1)
        {
            cursor->state = CLICKED;
            cursor->x += mouse_delta_x;
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

void slider_cursor_render(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return;

    SDL_Color color;
    SDL_Rect cursor_rect = {cursor->x, cursor->y, cursor->size, cursor->size};
    SDL_Rect outline_rect = {cursor->x - cursor->style->outline, cursor->y - cursor->style->outline, cursor->size + cursor->style->outline * 2, cursor->size + cursor->style->outline * 2};

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