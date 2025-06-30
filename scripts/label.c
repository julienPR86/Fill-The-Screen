#include "../main.h"

Label *label_init(Label *label, float scale_x, float scale_y)
{
    if (NULL == label || NULL == label->text || 0 >= label->font_size || label->font_size > max_font_size)
        return NULL;

    (void)scale_y;

    label->update = false;
    label->local_scale = scale_x;

    if (true != TTF_GetStringSize(roboto_regular_fonts[(int)(label->font_size * scale_x)-1], label->text, strlen(label->text), &label->rect.width, &label->rect.height))
    {
        fprintf(stderr, "Size text error : %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Color color = {label->text_color.r, label->text_color.g, label->text_color.b, label->text_color.a};
    
    label->surface = TTF_RenderText_Blended(roboto_regular_fonts[(int)(label->font_size * scale_x)-1], label->text, strlen(label->text), color);
    if (NULL == label->surface)
    {
        fprintf(stderr, "Surface allocation error : %s\n", SDL_GetError());
        return NULL;
    }

    label->texture = SDL_CreateTextureFromSurface(renderer, label->surface);
    if (NULL == label->texture)
    {
        fprintf(stderr, "Texture allocation error : %s\n", SDL_GetError());
        SDL_DestroySurface(label->surface);
        label->surface = NULL;
        return NULL;
    }

    if (true != SDL_SetTextureBlendMode(label->texture, SDL_BLENDMODE_BLEND))
    {
        fprintf(stderr, "Cannot set texture blend mode : %s\n", SDL_GetError());
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
        
    if ((label->update || label->local_scale != scale_x) && label->active)
    {
        label_free(label);
        label_init(label, scale_x, scale_y);
        label->update = false;
        label->local_scale = scale_x;
    }
    return;
}

void label_render(Label *label, float scale_x, float scale_y)
{
    if (NULL == label || NULL == label->texture || !label->active || 0 == scale_x)
        return;
    
    UI_Element anchored_rect = label->rect;
    set_UI_element_position(&anchored_rect, anchored_rect.x, anchored_rect.y, scale_x, scale_y, anchored_rect.anchor);

    render_outline(&anchored_rect, 1.0, 1.0);
    
    SDL_FRect label_rect = {anchored_rect.x, anchored_rect.y, anchored_rect.width, anchored_rect.height};

    if (true != SDL_RenderTexture(renderer, label->texture, NULL, &label_rect))
    {
        fprintf(stderr, "Render copy error : %s\n", SDL_GetError());
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

    label->rect.x = rect->x + CENTERED(rect->width * scale_x, label->rect.width);
    label->rect.y = rect->y + CENTERED(rect->height * scale_y, label->rect.height);
    return;
}