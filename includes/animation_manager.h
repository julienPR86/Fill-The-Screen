#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "animations/constant_animation.h"

//Stores all current running animations
typedef struct AnimationManager
{
	ConstantAnimation **constant_animations;
	int	constant_animation_count;
} AnimationManager;

//The global game animation manager
extern AnimationManager animation_manager;

/**
 * @brief Updates all running animations and delete them dynamicly if they've finished.
 * @param manager The animation manager tu update.
*/
void	animation_manager_update(AnimationManager *manager);

/**
 * @brief Destroys all animations left, does nothing if its empty.
 * @param manager The animation manager to destroy.
 * @return 0 on success, 1 on failure.
 */
int	animation_manager_destroy(AnimationManager *manager);

/**
 * @brief Adds an allocated constant animation to the animation manager passed in.
 * @param manager The animation manager where to add the new constant animation.
 * @param animation The new allocated animation to add.
 * @return 0 on success, 1 on failure.
 */
int	animation_manager_add_constant_animation(AnimationManager *manager, ConstantAnimation *animation);

/**
 * @brief Removes an existing constant animation in the animation manager passed in.
 * @param manager The manager where to remove the animation.
 * @param animation The animation to remove.
 * @return 0 on success, 1 on failure.
 */
int	animation_manager_remove_constant_animation(AnimationManager *manager, ConstantAnimation *animation);

/**
 * @brief Checks if there already is a constant animation that modifies 'value'.
 * @param manager The animation manager where to check.
 * @param value A pointer to the value.
 * @return 0 on success, 1 on failure.
 */
int	animation_manager_check_constant_animation(AnimationManager *manager, double *value);

#endif