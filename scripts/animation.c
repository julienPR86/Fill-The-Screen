#include "../main.h"

void float_animation_set_fields(FloatAnimation *animation, float *value, float goal, int frame_time, int active)
{
    if (NULL == animation || NULL == animation->value)
        return;
    
    animation->value = value;
    animation->cache_value = *value;
    animation->goal_value = goal;
    animation->frame_time = frame_time;
    animation->frame_counter = 0;
    animation->active = active;
    return;
}

void float_animation_update(FloatAnimation *animation)
{
    if (NULL == animation || NULL == animation->value || !animation->active || animation->frame_counter > animation->frame_time)
        return;
    
    *animation->value = LERP(animation->cache_value, animation->goal_value, (animation->frame_counter/animation->frame_time));
    animation->frame_counter++;
    if (animation->frame_counter > animation->frame_time)
    {
        animation->active = false;
        animation->frame_counter = 0;
    }
    return;
}