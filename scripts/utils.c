#include "../main.h"

int get_fps()
{
    const int update = 10;
    static int fps = 0;
    static int counter = 0;
    static Uint64 last_time = 0;
    static float total_time = 0;

    Uint64 current_time = SDL_GetTicks64();
    delta_time = (current_time - last_time) * 0.001f;
    last_time = current_time;

    total_time += delta_time;
    counter++;

    if (counter == update)
    {
        if (total_time > 0)
            fps = (int)(update / total_time);
        else
            fps = 0;

        total_time = 0;
        counter = 0;
        if (0 > snprintf(FPS_text, 8, "%d", fps))
        {
            FPS_text = NULL;
        }
        FPS_label.update = true;
    }
    return fps;
}

void cap_fps(Uint64 start_time)
{
    Uint64 frame_time = SDL_GetTicks64() - start_time;
    Uint64 target_time = 1000 / MAX_FPS;

    if (frame_time < target_time)
        SDL_Delay(target_time - frame_time);
    return;
}


void mouse_pressed(SDL_Event event)
{
    if (SDL_MOUSEBUTTONDOWN == event.type && !mouse_button_pressed)
    {
        mouse_button_pressed = event.button.button;
    }
    if (SDL_MOUSEBUTTONUP == event.type)
    {
        if (event.button.button == mouse_button_pressed)
        {
            mouse_button_pressed = 0;
        }
    }
}

int button_collision(Button *button, int x, int y)
{
    if (x >= button->x && x <= button->x+button->width && y >= button->y && y <= button->y+button->height)
    {
        return true;
    }
    return false;
}

int get_button_height(Button *button)
{
    return button->height+button->outline;
}
int get_button_width(Button *button)
{
    return button->width+button->outline;
}