#include "../main.h"

ColorPicker *picker_init(ColorPicker *picker, float scale_x, float scale_y)
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

    for (i = 0; i < 4; i++)
    {
        label_init(picker->labels[i], scale_x, scale_y);
        picker->labels[i]->rect.anchor = NONE;
    }
    for (i = 0; i < 3; i++)
    {
        slider_init(picker->sliders[i], scale_x, scale_y);
    }

    picker_set_positions(picker, scale_x, scale_y);
    picker->rect.width = picker_get_width(picker, scale_x);
    picker->rect.height = picker_get_height(picker, scale_y);

    return picker;
}

int picker_update(ColorPicker *picker, float scale_x, float scale_y)
{
    if (NULL == picker || !picker->active)
        return RETURN_NONE;
        
    int out = RETURN_NONE, i;
    for (i = 0; i < 4; i++)
    {
        label_update(picker->labels[i], scale_x, scale_y);
    }

    for (i = 0; i < 3; i++)
    {
        if (RETURN_NONE != out)
            return out;

        out = slider_update(picker->sliders[i], scale_x, scale_y);
    }
    return out;
}

void picker_render(ColorPicker *picker, float scale_x, float scale_y)
{
    if (NULL == picker || !picker->active)
        return;

    UI_Element anchored_rect = picker->rect;
    set_UI_element_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, scale_x, scale_y, anchored_rect.anchor);

    rect_render(picker->color_rect, scale_x, scale_y);

    int i;
    for (i = 0; i < 4; i++)
    {
        label_render(picker->labels[i], scale_x, scale_y);
    }

    for (i = 0; i < 3; i++)
    {
        slider_render(picker->sliders[i], scale_x, scale_y);
    }
    render_outline(&anchored_rect, scale_x, scale_y);
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

void picker_set_positions(ColorPicker *picker, float scale_x, float scale_y)
{
    if (NULL == picker || NULL == picker->labels || NULL == picker->sliders)
        return;

    int pad_x = get_width(&picker->sliders[0]->cursor->rect, scale_x)/2;

    //Positions the color rect in the top left corner
    set_UI_element_position(&picker->color_rect->rect, picker->rect.x + pad_x, picker->rect.y, 1, 1, 1, 1, TOP_LEFT);
    //Positions the picker title in the top left corner
    set_UI_element_position(&picker->labels[0]->rect, picker->rect.x + pad_x, picker->rect.y, 1, 1, 1, 1, TOP_LEFT); 

    //check which one of the color rect and the title have the biggest height
    if (picker->labels[0]->rect.height > get_height(&picker->color_rect->rect, 1))
    {
        //Moves the color rect to the right center of the picker title
        set_UI_element_position(&picker->color_rect->rect, picker->labels[0]->rect.x + picker->labels[0]->rect.width/scale_x + pad_x, picker->labels[0]->rect.y + picker->labels[0]->rect.height/scale_y/2, 1, 1, 1, 1, MID_LEFT); 
    }
    else
    {
        //Positions the picker title in the middle of the color rect
        set_UI_element_position(&picker->labels[0]->rect, picker->rect.x + pad_x, picker->rect.y + get_height(&picker->color_rect->rect, 1)/2, 1, 1, 1, 1, MID_LEFT);
        //Then moves the color rect to the right of the picker title
        set_UI_element_position(&picker->color_rect->rect, picker->labels[0]->rect.x + picker->labels[0]->rect.width/scale_x + pad_x, picker->rect.y, 1, 1, 1, 1, TOP_LEFT); 
    }
    
    int y_position = MAX(picker->labels[0]->rect.y + picker->labels[0]->rect.height/scale_y, picker->color_rect->rect.y + get_height(&picker->color_rect->rect, 1));

    //Positions the second label under the color rect OR the title
    set_UI_element_position(&picker->labels[1]->rect, picker->rect.x + pad_x, y_position, 1, 1, 1, 1, TOP_LEFT);
    //Positions the first slider under the second label
    set_UI_element_position(&picker->sliders[0]->rect, picker->rect.x + pad_x, picker->labels[1]->rect.y + picker->labels[1]->rect.height/scale_y, 1, 1, 1, 1, TOP_LEFT);

    //Positions the third label
    set_UI_element_position(&picker->labels[2]->rect, picker->rect.x + pad_x, picker->sliders[0]->rect.y + get_height(&picker->sliders[0]->rect, 1), 1, 1, 1, 1, TOP_LEFT);
    //Positions the second slider
    set_UI_element_position(&picker->sliders[1]->rect, picker->rect.x + pad_x, picker->labels[2]->rect.y + picker->labels[2]->rect.height/scale_y, 1, 1, 1, 1, TOP_LEFT);

    //Positions the fourth label
    set_UI_element_position(&picker->labels[3]->rect, picker->rect.x + pad_x, picker->sliders[1]->rect.y + get_height(&picker->sliders[1]->rect, 1), 1, 1, 1, 1, TOP_LEFT);
    //Positions the third slider
    set_UI_element_position(&picker->sliders[2]->rect, picker->rect.x + pad_x, picker->labels[3]->rect.y + picker->labels[3]->rect.height/scale_y, 1, 1, 1, 1, TOP_LEFT);

    return;
}

int picker_get_height(ColorPicker *picker, float scale_y)
{
    if (NULL == picker || NULL == picker->sliders || NULL == picker->labels)
        return RETURN_NONE;

    int height = 0, i;

    height += MAX(get_height(&picker->color_rect->rect, 1), picker->labels[0]->rect.height / scale_y);

    for (i = 1; i < 4; i++)
    {
        height += picker->labels[i]->rect.height / scale_y;
    }
    for (i = 0; i < 3; i++)
    {
        height += slider_get_height(picker->sliders[i], 1);
    }

    return height;
}

int picker_get_width(ColorPicker *picker, float scale_x)
{
    if (NULL == picker || NULL == picker->sliders || NULL == picker->labels)
        return RETURN_NONE;

    scale_x = 1;

    return MAX(picker->labels[0]->rect.width * 1.1 + get_width(&picker->color_rect->rect, scale_x), slider_get_width(picker->sliders[0], scale_x));
}
