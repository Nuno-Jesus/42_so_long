/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:29:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 22:14:09 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_walls_1(t_game *g)
{
	g->sp.img[WALL_U] = mlx_xpm_file_to_image(g->disp.mlx, FW1,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[WALL_L] = mlx_xpm_file_to_image(g->disp.mlx, FW2,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[WALL_R] = mlx_xpm_file_to_image(g->disp.mlx, FW3,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_L] = mlx_xpm_file_to_image(g->disp.mlx, FW4,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_R] = mlx_xpm_file_to_image(g->disp.mlx, FW5,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[WALL_D] = mlx_xpm_file_to_image(g->disp.mlx, FW6,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BARRIER_L] = mlx_xpm_file_to_image(g->disp.mlx, FW7,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BARRIER_R] = mlx_xpm_file_to_image(g->disp.mlx, FW8,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[PIPE_H] = mlx_xpm_file_to_image(g->disp.mlx, FW9,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[PIPE_V] = mlx_xpm_file_to_image(g->disp.mlx, FW10,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[EDGE_U] = mlx_xpm_file_to_image(g->disp.mlx, FW11,
			&(g->sp.width), &(g->sp.height));
}

void	load_walls_2(t_game *g)
{
	g->sp.img[EDGE_D] = mlx_xpm_file_to_image(g->disp.mlx, FW12,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[EDGE_L] = mlx_xpm_file_to_image(g->disp.mlx, FW13,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[EDGE_R] = mlx_xpm_file_to_image(g->disp.mlx, FW14,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BOUNDED] = mlx_xpm_file_to_image(g->disp.mlx, FW15,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BOUNDLESS] = mlx_xpm_file_to_image(g->disp.mlx, FW16,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_DL] = mlx_xpm_file_to_image(g->disp.mlx, FW17,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_DR] = mlx_xpm_file_to_image(g->disp.mlx, FW18,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_UL_2] = mlx_xpm_file_to_image(g->disp.mlx, FW19,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_UR_2] = mlx_xpm_file_to_image(g->disp.mlx, FW20,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_DL_2] = mlx_xpm_file_to_image(g->disp.mlx, FW21,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_DR_2] = mlx_xpm_file_to_image(g->disp.mlx, FW22,
			&(g->sp.width), &(g->sp.height));
}

void	load_walls_3(t_game *g)
{
	g->sp.img[BOUNDLESS_2] = mlx_xpm_file_to_image(g->disp.mlx, FW23,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BARRIER_U_2] = mlx_xpm_file_to_image(g->disp.mlx, FW24,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BARRIER_D_2] = mlx_xpm_file_to_image(g->disp.mlx, FW25,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BARRIER_L_2] = mlx_xpm_file_to_image(g->disp.mlx, FW26,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[BARRIER_R_2] = mlx_xpm_file_to_image(g->disp.mlx, FW27,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_BDL] = mlx_xpm_file_to_image(g->disp.mlx, FW28,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_BDR] = mlx_xpm_file_to_image(g->disp.mlx, FW29,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_BUL] = mlx_xpm_file_to_image(g->disp.mlx, FW30,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[CORNER_BUR] = mlx_xpm_file_to_image(g->disp.mlx, FW31,
			&(g->sp.width), &(g->sp.height));
}

void	load_spaces(t_game *g)
{
	g->sp.img[S1] = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp.width), &(g->sp.height));
}

void	load_walls(t_game *g)
{
	load_walls_1(g);
	load_walls_2(g);
	load_walls_3(g);
}
