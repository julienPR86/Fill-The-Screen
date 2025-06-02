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
    if (element->outline.size > 0)
    {
        SDL_FRect outline_rect = {element->x - element->outline.size * scale, element->y - element->outline.size * scale, element->width * scale + element->outline.size * 2 * scale, element->height * scale + element->outline.size * 2 * scale};
    
        SDL_SetRenderDrawColor(renderer, element->outline.color.r, element->outline.color.g, element->outline.color.b, element->outline.color.a);
        SDL_RenderFillRect(renderer, &outline_rect);
    }

    if (element->inline_.size <= 0)
        return;

    SDL_FRect inline_rect = {element->x, element->y, element->width, element->height};

    SDL_SetRenderDrawColor(renderer, element->inline_.color.r, element->inline_.color.g, element->inline_.color.b, element->inline_.color.a);
    SDL_RenderFillRect(renderer, &inline_rect);
    return;
}