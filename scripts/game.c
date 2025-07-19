#include "../main.h"

int game_restart()
{
    map_reset(map, EMPTY_SQUARE);
    switch (game_mode)
    {
        case DISCOVERY_MODE:
            map_random(map, FAKE_SQUARE);
            break;
        case CONSTRAINT_MODE:
            map_random(map, COLLISION_SQUARE);
            break;
        default:
            break;
    }
    map->map[0][0] = PLAYER_SQUARE;
    player_reset(player);
    return 0;
}

int game_quit()
{
    free(player);
    player = NULL;
    map_free(map);
    free(map);
    map = NULL;
    return 0;
}
