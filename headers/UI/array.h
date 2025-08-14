#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "../../main.h"

typedef struct Array
{
    UI_Element **elements;
    int element_count;
    int max_per_row;
    int max_per_column;
    int padding;
} Array;

#endif