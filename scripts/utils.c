#include "../main.h"

int get_fps()
{
    const int update = 20;
    static int fps = 0;
    static int counter = 0;
    static Uint64 last_time = 0;
    static float total_time = 0;

    Uint64 current_time = SDL_GetTicks();
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
    Uint64 frame_time = SDL_GetTicks() - start_time;
    Uint64 target_time = 1000 / MAX_FPS;

    if (frame_time < target_time)
        SDL_Delay(target_time - frame_time);
    return;
}


void mouse_event(SDL_Event event)
{
    if (SDL_EVENT_MOUSE_BUTTON_DOWN == event.type && !mouse_state.button_pressed)
    {
        mouse_state.button_pressed = event.button.button;
    }
    if (SDL_EVENT_MOUSE_BUTTON_UP == event.type)
    {
        if (event.button.button == mouse_state.button_pressed)
        {
            mouse_state.button_pressed = 0;
        }
    }
    if (SDL_EVENT_MOUSE_WHEEL == event.type)
    {
        mouse_state.wheel_value = event.wheel.y;
    }
    return;
}

void mouse_event_update()
{
    mouse_state.wheel_value = 0;
    mouse_state.frame_input = (mouse_state.previous_button_pressed != mouse_state.button_pressed);
    mouse_state.previous_button_pressed = mouse_state.button_pressed;
    return;
}

void get_mouse_delta(float *_x, float *_y)
{
    float x, y;
    SDL_GetMouseState(&x, &y);
    *_x = x - mouse_state.x;
    *_y = y - mouse_state.y;
    return;
}

int set_window_size(SDL_Window *window, int w, int h)
{
    if (NULL == window || w <= 0 || h <= 0)
        return 0;

    if (!SDL_SetWindowSize(window, w, h))
    {
        fprintf(stderr, "Window resize error : %s\n", SDL_GetError());
        return 0;
    }
    return 1;
}

void update_window_size(SDL_Event event, SDL_Window *window)
{
    if (SDL_EVENT_WINDOW_RESIZED == event.type)
    {
        if (true != SDL_GetWindowSize(window, &WIDTH, &HEIGHT))
        {
            fprintf(stderr, "Failed to get window size : %s\n", SDL_GetError());
        }
        update_scale();
    }
}

void update_scale()
{
    SCALE_X = (float)WIDTH / 1080;
    SCALE_Y = (float)HEIGHT / 720;
    return;
}

int get_number_digits(int number)
{
    return (number == 0) ? 1 : ((int)log10(number)+1);
}

double round_to(double number, int n)
{
    double factor = pow(10.0, n);
    return round(number * factor) / factor;
}