#include "../main.h"

Toogle *toogle_init(Toogle *toogle)
{
    if (NULL == toogle || NULL == label_init(toogle->label))
        return NULL;

    toogle->width = MAX(toogle->width * SCALEX, toogle->label->w * toogle->label->scale);
    toogle->height = MAX(toogle->height * SCALEY, toogle->label->h * toogle->label->scale);

    toogle->label->x = toogle->x + CENTERED(toogle->width, toogle->label->w * toogle->label->scale);
    toogle->label->y = toogle->y + CENTERED(toogle->height, toogle->label->h * toogle->label->scale);

    toogle->style->outline *= SCALEY;
    toogle->style->inline_ *= SCALEY;

    return toogle;
}

int toogle_update(Toogle *toogle)
{
    if (NULL == toogle || !toogle->active)
        return -1;
    
    static int update = 1;
    int x, y, out = -1; // returns -1 if the toogle isn't clicked
    SDL_GetMouseState(&x, &y);
    if (toogle_collision(toogle, x, y))
    {
        if (mouse_button_pressed == 1 && update)
        {
            switch (toogle->state)
            {
                case NORMAL:
                case HOVERED:
                    toogle->state = CLICKED;
                    if (NULL != toogle->command)
                        out = toogle->command();
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
    return out;
}

void toogle_render(Toogle *toogle)
{
    if (NULL == toogle || !toogle->active)
        return;
        
    SDL_Color toogle_color;
    SDL_Rect toogle_rect = {toogle->x+toogle->style->inline_, toogle->y+toogle->style->inline_, toogle->width-toogle->style->inline_*2, toogle->height-toogle->style->inline_*2};
    SDL_Rect inline_rect = {toogle->x, toogle->y, toogle->width, toogle->height};
    SDL_Rect outline_rect = {toogle->x-toogle->style->outline, toogle->y-toogle->style->outline, toogle->width+toogle->style->outline*2, toogle->height+toogle->style->outline*2};

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
