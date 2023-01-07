/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:03:57 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/07 18:05:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*map_new(unsigned int length, unsigned int width)
{
	t_map	*map;
	
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->bytes = ft_calloc(length + 1, sizeof(char *));
	if (!map->bytes)
	{
		free(map);
		return (NULL);
	}
	map->length = length;
	map->width = width;
	return (map);
}

void	map_delete(t_map *map)
{
	if (!map)
		return ;
	matrix_delete(map->bytes);
	free(map);
}

int	get_map_width(t_game *game, char *filename)
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
			break;
		lines++;
		free(tmp);
	}
	close(fd);
	return (lines);
}

void	read_map(t_game *game, char *filename)
{
	int	fd;
	unsigned int	i;

	i = 0;
	game->map = map_new(get_map_width(game, filename), 0);
	if (!game->map)
		message(game, "Allocation error on game->map\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(game, "Couldn't open requested file.\n");
	while (i < game->map->length)
	{
		game->map->bytes[i] = get_next_line(fd);
		if (!game->map->bytes[i])
			message(game, "Allocation failed on map lines.\n");
		i++;
	}
	close(fd);
}
