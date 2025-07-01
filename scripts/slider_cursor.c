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

void slider_cursor_render(SliderCursor *cursor, float scale_x, float scale_y)
{
    if (NULL == cursor || NULL == cursor->style)
        return;

    UI_Element anchored_rect = cursor->rect;
    set_UI_element_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);

    Color color;
    SDL_FRect cursor_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale_x, anchored_rect.height * scale_y};

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

    render_outline(&anchored_rect, scale_x, scale_y);
    render_inline(&anchored_rect, scale_x, scale_y);
    return;
}