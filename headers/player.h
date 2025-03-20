#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct Player
{
    double x;
    double y;
    int moves;
    int can_move;
    int frame_move;
} Player;

extern Player *player;

int player_init();
void player_move(int x, int y);
void player_reset(Player *player);

#endif