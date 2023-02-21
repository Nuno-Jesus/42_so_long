/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 16:57:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_players(t_game *g)
{
	g->player_frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_sprite));
	if (!g->player_frames)
		message(g, "Failed allocation on player frames!\n");
	g->sp[P1].img = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->sp[P1].width), &(g->sp[P1].height));
	g->player_frames[0].img = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->player_frames[0].width), &(g->player_frames[0].height));
	g->player_frames[1].img = mlx_xpm_file_to_image(g->disp.mlx, FP2,
			&(g->player_frames[1].width), &(g->player_frames[1].height));
	g->player_frames[2].img = mlx_xpm_file_to_image(g->disp.mlx, FP3,
			&(g->player_frames[2].width), &(g->player_frames[2].height));
	g->player_frames[3].img = mlx_xpm_file_to_image(g->disp.mlx, FP4,
			&(g->player_frames[3].width), &(g->player_frames[3].height));
	g->player_frames[4].img = mlx_xpm_file_to_image(g->disp.mlx, FP5,
			&(g->player_frames[4].width), &(g->player_frames[4].height));
	g->player_frames[5].img = mlx_xpm_file_to_image(g->disp.mlx, FP6,
			&(g->player_frames[5].width), &(g->player_frames[5].height));
	g->player_frames[6].img = mlx_xpm_file_to_image(g->disp.mlx, FP7,
			&(g->player_frames[6].width), &(g->player_frames[6].height));
}

void	load_coins(t_game *g)
{
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->sp[C1].width), &(g->sp[C1].height));
}

void	load_exits(t_game *g)
{
	g->sp[E1].img = mlx_xpm_file_to_image(g->disp.mlx, FE1,
			&(g->sp[E1].width), &(g->sp[E1].height));
}

void	load_spaces(t_game *g)
{
	g->sp[S1].img = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp[S1].width), &(g->sp[S1].height));
}q