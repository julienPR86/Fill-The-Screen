#include "../../main.h"

int array_set_fields(Array *array, UI_Element **elements, int element_count, int max_per_line, int padding, int elements_anchor)
{
    if (NULL == array || NULL == elements || 0 == element_count || 0 == max_per_line)
        return -1;

    array->elements = elements;
    array->element_count = element_count;
    array->max_per_line = max_per_line;
    array->padding = padding;
    array->elements_anchor = elements_anchor;
    return 0;
}
Array *array_init(Array *array)
{
    if (NULL == array)
        return NULL;

    for (int i = 0; i < array->element_count; i++)
    {
        array->elements[i]->anchor = array->elements_anchor;
    }
    array->rect.width = array_get_width(array);
    array->rect.height = array_get_height(array);
    UI_Element_set_position(&array->rect, array->rect.x, array->rect.y, 1, 1, 1, 1, array->rect.anchor);
    array_set_elements_position(array);
    return array;
}

Array *array_set_elements_position(Array *array)
{
    if (NULL == array)
        return NULL;

    int x_pos = 0;
    int y_pos = 0;
    for (int i = 0; i < array->element_count; i++)
    {
        if (i && i % array->max_per_line == 0)
        {
            x_pos = 0;
            y_pos += array->padding + UI_Element_get_height(array->elements[i - 1], SCALE_Y);
        }
        UI_Element_set_position(array->elements[i], array->rect.x + x_pos, array->rect.y + y_pos, SCALE_X, SCALE_Y, -SCALE_X, -SCALE_Y, array->elements_anchor);
        x_pos += array->padding + UI_Element_get_width(array->elements[i], SCALE_X);
    }
    return array;
}

UI_Element *array_get_element(Array *array, int x, int y)
{
    if (NULL == array || x >= array->max_per_line || y >= array->element_count / array->max_per_line)
        return (NULL);

    UI_Element *element = array->elements[y * array->max_per_line + x];
    return element;
}

int array_get_width(Array *array)
{
    if (NULL == array || array->element_count <= 0)
        return -1;

    int width;
    int max_width = 0;
    UI_Element *element;
    for (int i = 0; i < array->element_count / array->max_per_line; i++)
    {
        width = 0;
        for (int j = 0; j < array->max_per_line; j++)
        {
            element = array_get_element(array, j, i);
            if (NULL != element)
                width += element->width;
        }
        if (width > max_width)
            max_width = width;
    }
    max_width += (array->max_per_line - 1) * array->padding;
    return max_width;
}

int array_get_height(Array *array)
{
    if (NULL == array || array->element_count <= 0)
        return -1;
    
    int height;
    int max_height = 0;
    UI_Element *element;
    for (int i = 0; i < array->max_per_line; i++)
    {
        height = 0;
        for (int j = 0; j < array->element_count / array->max_per_line; j++)
        {
            element = array_get_element(array, i, j);
            if (NULL != element)
                height += element->height;
        }
        if (height > max_height)
            max_height = height;
    }
    max_height += array->element_count / array->max_per_line * array->padding;
    return max_height;
}