#include <stdio.h>
#include "map.c"

#ifndef PLAYER
#define PLAYER

typedef struct
{
    int x;
    int y;
    int moves;
} Player;

int player_move(Player *player, Map *map, int x, int y)
{
    if (x ^ y)
    {
        if (player->x+x >= map->width || player->x+x < 0 || !map->map[player->y][player->x + x] ||
            player->y+y >= map->height || player->y+y < 0 || !map->map[player->y + y][player->x])
        {
            return 1;
        }

        if (!(rand() % 6))
        {
            map->map[player->y][player->x] = 0;
        }
        else
        {
            map->map[player->y][player->x] = 2;
        }

        player->x += x;
        player->y += y;
        map->map[player->y][player->x] = 3;
    }
    return 0;
}

void player_reset(Player *player)
{
    player->x = 0;
    player->y = 0;
    player->moves = 0;
}

#endif