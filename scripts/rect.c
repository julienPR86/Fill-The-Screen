#include "../main.h"

void rect_render(Rect *rect, float scale)
{
    if (NULL == rect || NULL == rect->rect_color)
        return;

    SDL_FRect main_rect = {rect->rect.x, rect->rect.y, rect->rect.width * scale, rect->rect.height * scale};

    render_outline(&rect->rect, scale);

    SDL_SetRenderDrawColor(renderer, rect->rect_color->r, rect->rect_color->g, rect->rect_color->b, rect->rect_color->a);
    SDL_RenderFillRect(renderer, &main_rect);
    return;
}

void render_outline(UI_Element *element, float scale)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->outline.size <= 0)
        return;

    SDL_FRect outline_rect;
    
    SDL_SetRenderDrawColor(renderer, element->outline.color.r, element->outline.color.g, element->outline.color.b, element->outline.color.a);
    for (int i = 1; i <= element->outline.size * scale; i++)
    {
        outline_rect.x = element->x - i;
        outline_rect.y = element->y - i;
        outline_rect.w = element->width * scale + i * 2;
        outline_rect.h = element->height * scale + i * 2;
        SDL_RenderRect(renderer, &outline_rect);
    }
    return;
}

void render_inline(UI_Element *element, float scale)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->inline_.size <= 0)
        return;

    SDL_FRect inline_rect;
    
    SDL_SetRenderDrawColor(renderer, element->inline_.color.r, element->inline_.color.g, element->inline_.color.b, element->inline_.color.a);
    for (int i = 0; i < element->inline_.size * scale; i++)
    {
        inline_rect.x = element->x +  i;
        inline_rect.y = element->y +  i;
        inline_rect.w = element->width * scale - i * 2;
        inline_rect.h = element->height * scale - i * 2;
        SDL_RenderRect(renderer, &inline_rect);
    }
    return;
}

int get_height(UI_Element *element, float scale)
{
    return (element->height + element->outline.size * 2) * scale;
}

int get_width(UI_Element *element, float scale)
{
    return (element->width + element->outline.size * 2) * scale;
}