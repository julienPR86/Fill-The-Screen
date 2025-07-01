#include "../main.h"

void rect_render(Rect *rect, float scale_x, float scale_y)
{
    if (NULL == rect || NULL == rect->rect_color)
        return;

    UI_Element anchored_rect = rect->rect;
    set_UI_element_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);

    SDL_FRect _rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale_x, anchored_rect.height * scale_y};

    render_outline(&anchored_rect, scale_x, scale_y);

    SDL_SetRenderDrawColor(renderer, rect->rect_color->r, rect->rect_color->g, rect->rect_color->b, rect->rect_color->a);
    SDL_RenderFillRect(renderer, &_rect);
    return;
}

void render_outline(UI_Element *element, float scale_x, float scale_y)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->outline.size <= 0)
        return;

    SDL_FRect outline_rect;
    
    SDL_SetRenderDrawColor(renderer, element->outline.color.r, element->outline.color.g, element->outline.color.b, element->outline.color.a);
    for (int i = 1; i <= element->outline.size; i++)
    {
        outline_rect.x = element->x - i;
        outline_rect.y = element->y - i;
        outline_rect.w = element->width * scale_x + i * 2;
        outline_rect.h = element->height * scale_y + i * 2;
        SDL_RenderRect(renderer, &outline_rect);
    }
    return;
}

void render_inline(UI_Element *element, float scale_x, float scale_y)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->inline_.size <= 0)
        return;

    SDL_FRect inline_rect;
    
    SDL_SetRenderDrawColor(renderer, element->inline_.color.r, element->inline_.color.g, element->inline_.color.b, element->inline_.color.a);
    for (int i = 0; i < element->inline_.size; i++)
    {
        inline_rect.x = element->x + i;
        inline_rect.y = element->y + i;
        inline_rect.w = element->width * scale_x - i * 2;
        inline_rect.h = element->height * scale_y - i * 2;
        SDL_RenderRect(renderer, &inline_rect);
    }
    return;
}

int get_height(UI_Element *element, float scale_y)
{
    return (element->height + element->outline.size * 2) * scale_y;
}

int get_width(UI_Element *element, float scale_x)
{
    return (element->width + element->outline.size * 2) * scale_x;
}