#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "../../main.h"

typedef struct Array
{
    int x;
    int y;
    UI_Element **elements;
    int element_count;
    int max_row_number;
    int max_column_number;
    int padding;
} Array;

int array_set_fields(Array *array, int x, int y, UI_Element **elements, int element_count, int max_row_number, int max_column_number, int padding);
Array *array_init(Array *array);

#endif