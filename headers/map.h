#ifndef _MAP_H_
#define _MAP_H_

extern int map_width;
extern int map_height;

enum SquareStates
{
    COLLISION_SQUARE,
    EMPTY_SQUARE,
    LINE_SQUARE,
    PLAYER_SQUARE,
    FAKE_SQUARE,
};

typedef struct Map
{
    int height;
    int width;
    int square_size;
    int **map;
    int **start_map;
} Map;

extern Map *map;

int map_init();
Map *map_creation(Map *map);
Map *map_free(Map *map);
Map *map_reset(Map *map, int value);
Map *map_random(Map *map, int value);
void map_print(Map *map);
void map_display(Map *map, int offset_x, int offset_y);
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
int map_get_squares_number(Map *map, int type);
int map_is_filled(Map *map);

#endif