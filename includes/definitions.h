#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef unsigned int	t_uint;
typedef char			t_int8;
typedef unsigned char	t_uint8;

typedef enum e_ReturnStatus
{
	SUCCESS,
	FAILURE,
}	t_status;

typedef enum e_GameState
{
	GAME_STATE_NONE,
	GAME_STATE_MAIN_MENU,
	GAME_STATE_OPTIONS,
	GAME_STATE_MODE_SELECTION,
	GAME_STATE_GAME,
	GAME_STATE_NEW_GAME,
	GAME_STATE_PAUSE_MENU,
	GAME_STATE_GAME_STATS,
	GAME_STATE_EXIT_GAME,
}	t_GameState;

#endif