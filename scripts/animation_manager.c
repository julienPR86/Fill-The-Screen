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
            float_animation_update(manager->float_animations[i]);
            if (manager->float_animations[i]->ended)
            {
                animation_manager_remove_float_animation(manager, manager->float_animations[i]);
            }
        }
    }
    return;
}

int animation_manager_add_float_animation(AnimationManager *manager, FloatAnimation *animation)
{
    if (NULL == manager || NULL == animation)
        return -1;

    manager->float_animation_count++;
    manager->float_animations = (FloatAnimation **)realloc(manager->float_animations, (manager->float_animation_count) * sizeof(FloatAnimation *));
    if (NULL == manager->float_animations)
    {
        fprintf(stderr, "Memory allocation error : failed ot add animation to manager\n");
        return -1;
    }
    manager->float_animations[manager->float_animation_count-1] = animation;
    return 0;
}

int animation_manager_remove_float_animation(AnimationManager *manager, FloatAnimation *animation)
{
    if (NULL == manager || NULL == manager->float_animations || 0 >= manager->float_animation_count || NULL == animation)
        return -1;
    
    int index;
    for (index = 0; index < manager->float_animation_count; index++) //get the index of animation in array
    {
        if (manager->float_animations[index] == animation)
            break;
    }

    if (index >= manager->float_animation_count)//check if index is in array
    {
        fprintf(stderr, "Animation not in array\n");
        return -1;
    }

    int last = manager->float_animation_count-1;

    FloatAnimation *save = manager->float_animations[last];
    manager->float_animations[last] = manager->float_animations[index];
    manager->float_animations[index] = save;

    manager->float_animation_count--;
    manager->float_animations = (FloatAnimation **)realloc(manager->float_animations, (manager->float_animation_count) * sizeof(FloatAnimation *));
    if (NULL == manager->float_animations)
    {
        fprintf(stderr, "Memory allocation error : failed ot remove animation to manager\n");
        return -1;
    }
    return 0;
}