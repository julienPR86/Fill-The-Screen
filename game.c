#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "player.c"
#include "map.c"

#ifndef GAME
#define GAME

void restart(Map *map, Player *player);

int start_game(SDL_Window *window, SDL_Renderer *renderer, int WIDTH, int HEIGHT, int FPS)
{
    Map *map = malloc(sizeof(Map));
    if (NULL == map)
    {
        fprintf(stderr, "Memory allocation error\n");
        return -1;
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

    srand(time(NULL));

    Player *player = (Player *)malloc(sizeof(Player));
    if (NULL == player)
    {
        fprintf(stderr, "Memory allocation error\n");
        map_free(map);
        return -1;
    }
    player->x = 0;
    player->y = 0;
    player->moves = 0;

    int direction[2] = {0,0};
    int direction_timer = 0;

    SDL_Event event;
    int running = 1;
    while (running)
    {
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
                return 1;
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
    return 0;
}

void restart(Map *map, Player *player)
{
    map_reset(map, 1);
    map->map[0][0] = 3;
    player_reset(player);
}
#endif