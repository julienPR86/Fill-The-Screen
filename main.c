#include "main.h"

int main()
{
    if (-1 == init())
    {
        fprintf(stderr, "Could not initialised the game\n");
        return -1;
    }

    if (-1 == game_loop())
    {
        fprintf(stderr, "Failed to start game loop\n");
    }

    exit_full_game();
    debug_log("Exit game successfully");
    return 0;
}
