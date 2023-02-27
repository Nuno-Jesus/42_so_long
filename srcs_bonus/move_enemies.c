/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:35:13 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 21:21:06 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	enemy_can_move(t_game *g, t_point p)
{
	return (at(g, p) == FLOOR || at(g, p) == PLAYER);
}

bool	enemy_has_possible_moves(t_game *g, t_point *pos)
{
	bool	can_move;

	can_move = false;
	can_move |= enemy_can_move(g, (t_point){pos->x + 1, pos->y});
	can_move |= enemy_can_move(g, (t_point){pos->x - 1, pos->y});
	can_move |= enemy_can_move(g, (t_point){pos->x, pos->y + 1});
	can_move |= enemy_can_move(g, (t_point){pos->x, pos->y - 1});
	return (can_move);
}

void	rage_move(t_game *g, t_entity *enemy)
{
	t_point	tmp;
	t_point	pos;

	tmp = enemy->next;
	pos = enemy->pos;
	if (g->player.pos.x < pos.x)
		enemy->next = (t_point){pos.x - 1, pos.y};
	if (enemy_can_move(g, enemy->next))
		return ;
	if (g->player.pos.y < pos.y)
		enemy->next = (t_point){pos.x, pos.y - 1};
	if (enemy_can_move(g, enemy->next))
		return ;
	if (g->player.pos.x > pos.x)
		enemy->next = (t_point){pos.x + 1, pos.y};
	if (enemy_can_move(g, enemy->next))
		return ;
	if (g->player.pos.y > pos.y)
		enemy->next = (t_point){pos.x, pos.y + 1};
	if (enemy_can_move(g, enemy->next))
		return ;
	enemy->next = tmp;
}

void		change_enemies_strategy(t_game *g, void (*strategy)(), t_status status)
{
	unsigned int	i;

	i = -1;
	g->enemy_strategy = strategy;
	g->enemy_status = status;
	if (status == ENRAGED)
		while (++i < g->map->num_enemies)
			g->enemies[i].move_freq = g->enemies[i].move_freq / 2;
}

void	normal_move(t_game *g, t_entity *enemy)
{
	int	offset;

	while (1)
	{
		offset = 1 - (rand() % 3);
		if (rand() % 2)
			enemy->next = (t_point){enemy->pos.x + offset, enemy->pos.y};
		else
			enemy->next = (t_point){enemy->pos.x, enemy->pos.y + offset};
		if (enemy_can_move(g, enemy->next))
			break ;
	}
}

void	move_enemies(t_game *g)
{
	unsigned int	i;

	i = -1;
	while (++i < g->map->num_enemies)
	{
		if (++g->enemies[i].move_counter % g->enemies[i].move_freq != 0)
			continue ;
		if (!enemy_has_possible_moves(g, &g->enemies[i].pos))
			continue ;
		(*g->enemy_strategy)(g, &g->enemies[i]);
		if (at(g, g->enemies[i].next) == PLAYER)
		{
			ft_putstr_fd("Game over.\n", STDOUT_FILENO);
			quit(g);
		}
		set(g, g->enemies[i].pos, FLOOR);
		render(g, &g->floor_sp, g->enemies[i].pos, 0);
		set(g, g->enemies[i].next, ENEMY);
		g->enemies[i].pos = g->enemies[i].next;
	}
}
