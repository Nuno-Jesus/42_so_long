/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:20:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 15:30:02 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	flood_fill(t_map *map, t_point curr, char **maze)
{
	static unsigned int	collected = 0;
	static bool			found_exit = false;

	if (maze[curr.y][curr.x] == WALL)
		return (false);
	else if (maze[curr.y][curr.x] == COIN)
		collected++;
	else if (maze[curr.y][curr.x] == EXIT)
		found_exit = true;
	maze[curr.y][curr.x] = WALL;
	flood_fill(map, (t_point){curr.x + 1, curr.y}, maze);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, maze);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, maze);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, maze);
	return (collected == map->num_coins && found_exit);
}
