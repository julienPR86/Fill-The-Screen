#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

//Modify a float value through a constant value change
typedef struct FloatAnimation
{
    //the value to animate
    double *value;
    //a copy of the first value of value
    double cache_value;
    //the value to reach
    double goal_value;
    //the duration of the animation in seconds
    double time;
    //timer to stop the animation when it should end
    double timer;
    //end boolean to tells if the animations as finished
    int ended;
    //active boolean to activate or des-activate the animation
    int active;
} FloatAnimation;

FloatAnimation *float_animation_create(double *value, double goal, double time, int active);

FloatAnimation *float_animation_set_fields(FloatAnimation *animation, double *value, double goal, double time, int active);

int float_animation_update(FloatAnimation *animation);

int float_animation_destroy(FloatAnimation *animation);

#endif