#include "../../main.h"

UI_Element *UI_Element_set_fields(UI_Element *element, int x, int y, int width, int height, Outline outline, Inline inline_, float scale, int anchor)
{
    element->x = x;
    element->y = y;
    element->width = width;
    element->height = height;
    element->outline = outline;
    element->inline_ = inline_;
    element->scale = scale;
    element->anchor = anchor;
    return element;
}

void UI_Element_match_size(UI_Element *element, UI_Element *frame, float scale_x, float scale_y)
{
    if (NULL == element || NULL == frame)
        return;

    if (element->width * scale_x < frame->width)
    {
        element->width = frame->width;
    }
    if (element->height * scale_y < frame->height)
    {
        element->height = frame->height;
    }
    return;
}

int UI_element_collision(UI_Element *element, int x, int y, float scale_x, float scale_y)
{
    UI_Element new_element = *element;
    UI_Element_set_position(&new_element, element->x, element->y, scale_x, scale_y, scale_x, scale_y, element->anchor);

    if (x >= new_element.x - new_element.outline.size * scale_x && x < new_element.x + (element->width + new_element.outline.size) * scale_x && y >= new_element.y - new_element.outline.size * scale_y && y < new_element.y + (new_element.height + new_element.outline.size) * scale_y)
    {
        return true;
    }
    return false;
}

void UI_Element_set_position(UI_Element *element, int x, int y, float x_position_factor, float y_position_factor, float scale_x, float scale_y, int anchor)
{
    element->x = x * x_position_factor;
    element->y = y * y_position_factor;
    
    switch (anchor)
    {
        case CENTER:
            element->x = x * x_position_factor - (element->width / 2 + element->outline.size) * scale_x;
            element->y = y * y_position_factor - (element->height / 2 + element->outline.size) * scale_y;
            break;

        case TOP_CENTER:
            element->x = x * x_position_factor - (element->width / 2 + element->outline.size) * scale_x;
            break;

        case TOP_RIGHT:
            element->x = x * x_position_factor - (element->width + element->outline.size) * scale_x;
            break;

        case MID_LEFT:
            element->y = y * y_position_factor - (element->height / 2 + element->outline.size) * scale_y;
            break;

        case MID_RIGHT:
            element->x = x * x_position_factor - (element->width + element->outline.size) * scale_x;
            element->y = y * y_position_factor - (element->height / 2 + element->outline.size) * scale_y;
            break;

        case BOTTOM_LEFT:
            element->y = y * y_position_factor - (element->height + element->outline.size) * scale_y;
            break;

        case BOTTOM_CENTER:
            element->x = x * x_position_factor - (element->width / 2 + element->outline.size) * scale_x;
            element->y = y * y_position_factor - (element->height + element->outline.size) * scale_y;
            break;

        case BOTTOM_RIGHT:
            element->x = x * x_position_factor - (element->width + element->outline.size) * scale_x;
            element->y = y * y_position_factor - (element->height + element->outline.size) * scale_y;
            break;

        case NONE:
        case TOP_LEFT:
        default:
            break;
    }
    return;
}

void UI_Element_render_outline(UI_Element *element, float scale_x, float scale_y)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->outline.size <= 0)
        return;

    SDL_FRect outline_rect;
    
    SDL_SetRenderDrawColor(renderer, element->outline.color.r, element->outline.color.g, element->outline.color.b, element->outline.color.a);
    for (int i = 1; i <= element->outline.size; i++)
    {
        outline_rect.x = element->x - i;
        outline_rect.y = element->y - i;
        outline_rect.w = element->width * scale_x + i * 2;
        outline_rect.h = element->height * scale_y + i * 2;
        SDL_RenderRect(renderer, &outline_rect);
    }
    return;
}

void UI_Element_render_inline(UI_Element *element, float scale_x, float scale_y)
{
    if (NULL == element || element->width <= 0 || element->height <= 0 || element->inline_.size <= 0)
        return;

    SDL_FRect inline_rect;
    
    SDL_SetRenderDrawColor(renderer, element->inline_.color.r, element->inline_.color.g, element->inline_.color.b, element->inline_.color.a);
    for (int i = 0; i < element->inline_.size; i++)
    {
        inline_rect.x = element->x + i;
        inline_rect.y = element->y + i;
        inline_rect.w = element->width * scale_x - i * 2;
        inline_rect.h = element->height * scale_y - i * 2;
        SDL_RenderRect(renderer, &inline_rect);
    }
    return;
}

int UI_Element_get_height(UI_Element *element, float scale_y)
{
    return (element->height + element->outline.size * 2) * scale_y;
}

int UI_Element_get_width(UI_Element *element, float scale_x)
{
    return (element->width + element->outline.size * 2) * scale_x;
}