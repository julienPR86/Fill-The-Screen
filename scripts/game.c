#include "../main.h"

int start_game()
{
    int YOFFSET = HEIGHT/2 - (map->height*map->square_size)/2;
    int XOFFSET = WIDTH/2 - (map->width*map->square_size)/2;

    srand(time(NULL));

    int direction[2] = {0,0};

    int running = 1, out;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);//background

        if (!player->remaining_moves)
        {
            direction[0] = 0;
            direction[1] = 0;
        }
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                quit_game();
                return 1;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (!player->remaining_moves)
                {
                    if (SDLK_d == event.key.keysym.sym)
                    {
                        direction[0] = 1;
                        direction[1] = 0;
                        player->remaining_moves = map->width;
                    }
                    if (SDLK_q == event.key.keysym.sym)
                    {
                        direction[0] = -1;
                        direction[1] = 0;
                        player->remaining_moves = map->width;
                    }
                    if (SDLK_z == event.key.keysym.sym)
                    {
                        direction[0] = 0;
                        direction[1] = -1;
                        player->remaining_moves = map->height;
                    }
                    if (SDLK_s == event.key.keysym.sym)
                    {
                        direction[0] = 0;
                        direction[1] = 1;
                        player->remaining_moves = map->height;
                    }
                }
                
                if (SDLK_r == event.key.keysym.sym)
                {
                    restart();
                }

                if (SDLK_ESCAPE == event.key.keysym.sym)
                {
                    out = pause_menu();
                    switch (out)
                    {
                        case 0:
                            break;
                        case 1:
                            quit_game();
                            return 1;
                        case 2:
                            restart();
                            break;
                        case 3:
                            quit_game();
                            return 0;
                    }
                }
            }
        }

        player_move(direction[0], direction[1]);
        map_display(XOFFSET, YOFFSET);
        if (map_is_filled(map))
        {
            restart();
        }

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    quit_game();
    return 0;
}

int restart()
{
    map_reset(map, 1);
    map->map[0][0] = 3;
    player_reset(player);
    return 0;
}

int quit_game()
{
    free(player);
    printf("free player ok\n");
    map_free(map);
    free(map);
    printf("free map ok\n");
    return 0;
}
