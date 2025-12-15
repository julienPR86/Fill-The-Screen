#include "../main.h"

void animation_manager_update(AnimationManager *manager)
{
    if (NULL == manager)
        return;
    
    int i;
    if (NULL != manager->constant_animations)
    {
        for (i = 0; i < manager->constant_animation_count; i++)
        {
            constant_animation_update(manager->constant_animations[i]);
            if (manager->constant_animations[i]->ended)
            {
                animation_manager_remove_constant_animation(manager, manager->constant_animations[i]);
            }
        }
    }
    return;
}

int animation_manager_destroy(AnimationManager *manager)
{
    if (NULL == manager)
        return -1;

    if (NULL != manager->constant_animations)
    {
        for (int i = 0; i < manager->constant_animation_count; i++)
        {
            constant_animation_destroy(manager->constant_animations[i]);
        }
        free(manager->constant_animations);
        debug_log("Destroyed manager's float animation list\n");
    }
    else
    {
        debug_log("Manager's float animation list is empty, did not removed any float animations\n");
    }
    return 0;
}

int animation_manager_add_constant_animation(AnimationManager *manager, ConstantAnimation *animation)
{
    if (NULL == manager || NULL == animation)
        return -1;
        
    manager->constant_animation_count++;
    manager->constant_animations = (ConstantAnimation **)realloc(manager->constant_animations, (manager->constant_animation_count) * sizeof(ConstantAnimation *));
    if (NULL == manager->constant_animations)
    {
        erro_log("Memory allocation error : failed ot add constant animation to manager.");
        return -1;
    }
    manager->constant_animations[manager->constant_animation_count-1] = animation;
    debug_log("Added float animation to manager\n");
    return 0;
}

int animation_manager_remove_constant_animation(AnimationManager *manager, ConstantAnimation *animation)
{
    if (NULL == manager || NULL == manager->constant_animations || 0 >= manager->constant_animation_count || NULL == animation)
        return -1;
    
    int index;
    for (index = 0; index < manager->constant_animation_count; index++) //get the index of animation in array
    {
        if (manager->constant_animations[index] == animation)
            break;
    }

    if (index >= manager->constant_animation_count)//check if index is in array
    {
        error_log("Could not remove constant animation : constant animation not in array.");
        return -1;
    }

    int last = manager->constant_animation_count-1;

    ConstantAnimation *save = manager->constant_animations[last];
    manager->constant_animations[last] = manager->constant_animations[index];
    manager->constant_animations[index] = save;

    constant_animation_destroy(animation);

    manager->constant_animation_count--;
    if (manager->constant_animation_count <= 0)
    {
        free(manager->constant_animations);
        manager->constant_animations = NULL;
        debug_log("Manager's float animation list is now empty\n");
        return 0;
    }
    else
    {
        manager->constant_animations = (ConstantAnimation **)realloc(manager->constant_animations, (manager->constant_animation_count) * sizeof(ConstantAnimation *));
        if (NULL == manager->constant_animations)
        {
        	error_log("Memory allocation error : failed to remove constant animation to manager.");
            return -1;
        }
    }
    debug_log("Removed float animation from manager\n");
    return 0;
}

int animation_manager_check_constant_animation(AnimationManager *manager, double *value)
{
    if (NULL == manager || NULL == value || NULL == manager->constant_animations)
        return -1;
    
    for (int i = 0; i < manager->constant_animation_count; i++)
    {
        if (value == manager->constant_animations[i]->value)
            return 1;
    }
    return 0;
}