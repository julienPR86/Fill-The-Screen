#include "../main.h"

Label *label_init(Label *label)
{
    if (NULL == label || NULL == label->text)
        return NULL;

    if (true != TTF_GetStringSize(label->font, label->text, strlen(label->text), &label->w, &label->h))
    {
        fprintf(stderr, "Size text error : %s\n", SDL_GetError());
        return NULL;
    }
    label->w *= SCALEY;
    label->h *= SCALEY;

    SDL_Color color = {label->text_color.r, label->text_color.g, label->text_color.b, label->text_color.a};
    
    label->surface = TTF_RenderText_Blended(label->font, label->text, strlen(label->text), color);
    if (NULL == label->surface)
    {
        fprintf(stderr, "Surface allocation error : %s\n", SDL_GetError());
        return NULL;
    }

    label->texture = SDL_CreateTextureFromSurface(renderer, label->surface);
    if (NULL == label->texture)
    {
        fprintf(stderr, "Texture allocation error : %s\n", SDL_GetError());
        return NULL;
    }

    if (true != SDL_SetTextureBlendMode(label->texture, SDL_BLENDMODE_BLEND))
    {
        fprintf(stderr, "Cannot set texture blend mode : %s\n", SDL_GetError());
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

void label_render(Label *label)
{
    if (NULL == label || NULL == label->texture || !label->active)
        return;
    
    SDL_FRect label_rect = {label->x, label->y, label->w*label->scale, label->h*label->scale};
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

void set_label_anchor(Label *label, int anchor, int offset_x, int offset_y)
{
    if (NULL == label)
        return;

    switch (anchor)
    {
        case CENTER:
            label->x = CENTERED(WIDTH, label->w*label->scale) + offset_x;
            label->y = CENTERED(HEIGHT, label->h*label->scale) + offset_y;
            break;
        case CENTER_X:
            label->x = CENTERED(WIDTH, label->w*label->scale) + offset_x;
            break;
        case CENTER_Y:
            label->y = CENTERED(HEIGHT, label->h*label->scale) + offset_y;
            break;
        case TOP_LEFT:
            label->x = offset_x;
            label->y = offset_y;
            break;
        case TOP_RIGHT:
            label->x = WIDTH - label->w*label->scale - offset_x;
            label->y = offset_y;
            break;
        case BOTTOM_LEFT:
            label->x = offset_x;
            label->y = HEIGHT - label->h*label->scale - offset_y;
            break;
        case BOTTOM_RIGHT:
            label->x = WIDTH - label->w*label->scale - offset_x;
            label->y = HEIGHT - label->h*label->scale - offset_y;
            break;
        default:
            break;
    }
    return;
}