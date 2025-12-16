#include "../../main.h"

void rect_set_fields(Rect *rect, Color *color)
{
    rect->rect_color = color;
    return;
}

void rect_render(Rect *rect, float scale_x, float scale_y)
{
    if (NULL == rect || NULL == rect->rect_color)
        return;

    UI_Element anchored_rect = rect->rect;
    UI_Element_set_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);

    SDL_FRect _rect = {anchored_rect.x, anchored_rect.y, (anchored_rect.width * scale_x), (anchored_rect.height * scale_y)};

    UI_Element_render_outline(&anchored_rect, scale_x, scale_y);

    SDL_SetRenderDrawColor(renderer, rect->rect_color->r, rect->rect_color->g, rect->rect_color->b, rect->rect_color->a);
    SDL_RenderFillRect(renderer, &_rect);
    return;
}

int rect_list_update_and_render(Rect *rects[], t_uint count)
{
    for (t_uint i = 0; i < count; i++)
    {
        rect_render(rects[i], SCALE_X, SCALE_Y);
    }
    return (0);
}