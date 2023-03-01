/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:18:51 by crypto            #+#    #+#             */
/*   Updated: 2023/02/28 19:22:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_print(t_map *map)
{
	unsigned int	i;

	i = 0;
	printf("Length: %u\n", map->cols);
	printf("Width: %u\n", map->rows);
	printf("Players: %u\n", map->num_players);
	printf("Enemies: %u\n", map->num_enemies);
	printf("Exits: %u\n", map->num_exits);
	printf("Coins: %u\n", map->num_potions);
	while (i < map->rows)
		printf("%s\n", map->bytes[i++]);
}
