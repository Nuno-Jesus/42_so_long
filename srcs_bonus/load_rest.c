/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 11:53:50 by ncarvalh         ###   ########.fr       */
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
	g->cframes = malloc(NUM_COIN_FRAMES * sizeof(t_sprite));
	if (!g->cframes)
		message(g, "Failed allocation on potions frames\n");
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->sp[C1].width), &(g->sp[C1].height));
	g->cframes[0].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->cframes[0].width), &(g->cframes[0].height));
	g->cframes[1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->cframes[1].width), &(g->cframes[1].height));
	g->cframes[2].img = mlx_xpm_file_to_image(g->disp.mlx, FC2,
			&(g->cframes[2].width), &(g->cframes[2].height));
	g->cframes[3].img = mlx_xpm_file_to_image(g->disp.mlx, FC3,
			&(g->cframes[3].width), &(g->cframes[3].height));
	g->cframes[4].img = mlx_xpm_file_to_image(g->disp.mlx, FC4,
			&(g->cframes[4].width), &(g->cframes[4].height));
	g->cframes[5].img = mlx_xpm_file_to_image(g->disp.mlx, FC5,
			&(g->cframes[5].width), &(g->cframes[5].height));
	g->cframes[6].img = mlx_xpm_file_to_image(g->disp.mlx, FC6,
			&(g->cframes[6].width), &(g->cframes[6].height));
	g->cframes[7].img = mlx_xpm_file_to_image(g->disp.mlx, FC7,
			&(g->cframes[7].width), &(g->cframes[7].height));
	g->cframes[8].img = mlx_xpm_file_to_image(g->disp.mlx, FC8,
			&(g->cframes[8].width), &(g->cframes[8].height));
	g->cframes[9].img = mlx_xpm_file_to_image(g->disp.mlx, FC9,
			&(g->cframes[9].width), &(g->cframes[9].height));
	g->cframes[10].img = mlx_xpm_file_to_image(g->disp.mlx, FC10,
			&(g->cframes[10].width), &(g->cframes[10].height));
	g->cframes[11].img = mlx_xpm_file_to_image(g->disp.mlx, FC11,
			&(g->cframes[11].width), &(g->cframes[11].height));
	g->cframes[12].img = mlx_xpm_file_to_image(g->disp.mlx, FC12,
			&(g->cframes[12].width), &(g->cframes[12].height));
	g->cframes[13].img = mlx_xpm_file_to_image(g->disp.mlx, FC13,
			&(g->cframes[13].width), &(g->cframes[13].height));
	g->cframes[14].img = mlx_xpm_file_to_image(g->disp.mlx, FC14,
			&(g->cframes[14].width), &(g->cframes[14].height));
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
