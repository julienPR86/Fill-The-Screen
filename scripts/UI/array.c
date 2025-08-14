#include "../../main.h"

int array_set_fields(Array *array, UI_Element **elements, int element_count, int max_row_number, int max_column_number, int padding)
{
    if (NULL == array || NULL == elements || 0 == element_count)
        return -1;

    array->elements = elements;
    array->element_count = element_count;
    array->max_row_number = max_row_number;
    array->max_column_number = max_column_number;
    array->padding = padding;
    return 0;
}
Array *array_init(Array *array)
{
    if (NULL == array)
        return NULL;
        
    return array;
}