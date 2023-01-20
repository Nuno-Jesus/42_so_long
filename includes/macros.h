/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 21:08:50 by ncarvalh         ###   ########.fr       */
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

# include "libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"

# define NUM_SPRITES	5
# define ENTITIES		"01CEP"
# define FS1			"xpm/space.xpm"
# define FW1			"xpm/wall.xpm"
# define FC1			"xpm/coin.xpm"
# define FE1			"xpm/exit.xpm"
# define FP1			"xpm/player.xpm"

typedef enum e_entity
{
	SPACE = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}			t_entity;

typedef enum e_key
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100
}			t_key;

typedef enum e_event
{
	ON_KEYPRESS = 2,
	ON_CLOSE = 17,
}				t_event;

typedef enum e_mask
{
	KEYPRESS_MASK = (1L << 0),
	CLOSE_MASK = (1L << 17)
}			t_mask;

typedef enum e_index
{
	W1,
	S1,
	C1,
	E1,
	P1,
}				t_index;

#endif