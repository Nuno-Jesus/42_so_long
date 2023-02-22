/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 22:15:13 by ncarvalh         ###   ########.fr       */
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
# include <time.h>

# include "libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"

# define DIRECTIONS			2
# define XOFFSET			-16
# define ENTITIES			"01CEP"

//! Sprite counters
# define NUM_WALLS			33
# define NUM_PLAYER_FRAMES	7
# define NUM_COIN_FRAMES	15

//! Sprite refreshing frequency
# define CALLS				250
# define CALLS_PER_FRAME	48

//! Binary map needed macros
# define DIFF				0
# define SUM				1
# define DIFFSUM			2 
# define SUMDIFF			3 
# define NOT_USED			'N'

//! Wall sprites
# define FW1		"images/bonus/walls/upper_wall.xpm"
# define FW2		"images/bonus/walls/left_wall.xpm"
# define FW3		"images/bonus/walls/right_wall.xpm"
# define FW4		"images/bonus/walls/left_corner_wall.xpm"
# define FW5		"images/bonus/walls/right_corner_wall.xpm"
# define FW6		"images/bonus/walls/lower_wall.xpm"
# define FW7		"images/bonus/walls/one_left_wall.xpm"
# define FW8		"images/bonus/walls/one_right_wall.xpm"
# define FW9		"images/bonus/walls/two_horizontal_wall.xpm"
# define FW10		"images/bonus/walls/two_vertical_wall.xpm"
# define FW11		"images/bonus/walls/edge_upper_wall.xpm"
# define FW12		"images/bonus/walls/edge_lower_wall.xpm"
# define FW13		"images/bonus/walls/edge_left_wall.xpm"
# define FW14		"images/bonus/walls/edge_right_wall.xpm"
# define FW15		"images/bonus/walls/bounded_wall.xpm"
# define FW16		"images/bonus/walls/boundless_wall.xpm"
# define FW17		"images/bonus/walls/corner_lower_left_wall.xpm"
# define FW18		"images/bonus/walls/corner_lower_right_wall.xpm"
# define FW19		"images/bonus/walls/corner_upper_left_wall_2.xpm"
# define FW20		"images/bonus/walls/corner_upper_right_wall_2.xpm"
# define FW21		"images/bonus/walls/corner_lower_left_wall_2.xpm"
# define FW22		"images/bonus/walls/corner_lower_right_wall_2.xpm"
# define FW23		"images/bonus/walls/boundless_2.xpm"
# define FW24		"images/bonus/walls/barrier_upper_2.xpm"
# define FW25		"images/bonus/walls/barrier_lower_2.xpm"
# define FW26		"images/bonus/walls/barrier_left_2.xpm"
# define FW27		"images/bonus/walls/barrier_right_2.xpm"
# define FW28		"images/bonus/walls/corner_boundless_lower_left.xpm"
# define FW29		"images/bonus/walls/corner_boundless_lower_right.xpm"
# define FW30		"images/bonus/walls/corner_boundless_upper_left.xpm"
# define FW31		"images/bonus/walls/corner_boundless_upper_right.xpm"

//! Player frames
# define FP1		"images/bonus/player/right_player_1.xpm"
# define FP2		"images/bonus/player/right_player_2.xpm"
# define FP3		"images/bonus/player/right_player_3.xpm"
# define FP4		"images/bonus/player/right_player_4.xpm"
# define FP5		"images/bonus/player/right_player_5.xpm"
# define FP6		"images/bonus/player/right_player_6.xpm"
# define FP7		"images/bonus/player/right_player_7.xpm"
# define FP8		"images/bonus/player/left_player_1.xpm"
# define FP9		"images/bonus/player/left_player_2.xpm"
# define FP10		"images/bonus/player/left_player_3.xpm"
# define FP11		"images/bonus/player/left_player_4.xpm"
# define FP12		"images/bonus/player/left_player_5.xpm"
# define FP13		"images/bonus/player/left_player_6.xpm"
# define FP14		"images/bonus/player/left_player_7.xpm"

//! Potion frames

# define FC1 		"images/bonus/potions/potion_1.xpm"
# define FC2 		"images/bonus/potions/potion_2.xpm"
# define FC3 		"images/bonus/potions/potion_3.xpm"
# define FC4 		"images/bonus/potions/potion_4.xpm"
# define FC5 		"images/bonus/potions/potion_5.xpm"
# define FC6 		"images/bonus/potions/potion_6.xpm"
# define FC7 		"images/bonus/potions/potion_7.xpm"
# define FC8 		"images/bonus/potions/potion_8.xpm"
# define FC9 		"images/bonus/potions/potion_9.xpm"
# define FC10 		"images/bonus/potions/potion_10.xpm"
# define FC11 		"images/bonus/potions/potion_11.xpm"
# define FC12 		"images/bonus/potions/potion_12.xpm"
# define FC13 		"images/bonus/potions/potion_13.xpm"
# define FC14 		"images/bonus/potions/potion_14.xpm"
# define FC15 		"images/bonus/potions/potion_15.xpm"

//! Rest sprites
# define FS1		"images/bonus/space.xpm"
# define FE1		"images/exit.xpm"

/**
 * @brief An enumerable type used to map a char to an entity
 */
typedef enum e_type
{
	SPACE = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}			t_type;

typedef enum e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}			t_direction;		
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
typedef enum e_id
{
	S1,
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