#include "../main.h"

Slider *slider_init(Slider *slider)
{
    if (NULL == slider || NULL == slider->style)
        return NULL;

    slider->style->cursor_scale = MAX(0, slider->style->cursor_scale);

    slider->style->cursor = MAX(slider->h, slider->style->cursor);
    slider->style->cursor *= slider->style->cursor_scale * SCALEY;

    slider->step = MIN(MAX(1, slider->step), slider->max);

    slider->w *= SCALEX;
    slider->h *= SCALEY;
    slider->style->outline *= SCALEY;

    return slider;
}

int slider_update(Slider *slider)
{
    if (NULL == slider || !slider->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the slider isn't clicked

    if (slider->value < slider->min)
        slider->value = slider->min;

    if (slider->value > slider->max)
        slider->value = slider->max;

    if (slider_cursor_collision(slider, mouse_x, mouse_y))
    {
        if (mouse_button_pressed == 1)
        {
            slider->state = CLICKED;
            
        }
        else
        {
            slider->state = HOVERED;
        }
    }
    else
    {
        slider->state = NORMAL;
    }
    
    return out;
}

void slider_render(Slider *slider)
{
    if (NULL == slider || NULL == slider->style || !slider->active)
        return;

    int cursor_x_pos;
    if (slider->value != 0)
        cursor_x_pos = slider->x + slider->w / ((float)slider->max / slider->value);
    else
        cursor_x_pos = slider->x;

    SDL_Color color;
    SDL_Rect outline_rect = {slider->x - slider->style->outline, slider->y - slider->style->outline, slider->w + slider->style->outline*2, slider->h + slider->style->outline * 2};
    SDL_Rect slider_rect = {slider->x, slider->y, slider->w, slider->h};
    SDL_Rect cursor_rect = {cursor_x_pos - slider->style->cursor / 2, slider->y + CENTERED(slider->h, slider->style->cursor), slider->style->cursor, slider->style->cursor};
    SDL_Rect outline_cursor_rect = {cursor_rect.x - slider->style->outline, cursor_rect.y - slider->style->outline, cursor_rect.w + slider->style->outline * 2, cursor_rect.h + slider->style->outline * 2};

    color = slider->style->outline_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    color = slider->style->background;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &slider_rect);

    if (0 == slider->style->cursor_scale)
        return;
        
    color = slider->style->outline_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_cursor_rect);

    switch (slider->state)
    {
        case NORMAL:
            color = slider->style->cursor_bg;
            break;
        case HOVERED:
            color = slider->style->cursor_hover_color;
            break;
        case CLICKED:
            color = slider->style->cursor_fg;
            break;
        default:
            break;
    }
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &cursor_rect);
        
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