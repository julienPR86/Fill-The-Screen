#include "../main.h"

Label *label_init(Label *label)
{
    label_destroy(label);
    if (NULL == label->text)
        return NULL;
    TTF_SizeText(label->font, label->text, &label->w, &label->h);
    label->surface = TTF_RenderText_Blended(label->font, label->text, label->text_color);
    label->texture = SDL_CreateTextureFromSurface(renderer, label->surface);
    if (label->bg.a < 255 || label->text_color.a < 255)
        SDL_SetTextureBlendMode(label->texture, SDL_BLENDMODE_BLEND);
    return label;
}

void label_render(Label *label)
{
    if (NULL == label->text)
        return;
    SDL_Rect label_rect = {label->x, label->y, label->w*label->scale, label->h*label->scale};
    SDL_RenderCopy(renderer, label->texture, NULL, &label_rect);
    return;
}

Label *label_destroy(Label *label)
{
    if (NULL == label)
    {
        return NULL;
    }
    if (NULL == label->texture || NULL == label->surface)
    {
        return;
    }
    SDL_DestroyTexture(label->texture);
    label->texture = NULL;
    SDL_FreeSurface(label->surface);
    label->surface = NULL;
    return label;
}