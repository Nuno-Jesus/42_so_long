/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:18:51 by crypto            #+#    #+#             */
/*   Updated: 2023/03/04 06:07:28 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_print(t_map *map)
{
	unsigned int	i;

	i = 0;
	ft_printf("Length: %u\n", map->cols);
	ft_printf("Width: %u\n", map->rows);
	ft_printf("Players: %u\n", map->num_players);
	ft_printf("Enemies: %u\n", map->num_enemies);
	ft_printf("Exits: %u\n", map->num_exits);
	ft_printf("Coins: %u\n", map->num_potions);
	while (i < map->rows)
		ft_printf("%s\n", map->bytes[i++]);
}

void	binary_map_print(t_game *g, int **mat)
{
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < g->map->rows + 2)
	{
		x = -1;
		while (++x < g->map->cols + 2)
			ft_printf("%d", mat[y][x]);
		ft_printf("\n");
	}
}
