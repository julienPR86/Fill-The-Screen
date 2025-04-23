#ifndef _GAME_H_
#define _GAME_H_

enum GameMods
{
    NO_ACTIVE_MODE,
    FILL_MODE,
    DISCOVERY_MODE,
    CONSTRAINT_MODE,
    FREE_MODE,
};

extern int game_speed;
extern int probability;
extern int game_mode;

//launch a game
int game();
//restart a game
int game_restart();
//quit your current game
int game_quit();

#endif