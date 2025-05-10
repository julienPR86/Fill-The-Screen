#include "../main.h"

int WIDTH = 1080;
int HEIGHT = 720;
float SCALEX;
float SCALEY;
int FPS;
int MAX_FPS = 144;
double delta_time;
int game_speed = 60;
int probability = 6;
int map_width = 33;
int map_height = 22;


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

Player *player = NULL;
Map *map = NULL;

Theme theme = {{{255,255,255,255}, {255, 240, 240, 255}, {255,255,255,255}, {0,0,0,255}, {255,255,255,255}, {255,255,255,255}}, 
                       {{0,0,0,255}, {255,255,255,255}, {255,128,0,255}, {255,0,0,255}, {255,255,255,255}}};

ButtonStyle button_style = {1, 1, {255, 0, 0, 255}, {255, 128, 0, 255}, {250, 70, 0, 255}, {0, 0, 0, 255}, {255, 255, 255, 255}};
ButtonStyle toogle_style = {0, 1, {255, 0, 0, 255}, {255, 128, 0, 255}, {250, 70, 0, 255}, {0, 0, 0, 255}, {255, 255, 255, 255}};
SliderCursorStyle slider_cursor_style = {1, {255, 0, 0, 255}, {255, 180, 0, 255}, {255, 100, 0, 255}, {0, 0, 0, 255}};
SliderStyle slider_style = {1, {255, 128, 0, 255}, {0, 0, 0, 255}};

float mouse_x = 0;
float mouse_y = 0;
float mouse_delta_x = 0;
float mouse_delta_y = 0;
int mouse_button_pressed = 0;
int mouse_wheel_value = 0;

int game_mode = NO_ACTIVE_MODE;

TTF_Font *roboto_regular;
TTF_Font *roboto_light;
int font_size = 300;



char *FPS_text;
Label FPS_label = {2, 0, 0, 0, 0.06, NULL, NULL, {0, 255, 75, 255}, NULL, NULL, false, true};



int init()
{
    if (true != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "Could not initialize SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return RETURN_FAILURE;
    }
    if (true != TTF_Init())
    {
        fprintf(stderr, "Could not initialize TTF : %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    window = SDL_CreateWindow("Fill The Screen", WIDTH, HEIGHT, 0);
    if (NULL == window)
    {
        fprintf(stderr, "Could not create the window : %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, NULL);
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
        fprintf(stderr, "Cound not initialised the font : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    roboto_light = TTF_OpenFont("font/Roboto-light.ttf", font_size);
    if (NULL == roboto_light)
    {
        fprintf(stderr, "Cound not initialised the font : %s\n", SDL_GetError());
        TTF_CloseFont(roboto_regular);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    SCALEX = (float)WIDTH / 1080;
    SCALEY = (float)HEIGHT / 720;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
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
    return RETURN_SUCCESS;
}

int map_init()
{
    if (0 == map_height || 0 == map_width)
        return RETURN_FAILURE;
        
    map = malloc(sizeof(Map));
    if (NULL == map)
    {
        fprintf(stderr, "Memory allocation error\n");
        return RETURN_FAILURE;
    }
    map->height = map_height;
    map->width = map_width;
    map->square_size = map_get_square_size(WIDTH, HEIGHT, map->width, map->height);
    map->map = NULL;
    if (NULL == map_creation(map))
    {
        free(map);
        map = NULL;
        return RETURN_FAILURE;
    }
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
    return RETURN_SUCCESS;
}

int player_init()
{
    player = (Player *)malloc(sizeof(Player));
    if (NULL == player)
    {
        fprintf(stderr, "Memory allocation error\n");
        return RETURN_FAILURE;
    }
    player->x = 0.0;
    player->y = 0.0;
    player->moves = 0;
    player->can_move = false;
    player->frame_move = 0;
    return RETURN_SUCCESS;
}
