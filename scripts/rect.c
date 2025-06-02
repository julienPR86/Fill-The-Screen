#include "../main.h"

void rect_render(Rect *rect, float scale)
{
    if (NULL == rect || NULL == rect->rect_color)
        return;

    SDL_FRect outline_rect = {rect->rect.x - rect->rect.outline.size * scale, rect->rect.y - rect->rect.outline.size * scale, (rect->rect.width + rect->rect.outline.size * 2) * scale, (rect->rect.height + rect->rect.outline.size * 2) * scale};
    SDL_FRect main_rect = {rect->rect.x, rect->rect.y, rect->rect.width * scale, rect->rect.height * scale};

    SDL_SetRenderDrawColor(renderer, rect->rect.outline.color.r, rect->rect.outline.color.g, rect->rect.outline.color.b, rect->rect.outline.color.a);
    SDL_RenderFillRect(renderer, &outline_rect);
    
    SDL_SetRenderDrawColor(renderer, rect->rect_color->r, rect->rect_color->g, rect->rect_color->b, rect->rect_color->a);
    SDL_RenderFillRect(renderer, &main_rect);
    return;
}

void render_outline(UI_Element *element, float scale)
{
    SDL_FRect outline_rect = {element->x - element->outline.size * scale, element->y - element->outline.size * scale, element->width * scale + element->outline.size * 2 * scale, element->height * scale + element->outline.size * 2 * scale};
    SDL_FRect inline_rect = {element->x - element->inline_.size * scale, element->y - element->inline_.size * scale, element->width * scale + element->inline_.size * 2 * scale, element->height * scale + element->inline_.size * 2 * scale};
    
    SDL_SetRenderDrawColor(renderer, element->outline.color.r, element->outline.color.g, element->outline.color.b, element->outline.color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    SDL_SetRenderDrawColor(renderer, element->inline_.color.r, element->inline_.color.g, element->inline_.color.b, element->inline_.color.a);
    SDL_RenderFillRect(renderer, &inline_rect);
    return;
}