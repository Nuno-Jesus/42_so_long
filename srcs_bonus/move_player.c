/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/12 11:39:43 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	render_tile(g, (t_point){g->next.x, g->next.y});
	g->curr = g->next;
}
