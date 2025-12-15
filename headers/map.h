#ifndef MAP_H
#define MAP_H

//The initial map width
extern int map_width;
//The initial map height
extern int map_height;

//Enum that represent the different tiles that can be on the map
enum SquareStates
{
    COLLISION_SQUARE,
    EMPTY_SQUARE,
    LINE_SQUARE,
    PLAYER_SQUARE,
    FAKE_SQUARE,
};

//Structure that represent a map
typedef struct Map
{
    //Map height
    int height;
    //Map width
    int width;
    //The size of each map's square
    int square_size;
    //The map array
    t_uint8 **map;
    //Keeps a copy of map at its creation
    t_uint8 **start_map;
    //The map offset on the x axis
    int x_offset;
    //The map offset on the y axis
    int y_offset;
} Map;

//The game map
extern Map *map;

//Need to be called befor using any map function
int map_init(Map *map);
//Creates a map
Map *map_creation(Map *map);
//Free the allocated ressources for the map
Map *map_free(Map *map);
//Reset the map arrays with value
Map *map_reset(Map *map, t_uint8 value);
//Sets randomly squares of the map arrays with value
Map *map_random(Map *map, t_uint8 value);
//Display the map arrays in the terminal
void map_print(Map *map);
//Display the map on screen
void map_display(Map *map);
//Returns the map arrays square size based on the screen and the map dimensions
int map_get_square_size(int screen_width, int screen_height, int map_width, int map_height);
//Return the squares number of a certain type in the map array
int map_get_squares_number(Map *map, int type);
//Returns true if the map is filled, false otherwise
t_uint8 map_is_filled(Map *map);
//Set the offset for the map based on the HEIGHT, WIDTH, and map size
void map_set_offset(Map *map);

#endif