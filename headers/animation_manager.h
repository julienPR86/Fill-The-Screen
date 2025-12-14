#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "animations/constant_animation.h"

typedef struct AnimationManager
{
    ConstantAnimation **constant_animations;
    int constant_animation_count;
} AnimationManager;

extern AnimationManager animation_manager;

void animation_manager_update(AnimationManager *manager);

int animation_manager_destroy(AnimationManager *manager);
//Adds a constant animation to the constant animation list of the animation manager
int animation_manager_add_constant_animation(AnimationManager *manager, ConstantAnimation *animation);
//Removes the constant animation in the constant animation list of the animation manager
int animation_manager_remove_constant_animation(AnimationManager *manager, ConstantAnimation *animation);
//Checks if there already is an animation that modifies the pointed value passed in 
int animation_manager_check_constant_animation(AnimationManager *manager, double *value);

#endif