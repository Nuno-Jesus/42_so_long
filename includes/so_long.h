/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:00:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/07 12:28:58 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "macros.h"

typedef struct s_map
{
	char			**bytes;
	unsigned int	length;
	unsigned int	width;
	unsigned int	num_coins;
	unsigned int	num_walls;
}t_map;

typedef struct s_point
{
	unsigned int x;
	unsigned int y;
}t_point;

typedef struct s_game
{
	// Double pointer map
	t_map			*map;
	// Player's position (x,y)
	t_point			player;
	// Number of collected coins so far
	unsigned int	coins;
}t_game;

t_game	*game_new();

t_map	*map_new(unsigned int length, unsigned int width);

void	game_delete(t_game *game);

void	map_delete(t_map *map);

//! ----------------------------------------------------------------- 

void	read_map(t_game *game, char *filename);

void	matrix_delete(char **matrix);

int		get_map_width(t_game *game, char *filename);


#endif