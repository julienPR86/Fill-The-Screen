#include "../main.h"

Player	*player_create(void)
{
	Player	*player;

	player = (Player *)malloc(sizeof(Player));
	if (NULL == player)
	{
		error_log("Memory allocation error : failed to allocate new player.");
		return (NULL);
	}
	return (player);
}

int player_init(Player *player)
{
	if (NULL == player)
		return (-1);
	player_reset(player);
    debug_log("Player initialised.");
    return 0;
}

void player_move(Player *player)
{
    if (!player->can_move || !(player->direction_x ^ player->direction_y))
        return;

    if (player->frame_move && (player->x + player->direction_x < 0 || player->y + player->direction_y < 0 || player->x + player->direction_x > default_map->width || player->y + player->direction_y > default_map->height ||
        COLLISION_SQUARE == default_map->map[(int)player->y][(int)player->x + player->direction_x] || COLLISION_SQUARE == default_map->map[(int)player->y + player->direction_y][(int)player->x]))
    {
        player->stats.moves--;
        player->can_move = 0;
        return;
    }
	if (player->frame_move)
		player->frame_move = 0;

    for (int i = 0; i < game_speed; i++)
    {
        if (player->x + player->direction_x < 0 || player->y + player->direction_y < 0 || player->x + player->direction_x > default_map->width || player->y + player->direction_y > default_map->height ||
            COLLISION_SQUARE == default_map->map[(int)player->y][(int)player->x + player->direction_x] || COLLISION_SQUARE == default_map->map[(int)player->y + player->direction_y][(int)player->x])
        {
            player->can_move = 0;
            return;
        }
        switch (game_mode)
        {
            case FREE_MODE:
            case FILL_MODE:
                if (!(rand() % probability))
                    default_map->map[(int)player->y][(int)player->x] = COLLISION_SQUARE;
                else
                    default_map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
            
            case DISCOVERY_MODE:
                if (FAKE_SQUARE == default_map->start_map[(int)player->y][(int)player->x])
                    default_map->map[(int)player->y][(int)player->x] = COLLISION_SQUARE;
                else
                    default_map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
            
            case CONSTRAINT_MODE:
                default_map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
            
            default:
                default_map->map[(int)player->y][(int)player->x] = LINE_SQUARE;
                break;
        }
        player->x += player->direction_x * delta_time;
        player->y += player->direction_y * delta_time;
        default_map->map[(int)player->y][(int)player->x] = PLAYER_SQUARE;
	}
	player_stats_update(player, default_map);
	return;
}

void player_set_move_direction(Player *player, t_int8 direction_x, t_int8 direction_y)
{
    player->direction_x = direction_x;
    player->direction_y = direction_y;
    player->can_move = true;
    player->frame_move = 1;
    player->stats.moves++;
}

void player_reset(Player *player)
{
    player->x = 0.0;
    player->y = 0.0;
    player->direction_x = 0;
    player->direction_y = 0;
    player->stats.moves = 0;
    player->stats.filled_squares = 0;
    player->stats.filled_square_ratio = 0.0;
    player->stats.fill_percent = 1.0 / (default_map->height * default_map->width) * 100.0;
    player->can_move = false;
    player->frame_move = 0;
    debug_log("Player reset.");
}

void	player_destroy(Player *player)
{
	if (NULL == player)
		return ;
	free(player);
	player = NULL;
	return ;
}

void	player_stats_update(Player *player, Map *map)
{
	t_uint	unfilled_square_count;

	if (NULL == player || NULL == map)
		return ;
	switch (game_mode)
	{
		case CONSTRAINT_MODE:
			unfilled_square_count = map_get_squares_number(map, EMPTY_SQUARE) + map_get_squares_number(map, COLLISION_SQUARE);
			break;
		case DISCOVERY_MODE:
			unfilled_square_count = map_get_squares_number(map, EMPTY_SQUARE) + map_get_squares_number(default_map, FAKE_SQUARE);
			break;
		default:
			unfilled_square_count = map_get_squares_number(map, EMPTY_SQUARE);
			break;
	}
	unfilled_square_count -= 1; //Because we count the player as a filled square
	player->stats.filled_squares = map->width * map->height - unfilled_square_count;
	player->stats.fill_percent = (map->height * map->width - unfilled_square_count) / (float)(default_map->height * default_map->width) * 100.0;
	player->stats.filled_square_ratio = (map->width * map->height - unfilled_square_count) / (float)player->stats.moves;
	return ;
}
