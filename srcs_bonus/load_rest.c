/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 19:29:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_right_player_frames(t_game *g)
{
	g->pframes[RIGHT] = malloc(NUM_PLAYER_FRAMES * sizeof(t_sprite));
	if (!g->pframes[RIGHT])
		message(g, "Failed allocation on right player frames\n");
	g->pframes[RIGHT][0].img = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->pframes[RIGHT][0].width), &(g->pframes[RIGHT][0].height));
	g->pframes[RIGHT][1].img = mlx_xpm_file_to_image(g->disp.mlx, FP2,
			&(g->pframes[RIGHT][1].width), &(g->pframes[RIGHT][1].height));
	g->pframes[RIGHT][2].img = mlx_xpm_file_to_image(g->disp.mlx, FP3,
			&(g->pframes[RIGHT][2].width), &(g->pframes[RIGHT][2].height));
	g->pframes[RIGHT][3].img = mlx_xpm_file_to_image(g->disp.mlx, FP4,
			&(g->pframes[RIGHT][3].width), &(g->pframes[RIGHT][3].height));
	g->pframes[RIGHT][4].img = mlx_xpm_file_to_image(g->disp.mlx, FP5,
			&(g->pframes[RIGHT][4].width), &(g->pframes[RIGHT][4].height));
	g->pframes[RIGHT][5].img = mlx_xpm_file_to_image(g->disp.mlx, FP6,
			&(g->pframes[RIGHT][5].width), &(g->pframes[RIGHT][5].height));
	g->pframes[RIGHT][6].img = mlx_xpm_file_to_image(g->disp.mlx, FP7,
			&(g->pframes[RIGHT][6].width), &(g->pframes[RIGHT][6].height));
}

void	load_left_player_frames(t_game *g)
{
	g->pframes[LEFT] = malloc(NUM_PLAYER_FRAMES * sizeof(t_sprite));
	if (!g->pframes[LEFT])
		message(g, "Failed allocation on left player frames\n");
	g->pframes[LEFT][0].img = mlx_xpm_file_to_image(g->disp.mlx, FP8,
			&(g->pframes[LEFT][0].width), &(g->pframes[LEFT][0].height));
	g->pframes[LEFT][1].img = mlx_xpm_file_to_image(g->disp.mlx, FP9,
			&(g->pframes[LEFT][1].width), &(g->pframes[LEFT][1].height));
	g->pframes[LEFT][2].img = mlx_xpm_file_to_image(g->disp.mlx, FP10,
			&(g->pframes[LEFT][2].width), &(g->pframes[LEFT][2].height));
	g->pframes[LEFT][3].img = mlx_xpm_file_to_image(g->disp.mlx, FP11,
			&(g->pframes[LEFT][3].width), &(g->pframes[LEFT][3].height));
	g->pframes[LEFT][4].img = mlx_xpm_file_to_image(g->disp.mlx, FP12,
			&(g->pframes[LEFT][4].width), &(g->pframes[LEFT][4].height));
	g->pframes[LEFT][5].img = mlx_xpm_file_to_image(g->disp.mlx, FP13,
			&(g->pframes[LEFT][5].width), &(g->pframes[LEFT][5].height));
	g->pframes[LEFT][6].img = mlx_xpm_file_to_image(g->disp.mlx, FP14,
			&(g->pframes[LEFT][6].width), &(g->pframes[LEFT][6].height));
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
}