#include "../main.h"

Slider *slider_init(Slider *slider)
{
    if (NULL == slider || NULL == slider_cursor_init(slider->cursor) || NULL == slider->style)
        return NULL;

    slider->step = MIN(MAX(1, slider->step), slider->max);
    slider->w *= SCALEX;
    slider->h *= SCALEY;
    slider->style->outline *= SCALEY;

    if (NULL == slider->value)
    {
        slider->cursor->x = slider->x;
        slider->cursor->y = slider->y;
        slider->cursor->size = 0;
        return slider;
    }

    if (slider->cursor->size < slider->h)
        slider->cursor->size = slider->h;
    
    if (*slider->value < slider->min)
        *slider->value = slider->min;

    if (*slider->value > slider->max)
        *slider->value = slider->max;

    slider->cursor->x = slider->x + (slider->w * ((float)(*slider->value - slider->min) / (slider->max - slider->min))) - (float)slider->cursor->size / 2;
    slider->cursor->y = slider->y + CENTERED(slider->h, slider->cursor->size);

    slider->label->text = (char *)malloc((get_number_digits(slider->max)+1) * sizeof(char));
    if (NULL == slider->label->text)
    {
        fprintf(stderr, "slider->label->text : Memory allocation error");
    }
    snprintf(slider->label->text, (get_number_digits(slider->max)+1), "%d", *slider->value);
    if (NULL == label_init(slider->label))
    {
        fprintf(stderr, "Failed to init slider label\n");
    }
    slider->label->x = slider->cursor->x + CENTERED(slider->cursor->size, slider->label->w * slider->label->scale);
    slider->label->y = slider->cursor->y + CENTERED(slider->cursor->size, slider->label->h * slider->label->scale);
    return slider;
}

int slider_update(Slider *slider)
{
    if (NULL == slider || NULL == slider->cursor || !slider->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the slider isn't clicked

    out = slider_cursor_update(slider->cursor);
    switch (out)
    {
        case RETURN_SLIDER_UPDATE:
            if (slider->cursor->x + slider->cursor->size / 2 < slider->x)
                slider->cursor->x = slider->x - slider->cursor->size / 2;
            else if (slider->cursor->x + slider->cursor->size / 2 > slider->x + slider->w)
                slider->cursor->x = slider->x + slider->w - slider->cursor->size / 2;

            slider->label->x = slider->cursor->x + CENTERED(slider->cursor->size, slider->label->w * slider->label->scale);
            slider->cursor->y = slider->y + CENTERED(slider->h, slider->cursor->size);

            if (NULL == slider->value)
                break;
            
            if (NULL != slider->label->text)
            {
                free(slider->label->text);
                slider->label->text = NULL;
            }
            
            slider->label->text = (char *)malloc((get_number_digits(slider->max)+1) * sizeof(char));
            if (NULL == slider->label->text)
            {
                fprintf(stderr, "slider->label->text : Memory allocation error");
            }
            snprintf(slider->label->text, (get_number_digits(slider->max)+1), "%d", *slider->value);
            slider->label->update = true;

            *slider->value = slider->min + (slider->max - slider->min) * (slider->cursor->x + slider->cursor->size / 2 - slider->x) / slider->w / slider->step * slider->step;
            
            if (*slider->value < slider->min)
                *slider->value = slider->min;

            if (*slider->value > slider->max)
                *slider->value = slider->max;
            break;
        
        default:
            break;
    }
    label_update(slider->label);
    return out;
}

void slider_render(Slider *slider)
{
    if (NULL == slider || NULL == slider->style || !slider->active)
        return;
    
    Color color;
    SDL_Rect slider_rect = {slider->x, slider->y, slider->w, slider->h};
    SDL_Rect outline_rect = {slider->x - slider->style->outline, slider->y - slider->style->outline, slider->w + slider->style->outline * 2, slider->h + slider->style->outline * 2};
    
    color = slider->style->outline_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    color = slider->style->background;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &slider_rect);

    slider_cursor_render(slider->cursor);
    label_render(slider->label);
    return;
}

void slider_free(Slider *slider)
{
    if (NULL == slider || NULL == slider->label)
        return;
    
    if (NULL != slider->label->text)
    {
        free(slider->label->text);
        slider->label->text = NULL;
    }

    label_free(slider->label);
    return;
}

void slider_list_free(Slider *sliders[], int size)
{
    if (NULL == sliders)
        return;
    
    for (int i = 0; i < size; i++)
    {
        if (NULL == sliders[i])
            continue;

        slider_free(sliders[i]);
    }
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