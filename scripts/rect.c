#include "../main.h"

void rect_render(Rect *rect, float scale)
{
    if (NULL == rect || NULL == rect->rect_color)
        return;

    SDL_FRect outline_rect = {rect->x - rect->outline * scale, rect->y - rect->outline * scale, (rect->w + rect->outline * 2) * scale, (rect->h + rect->outline * 2) * scale};
    SDL_FRect main_rect = {rect->x, rect->y, rect->w * scale, rect->h * scale};

    SDL_SetRenderDrawColor(renderer, rect->outline_color.r, rect->outline_color.g, rect->outline_color.b, rect->outline_color.a);
    SDL_RenderFillRect(renderer, &outline_rect);
    
    SDL_SetRenderDrawColor(renderer, rect->rect_color->r, rect->rect_color->g, rect->rect_color->b, rect->rect_color->a);
    SDL_RenderFillRect(renderer, &main_rect);
    return;
}