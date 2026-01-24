#include "../includes/main.h"

int	main(void)
{
	if (SUCCESS != init())
	{
		error_log("Could not initialise the game.");
		return (FAILURE);
	}
	if (SUCCESS != game_loop())
		error_log("Failed to start game loop.");
	exit_full_game();
	debug_log("Game exited successfully.");
	return (SUCCESS);
}
