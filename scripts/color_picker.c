#include "../main.h"

ColorPicker *picker_init(ColorPicker *picker)
{
    return picker;
}

int picker_update(ColorPicker *picker, float scale)
{
    return 0;
}

void picker_render(ColorPicker *picker, float scale)
{
    if (NULL == picker)
        return;
        
    rect_render(picker->color_rect, scale);

    int i;
    for (i = 0; i < 4; i++)
    {
        label_render(picker->labels[i]);
    }

    for (i = 0; i < 3; i++)
    {
        slider_render(picker->sliders[i], scale);
    }
    return;
}

void picker_free(ColorPicker *picker)
{
    if (NULL == picker)
        return;

    label_list_free(picker->labels, 4);
    slider_list_free(picker->sliders, 3);
    return;
}

void picker_list_free(ColorPicker *pickers[], int size)
{
    if (NULL == pickers)
        return;

    for (int i = 0; i < size; i++)
    {
        picker_free(pickers[i]);
    }
    return;
}

int picker_height(ColorPicker *picker, float scale)
{
    return picker->rect.width * scale;
}

int picker_width(ColorPicker *picker, float scale)
{
    return picker->rect.height * scale;
}
