#ifndef _MAP_H_
#define _MAP_H_

//map width
extern int map_width;
//map height
extern int map_height;

//Enum the differents tiles that can be on the map
enum SquareStates
{
    COLLISION_SQUARE,
    EMPTY_SQUARE,
    LINE_SQUARE,
    PLAYER_SQUARE,
    FAKE_SQUARE,
};

//map structure
typedef struct Map
{
    //map height
    int height;
    //map width
    int width;
    //the size a each map's square
    int square_size;
    //the map array
    int **map;
    //save the map array a his creation
    int **start_map;
} Map;

//The map
extern Map *map;

//need to be called befor using any map function
int map_init();
//allocate the map arrays
Map *map_creation(Map *map);
//free the map arrays
Map *map_free(Map *map);
//reset all the map values
Map *map_reset(Map *map, int value);
//set random value for each array square
Map *map_random(Map *map, int value);
//display the map in the console
void map_print(Map *map);
//display the map on the screen with a offset if nessecary
void map_display(Map *map, int offset_x, int offset_y);
//return the nessecary map square size based on the screen and map size
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
//return the number of type square in the map array
int map_get_squares_number(Map *map, int type);
//check if there is no more empty square in the map
int map_is_filled(Map *map);

#endif