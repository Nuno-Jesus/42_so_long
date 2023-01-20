/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:00:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 17:14:50 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "macros.h"

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}				t_point;

typedef struct s_map
{
	char			**bytes;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	num_coins;
	unsigned int	num_exits;
	unsigned int	num_players;
}				t_map;

typedef struct s_sprite{
	void	*img;
	int		width;
	int		height;
}				t_sprite;

typedef struct s_graphics {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}				t_graphics;

typedef struct s_game
{
	t_map			*map;	
	t_point			curr;
	t_point			next;
	t_graphics		disp;
	t_sprite		*sp;
	unsigned int	coins;
}				t_game;

bool	is_filename_valid(char *filename);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= ALGORITHMS =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

bool	flood_fill(t_map *map, t_point curr, char **maze);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ DESTROY _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

void	destroy_game(t_game *game);

void	destroy_sprites(t_game *g);

void	destroy_map(t_map *map);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

void	init_game(char *filename);

void	init_graphics(t_game *g);

void	load_sprites(t_game *g);

int		quit(t_game *game);

int		kb_hook(int keycode, t_game *game);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= MOVE_PLAYER =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void	move_player(t_game *game);

bool	is_valid_movement(t_game *g);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RENDER _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

void	render_tile(t_game *g, int x, int y);

void	render_map(t_game *g);

int		render_frame(t_game *g);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ MAP _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

t_map	*map_new(unsigned int cols, unsigned int rows);

int		get_num_lines(t_game *game, char *filename);

void	read_map(t_game *game, char *filename);

void	map_print(t_map *map);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ VALIDATOR _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

bool	is_map_rectangular(t_map *map);

bool	is_map_bounded(t_map *map);

bool	has_valid_entities(t_game *g);

bool	has_valid_path(t_game *game);

void	validate_map(t_game *game);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\ UTILS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ 

void	matrix_delete(char **matrix);

void	message(t_game *game, char *text);

char	at(t_game *g, t_point p);

void	print_point(t_point *point);

bool	is_same_point(t_point p1, t_point p2);

#endif