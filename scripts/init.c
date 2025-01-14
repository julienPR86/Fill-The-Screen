#include "../main.h"

int WIDTH = 1080;
int HEIGHT = 720;
int FPS = 60;
SDL_Color colors[4] = {{0,0,0,255}, {255,255,255,255}, {255,128,0,255}, {255,0,0,255}};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

int mouse_button_pressed = 0;

Player *player = NULL;
Map *map = NULL;

int init()
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Could not initialize SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return RETURN_FAILURE;
    }
    window = SDL_CreateWindow("Fill The Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        fprintf(stderr, "Could not create the window : %s\n", SDL_GetError());
        SDL_Quit();
        return RETURN_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer)
    {
        fprintf(stderr, "Could not create the renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return RETURN_FAILURE;
    }
    return RETURN_ZERO;
}

int map_init()
{
    map = malloc(sizeof(Map));
    if (NULL == map)
    {
        fprintf(stderr, "Memory allocation error\n");
        return RETURN_FAILURE;
    }
    map->height = 22;
    map->width = 33;
    map->square_size = map_get_square_size(WIDTH, HEIGHT, map->width, map->height);
    map->map = NULL;
    map_creation(map);
    map_reset(map, 1);
    map->map[0][0] = 3; //basic player position
    return RETURN_ZERO;
}

int player_init()
{
    player = (Player *)malloc(sizeof(Player));
    if (NULL == player)
    {
        fprintf(stderr, "Memory allocation error\n");
        map_free(map);
        free(map);
        return RETURN_FAILURE;
    }
    player->x = 0;
    player->y = 0;
    player->moves = 0;
    player->remaining_moves = 0;
    return RETURN_ZERO;
}
