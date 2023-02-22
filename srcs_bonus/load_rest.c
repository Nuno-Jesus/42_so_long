/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 17:29:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_right_player_frames(t_game *g)
{
	g->pframes[RIGHT].img = malloc(NUM_PLAYER_FRAMES * sizeof(void *));
	if (!g->pframes[RIGHT].img)
		message(g, "Failed allocation on right player frames\n");
	g->pframes[RIGHT].img[0] = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
	g->pframes[RIGHT].img[1] = mlx_xpm_file_to_image(g->disp.mlx, FP2,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
	g->pframes[RIGHT].img[2] = mlx_xpm_file_to_image(g->disp.mlx, FP3,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
	g->pframes[RIGHT].img[3] = mlx_xpm_file_to_image(g->disp.mlx, FP4,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
	g->pframes[RIGHT].img[4] = mlx_xpm_file_to_image(g->disp.mlx, FP5,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
	g->pframes[RIGHT].img[5] = mlx_xpm_file_to_image(g->disp.mlx, FP6,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
	g->pframes[RIGHT].img[6] = mlx_xpm_file_to_image(g->disp.mlx, FP7,
			&(g->pframes[RIGHT].width), &(g->pframes[RIGHT].height));
}

void	load_left_player_frames(t_game *g)
{
	g->pframes[LEFT].img = malloc(NUM_PLAYER_FRAMES * sizeof(t_sprite));
	if (!g->pframes[LEFT].img)
		message(g, "Failed allocation on left player frames\n");
	g->pframes[LEFT].img[0] = mlx_xpm_file_to_image(g->disp.mlx, FP8,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
	g->pframes[LEFT].img[1] = mlx_xpm_file_to_image(g->disp.mlx, FP9,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
	g->pframes[LEFT].img[2] = mlx_xpm_file_to_image(g->disp.mlx, FP10,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
	g->pframes[LEFT].img[3] = mlx_xpm_file_to_image(g->disp.mlx, FP11,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
	g->pframes[LEFT].img[4] = mlx_xpm_file_to_image(g->disp.mlx, FP12,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
	g->pframes[LEFT].img[5] = mlx_xpm_file_to_image(g->disp.mlx, FP13,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
	g->pframes[LEFT].img[6] = mlx_xpm_file_to_image(g->disp.mlx, FP14,
			&(g->pframes[LEFT].width), &(g->pframes[LEFT].height));
}

void	load_coins(t_game *g)
{
	g->cframes.img = malloc(NUM_COIN_FRAMES * sizeof(t_sprite));
	if (!g->cframes.img)
		message(g, "Failed allocation on potions frames\n");
	g->cframes.img[0] = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[1] = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[2] = mlx_xpm_file_to_image(g->disp.mlx, FC2,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[3] = mlx_xpm_file_to_image(g->disp.mlx, FC3,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[4] = mlx_xpm_file_to_image(g->disp.mlx, FC4,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[5] = mlx_xpm_file_to_image(g->disp.mlx, FC5,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[6] = mlx_xpm_file_to_image(g->disp.mlx, FC6,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[7] = mlx_xpm_file_to_image(g->disp.mlx, FC7,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[8] = mlx_xpm_file_to_image(g->disp.mlx, FC8,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[9] = mlx_xpm_file_to_image(g->disp.mlx, FC9,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[10] = mlx_xpm_file_to_image(g->disp.mlx, FC10,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[11] = mlx_xpm_file_to_image(g->disp.mlx, FC11,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[12] = mlx_xpm_file_to_image(g->disp.mlx, FC12,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[13] = mlx_xpm_file_to_image(g->disp.mlx, FC13,
			&(g->cframes.width), &(g->cframes.height));
	g->cframes.img[14] = mlx_xpm_file_to_image(g->disp.mlx, FC14,
			&(g->cframes.width), &(g->cframes.height));
}

void	load_exits(t_game *g)
{
	g->sp.img[E1] = mlx_xpm_file_to_image(g->disp.mlx, FE1,
			&(g->sp.width), &(g->sp.height));
}

void	load_spaces(t_game *g)
{
	g->sp.img[S1] = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp.width), &(g->sp.height));
}
