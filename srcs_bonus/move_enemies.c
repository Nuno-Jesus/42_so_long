/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:35:13 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/25 20:03:15 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	can_enemy_move(t_game *g, t_point *p)
{
	return (at(g, *p) == SPACE || at(g, *p) == PLAYER);
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


void	rage_move(t_game *g, t_entity *enemy)
{
	t_point	tmp;
	t_point	pos;

	tmp = enemy->next;
	pos = enemy->pos;
	enemy->dir = LEFT;
	if (g->player.pos.x < pos.x)
	{
		enemy->next = (t_point){pos.x - 1, pos.y};
		#ifdef DEBUG
			printf("Moving to %d %d\n", enemy->next.x, enemy->next.y);		
		#endif
	}
	if (can_enemy_move(g, &enemy->next))
		return ;
	if (g->player.pos.x > pos.x)
	{
		enemy->next = (t_point){pos.x + 1, pos.y};
		#ifdef DEBUG
			printf("Moving to %d %d\n", enemy->next.x, enemy->next.y);		
		#endif
	}
	if (can_enemy_move(g, &enemy->next))
		return ;
	if (g->player.pos.y < pos.y)
	{
		enemy->next = (t_point){pos.x, pos.y - 1};
		#ifdef DEBUG
			printf("Moving to %d %d\n", enemy->next.x, enemy->next.y);		
		#endif
	}
	if (can_enemy_move(g, &enemy->next))
		return ;
	if (g->player.pos.y > pos.y)
	{
		enemy->next = (t_point){pos.x, pos.y + 1};
		#ifdef DEBUG
			printf("Moving to %d %d\n", enemy->next.x, enemy->next.y);		
		#endif
	}
	if (can_enemy_move(g, &enemy->next))
		return ;
	enemy->next = tmp;
}

void		change_enemies_strategy(t_game *g, void (*strategy)(), int freq, t_status status)
{
	unsigned int	i;

	i = -1;
	while (++i < g->map->num_enemies)
	{
		g->enemies[i].strategy = strategy;
		g->enemies[i].move_freq = freq;
		g->enemies[i].status = status;
	}
}

void	random_move(t_game *g, t_entity *enemy)
{
	int	offset;

	while (1)
	{
		offset = 1 - (rand() % 3);
		if (rand() % 2)
			enemy->next = (t_point){enemy->pos.x + offset, enemy->pos.y};
		else
			enemy->next = (t_point){enemy->pos.x, enemy->pos.y + offset};
		if (can_enemy_move(g, &enemy->next))
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
		if (!enemy_has_possible_moves(g, &g->enemies[i]))
			continue ;
		(*g->enemies[i].strategy)(g, &g->enemies[i]);
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
