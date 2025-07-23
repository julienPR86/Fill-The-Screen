#include "../../main.h"

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

FloatAnimation *float_animation_set_fields(FloatAnimation *animation, float *value, float goal, float time, int active)
{
    if (NULL == animation || NULL == animation->value)
        return NULL;
    
    animation->value = value;
    animation->cache_value = *value;
    animation->goal_value = goal;
    animation->time = time;
    animation->timer = 0;
    animation->ended = false;
    animation->active = active;
    return animation;
}

int float_animation_update(FloatAnimation *animation)
{
    if (NULL == animation || NULL == animation->value || !animation->active || animation->timer > animation->time)
        return -1;
    
    *animation->value = LERP(animation->cache_value, animation->goal_value, (animation->timer/(float)animation->time));
    animation->timer += 1 * delta_time;
    if (animation->timer > animation->time)
    {
        animation->ended = true;
        animation->active = false;
        animation->timer = 0;
    }
    return 0;
}

int float_animation_destroy(FloatAnimation *animation)
{
    if (NULL == animation)
        return -1;
    
    free(animation);
    return 0;
}