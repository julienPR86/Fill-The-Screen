#include "../main.h"

FloatAnimation *float_animation_create()
{
    FloatAnimation *animation;
    animation = (FloatAnimation *)malloc(sizeof(FloatAnimation));
    if (NULL == animation)
    {
        fprintf(stderr, "Memory allocation error : Failed to create float animation\n");
        return NULL;
    }
    return animation;
}

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
    
    *animation->value = LERP(animation->cache_value, animation->goal_value, (animation->frame_counter/(float)animation->frame_time));
    animation->frame_counter++;
    if (animation->frame_counter > animation->frame_time)
    {
        animation->active = false;
        animation->frame_counter = 0;
    }
    return;
}

int float_animation_destroy(FloatAnimation *animation)
{
    if (NULL == animation)
        return -1;
    
    free(animation);
    return 0;
}