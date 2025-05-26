#include "../main.h"

Slider *slider_init(Slider *slider, float scale)
{
    if (NULL == slider || NULL == slider_cursor_init(slider->cursor) || NULL == slider->style)
        return NULL;

    if (NULL == slider->value)
    {
        slider->cursor->rect.x = slider->rect.x;
        slider->cursor->rect.y = slider->rect.y;
        slider->cursor->rect.width = 0;
        slider->cursor->rect.height = 0;
        return slider;
    }

    slider->step = MIN(MAX(1, slider->step), slider->max);

    if (slider->cursor->rect.height < slider->rect.height)
        slider->cursor->rect.height = slider->rect.height;
    
    slider->cursor->rect.width = slider->cursor->rect.height;

    slider_clamp_value(slider);

    slider_set_cursor_position(slider, scale);

    if (NULL != slider->label)
    {
        slider->label->text = (char *)malloc((get_number_digits(slider->max)+1) * sizeof(char));
        if (NULL == slider->label->text)
        {
            fprintf(stderr, "slider->label->text : Memory allocation error");
        }
        snprintf(slider->label->text, get_number_digits(slider->max)+1, "%d", *slider->value);

        slider->label = label_init(slider->label);
        
        slider_set_label_position(slider, scale);
    }
    return slider;
}

int slider_update(Slider *slider, float scale)
{
    if (NULL == slider || NULL == slider->cursor || !slider->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the slider isn't clicked

    out = slider_cursor_update(slider->cursor);
    switch (out)
    {
        case RETURN_SLIDER_UPDATE:
            break;
            
        default:
            break;
    }

    slider_clamp_cursor_position(slider, scale);
    slider_set_label_position(slider, scale);
    
    if (RETURN_NONE == out)
    {    
        if (UI_element_collision(&slider->rect, mouse_x, mouse_y, SCALE) || slider->cursor->state == CLICKED)
        {
            if (mouse_button_pressed == MOUSE_STATE_LEFT_CLICK)
            {
                slider->cursor->state = CLICKED;
                slider->cursor->rect.x += mouse_delta_x;
                out = RETURN_SLIDER_UPDATE;
            }
        }
    }
    
    if (RETURN_NONE != out && NULL != slider->label && NULL != slider->value) // Execute if the slider is being updated
    {
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

        *slider->value = slider->min + (slider->max - slider->min) * (slider->cursor->rect.x + (slider->cursor->rect.width * scale) / 2 - slider->rect.x) / (slider->rect.width * scale) / slider->step * slider->step;
        slider_clamp_value(slider);

        label_update(slider->label);
    }
    return out;
}

void slider_render(Slider *slider, float scale)
{
    if (NULL == slider || NULL == slider->style || !slider->active)
        return;
    
    Color color;
    SDL_FRect slider_rect = {slider->rect.x, slider->rect.y, slider->rect.width * scale, slider->rect.height * scale};
    SDL_FRect outline_rect = {slider->rect.x - slider->style->outline * scale, slider->rect.y - slider->style->outline * scale, (slider->rect.width + slider->style->outline * 2) * scale, (slider->rect.height + slider->style->outline * 2) * scale};
    
    color = slider->style->outline_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    color = slider->style->background;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &slider_rect);

    slider_cursor_render(slider->cursor, scale);
    if (NULL != slider->label)
    {
        label_render(slider->label);
    }
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

void slider_clamp_value(Slider *slider)
{
    if (NULL == slider)
        return;
        
    if (*slider->value < slider->min)
    {
        *slider->value = slider->min;
    }

    if (*slider->value > slider->max)
    {
        *slider->value = slider->max;
    }
    return;
}

void slider_set_cursor_position(Slider *slider, float scale)
{
    if (NULL == slider || NULL == slider->cursor || NULL == slider->value)
        return;

    slider->cursor->rect.x = slider->rect.x + (slider->rect.width * scale * ((float)(*slider->value - slider->min) / (slider->max - slider->min))) - (float)slider->cursor->rect.width * scale / 2;
    slider->cursor->rect.y = slider->rect.y + CENTERED(slider->rect.height * scale, slider->cursor->rect.height * scale);
    return;
}

void slider_clamp_cursor_position(Slider *slider, float scale)
{
    if (NULL == slider || NULL == slider->cursor)
        return;

    if (slider->cursor->rect.x + slider->cursor->rect.width / 2 < slider->rect.x)
    {
        slider->cursor->rect.x = slider->rect.x - slider->cursor->rect.width / 2;
    }

    else if (slider->cursor->rect.x + slider->cursor->rect.width / 2 > slider->rect.x + slider->rect.width * scale)
    {
        slider->cursor->rect.x = slider->rect.x + slider->rect.width * scale - slider->cursor->rect.width / 2;
    }
    
    if (slider->cursor->rect.y < slider->rect.y)
    {
        slider->cursor->rect.y = slider->rect.y;
    }
    else if (slider->cursor->rect.y > slider->rect.y)
    {
        slider->cursor->rect.y = slider->rect.y;
    }

    return;
}

void slider_set_label_position(Slider *slider, float scale)
{
    if (NULL == slider || NULL == slider->label)
        return;

    slider->label->rect.x = slider->rect.x + slider->rect.width * scale + 10;
    slider->label->rect.y = slider->rect.y + CENTERED(slider->rect.height * scale, slider->label->rect.height * scale);
    return;
}

int slider_height(Slider *slider, float scale)
{
    if (NULL == slider)
        return 0;

    return (slider->rect.height + slider->style->outline * 2) * scale;
}

int slider_width(Slider *slider, float scale)
{
    if (NULL == slider)
        return 0;

    return (slider->rect.width + slider->style->outline * 2) * scale;
}