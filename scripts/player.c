#include "../main.h"

int player_move(int x, int y)
{
    static int previous_state = 3;
    if (x ^ y && player->remaining_moves)
    {
        for (int i = 0; i < game_speed; i++)
        {
            if (player->x+x >= map->width || player->x+x < 0 || map->map[(int)player->y][(int)player->x + x] == COLLISION_SQUARE ||
                player->y+y >= map->height || player->y+y < 0 || map->map[(int)player->y + y][(int)player->x] == COLLISION_SQUARE)
            {
                if (player->frame_move)
                {
                    player->moves--;
                }
                player->remaining_moves = 0;
                return 1;
            }

            if (DISCOVERY_MODE == game_mode && previous_state == FAKE_SQUARE)
            {
                map->map[(int)player->y][(int)player->x] = COLLISION_SQUARE;
            }
            else if (!(DISCOVERY_MODE == game_mode || CONSTRAINT_MODE == game_mode) && !(rand() % probability))
            {
                map->map[(int)player->y][(int)player->x] = COLLISION_SQUARE;
            }
            else
            {
                map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
            }
            player->x += x * delta_time;
            player->y += y * delta_time;
            previous_state = map->map[(int)player->y][(int)player->x];
            map->map[(int)player->y][(int)player->x] = PLAYER_SQUARE;
            player->remaining_moves--;
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
