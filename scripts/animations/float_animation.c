#include "../../main.h"

FloatAnimation *float_animation_create(double *value, double goal, double time, int active)
{
    if (NULL == value)
        return NULL;

    if ((0 != animation_manager_check_float_animation(&animation_manager, value) && NULL != animation_manager.float_animations) || *value == goal)
    {
        return NULL;
    }

    FloatAnimation *animation;
    animation = (FloatAnimation *)malloc(sizeof(FloatAnimation));
    if (NULL == animation)
    {
        fprintf(stderr, "Memory allocation error : Failed to create float animation\n");
        return NULL;
    }
    float_animation_set_fields(animation, value, goal, time, active);
    debug_log("Float animation created\n");
    return animation;
}

FloatAnimation *float_animation_set_fields(FloatAnimation *animation, double *value, double goal, double time, int active)
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

    animation->timer += delta_time;
    *animation->value = lerpf(animation->cache_value, animation->goal_value, (animation->timer/animation->time));
    if (animation->timer > animation->time)
    {
        *animation->value = animation->goal_value;
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
    debug_log("Float animation destroyed\n");
    return 0;
}