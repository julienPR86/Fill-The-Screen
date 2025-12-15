#include "../../main.h"

ConstantAnimation *constant_animation_create(double *value, double goal, double time, t_uint8 active)
{
    if (NULL == value)
        return NULL;

    if ((0 != animation_manager_check_constant_animation(&animation_manager, value) && NULL != animation_manager.constant_animations) || *value == goal)
    {
        return NULL;
    }

    ConstantAnimation *animation;
    animation = (ConstantAnimation *)malloc(sizeof(ConstantAnimation));
    if (NULL == animation)
    {
        error_log("Memory allocation error : failed to create constant animation.");
        return NULL;
    }
    constant_animation_set_fields(animation, value, goal, time, active);
    debug_log("Constant animation created.");
    return animation;
}

ConstantAnimation *constant_animation_set_fields(ConstantAnimation *animation, double *value, double goal, double time, t_uint8 active)
{
    if (NULL == animation || NULL == value)
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

int constant_animation_update(ConstantAnimation *animation)
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

int constant_animation_destroy(ConstantAnimation *animation)
{
    if (NULL == animation)
        return -1;
    
    free(animation);
	animation = NULL;
    debug_log("Constant animation destroyed.");
    return 0;
}