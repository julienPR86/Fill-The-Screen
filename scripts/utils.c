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

int UI_element_collision(UI_Element *element, int x, int y, float scale)
{
    int _x_, _y_;
    switch (element->anchor)
    {
        case NONE:
            _x_ = element->x + element->outline.size * scale;
            _y_ = element->y + element->outline.size * scale;
            break;

        case CENTER:
            _x_ = element->x - (element->width / 2 + element->outline.size) * scale;
            _y_ = element->y - (element->height / 2 + element->outline.size) * scale;
            break;

        case TOP_LEFT:
            _x_ = element->x + element->outline.size * scale;
            _y_ = element->y + element->outline.size * scale;
            break;

        case TOP_CENTER:
            _x_ = element->x - (element->width / 2 + element->outline.size) * scale;
            _y_ = element->y + element->outline.size * scale;
            break;

        case TOP_RIGHT:
            _x_ = element->x - (element->width + element->outline.size) * scale;
            _y_ = element->y + element->outline.size * scale;
            break;

        case MID_LEFT:
            _x_ = element->x + element->outline.size * scale;
            _y_ = element->y - (element->height / 2 + element->outline.size) * scale;
            break;

        case MID_RIGHT:
            _x_ = element->x - (element->width + element->outline.size) * scale;
            _y_ = element->y - (element->height / 2 + element->outline.size) * scale ;
            break;

        case BOTTOM_LEFT:
            _x_ = element->x + element->outline.size * scale;
            _y_ = element->y - (element->height + element->outline.size) * scale;
            break;

        case BOTTOM_CENTER:
            _x_ = element->x - (element->width / 2 + element->outline.size) * scale;
            _y_ = element->y - (element->height + element->outline.size) * scale;
            break;

        case BOTTOM_RIGHT:
            _x_ = element->x - (element->width + element->outline.size) * scale;
            _y_ = element->y - (element->height + element->outline.size) * scale;
            break;

        default:
            _x_ = element->x + element->outline.size * scale;
            _y_ = element->y + element->outline.size * scale;
            break;
    }
    if (x > _x_ && x < _x_ + element->width * scale && y > _y_ && y < _y_ + element->height * scale)
    {
        return true;
    }
    return false;
}

void set_UI_element_position(UI_Element *element, int x, int y, float scale, int anchor)
{
    int _anchor_;
    if (NONE == anchor)
        _anchor_ = element->anchor;
    else
        _anchor_ = anchor;

    switch (_anchor_)
    {
        case NONE:
            element->x = x + element->outline.size * scale;
            element->y = y + element->outline.size * scale;
            break;
        
        case CENTER:
            element->x = x - (element->width / 2 + element->outline.size) * scale;
            element->y = y - (element->height / 2 + element->outline.size) * scale;
            break;

        case TOP_LEFT:
            element->x = x + element->outline.size * scale;
            element->y = y + element->outline.size * scale;
            break;

        case TOP_CENTER:
            element->x = x - (element->width / 2 + element->outline.size) * scale;
            element->y = y + element->outline.size * scale;
            break;

        case TOP_RIGHT:
            element->x = x - (element->width + element->outline.size) * scale;
            element->y = y + element->outline.size * scale;
            break;

        case MID_LEFT:
            element->x = x + element->outline.size * scale;
            element->y = y - (element->height / 2 + element->outline.size) * scale;
            break;

        case MID_RIGHT:
            element->x = x - (element->width + element->outline.size) * scale;
            element->y = y - (element->height / 2 + element->outline.size) * scale ;
            break;

        case BOTTOM_LEFT:
            element->x = x + element->outline.size * scale;
            element->y = y - (element->height + element->outline.size) * scale;
            break;

        case BOTTOM_CENTER:
            element->x = x - (element->width / 2 + element->outline.size) * scale;
            element->y = y - (element->height + element->outline.size) * scale;
            break;

        case BOTTOM_RIGHT:
            element->x = x - (element->width + element->outline.size) * scale;
            element->y = y - (element->height + element->outline.size) * scale;
            break;

        default:
            element->x = x + element->outline.size * scale;
            element->y = y + element->outline.size * scale;
            break;
    }
    return;
}

int get_number_digits(int number)
{
    return (number == 0) ? 1 : ((int)log10(number)+1);
}