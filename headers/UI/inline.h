#ifndef INLINE_H
#define INLINE_H

#include "../color.h"

//Structure that represent the inline rect of an UI_Element
typedef struct Inline
{
    //Inline thickness
    int size;
    //Inline color
    Color color;
} Inline;

#endif