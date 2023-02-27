/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:11:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 20:44:00 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

bool	has_valid_entities(t_game *g)
{
	unsigned int	i;
	unsigned int	k;

	i = -1;
	while (++i < g->map->rows)
	{
		k = -1;
		while (++k < g->map->cols)
		{
			if (g->map->bytes[i][k] == PLAYER)
			{
				g->map->num_players++;
				g->curr = (t_point){k, i};
				g->next = g->curr;
			}
			else if (g->map->bytes[i][k] == EXIT)
				g->map->num_exits++;
			else if (g->map->bytes[i][k] == POTION)
				g->map->num_potions++;
			else if (!ft_strchr(ENTITIES, g->map->bytes[i][k]))
				return (false);
		}
	}
	return (g->map->num_players == 1 && g->map->num_exits == 1
		&& g->map->num_potions >= 1);
}

bool	has_valid_path(t_game *game)
{
	char			**dup;
	bool			is_valid;
	unsigned int	i;

	i = 0;
	dup = ft_calloc(game->map->rows + 1, sizeof(char *));
	if (!dup)
		message(game, "Failed allocation on has_valid_path()\n");
	while (i < game->map->rows)
	{
		dup[i] = ft_strdup(game->map->bytes[i]);
		if (!dup[i])
		{
			matrix_delete(dup);
			message(game, "Failed allocation on has_valid_path()\n");
		}
		i++;
	}
	is_valid = flood_fill(game->map, game->curr, dup);
	matrix_delete(dup);
	return (is_valid);
}

void	validate_map(t_game *game)
{
	if (game->map->rows == 0)
		message(game, "Map is empty.\n");
	if (!is_map_rectangular(game->map))
		message(game, "Map is not rectangular.\n");
	if (!is_map_bounded(game->map))
		message(game, "Map is not bounded by walls.\n");
	if (!has_valid_entities(game))
		message(game, "Map has invalid entities.\n");
	if (!has_valid_path(game))
		message(game, "Map has not a traversable path to end the level.\n");
}
