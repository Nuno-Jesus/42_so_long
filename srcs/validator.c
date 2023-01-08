/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:11:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/08 15:32:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_map_rectangular(t_map *map)
{
	unsigned int	i;
	unsigned int	first_len;

	i = 0;
	first_len = ft_strlen(map->bytes[0]);
	while (i < map->rows)
		if (ft_strlen(map->bytes[i++]) != first_len)
			return (false);
	map->cols = first_len;
	return (true);
}

bool	is_map_bounded(t_map *map)
{
	unsigned int	i;
	
	i = -1;
	while (++i < map->rows)
		if (map->bytes[i][0] != WALL || map->bytes[i][map->cols - 1] != WALL)
			return (false);
	i = -1;
	while (++i < map->cols)
		if (map->bytes[0][i] != WALL || map->bytes[map->rows - 1][i] != WALL)
			return (false);
	return (true);
}

bool	has_valid_entities(t_map *map)
{
	unsigned int	i;
	unsigned int	k;
	
	i = -1;
	k = -1;
	while (++i < map->rows)
	{
		k = -1;
		while (++k < map->cols)
			if (!ft_strchr(ENTITIES, map->bytes[i][k]))
				return (false);		
	}
	return (true);
}

void	validate_map(t_game *game)
{
	if (game->map->rows == 0)
		message(game, "Map is empty.\n");
	if (!is_map_rectangular(game->map))
		message(game, "Map is not rectangular.\n");
	if (!is_map_bounded(game->map))
		message(game, "Map is not bounded by walls.\n");
	if (!has_valid_entities(game->map))
		message(game, "Map has invalid entities.\n");
	
}