#include "../main.h"

Slider *slider_init(Slider *slider)
{
    if (NULL == slider || NULL == slider_cursor_init(slider->cursor) || NULL == slider->style)
        return NULL;

    slider->step = MIN(MAX(1, slider->step), slider->max);
    slider->w *= SCALEX;
    slider->h *= SCALEY;
    slider->style->outline *= SCALEY;

    if (slider->cursor->size < slider->h)
        slider->cursor->size = slider->h;
    
    if (*slider->value < slider->min)
        *slider->value = slider->min;

    if (*slider->value > slider->max)
        *slider->value = slider->max;

    slider->cursor->y = slider->y + CENTERED(slider->h, slider->cursor->size);
    slider->cursor->x = slider->x + slider->w  / ((float)slider->min + (slider->max - slider->min) / (*slider->value)) - slider->cursor->size/2;

    return slider;
}

int slider_update(Slider *slider)
{
    if (NULL == slider || NULL == slider->cursor || !slider->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the slider isn't clicked
    
    if (*slider->value < slider->min)
        *slider->value = slider->min;

    if (*slider->value > slider->max)
        *slider->value = slider->max;

    out = slider_cursor_update(slider->cursor);

    if (slider->cursor->x + slider->cursor->size / 2 < slider->x)
        slider->cursor->x = slider->x - slider->cursor->size / 2;

    else if (slider->cursor->x + slider->cursor->size / 2 > slider->x + slider->w)
        slider->cursor->x = slider->x + slider->w - slider->cursor->size / 2;

    slider->cursor->y = slider->y + CENTERED(slider->h, slider->cursor->size);

    *slider->value = slider->min + (slider->max - slider->min) * (slider->cursor->x + slider->cursor->size / 2 - slider->x) / slider->w / slider->step * slider->step;
    return out;
}

void slider_render(Slider *slider)
{
    if (NULL == slider || NULL == slider->style || !slider->active)
        return;
    
    SDL_Color color;
    SDL_Rect slider_rect = {slider->x, slider->y, slider->w, slider->h};
    SDL_Rect outline_rect = {slider->x - slider->style->outline, slider->y - slider->style->outline, slider->w + slider->style->outline * 2, slider->h + slider->style->outline * 2};
    
    color = slider->style->outline_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    color = slider->style->background;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &slider_rect);

    slider_cursor_render(slider->cursor);
    return;
}

int slider_height(Slider *slider)
{
    return slider->h + slider->style->outline*2;
}

int slider_width(Slider *slider)
{
    return slider->w + slider->style->outline*2;
}