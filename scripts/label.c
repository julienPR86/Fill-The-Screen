#include "../main.h"

Label *label_init(Label *label)
{
    if (NULL == label || NULL == label->text)
        return NULL;

    if (0 != TTF_SizeText(label->font, label->text, &label->w, &label->h))
    {
        fprintf(stderr, "Size text error : %s\n", TTF_GetError());
    }
    
    label->surface = TTF_RenderText_Blended(label->font, label->text, label->text_color);
    if (NULL == label->surface)
    {
        fprintf(stderr, "Surface allocation error : %s\n", TTF_GetError());
    }

    label->texture = SDL_CreateTextureFromSurface(renderer, label->surface);
    if (NULL == label->texture)
    {
        fprintf(stderr, "Texture allocation error : %s\n", SDL_GetError());
    }

    if (label->bg.a < 255 || label->text_color.a < 255)
    {
        if (0 != SDL_SetTextureBlendMode(label->texture, SDL_BLENDMODE_BLEND))
        {
            fprintf(stderr, "Cannot set texture blend mode : %s\n", SDL_GetError());
        }
    }
    return label;
}

void label_render(Label *label)
{
    if (NULL == label || NULL == label->texture)
        return;
    
    if (label->update)
    {
        label_free(label);
        label_init(label);
        label->update = false;
    }
    SDL_Rect label_rect = {label->x, label->y, label->w*label->scale, label->h*label->scale};
    if (0 != SDL_RenderCopy(renderer, label->texture, NULL, &label_rect))
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
        SDL_FreeSurface(label->surface);
        label->surface = NULL;
    }
    return;
}

void label_list_free(Label *labels[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (labels[i] == &FPS_label)
            continue;
        
        label_free(labels[i]);
    }
    return;
}