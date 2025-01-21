#include "../main.h"

int button_update(Button *button)
{
    int x, y, out = -1; // returns -1 if the button isn't clicked
    SDL_GetMouseState(&x, &y);
    if (button_collision(button, x, y))
    {
        if (mouse_button_pressed == 1)
        {
            button->clicked = 1;
        }
        else if (mouse_button_pressed == 0 && button->clicked)
        {
            button->clicked = 0;
            out = button->command();
        }
    }
    else
    {
        if (button->clicked)
        {
            button->clicked = 0;
        }
    }
    return out;
}

void button_render(Button *button)
{
    SDL_Color color;
    color = button->outline_color;
    SDL_Rect button_rect = {button->x-button->padx, button->y-button->pady, button->width+button->padx*2, button->height+button->pady*2};
    SDL_Rect outline_rect = {button->x-button->outline-button->padx, button->y-button->outline-button->pady, button->width+button->outline*2+button->padx*2, button->height+button->outline*2+button->pady*2};
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    if (button->clicked)
        color = button->fg;
    else
        color = button->bg;
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &button_rect);
    display_text(button->text, button->x, button->y, button->width, button->height, button->font, button->text_color, color);
    
    return;
}

void label_render(Label *label)
{
    SDL_Color color;
    color = label->outline_color;
    SDL_Rect label_rect = {label->x, label->y, label->width, label->height};
    SDL_Rect outline_rect = {label->x-label->outline, label->y-label->outline, label->width+label->outline*2, label->height+label->outline*2};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &outline_rect);

    color = label->bg;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &label_rect);
    display_text(label->text, label->x, label->y, label->width, label->height, label->font, label->text_color, color);
    return;
}

void display_text(char *text, int x, int y, int w, int h, TTF_Font *font, SDL_Color bg, SDL_Color fg)
{
    SDL_Surface *text_surface = TTF_RenderText_Shaded(font, text, bg, fg);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_FreeSurface(text_surface);
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderCopy(renderer, text_texture, NULL, &rect);
    return;
}
