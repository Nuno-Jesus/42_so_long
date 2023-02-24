/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:38:07 by crypto            #+#    #+#             */
/*   Updated: 2023/02/24 04:55:45 by ncarvalh         ###   ########.fr       */
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
 * @param num_coins The number of collected in the map
 * @param num_exits The number of exits in the map
 * @param num_players The number of players in the map
 */
typedef struct s_map
{
	char			**bytes;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	num_coins;
	unsigned int	num_exits;
	unsigned int	num_players;
	unsigned int	num_enemies;
}				t_map;

/**
 * @brief A struct sprite related data
 * @param img The mlx pointer of the sprite image
 * @param width The width of the sprite
 * @param height The height of the sprite
 */
typedef struct s_sprite
{
	void	**img;
	int		width;
	int		height;
	int		nframes;
	int		curr;
}				t_sprite;

/**
 * @brief Data structure containing mlx related data
 * @param mlx The mlx pointer
 * @param win The mlx window pointer
 * @param img The mlx img pointer
 * @param addr An mlx image address pointer
 * @param height (unused)
 * @param width (unused)
 * @param bpp (unused)
 * @param line_length (unused)
 * @param endian (unused)
 */
typedef struct s_display
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}				t_display;

typedef struct s_entity
{
	int			frame;
	t_direction	dir;
	t_point		pos;
	t_point		next;
	void		(*strategy)();
}				t_entity;

/**
 * @brief The root of the so_long project encapsulating other structs
 * @param map The map struct
 * @param curr The current player's position
 * @param next The next player's position given the keyboard inputs
 * @param disp The t_display display
 * @param sp The t_sprite array containing all the used sprites
 * @param collected The number of collected collected so far
 * @param moves The number of moves so far
 */
typedef struct s_game
{
	t_map			*map;	
	t_point			enext;
	t_display		disp;
	t_sprite		sp;
	t_entity		*coins;
	t_sprite		cframes;
	t_entity		player;
	t_sprite		*pframes;
	t_entity		*enemies;
	t_sprite		*eframes;
	unsigned int	collected;
	unsigned int	moves;
}					t_game;

// I was refactoring the sprite struct

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= ANIMATE =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void		animate_player(t_game *g);

void		animate_enemies(t_game *g);

void		animate_coins(t_game *g);

/**
 * @brief Given the filename passed as argument, it checks if the filename
 * is valid by checking for the ".ber" suffix and if the file exists
 * 
 * @param filename The terminal input 
 * @return true if the filename is valid, false otherwise 
 */
bool		is_filename_valid(char *filename);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= ALGORITHMS =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

/**
 * @brief Given an auxiliary map it checks for a valid path between the 
 * player's position and the exit. It also counts the number of collected
 * collected so far in the algorithm to match it against the total number
 * of collected. It works by recursively exploring the 4 adjacent positions.
 * 
 * @param map The map structure containing the number of collected to collect 
 * @param curr The current position to explore
 * @param maze The auxiliary map to fill
 * @return true if there is a valid path and all collected are collected, false 
 * otherwise 
 */
bool		flood_fill(t_map *map, t_point curr, char **maze);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\ BINARY_WALL_MAP /=\_/=\_/=\_/=\_/=\_/=\_/=\_
bool		has_diags(int **mat, t_point *p, char *diagonals);

bool		bin(t_point *p, int **mat, t_point vals, int op);

void		fill_binary_matrix(t_game *g, int **mat);

int			**create_binary_matrix(unsigned int y, unsigned int x);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ DESTROY _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief Frees the memory associated to a t_game structure
 * @param game The t_game struct to free
 */
void		destroy_game(t_game *game);

void		init_position(t_game *g, t_point *pos, t_type type);

/**
 * @brief Frees the memory from the sprite array inside the t_game struct
 * @param g The t_game struct to free the sprites memory from
 */
void		destroy_sprites(t_game *g);

/**
 * @brief Frees the memory associated with a t_map struct
 * @param map The t_map struct to free the memory from
 */
void		destroy_map(t_map *map);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

void		init_entities(t_game *g);

void		init_position(t_game *g, t_point *pos, t_type type);
/**
 * @brief This function has several roles: to read and parse the map from
 * the file passed as argument, to initialize the graphical environment,
 * load sprites and to register events
 * 
 * @param filename The filename to read the map from
 */
void		init_game(char *filename);

/**
 * @brief It initializes the graphical environment by allocating memory
 * to the mlx, window and other needed pointers
 * 
 * @param g The t_game struct to use
 */
void		init_graphics(t_game *g);

/**
 * @brief This function is called to load the .xpm files in the initiation
 * of the graphical environment, to prevent multiple and unnecessary loads
 * 
 * @param g The t_game struct to use 
 */
void		load_sprites(t_game *g);

/**
 * @brief It stops the process if either the ESC key was pressed or the X
 * button was clicked. It also frees the memory of the t_game struct
 * 
 * @param game The t_game to free the memory from
 * @return int (Unused)
 */
int			quit(t_game *game);

/**
 * @brief Used to register the keyboard events needed for the project, such
 * as WASD and ESC keycode events
 * 
 * @param keycode The scancode of the pressed key
 * @param game The t_game struct to use
 * @return int (unused)
 */
int			move_handler(int keycode, t_game *game);
//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= LOAD_WALLS =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void		load_walls_1(t_game *g);

void		load_walls_2(t_game *g);

void		load_walls_3(t_game *g);

void		load_walls(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= LOAD_REST =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void		load_player_frames_2(t_game *g);

void		load_player_frames(t_game *g);

void		load_coins_frames(t_game *g);

void		load_exits(t_game *g);

void		load_spaces(t_game *g);

void		load_enemy_frames(t_game *g);
//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MOVE_PLAYER =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void		player_controller(t_game *g);

/**
 * @brief Depending on the next position of the player, this function updates
 * the char map with the new chars. It also renders the new images and saves
 * the image the player has stepped on to render it after the player steps out.
 * 
 * @param game The t_game struct to use
 */
void		move_player(t_game *game);

/**
 * @brief 
 * 
 * @param g 
 */
void		move_enemies(t_game *g);
/**
 * @brief Given a keyboard event it checks if the next movement is inside the
 * map bounds and if it is necessary to render the player again (if he didn't
 * move that's not necessary)
 * 
 * @param g The t_game struct to use
 * @param e The entity that should be moved
 * @return true if the move is valid, false otherwise 
 */
bool		can_player_move(t_game *g, t_entity *e);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RENDER _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

void		render_sprite(t_game *g, t_sprite *s, t_point p, int frame);
/**
 * @brief Given a pair of coordinates, it renders a map tile. Depending on the
 * entity in that tile it renders a different image.
 * 
 * @param g The t_game struct to use
 * @param x The x coordinate in the map array
 * @param y The y coordinate in the map array
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
 * @brief Renders the next frame of the game, by knowing if the player moved
 * or not. This is the function called in the mlx_loop_hook
 * 
 * @param g The t_game struct used 
 * @return int (Unused)
 */
int			render_frame(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MOVE_ENEMIES =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
bool		can_enemy_move(t_game *g, t_entity *e);

bool		enemy_has_possible_moves(t_game *g, t_entity *e);

void		generate_move(t_game *g, t_entity *e);

void		move_enemies(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ MAP _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

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

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RENDER_WALLS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 
t_id		pick_wall_sprite_3(t_point *p, int **mat);

t_id		pick_wall_sprite_2(t_point *p, int **mat);

t_id		pick_wall_sprite(t_point p, int **mat);

void		render_inner_walls(t_game *g);

void		render_outter_walls(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MAP_VALIDATOR =\_/=\_/=\_/=\_/=\_/=\_/=\_/=

/**
 * @brief Given the read map, it checks if all lines have the same length
 * 
 * @param map The t_map struct to use
 * @return true if all lines are coherent, false otherwise 
 */
bool		is_map_rectangular(t_map *map);

/**
 * @brief Given the read map, it checks if the map is bounded by walls
 * 
 * @param map The t_map struct to use
 * @return true if the map is bounded, false otherwise 
 */
bool		is_map_bounded(t_map *map);

/**
 * @brief Given the read map, it checks if the map has only '1', '0',
 * 'C', 'E' and 'P' chars
 * 
 * @param g The t_game struct to use 
 * @return true if the map has valid entities, false otherwise 
 */
bool		has_valid_entities(t_game *g);

/**
 * @brief Given the read map, it creates an auxiliary map to call 
 * the flood_fill function and return a boolean representing if the
 * map is playable (read flood_fill doc)
 * 
 * @param game The t_game struct to use
 * @return true if the map is playable, false otherwise 
 */
bool		has_valid_path(t_game *g);

/**
 * @brief This function is used merely to call the other validator
 * functions and abort if anything goes wrong. If some 
 * mis-configuration is found, the program aborts and all the memory is
 * free'd
 * 
 * @param game The t_game struct to use
 */
void		validate_map(t_game *g);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ UTILS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

/**
 * @brief Deletes the memory associated to a char matrix
 * @param matrix The matrix to delete the memory from 
 */
void		ft_delete_matrix(void *matrix);

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
 * @brief Given the coordinates of a point in the map, it returns the
 * entity in it
 * 
 * @param g The t_game struct to use
 * @param p The coordinates to search on
 * @return The char containing the entity
 */
t_type		at(t_game *g, t_point p);

int			ft_todigit(int c);

bool		is_same_point(t_point p1, t_point p2);

#endif