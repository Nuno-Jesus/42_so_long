/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 06:04:11 by ncarvalh         ###   ########.fr       */
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
# include "ft_printf.h"
# include "../mlx/mlx.h"

# define DEBUG

//! Number of sprite versions for enemies and player
# define NUM_SPRITE_VERSIONS	2

//! X offset to render tiles correctly (it cuts the sprite of the side
//! walls to make them look like smaller walls)
# define XOFFSET				-16

//! Entities that can be in the .ber maps
# define ENTITIES				"01CEPM"

//! Macro used to know which cells are being checked to render the right
//! wall sprite frame. A cell with 'N' is not being considered
# define NOT_USED			'N'

//! Sprite counters
# define NUM_WALLS			31
# define NUM_PLAYER_FRAMES	7
# define NUM_COIN_FRAMES	15
# define NUM_ENEMY_FRAMES	8
# define NUM_EXIT_FRAMES	1
# define NUM_FLOOR_FRAMES	1

//! Sprite refreshing frequency
# define ANIMATE_CALLS		250
# define CALLS_PER_FRAME	40
# define MOVE_CALLS			50000

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

/**
 * @brief An enumerable type used to map an integer to a direction
 */
typedef enum e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}			t_direction;

/**
 * @brief An enumerable type used to map an integer to a status used on enemies
 */
typedef enum e_status
{
	NORMAL,
	ENRAGED,
	AFRAID,
}			t_status;

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
typedef enum e_wall
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
}				t_wall;

#endif