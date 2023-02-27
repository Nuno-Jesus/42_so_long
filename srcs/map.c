/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:03:57 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 20:44:00 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_new(unsigned int cols, unsigned int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->bytes = ft_calloc(rows + 1, sizeof(char *));
	if (!map->bytes)
	{
		free(map);
		return (NULL);
	}
	map->cols = cols;
	map->rows = rows;
	return (map);
}

int	get_num_lines(t_game *game, char *filename)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(game, "Couldn't open requested file.\n");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		lines++;
		free(tmp);
	}
	close(fd);
	return (lines);
}

void	read_map(t_game *game, char *filename)
{
	int				fd;
	char			*tmp;
	unsigned int	i;

	i = 0;
	game->map = map_new(0, get_num_lines(game, filename));
	if (!game->map)
		message(game, "Allocation error on game->map\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(game, "Couldn't open requested file.\n");
	while (i < game->map->rows)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			message(game, "Allocation failed on map lines.\n");
		game->map->bytes[i] = ft_strtrim(tmp, "\n");
		if (!game->map->bytes[i++])
			message(game, "Allocation failed on map lines 2.\n");
		free(tmp);
	}
	close(fd);
}

/* 
void	map_print(t_map *map)
{
	unsigned int	i;

	i = 0;
	printf("Length: %u\n", map->cols);
	printf("Width: %u\n", map->rows);
	printf("Players: %u\n", map->num_players);
	printf("Exits: %u\n", map->num_exits);
	printf("Coins: %u\n", map->num_potions);
	while (i < map->rows)
		printf("%s\n", map->bytes[i++]);
}
 */
