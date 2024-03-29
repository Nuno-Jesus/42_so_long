/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/04 11:33:24 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

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

# define NUM_SPRITES		5
# define NUM_SPRITES_BONUS	9

# define ENTITIES	"01CEP"
# define FW1		"images/mandatory/wall.xpm"
# define FS1		"images/mandatory/space.xpm"
# define FC1		"images/mandatory/coin.xpm"
# define FE1		"images/mandatory/exit.xpm"
# define FP1		"images/mandatory/player.xpm"

/**
 * @brief An enumerable type used to map a char to an entity
 */
typedef enum e_entity
{
	FLOOR = '0',
	WALL = '1',
	POTION = 'C',
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
	W1,
	S1,
	C1,
	E1,
	P1,
}				t_id;

#endif