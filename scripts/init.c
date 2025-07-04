#include "../main.h"

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;
int WIDTH;
int HEIGHT;
float SCALE_X;
float SCALE_Y;
int FPS;
int MAX_FPS = 144;
double delta_time;
int game_speed = 60;
int probability = 6;
int map_width = 40;
int map_height = 26;

MouseState mouse_state = {0, 0, 0, 0, MOUSE_STATE_NONE, MOUSE_STATE_NONE, 0, 0};


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

Player *player = NULL;
Map *map = NULL;

Theme theme = {{{255,225,225,255}, {255, 225, 225, 255}, {255,225,225,255}, {0,0,0,255}, {255,225,225,255}, {255,225,225,255}}, 
                       {{10,10,20,255}, {255,225,200,255}, {255,128,0,255}, {255,0,0,255}, {255,255,255,255}}};

ButtonStyle button_style = {{255, 0, 0, 255}, {255, 128, 0, 255}, {250, 70, 0, 255}};
ButtonStyle toggle_style = {{255, 0, 0, 255}, {255, 128, 0, 255}, {250, 70, 0, 255}};
SliderCursorStyle slider_cursor_style = {{255, 0, 0, 255}, {255, 180, 0, 255}, {255, 100, 0, 255}};
SliderStyle slider_style = {{255, 128, 0, 255}};

const Color DARK = {0, 0, 0, 255};
const Color WHITE = {255, 255, 255, 255};

Outline *outlines;
int max_outline_size = 10;
Inline *inlines;
int max_inline_size = 5;

int game_mode = NO_ACTIVE_MODE;

TTF_Font **roboto_regular_fonts;
int max_font_size = 300;


char *FPS_text;
Label FPS_label = {{2, 0, 0, 0, {0, {0, 0, 0, 255}}, {0, {255, 255, 255, 255}}, TOP_LEFT}, NULL, 20, {0, 255, 75, 255}, NULL, NULL, false, 1.0, true};



int init()
{
    WIDTH = WINDOW_WIDTH;
    HEIGHT = WINDOW_HEIGHT;
    
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
    window = SDL_CreateWindow("Fill The Screen", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    if (NULL == window)
    {
        fprintf(stderr, "Could not create the window : %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, "software");
    if (NULL == renderer)
    {
        fprintf(stderr, "Could not create the renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }

    outlines = (Outline *)malloc(max_outline_size * sizeof(Outline));
    if (NULL == outlines)
    {
        fprintf(stderr, "Memory alocation error : Outlines array");
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
        SDL_DestroyWindow(window);
        window = NULL;
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    for (int i = 0; i < max_outline_size; i++)
    {
        outlines[i].size = i;
        outlines[i].color = DARK;
    }

    inlines = (Inline *)malloc(max_inline_size * sizeof(Inline));
    if (NULL == inlines)
    {
        fprintf(stderr, "Memory alocation error : Outlines array");
        free(outlines);
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
        SDL_DestroyWindow(window);
        window = NULL;
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    for (int i = 0; i < max_inline_size; i++)
    {
        inlines[i].size = i;
        inlines[i].color = WHITE;
    }

    roboto_regular_fonts = (TTF_Font **)malloc(max_font_size * sizeof(TTF_Font *));
    if (NULL == roboto_regular_fonts)
    {
        fprintf(stderr, "memory allocation error : Could not allocate font array");
        free(inlines);
        free(outlines);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return RETURN_FAILURE;
    }
    else
    {
        for (int i = 0; i < max_font_size; i++)
        {
            roboto_regular_fonts[i] = TTF_OpenFont("font/Roboto-regular.ttf", i+1);
            if (NULL == roboto_regular_fonts[i])
            {
                fprintf(stderr, "Could not initialised the font; size : %d; %s\n", i, SDL_GetError());
                free(inlines);
                free(outlines);
                for (int j = 0; j < i; j++)
                {
                    TTF_CloseFont(roboto_regular_fonts[j]);
                }
                free(roboto_regular_fonts);
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                TTF_Quit();
                SDL_Quit();
                return RETURN_FAILURE;
            }
        }
    }
    update_scale();

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    srand(time(NULL) * (WIDTH / HEIGHT));


    FPS_text = (char *)malloc(8 * sizeof(char));
    if (NULL == FPS_text)
    {
        fprintf(stderr, "Memory allocation error\n");
    }
    else
    {
        FPS_text[0] = '0';
        FPS_text[1] = '\0';
        FPS_label.text = FPS_text;
        FPS_label.rect.outline = outlines[0];
        FPS_label.rect.inline_ = inlines[0];
        label_init(&FPS_label, SCALE_X, SCALE_Y);
    }
    
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
