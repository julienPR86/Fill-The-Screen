#ifndef OUTLINE_H
#define OUTLINE_H

#include "../color.h"

//Structure that represent the outline rect of an UI_Element
typedef struct Outline
{
    //Outline thickness
    int size;
    //outline color
    Color color;
} Outline;

#endif