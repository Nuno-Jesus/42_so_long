/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:48:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 07:11:52 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate(t_game *g, t_entity *ent, t_sprite *frames, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (++ent[i].curr_speed % ent[i].speed != 0)
			continue ;
		if (is_same_point(ent[i].pos, (t_point){-1, -1}))
			continue ;
		if (++ent[i].freq % ent[i].frame_freq == 0)
			ent[i].frame = (ent[i].frame + 1) % frames->nframes;
		render(g, &g->sp, ent[i].pos, S1);
		render(g, &frames[ent[i].dir], ent[i].pos, ent[i].frame);
	}
}
/* 
void	animate_player(t_game *g)
{
	static int	calls = 0;
	static int	freq = 0;

	if (++calls % ANIMATE_CALLS != 0)
		return ;
	if (++freq % CALLS_PER_FRAME == 0)
		g->player.frame = \
			(g->player.frame + 1) % g->pframes[g->player.dir].nframes;
	render(g, &g->sp, g->player.pos, S1);
	render(g, &g->pframes[g->player.dir], \
		g->player.pos, g->player.frame);
}


void	animate_coins(t_game *g)
{
	static int		calls = 0;
	static int		freq = 0;
	unsigned int	i;

	i = -1;
	if (++calls % ANIMATE_CALLS != 0)
		return ;
	if (++freq % CALLS_PER_FRAME != 0)
		return ;
	while (++i < g->map->num_coins)
	{
		if (is_same_point(g->coins[i].pos, (t_point){-1, -1}))
			continue ;
		g->coins[i].frame = \
			(g->coins[i].frame + 1) % g->cframes.nframes;
		render(g, &g->sp, g->coins[i].pos, S1);
		render(g, &g->cframes, \
			g->coins[i].pos, g->coins[i].frame);
	}			
}

void	animate_enemies(t_game *g)
{
	static int		calls = 0;
	static int		freq = 0;
	unsigned int	i;

	i = -1;
	if (++calls % 500 != 0)
		return ;
	if (++freq % CALLS_PER_FRAME != 0)
		return ;
	while (++i < g->map->num_enemies)
	{
		if (is_same_point(g->enemies[i].pos, (t_point){-1, -1}))
			continue ;
		g->enemies[i].frame = \
			(g->enemies[i].frame + 1) % g->eframes[g->enemies[i].dir].nframes;
		render(g, &g->sp, g->enemies[i].pos, S1);
		render(g, &g->eframes[g->enemies[i].dir], \
			g->enemies[i].pos, g->enemies[i].frame);
	}
}
 */