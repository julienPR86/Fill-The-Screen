#ifndef _ANIMATIONS_H_
#define _ANIMATION_H_

//Modify a float value through a constant value change
typedef struct FloatAnimation
{
    //the value to animate
    float *value;
    //a copy of the first value of value
    float cache_value;
    //the value to reach
    float goal_value;
    //the number of frame to do the animation
    int frame_time;
    //frame counter to do the animation
    int frame_counter;
    //active boolean to activate or des-activate the animation
    int active;
} FloatAnimation;

void float_animation_set_fields(FloatAnimation *animation, float *value, float goal, int frame_time, int active);

void float_animation_update(FloatAnimation *animation);


#endif