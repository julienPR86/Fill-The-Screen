#include "../main.h"

Label *label_init(Label *label)
{
    if (NULL == label || NULL == label->text || 0 >= label->font_size || label->font_size > max_font_size)
        return NULL;

    label->update = false;

    if (true != TTF_GetStringSize(roboto_regular_fonts[label->font_size-1], label->text, strlen(label->text), &label->rect.width, &label->rect.height))
    {
        fprintf(stderr, "Size text error : %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Color color = {label->text_color.r, label->text_color.g, label->text_color.b, label->text_color.a};
    
    label->surface = TTF_RenderText_Blended(roboto_regular_fonts[label->font_size-1], label->text, strlen(label->text), color);
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

void label_update(Label *label)
{
    if (NULL == label)
        return;
        
    if (label->active && label->update)
    {
        label_free(label);
        label_init(label);
        label->update = false;
    }
    return;
}

void label_render(Label *label, float scale)
{
    if (NULL == label || NULL == label->texture || !label->active)
        return;

    render_outline(&label->rect, scale);
    
    SDL_FRect label_rect = {label->rect.x, label->rect.y, label->rect.width, label->rect.height};

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
