/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 03:11:38 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_valid_movement(t_game *g, t_entity *e)
{
	return (!is_same_point(e->pos, e->next) && at(g, e->next) != WALL);
}

void	move_player(t_game *g)
{
	static t_type	previous = SPACE;
	unsigned int	i;

	g->map->bytes[g->player.pos.y][g->player.pos.x] = previous;
	render_tile(g, (t_point){g->player.pos.x, g->player.pos.y});
	if (at(g, g->player.next) == COIN)
	{
		previous = SPACE;
		i = -1;
		while (++i < g->map->num_coins)
		{
			if (is_same_point(g->coins[i].pos, g->player.next))
			{
				g->coins[i].pos = (t_point){-1, -1};
				break ;
			}
		}
	}
	else
		previous = g->map->bytes[g->player.next.y][g->player.next.x];
	g->map->bytes[g->player.next.y][g->player.next.x] = PLAYER;
	g->player.pos = g->player.next;
}
/* 
void	move_enemies(t_game *g)
{
	static t_type	previous = SPACE;
	unsigned int	i;

	g->map->bytes[g->curr.y][g->curr.x] = previous;
	render_tile(g, (t_point){g->curr.x, g->curr.y});
	if (at(g, g->next) == ENEMY)
	{
		previous = SPACE;
		i = -1;
		while (++i < g->map->num_enemies)
		{
			if (is_same_point(g->enemies[i].pos, g->next))
			{
				g->enemies[i].pos = (t_point){-1, -1};
				break ;
			}
		}
	}
	else
		previous = g->map->bytes[g->next.y][g->next.x];
	g->map->bytes[g->next.y][g->next.x] = ENEMY;
	g->curr = g->next;
}
 */