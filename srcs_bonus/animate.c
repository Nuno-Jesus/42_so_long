/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:48:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 22:16:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_player(t_game *g)
{
	static int	calls = 0;
	static int	freq = 0;

	if (++calls % CALLS != 0)
		return ;
	if (++freq % CALLS_PER_FRAME == 0)
		g->player->current_frame = \
			++(g->player->current_frame) % NUM_PLAYER_FRAMES;
	render_sprite(g, &g->sp, g->curr, S1);
	render_sprite(g, &g->pframes[g->player_dir], \
		g->curr, g->player->current_frame);
}

void	animate_coins(t_game *g)
{
	static int		calls = 0;
	static int		freq = 0;
	unsigned int	i;

	i = -1;
	if (++calls % CALLS != 0)
		return ;
	if (++freq % CALLS_PER_FRAME != 0)
		return ;
	while (++i < g->map->num_coins)
	{
		if (is_same_point(g->coins[i].pos, (t_point){-1, -1}))
			continue ;
		g->coins[i].current_frame = \
			++g->coins[i].current_frame % NUM_COIN_FRAMES;
		render_sprite(g, &g->sp, g->coins[i].pos, S1);
		render_sprite(g, &g->cframes, \
			g->coins[i].pos, g->coins[i].current_frame);
	}			
}
