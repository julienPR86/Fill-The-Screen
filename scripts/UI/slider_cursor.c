#include "../../main.h"

SliderCursor *slider_cursor_set_fields(SliderCursor *cursor, int state, SliderCursorStyle *style)
{
    cursor->state = state;
    cursor->style = style;
    return cursor;
}

SliderCursor *slider_cursor_init(SliderCursor *cursor)
{
    if (NULL == cursor || NULL == cursor->style)
        return NULL;

    return cursor;
}

int slider_cursor_update(SliderCursor *cursor)
{
    if (NULL == cursor)
        return 0;
    
    return 0;
}

void slider_cursor_render(SliderCursor *cursor, float scale_x, float scale_y)
{
    if (NULL == cursor || NULL == cursor->style)
        return;

    UI_Element anchored_rect = cursor->rect;
    UI_Element_set_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);

    Color color;
    SDL_FRect cursor_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale_x * anchored_rect.scale, anchored_rect.height * scale_y * anchored_rect.scale};

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

    UI_Element_render_outline(&anchored_rect, scale_x, scale_y);
    UI_Element_render_inline(&anchored_rect, scale_x, scale_y);
    return;
}