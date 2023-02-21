/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/21 02:50:51 by ncarvalh         ###   ########.fr       */
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

# define NUM_SPRITES	35

//! Wall sprites
# define ENTITIES	"01CEP"
# define FW1		"images/bonus/upper_wall.xpm"
# define FW2		"images/bonus/left_wall.xpm"
# define FW3		"images/bonus/right_wall.xpm"
# define FW4		"images/bonus/left_corner_wall.xpm"
# define FW5		"images/bonus/right_corner_wall.xpm"
# define FW6		"images/bonus/lower_wall.xpm"
# define FW7		"images/bonus/one_left_wall.xpm"
# define FW8		"images/bonus/one_right_wall.xpm"
# define FW9		"images/bonus/two_horizontal_wall.xpm"
# define FW10		"images/bonus/two_vertical_wall.xpm"
# define FW11		"images/bonus/edge_upper_wall.xpm"
# define FW12		"images/bonus/edge_lower_wall.xpm"
# define FW13		"images/bonus/edge_left_wall.xpm"
# define FW14		"images/bonus/edge_right_wall.xpm"
# define FW15		"images/bonus/bounded_wall.xpm"
# define FW16		"images/bonus/boundless_wall.xpm"
# define FW17		"images/bonus/corner_lower_left_wall.xpm"
# define FW18		"images/bonus/corner_lower_right_wall.xpm"
# define FW19		"images/bonus/corner_upper_left_wall_2.xpm"
# define FW20		"images/bonus/corner_upper_right_wall_2.xpm"
# define FW21		"images/bonus/corner_lower_left_wall_2.xpm"
# define FW22		"images/bonus/corner_lower_right_wall_2.xpm"
# define FW23		"images/bonus/boundless_2.xpm"
# define FW24		"images/bonus/barrier_upper_2.xpm"
# define FW25		"images/bonus/barrier_lower_2.xpm"
# define FW26		"images/bonus/barrier_left_2.xpm"
# define FW27		"images/bonus/barrier_right_2.xpm"
# define FW28		"images/bonus/corner_boundless_lower_left.xpm"
# define FW29		"images/bonus/corner_boundless_lower_right.xpm"
# define FW30		"images/bonus/corner_boundless_upper_left.xpm"
# define FW31		"images/bonus/corner_boundless_upper_right.xpm"

//! Rest sprites
# define FS1		"images/bonus/space.xpm"
# define FC1		"images/coin.xpm"
# define FE1		"images/exit.xpm"
# define FP1		"images/player.xpm"

# define DIFF		0
# define SUM		1
# define DIFFSUM	2 
# define SUMDIFF	3 

# define NOT_USED	'N'

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
	CORNER_UL_2,
	CORNER_UR_2,
	CORNER_DL_2,
	CORNER_DR_2,
	BOUNDLESS_2,
	BARRIER_L_2,
	BARRIER_R_2,
	BARRIER_U_2,
	BARRIER_D_2,
	CORNER_BDL,
	CORNER_BDR,
	CORNER_BUL,
	CORNER_BUR,
}				t_id;

#endif