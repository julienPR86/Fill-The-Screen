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
    UI_Element new_element = *element;
    set_UI_element_position(&new_element, element->x, element->y, scale, element->anchor);

    if (x >= new_element.x - new_element.outline.size * scale && x < new_element.x + (element->width + new_element.outline.size) * scale && y >= new_element.y - new_element.outline.size * scale && y < new_element.y + (new_element.height + new_element.outline.size) * scale)
    {
        return true;
    }
    return false;
}

void set_UI_element_position(UI_Element *element, int x, int y, float scale, int anchor)
{
    switch (anchor)
    {
        case NONE:
            element->x = x;
            element->y = y;
            break;
        
        case CENTER:
            element->x = x - (element->width / 2 + element->outline.size) * scale;
            element->y = y - (element->height / 2 + element->outline.size) * scale;
            break;

        case TOP_LEFT:
            element->x = x;
            element->y = y;
            break;

        case TOP_CENTER:
            element->x = x - (element->width / 2 + element->outline.size) * scale;
            element->y = y;
            break;

        case TOP_RIGHT:
            element->x = x - (element->width + element->outline.size) * scale;
            element->y = y;
            break;

        case MID_LEFT:
            element->x = x;
            element->y = y - (element->height / 2 + element->outline.size) * scale;
            break;

        case MID_RIGHT:
            element->x = x - (element->width + element->outline.size) * scale;
            element->y = y - (element->height / 2 + element->outline.size) * scale ;
            break;

        case BOTTOM_LEFT:
            element->x = x;
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
            element->x = x;
            element->y = y;
            break;
    }
    return;
}

int get_number_digits(int number)
{
    return (number == 0) ? 1 : ((int)log10(number)+1);
}