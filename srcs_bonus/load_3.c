/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:45:10 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 04:54:41 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_frames_2(t_game *g)
{
	g->eframes[LEFT].img = malloc(NUM_PLAYER_FRAMES * sizeof(t_sprite));
	if (!g->eframes[LEFT].img)
		message(g, "Failed allocation on left player frames\n");
	g->eframes[LEFT].img[0] = mlx_xpm_file_to_image(g->disp.mlx, FP8,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[1] = mlx_xpm_file_to_image(g->disp.mlx, FP9,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[2] = mlx_xpm_file_to_image(g->disp.mlx, FP10,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[3] = mlx_xpm_file_to_image(g->disp.mlx, FP11,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[4] = mlx_xpm_file_to_image(g->disp.mlx, FP12,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[5] = mlx_xpm_file_to_image(g->disp.mlx, FP13,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[6] = mlx_xpm_file_to_image(g->disp.mlx, FP14,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
}

void	load_enemy_frames(t_game *g)
{
	g->eframes[RIGHT].img = malloc(NUM_PLAYER_FRAMES * sizeof(void *));
	if (!g->eframes[RIGHT].img)
		message(g, "Failed allocation on right player frames\n");
	g->eframes[RIGHT].img[0] = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[1] = mlx_xpm_file_to_image(g->disp.mlx, FP2,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[2] = mlx_xpm_file_to_image(g->disp.mlx, FP3,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[3] = mlx_xpm_file_to_image(g->disp.mlx, FP4,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[4] = mlx_xpm_file_to_image(g->disp.mlx, FP5,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[5] = mlx_xpm_file_to_image(g->disp.mlx, FP6,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[6] = mlx_xpm_file_to_image(g->disp.mlx, FP7,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	load_enemy_frames_2(g);
}

void	load_sprites(t_game *g)
{
	g->sp.img = malloc(NUM_WALLS * sizeof(void *));
	if (!g->sp.img)
		message(g, "Failed allocation on sprites array\n");
	g->pframes = malloc(2 * sizeof(t_sprite));
	if (!g->pframes)
		message(g, "Failed allocation on player frames array\n");
	g->eframes = malloc(2 * sizeof(t_sprite));
	if (!g->eframes)
		message(g, "Failed allocation on enemy frames array\n");
	load_walls(g);
	load_player_frames(g);
	load_enemy_frames(g);
	load_coins_frames(g);
	load_exits(g);
	load_spaces(g);
}
