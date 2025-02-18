#include "../main.h"

void player_move(int delta_x, int delta_y)
{
    if (!player->can_move || !(delta_x ^ delta_y))
        return;

    if (player->frame_move && player->x + delta_x < 0 || player->y + delta_y < 0 || player->x + delta_x > map->width || player->y + delta_y > map->height ||
        COLLISION_SQUARE == map->map[(int)player->y][(int)player->x + delta_x] || COLLISION_SQUARE == map->map[(int)player->y + delta_y][(int)player->x])
    {
        player->moves--;
        player->can_move = 0;
        return;
    }
    
    for (int i = 0 ; i  < game_speed; i++)
    {
        if (player->x + delta_x < 0 || player->y + delta_y < 0 || player->x + delta_x > map->width || player->y + delta_y > map->height ||
            COLLISION_SQUARE == map->map[(int)player->y][(int)player->x + delta_x] || COLLISION_SQUARE == map->map[(int)player->y + delta_y][(int)player->x])
        {
            player->can_move = 0;
            return;
        }
        switch (game_mode)
        {
            case FREE_MODE:
            case FILL_MODE:
                if (!(rand() % probability))
                    map->map[(int)player->y][(int)player->x] = COLLISION_SQUARE;
                else
                    map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
            
            case DISCOVERY_MODE:
                if (FAKE_SQUARE == map->start_map[(int)player->y][(int)player->x])
                    map->map[(int)player->y][(int)player->x] = COLLISION_SQUARE;
                else
                    map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
            
            case CONSTRAINT_MODE:
                map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
            
            default:
                map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
        }
        player->x += delta_x * delta_time;
        player->y += delta_y * delta_time;
        map->map[(int)player->y][(int)player->x] = PLAYER_SQUARE;
    }
    return;
}

void player_reset(Player *player)
{
    player->x = 0;
    player->y = 0;
    player->moves = 0;
    player->can_move = 0;
}
