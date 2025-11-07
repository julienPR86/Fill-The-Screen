#include "../main.h"

Map *map_creation(Map *map)
{
    map->map = (int **)malloc(map->height * sizeof(int *));
    if (NULL == map->map)
    {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    map->start_map = (int **)malloc(map->height * sizeof(int *));
    if (NULL == map->start_map)
    {
        free(map->map);
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    for (int i = 0; i < map->height; i++)
    {
        map->map[i] = (int *)malloc(map->width * sizeof(int));
        map->start_map[i] = (int *)malloc(map->width * sizeof(int));
        if (NULL == map->map[i] || NULL == map->start_map[i])
        {
            for (int j = 0; j < i; j++)
            {
                free(map->map[j]);
                free(map->start_map[j]);
            }
            free(map->map);
            free(map->start_map);
            fprintf(stderr, "Memory allocation error\n");
            return NULL;
        }
    }
    debug_log("Map created\n");
    return map;
}

Map *map_free(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->map[i]);
        free(map->start_map[i]);
    }
    free(map->map);
    map->map = NULL;
    free(map->start_map);
    map->start_map = NULL;
    return map;
}

Map *map_reset(Map *map, int value)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            map->map[y][x] = value;
            map->start_map[y][x] = value;
        }
    }
    debug_log("Map has been reset\n");
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
                map->start_map[y][x] = value;
            }
        }
    }
    return map;
}

void map_print(Map *map)
{
    printf("map :\n");
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
           printf("%d ", map->map[y][x]);
        }
        printf("\n");
    }
    printf("\nstart map :\n");
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
           printf("%d ", map->start_map[y][x]);
        }
        printf("\n");
    }
    return;
}

void map_display(Map *map)
{
    Color color = theme.game_colors.empty_square_color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_FRect rect = {map->x_offset, map->y_offset, map->square_size * map->width, map->square_size * map->height};
    SDL_RenderFillRect(renderer, &rect);

    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            switch (map->map[y][x])
            {
                case COLLISION_SQUARE:
                    color = theme.game_colors.collision_square_color;
                    break;
                case EMPTY_SQUARE:
                    continue;
                    break;
                case LINE_SQUARE:
                    color = theme.game_colors.line_square_color;
                    break;
                case PLAYER_SQUARE:
                    color = theme.game_colors.player_square_color;
                    break;
                case FAKE_SQUARE:
                    color = theme.game_colors.fake_square_color;
                    break;
                default:
                    break;
            }
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_FRect rect = {x * map->square_size + map->x_offset, y * map->square_size + map->y_offset, map->square_size, map->square_size};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    return;
}

int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height)
{
    if (screen_width/map_width < screen_height/map_height)
        return screen_width/map_width;

    else
        return screen_height/map_height;

    return 0;
}

int map_get_squares_number(Map *map, int type)
{
    int count = 0;
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == type)
                count++;
        }
    }
    return count;
}

int map_is_filled(Map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == EMPTY_SQUARE)
                return false;
        }
    }
    debug_log("Map is filled\n");
    return true;
}

void map_set_offset()
{
    map->y_offset = CENTERED(HEIGHT, (map->height * map->square_size));
    map->x_offset = CENTERED(WIDTH, (map->width * map->square_size));
    return;
}

