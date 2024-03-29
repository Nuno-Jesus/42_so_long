/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:48:55 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/04 08:02:58 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate(t_game *g, t_entity *ent, t_sprite *frames, int n)
{
	int	i;
	int	frame_set;

	i = -1;
	while (++i < n)
	{
		if (++ent[i].curr_speed % ent[i].animate_speed != 0)
			continue ;
		if (is_same_point(ent[i].pos, (t_point){-1, -1}))
			continue ;
		if (++ent[i].curr_freq % ent[i].frame_freq == 0)
			ent[i].frame = (ent[i].frame + 1) % frames->nframes;
		render(g, &g->floor_sp.frames[0], ent[i].pos);
		if (ent[i].type == ENEMY)
			frame_set = g->enemy_status;
		else
			frame_set = ent[i].dir;
		render(g, &frames[frame_set].frames[ent[i].frame], ent[i].pos);
	}
}
