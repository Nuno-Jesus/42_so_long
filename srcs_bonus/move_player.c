/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 04:43:44 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	can_player_move(t_game *g, t_entity *e)
{
	return (!is_same_point(e->pos, e->next) && at(g, e->next) != WALL);
}

void	move_player(t_game *g)
{
	static t_type	previous = SPACE;
	unsigned int	i;

	g->map->bytes[g->player.pos.y][g->player.pos.x] = previous;
	render_tile(g, g->player.pos);
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

void	player_controller(t_game *g)
{
	if (at(g, g->player.next) == COIN)
		g->collected++;
	else if (at(g, g->player.next) == ENEMY)
	{
		ft_putstr_fd("Game over.\n", STDOUT_FILENO);
		quit(g);
	}
	else if (at(g, g->player.next) == EXIT && g->collected == g->map->num_coins)
		quit(g);
}
