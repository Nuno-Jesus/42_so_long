/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/26 23:39:37 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_handler(int keycode, t_game *g)
{
	if (keycode == ESC)
		quit(g);
	else if (keycode == W)
		g->player.next = (t_point){g->player.pos.x, g->player.pos.y - 1};
	else if (keycode == A)
	{
		g->player.next = (t_point){g->player.pos.x - 1, g->player.pos.y};
		g->player.dir = LEFT;
	}
	else if (keycode == S)
		g->player.next = (t_point){g->player.pos.x, g->player.pos.y + 1};
	else if (keycode == D)
	{
		g->player.next = (t_point){g->player.pos.x + 1, g->player.pos.y};
		g->player.dir = RIGHT;
	}
	return (keycode);
}

bool	can_player_move(t_game *g, t_entity *e)
{
	return (!is_same_point(e->pos, e->next) && at(g, e->next) != WALL);
}

void	collect_coins(t_game *g, t_point *p)
{
	unsigned int	i;
	
	i = -1;
	while (++i < g->map->num_coins)
	{
		if (!is_same_point(g->coins[i].pos, *p))
			continue ;
		g->coins[i].pos = (t_point){-1, -1};
		break ;
	}
	g->collected++;
}

void	move_player(t_game *g)
{
	static t_type	previous = SPACE;

	set(g, g->player.pos, previous);
	render_tile(g, g->player.pos);
	if (at(g, g->player.next) == COIN)
		previous = SPACE;
	else
		previous = at(g, g->player.next);
	set(g, g->player.next, PLAYER);
	g->player.pos = g->player.next;
}

void	player_controller(t_game *g)
{
	if (at(g, g->player.next) == COIN)
		collect_coins(g, &g->player.next);
	else if (at(g, g->player.next) == ENEMY)
	{
		ft_putstr_fd("Game over.\n", STDOUT_FILENO);
		quit(g);
	}
	else if (g->collected == g->map->num_coins)
	{
		if (at(g, g->player.next) == EXIT)
			quit(g);
		if (g->enemy_status != ENRAGED)
			change_enemies_strategy(g, &rage_move, ENRAGED);		
	}
}
