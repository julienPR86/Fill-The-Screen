#ifndef PLAYER_H
#define PLAYER_H

//Structure that represent a player
typedef struct Player
{
    //X position
    double x;
    //Y position
    double y;
    //Boolean for the x direction
    t_uint8 direction_x;
    //Boolean for the y direction
    t_uint8 direction_y;
    //The number of times the player moved
    int moves;
    //Tells if the player can move
    t_uint8 can_move;
    //Is set to 1 if the player moved the same frame as the input
    t_uint8 frame_move;
} Player;

//The default player
extern Player *player;

//Needs to be called before all player functions 
int player_init(Player *player);
//Move the player towards its x or y direction
void player_move(Player *player);
//Prepare the player to move in a x or y direction
void player_set_move_direction(int direction_x, int direction_y);
//Resets the player passed in
void player_reset(Player *player);

#endif