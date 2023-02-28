/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:14:15 by crypto            #+#    #+#             */
/*   Updated: 2023/02/28 19:39:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_strategy(t_game *g, void (*strategy)(), t_status status)
{
	unsigned int	i;

	i = -1;
	g->enemy_strategy = strategy;
	g->enemy_status = status;
	if (status == ENRAGED)
		while (++i < g->map->num_enemies)
			g->enemies[i].move_freq = g->enemies[i].move_freq / 2;
}

void	chase_strategy(t_game *g, t_entity *enemy)
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

void	random_strategy(t_game *g, t_entity *enemy)
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
