/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:00:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 15:29:59 by ncarvalh         ###   ########.fr       */
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

typedef struct	s_sprite{
	void	*img;
	int		width;
	int		height;
}				t_sprite;

typedef struct	s_graphics {
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
	t_sprite 		*sp;
	unsigned int	coins;
}				t_game;


//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ GAME _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

t_game	*game_new();

void	game_delete(t_game *game);

void	game_init(char *filename);

bool	is_filename_valid(char *filename);

void	init_graphics(t_game *g);

void	delete_sprites(t_game *g);

void	load_sprites(t_game *g);

void	render_tile(t_game *g, int x, int y);

void	render_map(t_game *g);

int		render_frame(t_game *g);

void	move_player(t_game *game);

bool	flood_fill(t_map *map, t_point curr, char **maze);

bool	is_same_point(t_point p1, t_point p2);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ MAP _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

t_map	*map_new(unsigned int cols, unsigned int rows);

void	map_delete(t_map *map);

void	map_print(t_map *map);
	 	
int		get_map_height(t_game *game, char *filename);

void	read_map(t_game *game, char *filename);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/= VALIDATOR =\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void	validate_map(t_game *game);

bool	is_valid_movement(t_game *g);

//_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ UTILS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void	matrix_delete(char **matrix);

void	message(t_game *game, char *text);

void	delete_sprites(t_game *g);

char	at(t_game *g, t_point p);

void	print_point(t_point *point);

#endif