#include "../main.h"

int WIDTH = 1080;
int HEIGHT = 720;
int FPS;
int MAX_FPS = 160;
double delta_time;
int game_speed = 60;
int probability = 6;



SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

Player *player = NULL;
Map *map = NULL;

const Theme basic = {{{255,255,255,255}, {255,255,255,255}, {0,0,0,255}, {255,255,255,255}, {255,255,255,255}},
                     {{0,0,0,255}, {255,255,255,255}, {255,128,0,255}, {255,0,0,255}, {255,255,255,255}}};
Theme current;

int mouse_button_pressed = 0;
int game_mode = NO_ACTIVE_MODE;

TTF_Font *roboto_regular;
TTF_Font *roboto_light;
int font_size = 300;



char *FPS_text;
Label FPS_label = {2, 2, 0, 0, 0.06, NULL, NULL, {0,0,0,0}, {0,200,40,255}, NULL, NULL, false};



int init()
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Could not initialize SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return RETURN_FAILURE;
    }
    if (0 != TTF_Init())
    {
        fprintf(stderr, "Could not initialize TTF : %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    window = SDL_CreateWindow("Fill The Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == window)
    {
        fprintf(stderr, "Could not create the window : %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer)
    {
        fprintf(stderr, "Could not create the renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    roboto_regular = TTF_OpenFont("font/Roboto-regular.ttf", font_size);
    if (NULL == roboto_regular)
    {
        fprintf(stderr, "Cound not initialised the font : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    roboto_light = TTF_OpenFont("font/Roboto-light.ttf", font_size);
    if (NULL == roboto_light)
    {
        fprintf(stderr, "Cound not initialised the font : %s\n", TTF_GetError());
        TTF_CloseFont(roboto_regular);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    current = basic;
    srand(time(NULL)*(WIDTH/HEIGHT));

    FPS_text = (char *)malloc(8 * sizeof(char));
    if (NULL == FPS_text)
    {
        fprintf(stderr, "Memory allocation error\n");
    }
    else
    {
        FPS_text[0] = '0';
        FPS_text[1] = '\0';
    }
    FPS_label.text = FPS_text;
    FPS_label.font = roboto_light;
    label_init(&FPS_label);
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
    map_reset(map, EMPTY_SQUARE);
    switch (game_mode)
    {
        case DISCOVERY_MODE:
            map_random(map, FAKE_SQUARE);
            break;
        case CONSTRAINT_MODE:
            map_random(map, COLLISION_SQUARE);
            break;
        default:
            break;
    }
    map->map[0][0] = 3; //basic player position
    return RETURN_ZERO;
}

int player_init()
{
    player = (Player *)malloc(sizeof(Player));
    if (NULL == player)
    {
        fprintf(stderr, "Memory allocation error\n");
        return RETURN_FAILURE;
    }
    player->x = 0;
    player->y = 0;
    player->moves = 0;
    player->remaining_moves = 0;
    player->frame_move = 0;
    return RETURN_ZERO;
}
