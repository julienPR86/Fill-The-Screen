#ifndef GAME_H
#define GAME_H

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

//Initialise the player and the map for the new game
int	new_game(void);
//The game main loop
int game_loop();
//Destroys allocated ressources used for a game
int game_quit();

#endif