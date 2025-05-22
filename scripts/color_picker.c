#include "../main.h"

ColorPicker *picker_init(ColorPicker *picker)
{
    if (NULL == picker || NULL == picker->color_rect)
        return NULL;
    
    int i;
    for (i = 0; i < 4; i++)
    {
        if (NULL == picker->labels[i])
        {
            fprintf(stderr, "Gap in picker's labels list\n");
            return NULL;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (NULL == picker->sliders[i])
        {
            fprintf(stderr, "Gap in picker's sliders list\n");
            return NULL;
        }
    }
    return picker;
}

int picker_update(ColorPicker *picker, float scale)
{
    if (NULL == picker)
        return RETURN_FAILURE;
        
    int out, i;
    for (i = 0; i < 4; i++)
    {
        label_update(picker->labels[i]);
    }

    for (i = 0; i < 3; i++)
    {
        if (RETURN_NONE != out)
            return out;

        out = slider_update(picker->sliders[i], scale);
    }
    return out;
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
