#ifndef _ANIMATION_MANAGER_H_
#define _ANIMATION_MANAGER_H_

#include "animations.h"

typedef struct AnimationManager
{
    FloatAnimation **float_animations;
    int float_animation_count;
} AnimationManager;

void animation_manager_update(AnimationManager *manager);

#endif