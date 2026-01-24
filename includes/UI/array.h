#ifndef ARRAY_H
#define ARRAY_H

#include "UI_Element.h"

//Structure that contains a list of elements and can controls their position based on multiples parameters
typedef struct Array
{
	//The array rect that contains its position and its dimensions
    UI_Element rect;
	//The elements list to control
    UI_Element **elements;
	//The number of elements in the elements list
    int element_count;
	//The max number of elements per line
    int max_per_line;
	//The free space between each elements
    int padding;
	//The anchor of each elements
    int elements_anchor;
} Array;

//Set the fields of an array with the arguments passed in
int array_set_fields(Array *array, UI_Element **elements, int element_count, int max_per_line, int padding, int elements_anchor);
//Initialise the array passed in, needs to be called before all array functions except array_set_fields
Array *array_init(Array *array);
//Sets the position of all elements based on the array parameters
Array *array_set_elements_position(Array *array);
//Returns the element at the (x, y) position in the array
UI_Element *array_get_element(Array *array, int x, int y);
//Returns the width of the array passed in
int array_get_width(Array *array);
//Returns the height of the array passed in
int array_get_height(Array *array);

#endif