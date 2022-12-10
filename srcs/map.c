/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:36:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 13:02:34 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

t_map	*map_new(t_point *dims)
{
	t_map *map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->dims = dims;
	return (map);
}

void	map_delete(t_map *map)
{
	if (!map)
		return ;
	if (map->dims)
		free(map->dims);
	if (map->exit)
		free(map->exit);
	if (map->coins)
		free(map->coins);
	if (map->walls)
		free(map->walls);
	if (map->player)
		free(map->player);
	free(map);
}