#include "../../main.h"

UI_Element *UI_Element_set_fields(UI_Element *element, int x, int y, int width, int height, Outline outline, Inline inline_, double scale, t_uint8 anchor)
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

    if (element->width * element->scale * scale_x < frame->width)
    {
        element->width = frame->width;
    }
    if (element->height * element->scale * scale_y < frame->height)
    {
        element->height = frame->height;
    }
    return;
}

int UI_element_collision(UI_Element *element, int x, int y, float scale_x, float scale_y)
{
    UI_Element new_element = *element;
    UI_Element_set_position(&new_element, element->x, element->y, scale_x, scale_y, scale_x, scale_y, element->anchor);

    if (x >= new_element.x - new_element.outline.size * scale_x && x < new_element.x + (element->width * element->scale + new_element.outline.size) * scale_x && y >= new_element.y - new_element.outline.size * scale_y && y < new_element.y + (new_element.height * element->scale + new_element.outline.size) * scale_y)
    {
        return true;
    }
    return false;
}

void UI_Element_set_position(UI_Element *element, int x, int y, float x_position_factor, float y_position_factor, float scale_x, float scale_y, int anchor)
{
    element->x = (int)(x * x_position_factor);
    element->y = (int)(y * y_position_factor);
    
    switch (anchor)
    {
        case CENTER:
            element->x = (int)(x * x_position_factor - (element->width >> 1) * scale_x * element->scale);
            element->y = (int)(y * y_position_factor - (element->height >> 1) * scale_y * element->scale);
            break;

        case TOP_CENTER:
            element->x = (int)(x * x_position_factor) - (int)((element->width >> 1) * scale_x * element->scale);
            break;

        case TOP_RIGHT:
            element->x = (int)(x * x_position_factor) - (int)((element->width) * scale_x * element->scale);
            break;

        case MID_LEFT:
            element->y = (int)(y * y_position_factor) - (int)((element->height >> 1) * scale_y * element->scale);
            break;

        case MID_RIGHT:
            element->x = (int)(x * x_position_factor) - (int)((element->width) * scale_x * element->scale);
            element->y = (int)(y * y_position_factor) - (int)((element->height >> 1) * scale_y * element->scale);
            break;

        case BOTTOM_LEFT:
            element->y = (int)(y * y_position_factor) - (int)((element->height) * scale_y * element->scale);
            break;

        case BOTTOM_CENTER:
            element->x = (int)(x * x_position_factor) - (int)((element->width >> 1) * scale_x * element->scale);
            element->y = (int)(y * y_position_factor) - (int)((element->height) * scale_y * element->scale);
            break;

        case BOTTOM_RIGHT:
            element->x = (int)(x * x_position_factor) - (int)((element->width) * scale_x * element->scale);
            element->y = (int)(y * y_position_factor) - (int)((element->height) * scale_y * element->scale);
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

	SDL_FRect outline_rect = {
		element->x - (int)(element->outline.size * scale_x * element->scale),
		element->y - (int)(element->outline.size * scale_y * element->scale),
		(int)(element->width * scale_x * element->scale) + (int)(element->outline.size * scale_x * element->scale) * 2,
		(int)(element->height * scale_y * element->scale) + (int)(element->outline.size * scale_y * element->scale) * 2
	};
	SDL_SetRenderDrawColor(renderer, element->outline.color.r, element->outline.color.g, element->outline.color.b, element->outline.color.a);
	SDL_RenderFillRect(renderer, &outline_rect);
	return;
}

void UI_Element_render_inline(UI_Element *element, float scale_x, float scale_y)
{
	if (NULL == element || element->width <= 0 || element->height <= 0 || element->inline_.size <= 0)
		return;

	SDL_FRect inline_rect = {
		element->x,
		element->y,
		(int)(element->width * element->scale * scale_x),
		(int)(element->height * element->scale * scale_y)
	};
	SDL_SetRenderDrawColor(renderer, element->inline_.color.r, element->inline_.color.g, element->inline_.color.b, element->inline_.color.a);
	SDL_RenderFillRect(renderer, &inline_rect);
	return;
}

int UI_Element_get_height(UI_Element *element, float scale_y)
{
    return (element->height * element->scale + element->outline.size * 2) * scale_y;
}

int UI_Element_get_width(UI_Element *element, float scale_x)
{
    return (element->width * element->scale + element->outline.size * 2) * scale_x;
}