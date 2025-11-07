#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "UI_Element.h"

typedef struct Array
{
    UI_Element rect;
    UI_Element **elements;
    int element_count;
    int max_per_line;
    int padding;
    int elements_anchor;
} Array;

int array_set_fields(Array *array, UI_Element **elements, int element_count, int max_per_line, int padding, int elements_anchor);
Array *array_init(Array *array);
Array *array_set_elements_position(Array *array);
UI_Element *array_get_element(Array *array, int x, int y);
int array_get_width(Array *array);
int array_get_height(Array *array);

#endif