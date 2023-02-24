/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:45:10 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 06:03:34 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_frames_2(t_game *g)
{
	g->eframes[LEFT].img = malloc(NUM_ENEMY_FRAMES * sizeof(void *));
	if (!g->eframes[LEFT].img)
		message(g, "Failed allocation on left enemy frames\n");
	g->eframes[LEFT].nframes = NUM_ENEMY_FRAMES;
	g->eframes[LEFT].img[0] = mlx_xpm_file_to_image(g->disp.mlx, FM1,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[1] = mlx_xpm_file_to_image(g->disp.mlx, FM2,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[2] = mlx_xpm_file_to_image(g->disp.mlx, FM3,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
	g->eframes[LEFT].img[3] = mlx_xpm_file_to_image(g->disp.mlx, FM4,
			&(g->eframes[LEFT].width), &(g->eframes[LEFT].height));
}

void	load_enemy_frames(t_game *g)
{
	g->eframes[RIGHT].img = malloc(NUM_ENEMY_FRAMES * sizeof(void *));
	if (!g->eframes[RIGHT].img)
		message(g, "Failed allocation on right enemy frames\n");
	g->eframes[RIGHT].nframes = NUM_ENEMY_FRAMES;
	g->eframes[RIGHT].img[0] = mlx_xpm_file_to_image(g->disp.mlx, FM5,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[1] = mlx_xpm_file_to_image(g->disp.mlx, FM6,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[2] = mlx_xpm_file_to_image(g->disp.mlx, FM7,
			&(g->eframes[RIGHT].width), &(g->eframes[RIGHT].height));
	g->eframes[RIGHT].img[3] = mlx_xpm_file_to_image(g->disp.mlx, FM8,
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
