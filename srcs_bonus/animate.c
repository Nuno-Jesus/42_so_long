/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:48:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 12:14:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_player(t_game *g)
{
	static int	calls = 0;
	static int	freq = 0;
	int			next;

	if (!(++calls % CALLS))
	{
		if (!(++freq % CALLS_PER_FRAME))
			++g->player_frame;
		next = g->player_frame % NUM_PLAYER_FRAMES;
		render_sprite(g, &g->sp[S1], g->curr, (t_point){-16, 0});
		render_sprite(g, &g->pframes[g->player_dir][next], \
			g->curr, (t_point){-16, 0});
	}
}

void	animate_coins(t_game *g)
{
	static int	calls = 0;
	static int	freq = 0;
	int			next;
	unsigned int 		i;

	if (!(++calls % CALLS))
	{
		if (!(++freq % CALLS_PER_FRAME))
			++g->coin_frame;
		next = g->coin_frame % NUM_COIN_FRAMES;
		i = -1;
		while (++i < g->map->num_coins)
		{
			render_sprite(g, &g->sp[S1], g->coins_pos[i], (t_point){-16, 0});
			render_sprite(g, &g->cframes[next], \
				g->coins_pos[i], (t_point){-16, 0});						
		}
	}
}
