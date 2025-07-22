#include "../main.h"

void animation_manager_update(AnimationManager *manager)
{
    if (NULL == manager)
        return;
    
    int i;
    if (NULL != manager->float_animations)
    {
        for (i = 0; i < manager->float_animation_count; i++)
        {
            if (NULL == manager->float_animations[i])
                continue;
                
            float_animation_update(manager->float_animations[i]);
        }
    }
    return;
}