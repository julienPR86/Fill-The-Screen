#include "../main.h"

int player_move(int x, int y, int mode)
{
    if (x ^ y && player->remaining_moves)
    {
        if (player->x+x >= map->width || player->x+x < 0 || !map->map[player->y][player->x + x] ||
            player->y+y >= map->height || player->y+y < 0 || !map->map[player->y + y][player->x])
        {
            player->remaining_moves = 0;
            return 1;
        }
        if (!(DISCOVERY_MODE == mode || CONSTRAINT_MODE == mode) && !(rand() % 6))
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
        player->moves++;
        if (player->remaining_moves)
        {
            player->remaining_moves --;
        }
    }
    return 0;
}

void player_reset(Player *player)
{
    player->x = 0;
    player->y = 0;
    player->moves = 0;
    player->remaining_moves = 0;
}
