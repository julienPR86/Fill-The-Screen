#include "../main.h"

ColorPicker *picker_init(ColorPicker *picker, float scale)
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
        label_init(picker->labels[i]);
    }
    for (i = 0; i < 3; i++)
    {
        slider_init(picker->sliders[i], scale);
    }

    picker_set_positions(picker, scale);
    picker->rect.width = picker_get_width(picker, scale);
    picker->rect.height = picker_get_height(picker, scale);

    return picker;
}

int picker_update(ColorPicker *picker, float scale)
{
    if (NULL == picker)
        return RETURN_FAILURE;
        
    int out = RETURN_NONE, i;
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
        label_render(picker->labels[i], scale);
    }

    for (i = 0; i < 3; i++)
    {
        slider_render(picker->sliders[i], scale);
    }
    render_outline(&picker->rect, scale);
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

void picker_set_positions(ColorPicker *picker, int scale)
{
    if (NULL == picker || NULL == picker->labels || NULL == picker->sliders)
        return;

    //Positions the color rect in the top left corner
    set_UI_element_position(&picker->color_rect->rect, picker->rect.x, picker->rect.y, scale, TOP_LEFT);
    //Positions the picker title in the top left corner
    set_UI_element_position(&picker->labels[0]->rect, picker->rect.x, picker->rect.y, scale, TOP_LEFT); 

    //check which one of the color rect and the title have the biggest height
    if (get_height(&picker->labels[0]->rect, scale) > get_height(&picker->color_rect->rect, scale))
    {
        //Moves the color rect to the right center of the picker title
        set_UI_element_position(&picker->color_rect->rect, picker->labels[0]->rect.x + get_width(&picker->labels[0]->rect, scale), picker->labels[0]->rect.y + picker->labels[0]->rect.height/2, scale, MID_LEFT); 
    }
    else
    {
        //Positions the picker title in the middle of the color rect
        set_UI_element_position(&picker->labels[0]->rect, picker->rect.x, picker->rect.y + get_height(&picker->color_rect->rect, scale)/2, scale, MID_LEFT);
        //Then moves the color rect to the right of the picker title
        set_UI_element_position(&picker->color_rect->rect, picker->labels[0]->rect.x + get_width(&picker->labels[0]->rect, scale), picker->rect.y, scale, TOP_LEFT); 
    }
     
    int y_position = MAX(picker->labels[0]->rect.y + get_height(&picker->labels[0]->rect, scale), picker->color_rect->rect.y + get_height(&picker->color_rect->rect, scale));

    //Positions the second label under the color rect OR the title
    set_UI_element_position(&picker->labels[1]->rect, picker->rect.x, y_position, scale, TOP_LEFT);
    //Positions the first slider under the second label
    set_UI_element_position(&picker->sliders[0]->rect, picker->rect.x, picker->labels[1]->rect.y + get_height(&picker->labels[1]->rect, scale), scale, TOP_LEFT);

    //Positions the third label
    set_UI_element_position(&picker->labels[2]->rect, picker->rect.x, picker->sliders[0]->rect.y + get_height(&picker->sliders[0]->rect, scale), scale, TOP_LEFT);
    //Positions the second slider
    set_UI_element_position(&picker->sliders[1]->rect, picker->rect.x, picker->labels[2]->rect.y + get_height(&picker->labels[2]->rect, scale), scale, TOP_LEFT);

    //Positions the fourth label
    set_UI_element_position(&picker->labels[3]->rect, picker->rect.x, picker->sliders[1]->rect.y + get_height(&picker->sliders[1]->rect, scale), scale, TOP_LEFT);
    //Positions the third slider
    set_UI_element_position(&picker->sliders[2]->rect, picker->rect.x, picker->labels[3]->rect.y + get_height(&picker->labels[3]->rect, scale), scale, TOP_LEFT);

    return;
}

int picker_get_height(ColorPicker *picker, float scale)
{
    if (NULL == picker || NULL == picker->sliders || NULL == picker->labels)
        return RETURN_NONE;

    int h1 = 0, h2 = 0, i;

    for (i = 0; i < 4; i++)
    {
        h1 += get_height(&picker->labels[i]->rect, scale);
    }
    for (i = 0; i < 3; i++)
    {
        h1 += get_height(&picker->sliders[i]->rect, scale);
    }

    h2 += get_height(&picker->color_rect->rect, scale);
    for (i = 2; i < 4; i++)
    {
        h2 += get_height(&picker->labels[i]->rect, scale);
    }
    for (i = 0; i < 3; i++)
    {
        h2 += get_height(&picker->sliders[i]->rect, scale);
    }

    return MAX(h1, h2);
}

int picker_get_width(ColorPicker *picker, float scale)
{
    if (NULL == picker || NULL == picker->sliders || NULL == picker->labels)
        return RETURN_NONE;

    return MAX(get_width(&picker->labels[0]->rect, scale) + get_width(&picker->color_rect->rect, scale), slider_get_width(picker->sliders[0], scale));
}
