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
    t_uint8 can_move;
    //Is set to 1 if the player moved the same frame as the input
    t_uint8 frame_move;
	//The current player statistics
	PlayerStats	stats;
} Player;

//The default player
extern Player	*default_player;

//Returns an allocated player structure
Player	*player_create(void);
//Needs to be called before all player functions 
int player_init(Player *player);
//Move the player towards its x or y direction
void player_move(Player *player);
//Prepare the player to move in a x or y direction
void player_set_move_direction(Player *player, t_int8 direction_x, t_int8 direction_y);
//Resets the player passed in
void player_reset(Player *player);
//Frees allocated ressources of the player passed in
void	player_destroy(Player *player);

//Updates the player stats
void	player_stats_update(Player *player, Map *map);

#endif