#ifndef _ANIMATIONS_H_
#define _ANIMATIONS_H_

//Modify a float value through a constant value change
typedef struct FloatAnimation
{
    //the value to animate
    float *value;
    //a copy of the first value of value
    float cache_value;
    //the value to reach
    float goal_value;
    //the duration of the animation in seconds
    float time;
    //timer to stop the animation when it should end
    float timer;
    //end boolean to tells if the animations as finished
    int ended;
    //active boolean to activate or des-activate the animation
    int active;
} FloatAnimation;

FloatAnimation *float_animation_create();

FloatAnimation *float_animation_set_fields(FloatAnimation *animation, float *value, float goal, float time, int active);

int float_animation_update(FloatAnimation *animation);

int float_animation_destroy(FloatAnimation *animation);

#endif