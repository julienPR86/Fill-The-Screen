#include "../main.h"

int button_update(Button *button)
{
    int x, y, out = -1; // returns -1 if the button isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        if (mouse_button_pressed == 1)
        {
            button->state = CLICKED;
        }
        else if (mouse_button_pressed == 0 && button->state == CLICKED)
        {
            button->state = NORMAL;
            out = button->command();
        }
        else
        {
            button->state = HOVERED;
        }
    }
    else
    {
        if (button->state)
        {
            button->state = NORMAL;
        }
    }
    return out;
}

void button_render(Button *button)
{
    SDL_Color color;
    color = button->outline_color;
    SDL_Rect button_rect = {button->x, button->y, button->width, button->height};
    SDL_Rect outline_rect = {button->x-button->outline, button->y-button->outline, button->width+button->outline*2, button->height+button->outline*2};
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    if (button->state == CLICKED)
        color = button->fg;
    else if (button->state == HOVERED)
        color = button->hover;
    else
        color = button->bg;
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &button_rect);

    int w, h;
    float text_scale = 0.1;
    TTF_SizeText(button->font, button->text, &w, &h);
    display_text(button->text, button->x+(button->width-w*text_scale)/2+button->padx, button->y+(button->height-h*text_scale)/2+button->pady, text_scale, button->font, button->text_color, color);
    return;
}

void label_render(Label *label)
{
    display_text(label->text, label->x, label->y, label->scale, label->font, label->text_color, label->bg);
    return;
}

void display_text(char *text, int x, int y, float scale, TTF_Font *font, SDL_Color bg, SDL_Color fg)
{
    if (NULL == text)
        return;
    int w, h;
    TTF_SizeText(font, text, &w, &h);
    SDL_Rect rect = {x, y, w*scale, h*scale};
    SDL_Surface *text_surface = TTF_RenderText_Blended(font, text, bg);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_SetTextureBlendMode(text_texture, SDL_BLENDMODE_BLEND);
    SDL_RenderCopy(renderer, text_texture, NULL, &rect);
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
    return;
}
