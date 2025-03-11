#include "../main.h"

Slider *slider_init(Slider *slider)
{
    if (NULL == slider)
        return NULL;

    

    return slider;
}

int slider_update(Slider *slider)
{
    if (NULL == slider || !slider->active)
        return RETURN_NONE;
    
    int out = RETURN_NONE; // returns RETURN_NONE if the slider isn't clicked

    return out;
}

void slider_render(Slider *slider)
{
    if (NULL == slider || !slider->active)
        return;
        
    return;
}

int slider_height(Slider *slider)
{
    return slider->h+slider->style->outline*2;
}

int slider_width(Slider *slider)
{
    return slider->w+slider->style->outline*2;
}