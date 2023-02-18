/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 12:02:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_BONUS_H
# define MACROS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"

# define NUM_SPRITES	22

# define ENTITIES	"01CEP"
# define UPPER_WALL		"xpm/bonus/upper_wall.xpm"
# define LEFT_WALL		"xpm/bonus/left_wall.xpm"
# define RIGHT_WALL		"xpm/bonus/right_wall.xpm"
# define CORNER_LEFT		"xpm/bonus/left_corner_wall.xpm"
# define CORNER_RIGHT		"xpm/bonus/right_corner_wall.xpm"
# define LOWER_WALL		"xpm/bonus/lower_wall.xpm"
# define BARRIER_LEFT		"xpm/bonus/one_left_wall.xpm"
# define BARRIER_RIGHT		"xpm/bonus/one_right_wall.xpm"
# define PIPE_HORIZONTAL		"xpm/bonus/two_horizontal_wall.xpm"
# define PIPE_VERTICAL		"xpm/bonus/two_vertical_wall.xpm"
# define EDGE_UPPER		"xpm/bonus/edge_upper_wall.xpm"
# define EDGE_LOWER		"xpm/bonus/edge_lower_wall.xpm"
# define EDGE_LEFT		"xpm/bonus/edge_left_wall.xpm"
# define EDGE_RIGHT		"xpm/bonus/edge_right_wall.xpm"
# define BOUNDED		"xpm/bonus/bounded_wall.xpm"
# define BOUNDLESS		"xpm/bonus/boundless_wall.xpm"
# define CORNER_LOWER_LEFT		"xpm/bonus/corner_lower_left_wall.xpm"
# define CORNER_LOWER_RIGHT		"xpm/bonus/corner_lower_right_wall.xpm"
# define SPACE1		"xpm/bonus/space.xpm"
# define POTION1		"xpm/coin.xpm"
# define EXIT1		"xpm/exit.xpm"
# define PLAYER1	"xpm/player.xpm"

/**
 * @brief An enumerable type used to map a char to an entity
 */
typedef enum e_entity
{
	SPACE = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}			t_entity;

/**
 * @brief Used to map a keyboard scancode to its given key
 */
typedef enum e_key
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100
}			t_key;

/**
 * @brief Maps a mlx hook event number to its given event
 */
typedef enum e_event
{
	ON_KEYPRESS = 2,
	ON_CLOSE = 17,
}				t_event;

/**
 * @brief Maps a mlx hook event mask number to its given mask
 */
typedef enum e_mask
{
	KEYPRESS_MASK = (1L << 0),
	CLOSE_MASK = (1L << 17)
}			t_mask;

/**
 * @brief Used to access the right sprite when rendering and loading sprites
 */
typedef enum e_index
{
	S1,
	C1,
	E1,
	P1,
	W1,
	W2,
	W3,
	W4,
	W5,
	W6,
	W7,
	W8,
	W9,
	W10,
	W11,
	W12,
	W13,
	W14,
	W15,
	W16,
	W17,
	W18,
}				t_index;

#endif