/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:48:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 17:05:33 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_player(t_game *g)
{
	static int	calls = 0;
	static int	freq = 0;

	if (!(++calls % CALLS))
	{
		if (!(++freq % CALLS_PER_FRAME))
		{
			g->pframes[RIGHT].curr = ++(g->pframes[RIGHT].curr) % NUM_PLAYER_FRAMES;
			g->pframes[LEFT].curr = ++(g->pframes[LEFT].curr) % NUM_PLAYER_FRAMES;
		}
		render_sprite(g, &g->sp, g->curr, S1);
		render_sprite(g, &g->pframes[g->player_dir], \
			g->curr, g->pframes[g->player_dir].curr);
	}
}

void	animate_coins(t_game *g)
{
	static int		calls = 0;
	static int		freq = 0;
	unsigned int	i;

	if (!(++calls % CALLS))
	{
		if (!(++freq % CALLS_PER_FRAME))
		{
			i = -1;
			while (++i < g->map->num_coins)
			{
				g->coins[i].current_frame = ++g->coins[i].current_frame % NUM_COIN_FRAMES;
				render_sprite(g, &g->sp, g->coins[i].pos, S1);
				render_sprite(g, &g->cframes, \
					g->coins[i].pos, g->coins[i].current_frame);						
			}			
		}
	}
}
