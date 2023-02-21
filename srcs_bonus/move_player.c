/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 03:31:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_valid_movement(t_game *g)
{
	return (!is_same_point(g->curr, g->next) && at(g, g->next) != WALL);
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
	render_tile(g, (t_point){g->curr.x, g->curr.y});
	animate_player(g);
	g->curr = g->next;
}
