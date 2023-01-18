/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/18 16:29:13 by ncarvalh         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define NUM_SPRITES	1
# define ENTITIES		"01CEP"
# define F_SPACE		"xpm/space.xpm"
# define F_WALL			"xpm/wall.xpm"
# define F_COIN			"xpm/coin.xpm"
# define F_EXIT			"xpm/exit.xpm"
# define F_PLAYER		"xpm/player.xpm"
# define OFFSET(x)		(x * 32)

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

typedef enum	e_event
{
	CLOSE_WINDOW = 17,
}				t_event;

typedef enum	e_index
{
	I_WALL,
	I_SPACE,
	I_COIN,
	I_EXIT,
	I_PLAYER,
}				t_index;

#endif