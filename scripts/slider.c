#include "../main.h"

Slider *slider_set_fields(Slider *slider, int *value, int min, int max, int step, Label *label, SliderCursor *cursor, SliderStyle *style, int active)
{
    slider->value = value;
    if (NULL != value)
        slider->cache_value = *value;
    slider->min = min;
    slider->max = max;
    slider->step = step;
    slider->label = label;
    slider->cursor = cursor;
    slider->style = style;
    slider->active = active;
    return slider;
}

Slider *slider_init(Slider *slider, float scale_x, float scale_y)
{
    if (NULL == slider || NULL == slider_cursor_init(slider->cursor) || NULL == slider->style || slider->min == slider->max)
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

    slider_clamp_value(slider);
    slider_set_cursor_position(slider);

    slider->cache_value = *slider->value;

    if (NULL != slider->label)
    {
        slider->label->rect.anchor = NONE;

        if (NULL == slider_label_text_update(slider))
        {
            slider->label = NULL;
            return slider;
        }
        label_init(slider->label, scale_x, scale_y);
        slider_set_label_position(slider, scale_x, scale_y);
    }
    return slider;
}

int slider_update(Slider *slider, float scale_x, float scale_y)
{
    if (NULL == slider || NULL == slider->cursor || !slider->active || NULL == slider->value)
        return RETURN_NONE;

    int out = RETURN_NONE; // returns RETURN_NONE if the slider isn't clicked / updated
    
    if (UI_element_collision(&slider->rect, mouse_state.x, mouse_state.y, scale_x, scale_y) || UI_element_collision(&slider->cursor->rect, mouse_state.x, mouse_state.y, scale_x, scale_y) || slider->cursor->state == CLICKED)
    {
        if (mouse_state.frame_input)
        {
            slider->cursor->state = CLICKED;
        }
        
        if (mouse_state.button_pressed == MOUSE_STATE_LEFT_CLICK && slider->cursor->state == CLICKED)
        {
            slider->cursor->rect.x += mouse_state.delta_x;
            out = RETURN_SLIDER_UPDATE;
        }
        else if (mouse_state.wheel_value != 0)
        {
            slider->cursor->state = CLICKED;
            *slider->value += mouse_state.wheel_value * -1;
            out = RETURN_SLIDER_UPDATE;
        }
        else if (mouse_state.button_pressed == MOUSE_STATE_NONE)
        {
            slider->cursor->state = HOVERED;
        }
    }
    else
    {
        slider->cursor->state = NORMAL;
    }

    if (slider->cache_value != *slider->value) // Update the slider if the value has changed elsewhere
    {
        slider_set_cursor_position(slider);

        slider_label_text_update(slider);
        label_update(slider->label, scale_x, scale_y);

        slider->cache_value = *slider->value;
    }
    
    slider_clamp_value(slider);
    slider_clamp_cursor_position(slider);
    slider_set_label_position(slider, scale_x, scale_y);
    label_update(slider->label, scale_x, scale_y);
    
    if (RETURN_NONE == out)// Exit the function if the slider isn't being clicked / updated
    {
        slider_set_cursor_position(slider);
        return out;
    }

    if (mouse_state.wheel_value == 0) // Check if we change the slider value with the mouse
    {
        *slider->value = slider_get_value(slider);
        slider->cache_value = *slider->value;
    }
    else
    {
        slider_set_cursor_position(slider);
        slider_clamp_cursor_position(slider);
    }

    //update the slider label text
    if (NULL != slider->label->text)
    {
        free(slider->label->text);
        slider->label->text = NULL;
    } 
    slider_label_text_update(slider);
    return out;
}

void slider_render(Slider *slider, float scale_x, float scale_y)
{
    if (NULL == slider || NULL == slider->style || !slider->active)
        return;

    UI_Element anchored_rect = slider->rect;
    UI_Element_set_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);
    
    Color color;
    SDL_FRect slider_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width * scale_x, anchored_rect.height * scale_y};

    color = slider->style->background;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &slider_rect);

    UI_Element_render_outline(&anchored_rect, scale_x, scale_y);
    UI_Element_render_inline(&anchored_rect, scale_x, scale_y);

    slider_cursor_render(slider->cursor, scale_x, scale_y);

    if (NULL != slider->label)
    {
        label_render(slider->label, 1.0, scale_y);
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

void slider_set_cursor_position(Slider *slider)
{
    if (NULL == slider || NULL == slider->cursor || NULL == slider->value)
        return;

    slider->cursor->rect.x = roundf(slider->rect.x + ((slider->rect.width) * ((float)(*slider->value - slider->min) / (slider->max - slider->min))) - (slider->cursor->rect.width / 2.0f));
    slider->cursor->rect.y = slider->rect.y + CENTERED(slider->rect.height, slider->cursor->rect.height);
    return;
}

int slider_check_cursor_position(Slider *slider)
{
    if (NULL == slider)
        return RETURN_NONE;

    if (*slider->value != slider_get_value(slider))
        return false;

    return true;
}

void slider_clamp_cursor_position(Slider *slider)
{
    if (NULL == slider || NULL == slider->cursor)
        return;

    if (slider->cursor->rect.x + (slider->cursor->rect.width / 2) < slider->rect.x)
    {
        slider->cursor->rect.x = slider->rect.x - (slider->cursor->rect.width / 2);
    }

    else if (slider->cursor->rect.x + (slider->cursor->rect.width / 2) > slider->rect.x + slider->rect.width)
    {
        slider->cursor->rect.x = slider->rect.x + slider->rect.width - (slider->cursor->rect.width / 2);
    }
    
    slider->cursor->rect.y = slider->rect.y + CENTERED(slider->rect.height, slider->cursor->rect.height);
    return;
}

Slider *slider_label_text_update(Slider *slider)
{
    int digits = get_number_digits(slider->max)+1;

    slider->label->text = (char *)malloc(digits * sizeof(char));
    if (NULL == slider->label->text)
    {
        fprintf(stderr, "slider label text : Memory allocation error");
        return NULL;
    }
    snprintf(slider->label->text, digits, "%d", *slider->value);
    slider->label->update = true;

    return slider;
}

void slider_set_label_position(Slider *slider, float scale_x, float scale_y)
{
    if (NULL == slider || NULL == slider->label || NULL == slider->cursor)
        return;

    slider->label->rect.x = slider->rect.x * scale_x + (slider->rect.width + slider->cursor->rect.width / 2 + 5) * scale_x;
    slider->label->rect.y = slider->rect.y + CENTERED(slider->rect.height * scale_y, slider->label->rect.height);
    return;
}

int slider_get_value(Slider *slider)
{
    if (NULL == slider || NULL == slider->cursor)
        return RETURN_NONE;

    float ratio = ((slider->cursor->rect.x + (slider->cursor->rect.width / 2.0f)) - slider->rect.x) / slider->rect.width;
    int value = roundf(ratio * (slider->max - slider->min)) + slider->min;
    return value;
}

int slider_get_height(Slider *slider, float scale_y)
{
    if (NULL == slider)
        return 0;

    return MAX(UI_Element_get_height(&slider->rect, scale_y), UI_Element_get_height(&slider->cursor->rect, scale_y));
}

int slider_get_width(Slider *slider, float scale_x)
{
    if (NULL == slider || NULL == slider->label || NULL == slider->cursor)
        return 0;

    return UI_Element_get_width(&slider->rect, scale_x) + UI_Element_get_width(&slider->cursor->rect, scale_x) + slider->label->rect.width + 5 * scale_x;
}

int slider_list_update_and_render(Slider *sliders[], int count)
{
    int out = RETURN_NONE;
    for (int i = 0; i < count; i++)
    {
        out = slider_update(sliders[i], SCALE_X, SCALE_Y);
        slider_render(sliders[i], SCALE_X, SCALE_Y);
    }
    return out;
}