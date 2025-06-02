#include "../main.h"

SliderCursor *slider_cursor_init(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return NULL;

    return cursor;
}

int slider_cursor_update(SliderCursor *cursor)
{
    if (NULL == cursor)
        return RETURN_NONE;
    
    return RETURN_NONE;
}

void slider_cursor_render(SliderCursor *cursor, float scale)
{
    if (NULL == cursor || NULL == cursor->style)
        return;

    Color color;
    SDL_FRect cursor_rect = {cursor->rect.x, cursor->rect.y, cursor->rect.width* scale, cursor->rect.height * scale};

    render_outline(&cursor->rect, scale);

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