/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:11:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/08 17:36:49 by marvin           ###   ########.fr       */
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

bool	has_valid_entities(t_game *game)
{
	unsigned int	i;
	unsigned int	k;

	i = -1;
	while (++i < game->map->rows)
	{
		k = -1;
		while (++k < game->map->cols)
		{
			if (game->map->bytes[i][k] == PLAYER)
			{
				game->map->num_players++;
				game->player = (t_point){k, i};
			}
			else if (game->map->bytes[i][k] == EXIT)
				game->map->num_exits++;
			else if (game->map->bytes[i][k] == COIN)
				game->map->num_coins++;
			else if (!ft_strchr(ENTITIES, game->map->bytes[i][k]))
				return (false);	
		}
	}
	return (game->map->num_players == 1 && 
		game->map->num_exits == 1 && 
		game->map->num_coins >= 1);
}

bool	flood_fill(t_map *map, t_point curr, char **maze)
{
	static unsigned int	coins = 0;
	static bool			found_exit = false;
	
	if (maze[curr.y][curr.x] == WALL)
		return (false);
	else if (maze[curr.y][curr.x] == COIN)
		coins++;
	else if (maze[curr.y][curr.x] == EXIT)
		found_exit = true;
	maze[curr.y][curr.x] = WALL;
	flood_fill(map, (t_point){curr.x + 1, curr.y}, maze);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, maze);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, maze);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, maze);
	return (coins == map->num_coins && found_exit);
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
	is_valid = flood_fill(game->map, game->player, dup);
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