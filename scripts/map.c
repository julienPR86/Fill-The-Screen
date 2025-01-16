#include "../main.h"

Map *map_creation(Map *map)
{
    map->map = (int **)malloc(map->height * sizeof(int *));
    if (NULL == map->map)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    for (int i = 0; i < map->height; i++)
    {
        map->map[i] = (int *)malloc(map->width * sizeof(int));
        if (NULL == map->map[i])
        {
            for (int j = 0; j < i; j++)
            {
                free(map->map[j]);
            }
            fprintf(stderr, "Memory allocation error\n");
            return NULL;
        }
    }
    return map;
}

Map *map_free(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->map[i]);
    }
    free(map->map);
    return map;
}

Map *map_reset(Map *map, int value)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            map->map[y][x] = value;
        }
    }
    return map;
}

Map *map_random(Map *map, int value)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (!(rand() % probability))
            {
                map->map[y][x] = value;
            }
        }
    }
    return map;
}

void map_print(Map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
           printf("%d ", map->map[y][x]);
        }
        printf("\n");
    }
    return;
}

void map_display(int offset_x, int offset_y)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            SDL_Color color = basic.colors[map->map[y][x]];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_Rect rect = {x*map->square_size+offset_x, y*map->square_size+offset_y, map->square_size, map->square_size};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    return;
}

int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height)
{
    if (screen_width/map_width < screen_height/map_height)
    {
        return screen_width/map_width;
    }
    else
    {
        return screen_height/map_height;
    }
    return RETURN_ZERO;
}

int map_is_filled(Map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == EMPTY_SQUARE)
            {
                return false;
            }
        }
    }
    return true;
}
