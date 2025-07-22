#ifndef _ANIMATION_MANAGER_H_
#define _ANIMATION_MANAGER_H_

#include "animations.h"

typedef struct AnimationManager
{
    FloatAnimation **float_animations;
} AnimationManager;

void animation_manager_update(AnimationManager *manager);

#endif