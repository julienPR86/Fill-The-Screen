#include "../main.h"

Toogle *toogle_init(Toogle *toogle)
{
    if (NULL == toogle)
        return NULL;

    toogle->label = label_init(toogle->label);

    toogle->width = toogle->width;
    toogle->height = toogle->height;

    if (NULL != toogle->label)
    {
        toogle->width = MAX(toogle->width, toogle->label->w);
        toogle->height = MAX(toogle->height, toogle->label->h);

        toogle->label->x = toogle->x + CENTERED(toogle->width, toogle->label->w);
        toogle->label->y = toogle->y + CENTERED(toogle->height, toogle->label->h);
    }
    return toogle;
}

int toogle_update(Toogle *toogle)
{
    if (NULL == toogle || !toogle->active)
        return RETURN_NONE;
    
    static int update = 1;
    int out = RETURN_NONE; // returns RETURN_NONE if the toogle isn't clicked
    if (toogle_collision(toogle, mouse_x, mouse_y, SCALE))
    {
        if (mouse_button_pressed == 1 && update)
        {
            switch (toogle->state)
            {
                case NORMAL:
                case HOVERED:
                    toogle->state = CLICKED;
                    break;
                case CLICKED:
                    toogle->state = HOVERED;
                    break;
                default:
                    break;
            }
            update = 0;
        }
        else if (mouse_button_pressed == 0 && !update)
        {
            update = 1;
        }
        else if (NORMAL == toogle->state)
        {
            toogle->state = HOVERED;
        }
    }
    else
    {
        if (HOVERED == toogle->state)
        {
            toogle->state = NORMAL;
        }
    }
    if (NULL != toogle->label)
        label_update(toogle->label);
        
    if (NULL != toogle->command && CLICKED == toogle->state)
        out = toogle->command();
    return out;
}

void toogle_render(Toogle *toogle, float scale)
{
    if (NULL == toogle || !toogle->active)
        return;
        
    Color toogle_color;
    SDL_FRect toogle_rect = {toogle->x + toogle->style->inline_ * scale, toogle->y + toogle->style->inline_ * scale, (toogle->width - toogle->style->inline_ * 2) * scale, (toogle->height - toogle->style->inline_ * 2) * scale};
    SDL_FRect inline_rect = {toogle->x, toogle->y, toogle->width * scale, toogle->height * scale};
    SDL_FRect outline_rect = {toogle->x - toogle->style->outline * scale, toogle->y - toogle->style->outline * scale, (toogle->width + toogle->style->outline * 2) * scale, (toogle->height + toogle->style->outline * 2) * scale};

    switch (toogle->state)
    {
        case NORMAL:
            toogle_color = toogle->style->background;
            break;
        case CLICKED:
            toogle_color = toogle->style->foreground;
            break;
        case HOVERED:
            toogle_color = toogle->style->hover_color;
            break;
        default:
            break;
    }

    SDL_SetRenderDrawColor(renderer, toogle->style->outline_color.r, toogle->style->outline_color.g, toogle->style->outline_color.b, toogle->style->outline_color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    SDL_SetRenderDrawColor(renderer, toogle->style->inline_color.r, toogle->style->inline_color.g, toogle->style->inline_color.b, toogle->style->inline_color.a);
    SDL_RenderFillRect(renderer, &inline_rect);

    SDL_SetRenderDrawColor(renderer, toogle_color.r, toogle_color.g, toogle_color.b, toogle_color.a);
    SDL_RenderFillRect(renderer, &toogle_rect);
    
    if (NULL != toogle->label)
        label_render(toogle->label);
    return;
}

void toogle_free(Toogle *toogle)
{
    if (NULL == toogle || NULL == toogle->label)
        return;
        
    label_free(toogle->label);
    return;
}

void toogle_list_free(Toogle *toogles[], int size)
{
    if (NULL == toogles)
        return;

    for (int i = 0; i < size; i++)
    {
        if (NULL == toogles[i])
            continue;

        toogle_free(toogles[i]);
    }
    return;
}

int toogle_height(Toogle *toogle, float scale)
{
    return (toogle->height + toogle->style->outline * 2) * scale;
}

int toogle_width(Toogle *toogle, float scale)
{
    return (toogle->width + toogle->style->outline * 2) * scale;
}
