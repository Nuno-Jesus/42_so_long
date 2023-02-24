/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 04:16:00 by ncarvalh         ###   ########.fr       */
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
			e->next = (t_point){e->pos.x + offset, e->pos.y};
		else
			e->next = (t_point){e->pos.x, e->pos.y + offset};
		if (can_enemy_move(g, e))
			break ;
	}
	// printf("%d %d\n", e->next.x, e->next.y);
	/* else if (at(g, e->next) == PLAYER)
	{
		ft_putstr_fd("Game over.\n", STDOUT_FILENO);
		quit(g);
	} */
}

void	move_enemies(t_game *g)
{
	static int	calls = 0;
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
