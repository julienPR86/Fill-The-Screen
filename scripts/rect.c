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

    UI_Element anchored_element = *element;
    set_UI_element_position(&anchored_element, anchored_element.x, anchored_element.y, scale, NONE);

    SDL_FRect outline_rect;
    
    SDL_SetRenderDrawColor(renderer, anchored_element.outline.color.r, anchored_element.outline.color.g, anchored_element.outline.color.b, anchored_element.outline.color.a);
    for (int i = 1; i <= element->outline.size * scale; i++)
    {
        outline_rect.x = anchored_element.x - i;
        outline_rect.y = anchored_element.y - i;
        outline_rect.w = anchored_element.width * scale + i * 2;
        outline_rect.h = anchored_element.height * scale + i * 2;
        SDL_RenderRect(renderer, &outline_rect);
    }
    return;
}

void render_inline(UI_Element *element, float scale)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->inline_.size <= 0)
        return;

    UI_Element anchored_element = *element;
    set_UI_element_position(&anchored_element, anchored_element.x, anchored_element.y, scale, NONE);

    SDL_FRect inline_rect;
    
    SDL_SetRenderDrawColor(renderer, anchored_element.inline_.color.r, anchored_element.inline_.color.g, anchored_element.inline_.color.b, anchored_element.inline_.color.a);
    for (int i = 0; i < anchored_element.inline_.size * scale; i++)
    {
        inline_rect.x = anchored_element.x +  i;
        inline_rect.y = anchored_element.y +  i;
        inline_rect.w = anchored_element.width * scale - i * 2;
        inline_rect.h = anchored_element.height * scale - i * 2;
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