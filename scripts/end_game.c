#include "../main.h"

int end_game()
{
    printf("moves : %d\n", player->moves);
    printf("fill : %f%%\n", fill_percent(map));
    return RETURN_RESTART_GAME;
}

float fill_percent(Map *map)
{
    int count = 0;
    float result = 0;
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == EMPTY_SQUARE)
            {
                count++;
            }
        }
    }
    result = (float)(map->height*map->width - count)/(map->height*map->width) * 100;
    return result;
}