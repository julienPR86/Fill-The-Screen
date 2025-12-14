#ifndef CONSTANT_ANIMATIONS_H
#define CONSTANT_ANIMATIONS_H

#include "types.h"

//Modify a floating point value through a constant change
typedef struct ConstantAnimation
{
    //A pointer to the value to change
    double *value;
    //A copy of the initial value
    double cache_value;
    //The goal value to reach at the end of the animation
    double goal_value;
    //The duration of the animation in seconds
    double time;
    //Private timer that increments through the animations updates
    double timer;
    //End boolean to tells if the animations has finished or not
    t_uint8 ended;
    //active boolean to activate or not the animation
    t_uint8 active;
} ConstantAnimation;

//Returns a constant animation structure based on the arguments passed in
ConstantAnimation *constant_animation_create(double *value, double goal, double time, t_uint8 active);
//Set the fields of a constant animation with the arguments passed in
ConstantAnimation *constant_animation_set_fields(ConstantAnimation *animation, double *value, double goal, double time, t_uint8 active);
//Updates the constant animation if its active
int constant_animation_update(ConstantAnimation *animation);
//Destroy and frees allocated ressources of the constant animation passed in
int constant_animation_destroy(ConstantAnimation *animation);

#endif