/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/21 18:19:40 by ncarvalh         ###   ########.fr       */
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

# define NUM_SPRITES		34
# define NUM_PLAYER_FRAMES	7
# define CALLS				250
# define FPS				8

//! Wall sprites
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
# define FW19		"xpm/bonus/corner_upper_left_wall_2.xpm"
# define FW20		"xpm/bonus/corner_upper_right_wall_2.xpm"
# define FW21		"xpm/bonus/corner_lower_left_wall_2.xpm"
# define FW22		"xpm/bonus/corner_lower_right_wall_2.xpm"
# define FW23		"xpm/bonus/boundless_2.xpm"
# define FW24		"xpm/bonus/barrier_upper_2.xpm"
# define FW25		"xpm/bonus/barrier_lower_2.xpm"
# define FW26		"xpm/bonus/barrier_left_2.xpm"
# define FW27		"xpm/bonus/barrier_right_2.xpm"
# define FW28		"xpm/bonus/corner_boundless_lower_left.xpm"
# define FW29		"xpm/bonus/corner_boundless_lower_right.xpm"
# define FW30		"xpm/bonus/corner_boundless_upper_left.xpm"
# define FW31		"xpm/bonus/corner_boundless_upper_right.xpm"

//! Player frames
# define FP1		"xpm/bonus/player/player_1.xpm"
# define FP2		"xpm/bonus/player/player_2.xpm"
# define FP3		"xpm/bonus/player/player_3.xpm"
# define FP4		"xpm/bonus/player/player_4.xpm"
# define FP5		"xpm/bonus/player/player_5.xpm"
# define FP6		"xpm/bonus/player/player_6.xpm"
# define FP7		"xpm/bonus/player/player_7.xpm"

//! Rest sprites
# define FS1		"xpm/bonus/space.xpm"
# define FC1		"xpm/coin.xpm"
# define FE1		"xpm/exit.xpm"

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