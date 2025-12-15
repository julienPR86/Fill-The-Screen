#include "main.h"

int main()
{
    if (-1 == init())
    {
        error_log("Could not initialise the game.");
        return -1;
    }

    if (-1 == game_loop())
    {
        error_log("Failed to start game loop.");
    }

    exit_full_game();
    debug_log("Game exited successfully.");
    return 0;
}
