/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 23:15:52 by crypto           ###   ########.fr       */
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

# define NUM_SPRITE_VERSIONS	2
# define XOFFSET				-16
# define ENTITIES				"01CEPM"

//! Sprite counters
# define NUM_WALLS			31
# define NUM_PLAYER_FRAMES	7
# define NUM_COIN_FRAMES	15
# define NUM_ENEMY_FRAMES	8
# define NUM_EXIT_FRAMES	1
# define NUM_FLOOR_FRAMES	1

//! Sprite refreshing frequency
# define ANIMATE_CALLS		250
# define CALLS_PER_FRAME	8
# define MOVE_CALLS			50000

//! Binary map needed macros
# define DIFF				0
# define SUM				1
# define DIFFSUM			2 
# define SUMDIFF			3 
# define NOT_USED			'N'

//! File paths
# define PLAYER_RIGHT_PATH	"images/bonus/player/right/player_"
# define PLAYER_LEFT_PATH	"images/bonus/player/left/player_"
# define ENEMY_CALM_PATH	"images/bonus/enemies/calm/enemy_"
# define ENEMY_RAGE_PATH	"images/bonus/enemies/rage/enemy_"
# define POTION_PATH		"images/bonus/potions/potion_"
# define WALL_PATH			"images/bonus/walls/wall_"
# define EXIT_PATH			"images/bonus/exit/exit_"
# define FLOOR_PATH			"images/bonus/floor/floor_"

/**
 * @brief An enumerable type used to map a char to an entity
 */
typedef enum e_type
{
	POTION = 'C',
	FLOOR = '0',
	WALL = '1',
	EXIT = 'E',
	ENEMY = 'M',
	PLAYER = 'P',
}			t_type;

typedef enum e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}			t_direction;

typedef enum e_status
{
	NORMAL,
	ENRAGED,
	AFRAID,
}t_status;

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