#include "../../main.h"

Label *label_set_fields(Label *label, char text[], t_uint font_size, Color text_color, t_uint8 update, double local_scale, t_uint8 active)
{
    label->text = text;
    label->font_size = font_size;
    label->text_color = text_color;
    label->surface = NULL;
    label->texture = NULL;
    label->update = update;
    label->local_scale = local_scale;
    label->active = active;
    return label;
}

Label *label_init(Label *label, float scale_x, float scale_y)
{
    if (NULL == label || NULL == label->text || label->font_size > max_font_size)
        return NULL;

    label->update = false;
    label->local_scale = MIN(scale_x, scale_y);

    if (true != TTF_GetStringSize(roboto_regular_fonts[(int)(label->font_size * label->local_scale)-1], label->text, strlen(label->text), &label->rect.width, &label->rect.height))
    {
        error_log("Failed to retrieve string size : %s.", SDL_GetError());
        return NULL;
    }

    SDL_Color color = {label->text_color.r, label->text_color.g, label->text_color.b, label->text_color.a};
    
    label->surface = TTF_RenderText_Blended(roboto_regular_fonts[(int)(label->font_size * label->local_scale)-1], label->text, strlen(label->text), color);
    if (NULL == label->surface)
    {
        error_log("Failed render label surface : %s.", SDL_GetError());
        return NULL;
    }

    label->texture = SDL_CreateTextureFromSurface(renderer, label->surface);
    if (NULL == label->texture)
    {
        error_log("Failed to create label texture from label surface : %s.", SDL_GetError());
        SDL_DestroySurface(label->surface);
        label->surface = NULL;
        return NULL;
    }

    if (true != SDL_SetTextureBlendMode(label->texture, SDL_BLENDMODE_BLEND))
    {
        error_log("Failed to set label texture mode to blend : %s.", SDL_GetError());
        SDL_DestroyTexture(label->texture);
        label->texture = NULL;
        SDL_DestroySurface(label->surface);
        label->surface = NULL;
        return NULL;
    }
    return label;
}

void label_update(Label *label, float scale_x, float scale_y)
{
    if (NULL == label)
        return;
        
    if ((label->update || label->local_scale != MIN(scale_x, scale_y)) && label->active)
    {
        label_free(label);
        label_init(label, scale_x, scale_y);
        label->update = false;
        label->local_scale = MIN(scale_x, scale_y);
    }
    return;
}

void label_render(Label *label, float scale_x, float scale_y)
{
    if (NULL == label || NULL == label->texture || !label->active || 0 == scale_x)
        return;
    
    UI_Element anchored_rect = label->rect;
    UI_Element_set_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, 1, 1, anchored_rect.anchor);

    UI_Element_render_outline(&anchored_rect, 1.0, 1.0);
    
    SDL_FRect label_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width, anchored_rect.height};

    if (true != SDL_RenderTexture(renderer, label->texture, NULL, &label_rect))
    {
        error_log("Failed to render label texture : %s.", SDL_GetError());
    }
    return;
}

void label_free(Label *label)
{
    if (NULL == label)
        return;
    
    if (NULL != label->texture)
    {
        SDL_DestroyTexture(label->texture);
        label->texture = NULL;
    }
    if (NULL != label->surface)
    {
        SDL_DestroySurface(label->surface);
        label->surface = NULL;
    }
    return;
}

void label_list_free(Label *labels[], int size)
{
    if (NULL == labels)
        return;
        
    for (int i = 0; i < size; i++)
    {
        if (labels[i] == &FPS_label)
            continue;
        
        label_free(labels[i]);
    }
    return;
}

void label_center(Label *label, UI_Element *rect, float scale_x, float scale_y)
{
    if (NULL == label || NULL == rect)
        return;

    label->rect.x = rect->x + CENTERED(rect->width * rect->scale * scale_x, label->rect.width);
    label->rect.y = rect->y + CENTERED(rect->height * rect->scale * scale_y, label->rect.height);
    return;
}

int label_list_update_and_render(Label *labels[], int count)
{
    for (int i = 0; i < count; i++)
    {
        label_update(labels[i], SCALE_X, SCALE_Y);
        label_render(labels[i], SCALE_X, SCALE_Y);
    }
    return 0;
}
