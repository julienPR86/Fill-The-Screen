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
        player->moves--;
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
    return;
}

void player_set_move_direction(Player *player, t_int8 direction_x, t_int8 direction_y)
{
    player->direction_x = direction_x;
    player->direction_y = direction_y;
    player->can_move = true;
    player->moves++;
    player->frame_move = 1;
}

void player_reset(Player *player)
{
    player->x = 0.0;
    player->y = 0.0;
    player->direction_x = 0;
    player->direction_y = 0;
    player->moves = 0;
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
