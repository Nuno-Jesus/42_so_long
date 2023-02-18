/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 12:26:16 by ncarvalh         ###   ########.fr       */
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
# define FW1		"xpm/bonus/upper_wall.xpm"
# define FW2		"xpm/bonus/left_wall.xpm"
# define FW3		"xpm/bonus/right_wall.xpm"
# define FW4		"xpm/bonus/left_corner_wall.xpm"
# define FW5		"xpm/bonus/right_corner_wall.xpm"
# define FW6		"xpm/bonus/lower_wall.xpm"
# define FW7		"xpm/bonus/one_left_wall.xpm"
# define FW8		"xpm/bonus/one_right_wall.xpm"
# define FW9		"xpm/bonus/two_horizontal_wall.xpm"
# define FW10		"xpm/bonus/two_vertical_wall.xpm"
# define FW11		"xpm/bonus/edge_upper_wall.xpm"
# define FW12		"xpm/bonus/edge_lower_wall.xpm"
# define FW13		"xpm/bonus/edge_left_wall.xpm"
# define FW14		"xpm/bonus/edge_right_wall.xpm"
# define FW15		"xpm/bonus/bounded_wall.xpm"
# define FW16		"xpm/bonus/boundless_wall.xpm"
# define FW17		"xpm/bonus/corner_lower_left_wall.xpm"
# define FW18		"xpm/bonus/corner_lower_right_wall.xpm"
# define FS1		"xpm/bonus/space.xpm"
# define FC1		"xpm/coin.xpm"
# define FE1		"xpm/exit.xpm"
# define FP1	"xpm/player.xpm"

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
	WALL_U,
	WALL_L,
	WALL_R,
	CORNER_L,
	CORNER_R,
	WALL_D,
	BARRIER_L,
	BARRIER_R,
	PIPE_H,
	PIPE_V,
	EDGE_U,
	EDGE_D,
	EDGE_L,
	EDGE_R,
	BOUNDED,
	BOUNDLESS,
	CORNER_DL,
	CORNER_DR,
}				t_index;

#endif