#include "../main.h"

int get_fps()
{
    const int update = 20;
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


void mouse_event(SDL_Event event)
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
    if (SDL_MOUSEWHEEL == event.type)
    {
        mouse_wheel_value = event.wheel.y;
    }
    return;
}

void mouse_event_reset()
{
    mouse_wheel_value = 0;
    return;
}

void get_mouse_delta(int *_x, int *_y)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    *_x = x - mouse_x;
    *_y = y - mouse_y;
    return;
}

int button_collision(Button *button, int x, int y)
{
    if (x >= button->x && x <= button->x+button->width && y >= button->y && y <= button->y+button->height)
    {
        return true;
    }
    return false;
}

int toogle_collision(Toogle *toogle, int x, int y)
{
    if (x >= toogle->x && x <= toogle->x+toogle->width && y >= toogle->y && y <= toogle->y+toogle->height)
    {
        return true;
    }
    return false;
}

int slider_cursor_collision(SliderCursor *cursor, int x, int y)
{
    if (x > cursor->x && y > cursor->y && x < cursor->x + cursor->size && y < cursor->y + cursor->size)
    {
        return true;
    }
    return false;
}

int get_number_digits(int number)
{
    return (number == 0) ? 0 : ((int)log10(number)+1);
}