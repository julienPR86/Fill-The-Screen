#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "const.c"
#include "player.c"
#include "map.c"

#ifndef GAME
#define GAME

void restart(Map *map, Player *player);

void start_game()
{
    Map *map = malloc(sizeof(Map));
    if (NULL == map)
    {
        fprintf(stderr, "Memory allocation error\n");
        OUTPUT_START_GAME = -1;
        return;
    }
    map->height = 22;
    map->width = 33;
    map->square_size = map_get_square_size(WIDTH, HEIGHT, map->width, map->height);
    map->map = NULL;
    map_creation(map);
    map_reset(map, 1);
    map->map[0][0] = 3; //player position

    int YOFFSET = HEIGHT/2 - (map->height*map->square_size)/2;
    int XOFFSET = WIDTH/2 - (map->width*map->square_size)/2;

    Player *player = (Player *)malloc(sizeof(Player));
    if (NULL == player)
    {
        fprintf(stderr, "Memory allocation error\n");
        map_free(map);
        free(map);
        OUTPUT_START_GAME = -1;
        return;
    }
    player->x = 0;
    player->y = 0;
    player->moves = 0;

    srand(time(NULL));

    int direction[2] = {0,0};
    int direction_timer = 0;

    int running = 1;
    while (running)
    {
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);//background

        if (direction_timer)
        {
            direction_timer--;
        }
        else
        {
            direction[0] = 0;
            direction[1] = 0;
        }
        while (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                free(player);
                printf("free player ok\n");
                map_free(map);
                free(map);
                printf("free map ok\n");
                OUTPUT_START_GAME = 1;
                return;
            }
            if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_d == event.key.keysym.sym)
                {
                    if (!direction_timer)
                    {
                        direction[0] = 1;
                        direction[1] = 0;
                        direction_timer = map->width;
                    }
                }
                if (SDLK_q == event.key.keysym.sym)
                {
                    if (!direction_timer)
                    {
                        direction[0] = -1;
                        direction[1] = 0;
                        direction_timer = map->width;
                    }
                }
                if (SDLK_z == event.key.keysym.sym)
                {
                    if (!direction_timer)
                    {
                        direction[0] = 0;
                        direction[1] = -1;
                        direction_timer = map->height;
                    }
                }
                if (SDLK_s == event.key.keysym.sym)
                {
                    if (!direction_timer)
                    {
                        direction[0] = 0;
                        direction[1] = 1;
                        direction_timer = map->height;
                    }
                }
                if (SDLK_r == event.key.keysym.sym)
                {
                    restart(map, player);
                }
            }
        }

        if (player_move(player, map, direction[0], direction[1]))
        {
            direction_timer = 0;
        }
        map_display(renderer, map, XOFFSET, YOFFSET);
        if (map_is_filled(map))
        {
            restart(map, player);
        }

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    free(player);
    printf("free player ok\n");
    map_free(map);
    free(map);
    printf("free map ok\n");
    OUTPUT_START_GAME = 0;
    return;
}

void restart(Map *map, Player *player)
{
    map_reset(map, 1);
    map->map[0][0] = 3;
    player_reset(player);
}
#endif