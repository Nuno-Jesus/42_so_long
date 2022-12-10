/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:02:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 13:03:20 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "macros.h"
# include "point.h"

typedef struct s_map
{
	t_point *dims;
	t_point *exit;
	t_point *coins;
	t_point *walls;
	t_point *player;
	size_t	num_coins;
	size_t	num_walls;
}t_map;

t_map	*map_new(t_point *dims);

void	map_delete(t_map *map);

#endif 