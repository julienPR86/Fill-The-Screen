#include "../main.h"

void rect_render(Rect *rect)
{
    SDL_Rect outline_rect = {rect->x - rect->outline, rect->y - rect->outline, rect->w + rect->outline*2, rect->h + rect->outline*2};
    SDL_Rect main_rect = {rect->x, rect->y, rect->w, rect->h};

    SDL_SetRenderDrawColor(renderer, rect->outline_color.r, rect->outline_color.g, rect->outline_color.b, rect->outline_color.a);
    SDL_RenderFillRect(renderer, &outline_rect);
    
    SDL_SetRenderDrawColor(renderer, rect->rect_color->r, rect->rect_color->g, rect->rect_color->b, rect->rect_color->a);
    SDL_RenderFillRect(renderer, &main_rect);
    return;
}