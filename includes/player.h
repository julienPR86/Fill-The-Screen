#ifndef PLAYER_H
#define PLAYER_H

//Structure that stores statistics about a player
typedef struct PlayerStats
{
	//The number of times the player moved
	t_uint	moves;
	//The number of spawned squares considered like a square that fill the map
	t_uint	filled_squares;
	//The ratio filled_squares / moves, depends on the active game mode
	double	filled_square_ratio;
	//The current map filling percentage
	double	fill_percent;
}	PlayerStats;


//Structure that represent a player
typedef struct Player
{
	//X position
	double x;
	//Y position
	double y;
	//Boolean for the x direction
	t_int8 direction_x;
	//Boolean for the y direction
	t_int8 direction_y;
	//Tells if the player can move
	t_uint8	can_move;
	//Is set to 1 if the player moved the same frame as the input
	t_uint8	frame_move;
	//The current player statistics
	PlayerStats	stats;
} Player;

//The default player
extern Player	*default_player;

/**
 * @brief Creates an allocated player.
 * @return The created player on success, NULL on failure.
 */
Player	*player_create(void);

/**
 * @brief Initialises player by reseting it.
 * @param map The newly created player.
 * @return 0 on success, 1 on failure.
 */
int	player_init(Player *player);

/**
 * @brief Moves a player based on its direction.
 * @param player The player to move.
 */
void	player_move(Player *player);

/**
 * @brief Sets the movement directions of player based on the sign of directions given.
 */
void	player_set_move_direction(Player *player, t_int8 direction_x, t_int8 direction_y);

//Resets player's fields to default value
void	player_reset(Player *player);

//Frees allocated ressources of the player passed in
void	player_destroy(Player *player);

//Updates the player stats
void	player_stats_update(Player *player, Map *map);

#endif