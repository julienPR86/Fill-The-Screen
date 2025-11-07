#ifndef _PLAYER_H_
#define _PLAYER_H_

//player structure
typedef struct Player
{
    //x position
    double x;
    //y position
    double y;
    //boolean for the x direction
    int direction_x;
    //boolean for the y direction
    int direction_y;
    //number of moves
    int moves;
    //tells if the player can move
    int can_move;
    //set to 1 for the frame when the player moves, 0 after
    int frame_move;
} Player;

//The player
extern Player *player;

//need to be called before all player functions 
int player_init();
//move the player towards x and y direction
void player_move(Player *player);
//Set the move direction of player and set all the moves boolean
void player_set_move_direction(int direction_x, int direction_y);
//reset all player fields
void player_reset(Player *player);

#endif