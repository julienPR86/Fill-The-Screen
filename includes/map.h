#ifndef MAP_H
#define MAP_H

//The initial map width
extern int	map_width;
//The initial map height
extern int	map_height;

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
	int	height;
	//Map width
	int	width;
	//The size of each map's square
	int	square_size;
	//The map array
	t_uint8	**map;
	//Keeps a copy of map at its creation
	t_uint8	**start_map;
	//The map offset on the x axis
	int	x_offset;
	//The map offset on the y axis
	int	y_offset;
} Map;

//The game map
extern Map	*default_map;

/**
 * @brief Creates an allocated Map.
 * @return The created map on success, NULL on failure.
 */
Map	*map_create(void);

/**
 * @brief Initialises map by setting all values to default.
 * @param map The newly created map.
 * @return 0 on success, 1 on failure.
 */
int	map_init(Map *map);

/**
 * @brief Initialises the map and start_map fields in map.
 * @param map An initialised map.
 * @return The updated map on success, NULL on failure.
 */
Map *map_creation(Map *map);

//Destroys allocated map's fields and map itself.
void	map_destroy(Map *map);

/**
 * @brief Resets map's map and start_map fields to value.
 * @param map The map where to reset map and start_map fields.
 * @param value The value that will replace all values in map and start_map fields.
 * @return Always returns map.
 */
Map *map_reset(Map *map, t_uint8 value);

//Randomly replaces squares value in map's map and start_map fields with a new value.
Map *map_random(Map *map, t_uint8 value);

//Prints the maps on the terminal.
void	map_print(Map *map);

//Display the map's map and start_map arrays in the terminal.
void	map_display(Map *map);

/**
 * @brief Calculate the ideal square size for the map based on the screen dimensions.
 * @return The size of a map square.
 */
int	map_get_square_size(int	screen_width, int screen_height, int map_width, int map_height);

/**
 * @brief Counts the number of type squares in map's map.
 * @return The right number.
 */
t_uint	map_get_squares_number(Map *map, int type);

/**
 * @brief Checks if map is filled.
 * @return true or false.
 */
t_uint8	map_is_filled(Map *map);

/**
 * @brief Centers correctly the map based on the screen size, map size and squares size.
 */
void	map_set_offset(Map *map);

#endif