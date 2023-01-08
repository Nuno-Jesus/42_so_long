/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:11:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/08 13:57:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_rect_map(t_game *game)
{
	unsigned int	i;
	unsigned int	first_len;

	i = 0;
	first_len = ft_strlen(game->map->bytes[0]);
	while (i < game->map->rows)
		if (ft_strlen(game->map->bytes[i++]) != first_len)
			return (false);
	game->map->cols = first_len;
	return (true);
}

void	validate_map(t_game *game)
{
	if (!is_rect_map(game))
		message(game, "Map is not rectangular.\n");
}