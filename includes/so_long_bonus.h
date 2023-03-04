/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:38:07 by crypto            #+#    #+#             */
/*   Updated: 2023/03/04 11:11:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "macros_bonus.h"

/**
 * @brief Struct containg the coordinates of a point
 * @param x The x coordinate
 * @param y The y coordinate
 */
typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}				t_point;

/**
 * @brief The struct used to represent the read map
 * @param bytes The char matrix with the char map
 * @param cols The number of columns of the map
 * @param rows The number of rows of the map
 * @param num_potions The number of potions collected in the map
 * @param num_exits The number of exits in the map
 * @param num_players The number of players in the map
 * @param num_enemies The number of enemies in the map
 */
typedef struct s_map
{
	char			**bytes;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	num_potions;
	unsigned int	num_exits;
	unsigned int	num_players;
	unsigned int	num_enemies;
}				t_map;

/**
 * @brief The sctruct used to represent an xpm file
 * @param img The mlx image pointer
 * @param addr The beginning address of the image pixels
 * @param width The width of the image
 * @param height The height of the image
 * @param bpp The number of bits per pixel
 * @param line_len The length of a line in bytes (unused)
 * @param endian The endianess of the image (unused)
 */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

/**
 * @brief A struct sprite related data
 * @param frames The array of t_img containing the xpm of the sprite
 * @param nframes The number of frames of the sprite
 */
typedef struct s_sprite
{
	t_img	*frames;
	int		nframes;
}				t_sprite;

/**
 * @brief Data structure containing mlx related data
 * @param mlx The mlx pointer
 * @param win The mlx window pointer
 * @param dims The dimensions of the window
 */
typedef struct s_display
{
	void	*mlx;
	void	*win;
	t_point	dims;
}				t_display;

/**
 * @brief Data structure containing the entity's own fields, 
 * animation related, position, next position, direction, etc.
 * @param frame The current frame of the animation
 * @param frame_freq The frequency of frame change
 * @param curr_freq The counter to match the frequency to change frames
 * @param move_counter The counter to match the frequency to move 
 * (used only for enemies)
 * @param move_freq The frequency of the movement (used only for enemies)
 * @param animate_speed The speed of rendering sprites
 * @param curr_speed The counter to match the speed of rendering sprites
 * @param type The type of the entity
 * @param dir The direction of the entity
 * @param pos The current position of the entity
 * @param next The next position of the entity
 */
typedef struct s_entity
{
	int			frame;
	int			frame_freq;
	int			curr_freq;
	int			move_counter;
	int			move_freq;
	int			animate_speed;
	int			curr_speed;
	t_type		type;
	t_direction	dir;
	t_point		pos;
	t_point		next;
}				t_entity;
/**
 * @brief The root of the so_long project encapsulating other structs
 * @param map The map struct
 * @param disp The t_display struct containing the mlx related data
 * @param player_sp The sprite struct array containing the player sprites
 * @param enemy_sp The sprite struct array containing the enemy sprites
 * @param floor_sp The sprite struct containing the floor sprite
 * @param walls_sp The sprite struct containing the walls sprite
 * @param exit_sp The sprite struct containing the exit sprite
 * @param potions_sp The sprite struct containing the potions sprite
 * @param player The player entity
 * @param enemies The enemies entity array
 * @param coins The coins entity array
 * @param enemy_status The current status of the enemy
 * @param enemy_strategy The current strategy of the enemy
 * @param collected The number of collected collected so far
 * @param moves The number of moves so far
 */
typedef struct s_game
{
	t_map			*map;	
	t_display		disp;
	t_sprite		*player_sp;
	t_sprite		*enemy_sp;
	t_sprite		floor_sp;
	t_sprite		walls_sp;
	t_sprite		exit_sp;
	t_sprite		potions_sp;
	t_entity		player;
	t_entity		*enemies;
	t_entity		*coins;
	t_status		enemy_status;
	void			(*enemy_strategy)();
	unsigned int	collected;
	unsigned int	moves;
}					t_game;

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= ANIMATE =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Given an array of entities of the same type and the frames associated
 * with them, it renders the next frame of the animation of each entity.
 * @param g The game structure
 * @param ent The entity array
 * @param frames The frames related with the animation of the entities
 * @param n The number of entities to animate
 */
void		animate(t_game *g, t_entity *ent, t_sprite *frames, int n);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= ALGORITHMS =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Given an auxiliary map it checks for a valid path between the 
 * player's position and the exit. It also counts the number of collected
 * potions so far to match it against the total number of potions. 
 * It works by recursively exploring the 4 adjacent positions.
 * 
 * @param map The map structure containing the number of collected to collect 
 * @param curr The current position to explore
 * @param maze The auxiliary map to fill
 * @return true if there is a valid path and all collected are collected, false 
 * otherwise 
 */
bool		flood_fill(t_map *map, t_point curr, char **maze);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\ BINARY_WALL_MAP /=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Given the binary wall map, it checks if the diagonals of the current
 * position match those passed as arguments
 * @param mat The binary wall map
 * @param p The current position
 * @param diagonals The values to match
 * @return true if the diagonals match, false otherwise
 */
bool		diags(int **mat, t_point *p, char *diagonals);

/**
 * @brief Given the binary wall map, it checks if the horizontal and vertical
 * sides of the current position match those passed as arguments
 * @param p The current position
 * @param mat The binary wall map
 * @param vals The values to match
 * @param op The operation to perform
 * @return true if the sides match, false otherwise
 */
bool		sides(int **mat, t_point *p, char *diagonals);
/**
 * @brief Given a map, it creates a binary matrix with 1s for walls and 0s for
 * empty spaces.
 * @param g The game structure
 * @param mat The binary matrix to fill
 */
void		fill_bin_matrix(t_game *g, int **mat);

/**
 * @brief Creates a new matrix of size y * x
 * @param rows The number of rows
 * @param cols The number of columns
 * @param size The size of each element of each pointer
 * @return The new matrix
 */
void		*ft_new_matrix(int rows, int cols, size_t size);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ DEBUG _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Prints the map information to the standard output such as
 * the number of potions, enemies, and other entities as the map itself.
 * @param map The map to print
 */
void		map_print(t_map *map);

/**
 * @brief Prints the binary wall map to the standard output
 * @param g The game structure
 * @param mat The binary wall map
 */
void		binary_map_print(t_game *g, int **mat);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ DESTROY _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Frees the memory associated to a t_game structure
 * @param game The t_game struct to free
 */
void		destroy_game(t_game *game);
/**
 * @brief Frees the memory from the sprite array inside the t_game struct
 * @param g The t_game struct to free the sprites memory from
 */
void		destroy_all_sprites(t_game *g);

/**
 * @brief Frees the memory from a sprite struct
 * @param g The t_game struct to free the sprites memory from
 * @param sp The sprite struct to free the memory from
 */
void		destroy_sprite(t_game *g, t_sprite *sp);

/**
 * @brief Frees the memory from a matrix
 * @param matrix The matrix to free the memory from
 * @param rows The number of rows of the matrix
 */
void		destroy_matrix(void *matrix, size_t rows);

/**
 * @brief Frees the memory associated with a t_map struct
 * @param map The t_map struct to free the memory from
 */
void		destroy_map(t_map *map);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief This function has several roles: to read and parse the map from
 * the file passed as argument, to initialize the graphical environment,
 * load sprites and to register events. It also calls the main game loop.
 * @param filename The filename to read the map from
 */
void		init_game(char *filename);

/**
 * @brief It initializes the player by intializing animation related fields.
 * @param g The t_game struct to use
 */
void		init_player(t_game *g);

/**
 * @brief It initializes the enemies by allocating memory to the t_entity
 * array and setting the position of each enemy, and animation related
 * fields as well.
 * @param g The t_game struct to use
 */
void		init_enemies(t_game *g);

/**
 * @brief It initializes the coins by allocating memory to the t_entity
 * array and setting the position of each coin, and animation related
 * fields as well.
 * @param g The t_game struct to use
 */
void		init_coins(t_game *g);

/**
 * @brief It initializes the graphical environment by allocating memory
 * to the mlx, window and other needed pointers
 * 
 * @param g The t_game struct to use
 */
void		init_graphics(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= IMAGE =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief It creates a new mlx image with the given dimensions
 * @param g The t_game struct to use
 * @param dims The dimensions of the new image
 * @return The new image
 */
t_img		new_image(t_game *g, t_point dims);

/**
 * @brief It creates a new mlx image from a file
 * @param g The t_game struct to use
 * @param path The path to the file to load
 * @return The new image
 */
t_img		new_file_image(t_game *g, char *path);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= LOAD_SPRITES =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief It loads the sprite frames, by concatenating the prefix with the
 * number of the frame and the ".xpm" string.
 * @param g The t_game struct to use
 * @param s The t_sprite struct to fill
 * @param prefix The prefix of the path to load from
 * @param n The number of frames to load
 */
void		load_xpm(t_game *g, t_sprite *s, char *prefix, int n);

/**
 * @brief It loads the sprites of walls, floors, exit and potions 
 * by calling load_xpm.
 * @param g The t_game struct to use
 */
void		load_static_entites_frames(t_game *g);

/**
 * @brief It loads the sprites of the enemies by calling load_xpm.
 * @param g The t_game struct to use
 */
void		load_enemies_frames(t_game *g);

/**
 * @brief It loads the sprites of the player by calling load_xpm.
 * @param g The t_game struct to use
 */
void		load_player_frames(t_game *g);

/**
 * @brief Calls the other load functions.
 * @param g The t_game struct to use
 */
void		load_sprites(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MAIN =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Destroys the game structure and frees all the allocated memory
 * and aborts the program.
 * @param filename The filename to read the map from
 * @return 0
 */
int			quit(t_game *game);

/**
 * @brief Given the filename passed as argument, it checks if the filename
 * is valid by checking for the ".ber" suffix and if the file exists
 * 
 * @param filename The terminal input 
 * @return true if the filename is valid, false otherwise 
 */
bool		is_filename_valid(char *filename);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MAP_VALIDATOR =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Checks if the map is rectangular
 * @param map The map to check
 * @return true if the map is rectangular, false otherwise
 */
bool		is_map_rectangular(t_map *map);

/**
 * @brief Checks if the map is bounded by walls
 * @param map The map to check
 * @return true if the map is bounded by walls, false otherwise
 */
bool		is_map_bounded(t_map *map);

/**
 * @brief Checks if the map is composed solely of valid characters
 * @param map The map to check
 * @return true if the map has valid entities false otherwise
 */
bool		has_valid_entities(t_game *g);

/**
 * @brief Checks if the map has a valid path from the player to the exit
 * and to all the potions
 * @param map The map to check
 * @return true if the map has valid paths, false otherwise
 */
bool		has_valid_path(t_game *g);

/**
 * @brief Calls the other validation functions
 * @param map The map to check
 * @return true if the map passes the other validations, false otherwise
 */
void		validate_map(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MOVE_ENEMIES =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief Checks if the enemy can move to the next position
 * @param g The t_game struct to use
 * @param p The next position of the enemy
 * @return true if the enemy can move to the next position, false otherwise
 */
bool		enemy_can_move(t_game *g, t_point p);

/**
 * @brief Checks if the enemy is not blocked and can move
 * @param g The t_game struct to use
 * @param pos The position of the enemy
 * @return true if the enemy has possible moves, false otherwise
 */
bool		enemy_has_possible_moves(t_game *g, t_point *pos);

/**
 * @brief For each enemy, and according to the enemy's strategy
 * it moves the enemies in the map
 * @param g The t_game struct to use
 */
void		move_enemies(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MOVE_PLAYER =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief It handles the keyboard events and updates the player's next
 * position
 * @param keycode The keycode of the pressed key
 * @param g The t_game struct to use
 * @return 0
 */
int			move_handler(int keycode, t_game *g);

/**
 * @brief Given a keyboard event it checks if the next movement is inside the
 * map bounds and if it is necessary to render the player again (if he didn't
 * move that's not necessary)
 * 
 * @param g The t_game struct to use
 * @param e The entity that should be moved
 * @return true if the move is valid, false otherwise 
 */
bool		player_can_move(t_game *g, t_entity *e);

/**
 * @brief It checks if the player has stepped on a coin and if so it
 * updates the number of collected potions
 * @param g The t_game struct to use
 * @param p The next position of the player
 */
void		collect_potions(t_game *g, t_point *p);

/**
 * @brief Depending on the next position of the player, this function updates
 * the char map with the new chars. It also renders the new images and saves
 * the image the player has stepped on to render it after the player steps out.
 * 
 * @param game The t_game struct to use
 */
void		move_player(t_game *game);

/**
 * @brief It checks if the player has stepped on the exit, potion or enemy
 * and if so it updates the game state.
 * @param g The t_game struct to use
 * @param p The next position of the player
 */
void		player_controller(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ READ_MAP _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief It creates a new malloc'ed t_map struct. It also allocates
 * memory of the char ** matrix
 * 
 * @param cols The number of columns of each line
 * @param rows The number of lines
 * @return t_map* pointer, NULL in failed allocation
 */
t_map		*map_new(unsigned int cols, unsigned int rows);

/**
 * @brief It reads the map file to know how many lines should be
 * allocated in the t_map struct
 * 
 * @param game The t_game struct to use
 * @param filename The filename to read the map from
 * @return The number of lines read from the file
 */
int			get_num_lines(t_game *game, char *filename);

/**
 * @brief Reads the lines from a map file into a char ** matrix
 * 
 * @param game The t_game struct to use
 * @param filename The filename to read the map from
 */
void		read_map(t_game *game, char *filename);

/**
 * @brief Returns the type of the entity in the given position
 * @param map The t_map struct to free
 */
t_type		at(t_game *g, t_point p);

/**
 * @brief Sets the type of the entity in the given position
 * @param map The t_map struct to free
 */
void		set(t_game *g, t_point p, t_type type);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RENDER _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief Renders the the frame of index frame of the sprite s in the
 * position p multiplied by the tile size and the X offset.
 * @param g The t_game struct to use
 * @param s The sprite to render
 * @param p The position to render the sprite
 * @param frame The index of the sprite to render
 */
void		render(t_game *g, t_img *img, t_point p);
/**
 * @brief Given a pair of coordinates, it renders a map tile. Depending on the
 * entity in that tile it renders a different image.
 * @param g The t_game struct to use
 * @param p The coordinates of the tile to render
 */
void		render_tile(t_game *g, t_point p);

/**
 * @brief Renders the map for the first time. This function is only called 
 * once, in the beggining, since rendering the entire map over and over is not 
 * necessary.
 * 
 * @param g The t_game struct to use
 */
void		render_map(t_game *g);

/**
 * @brief Renders the number of steps the player has taken
 * @param g The t_game struct to use
 * @param p The position to render the player
 */
void		render_counter(t_game *g);

/**
 * @brief Renders the next frame of the game, by knowing if the player moved
 * or not. This is the function called in the mlx_loop_hook
 * 
 * @param g The t_game struct used 
 * @return 0
 */
int			render_frame(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RENDER_WALLS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief Picks a wall sprite depending on the surrounding tiles
 * @param p The position of the wall
 * @param mat The map matrix
 */
t_wall		pick_wall_sprite_3(t_point *p, int **mat);

/**
 * @brief Picks a wall sprite depending on the surrounding tiles
 * @param p The position of the wall
 * @param mat The map matrix
 */
t_wall		pick_wall_sprite_2(t_point *p, int **mat);

/**
 * @brief Picks a wall sprite depending on the surrounding tiles
 * @param p The position of the wall
 * @param mat The map matrix
 */
t_wall		pick_wall_sprite(t_point p, int **mat);

/**
 * @brief Renders the inner walls of the map
 * @param g The t_game struct to use
 */
void		render_inner_walls(t_game *g);

/**
 * @brief Renders the outter walls of the map
 * @param g The t_game struct to use
 */
void		render_outter_walls(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= STRATEGY =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Changes the strategy of the enemies, depending on their status and
 * also updates the status of the enemies.
 * @param g The game structure
 * @param strategy The new strategy of the enemies
 * @param status The new status of the enemies
 */
void		change_strategy(t_game *g, void (*strategy)(), t_status status);

/**
 * @brief If the enemies are in the NORMAL state, each enemy will
 * move randomly.
 * @param g The game structure
 * @param enemy The enemy array to update the positions of
 */
void		random_strategy(t_game *g, t_entity *enemy);

/**
 * @brief If the enemies are in the ENRAGED state, each enemy will
 * move towards the player.
 * @param g The game structure
 * @param enemy The enemy array to update the positions of
 */
void		chase_strategy(t_game *g, t_entity *enemy);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ UTILS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief It outputs the "Error\n" string followed by an error message to
 * indicate what the error was all about. It also frees the memory of the
 * t_game struct
 * 
 * @param game The t_game struct to free the memory from
 * @param text The message to output to the console
 */
void		message(t_game *game, char *text);

/**
 * @brief Given an integer, it returns the corresponding digit char
 * @param c The integer to convert to char
 * @return The converted char, or c if the conversion is not possible
 */
int			ft_tochar(int c);

/**
 * @brief Given a char, it returns the corresponding digit integer
 * @param c The char to convert to integer
 * @return The converted integer, or c if the conversion is not possible
 */
int			ft_tonum(int c);

/**
 * @brief Given 2 points it compares both to check if they are the same
 * @param p1 The first point
 * @param p2 The second point
 * @return true if the points are the same, false otherwise 
 */
bool		is_same_point(t_point p1, t_point p2);

/**
 * @brief Frees the memory of a pointer, if the pointer is not NULL
 * @param ptr The pointer to free the memory from
 */
void		ft_free(void *ptr);

#endif