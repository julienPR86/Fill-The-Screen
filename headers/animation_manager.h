#ifndef _ANIMATION_MANAGER_H_
#define _ANIMATION_MANAGER_H_

#include "animations/float_animation.h"

typedef struct AnimationManager
{
    FloatAnimation **float_animations;
    int float_animation_count;
} AnimationManager;

extern AnimationManager animation_manager;

void animation_manager_update(AnimationManager *manager);

int animation_manager_add_float_animation(AnimationManager *manager, FloatAnimation *animation);
int animation_manager_remove_float_animation(AnimationManager *manager, FloatAnimation *animation);

#endif