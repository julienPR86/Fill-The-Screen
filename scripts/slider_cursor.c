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
    SDL_FRect outline_rect = {cursor->rect.x - cursor->rect.outline.size * scale, cursor->rect.y - cursor->rect.outline.size * scale, (cursor->rect.width + cursor->rect.outline.size * 2) * scale, (cursor->rect.height + cursor->rect.outline.size * 2) * scale};

    color = cursor->rect.outline.color;
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