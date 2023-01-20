/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 20:52:46 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_movement(t_game *g)
{
	return (!is_same_point(g->curr, g->next) \
		&& at(g, g->next) != WALL \
		&& g->next.y >= 0 && g->next.y < g->map->rows \
		&& g->next.x >= 0 && g->next.x < g->map->cols);
}

void	move_player(t_game *g)
{
	static t_entity	previous = SPACE;

	g->map->bytes[g->curr.y][g->curr.x] = previous;
	if (at(g, g->next) != COIN)
		previous = g->map->bytes[g->next.y][g->next.x];
	else
		previous = SPACE;
	g->map->bytes[g->next.y][g->next.x] = PLAYER;
	render_tile(g, g->curr.x, g->curr.y);
	render_tile(g, g->next.x, g->next.y);
	g->curr = g->next;
	ft_putstr_fd("Number of movements: ", STDOUT_FILENO);
	ft_putnbr_fd(++g->moves, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
