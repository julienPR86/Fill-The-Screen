#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "player.c"
#include "map.c"

int main(int argc, char **argv)
{
    int WIDTH = 1080, HEIGHT = 720, FPS = 60;
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Could not initialize SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        fprintf(stderr, "Could not create the window : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer)
    {
        fprintf(stderr, "Could not create the renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Map *map = malloc(sizeof(Map));
    if (NULL == map)
    {
        fprintf(stderr, "Memory allocation error\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    map->height = 16;
    map->width = 32;
    map->square_size = map_set(WIDTH, HEIGHT, map->width, map->height);;
    map->map = NULL;
    map_creation(map);
    map_reset(map, 1);
    map->map[0][0] = 3; //player position

    srand(time(NULL));

    Player *player = (Player *)malloc(sizeof(Player));
    if (NULL == player)
    {
        fprintf(stderr, "Memory allocation error\n");
        map_free(map);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
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
                running = 0;
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
            }
        }

        if (player_move(player, map, direction[0], direction[1]))
        {
            direction_timer = 0;
        }
        map_display(renderer, map);

        SDL_Delay(1.0/FPS*1000);
        SDL_RenderPresent(renderer);
    }
    free(player);
    printf("free player ok\n");
    map_free(map);
    free(map);
    printf("free map ok\n");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("end ok\n");
    return 0;
}