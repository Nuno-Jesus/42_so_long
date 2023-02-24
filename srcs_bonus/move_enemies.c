/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:35:13 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 06:43:27 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	can_enemy_move(t_game *g, t_entity *e)
{
	return (at(g, e->next) == SPACE || at(g, e->next) == PLAYER);
}

bool	enemy_has_possible_moves(t_game *g, t_entity *e)
{
	bool	can_move;

	can_move = false;
	can_move |= (at(g, (t_point){e->pos.x + 1, e->pos.y}) == SPACE
			|| at(g, (t_point){e->pos.x + 1, e->pos.y}) == PLAYER);
	can_move |= (at(g, (t_point){e->pos.x - 1, e->pos.y}) == SPACE
			|| at(g, (t_point){e->pos.x - 1, e->pos.y}) == PLAYER);
	can_move |= (at(g, (t_point){e->pos.x, e->pos.y + 1}) == SPACE
			|| at(g, (t_point){e->pos.x, e->pos.y + 1}) == PLAYER);
	can_move |= (at(g, (t_point){e->pos.x, e->pos.y - 1}) == SPACE
			|| at(g, (t_point){e->pos.x, e->pos.y - 1}) == PLAYER);
	return (can_move);
}

void	generate_move(t_game *g, t_entity *e)
{
	int	offset;

	while (1)
	{
		offset = 1 - (rand() % 3);
		if (rand() % 2)
		{
			e->next = (t_point){e->pos.x + offset, e->pos.y};
			if (offset < 0)
				e->dir = LEFT;
			else
				e->dir = RIGHT;
		}
		else
			e->next = (t_point){e->pos.x, e->pos.y + offset};
		if (can_enemy_move(g, e))
			break ;
	}
}

void	move_enemies(t_game *g)
{
	static int		calls = 0;
	unsigned int	i;

	i = -1;
	if (++calls % MOVE_CALLS != 0)
		return ;
	while (++i < g->map->num_enemies)
	{
		if (!enemy_has_possible_moves(g, &g->enemies[i]))
			continue ;
		generate_move(g, &g->enemies[i]);
		if (at(g, g->enemies[i].next) == PLAYER)
		{
			ft_putstr_fd("Game over.\n", STDOUT_FILENO);
			quit(g);
		}
		g->map->bytes[g->enemies[i].pos.y][g->enemies[i].pos.x] = SPACE;
		render_tile(g, g->enemies[i].pos);
		g->map->bytes[g->enemies[i].next.y][g->enemies[i].next.x] = ENEMY;
		render_tile(g, g->enemies[i].next);
		g->enemies[i].pos = g->enemies[i].next;
	}
}
