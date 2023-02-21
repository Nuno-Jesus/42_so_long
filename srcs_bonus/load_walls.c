/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:29:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 00:36:45 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_walls_1(t_game *g)
{
	g->sp[WALL_U].img = mlx_xpm_file_to_image(g->disp.mlx, FW1,
			&(g->sp[WALL_U].width), &(g->sp[WALL_U].height));
	g->sp[WALL_L].img = mlx_xpm_file_to_image(g->disp.mlx, FW2,
			&(g->sp[WALL_L].width), &(g->sp[WALL_L].height));
	g->sp[WALL_R].img = mlx_xpm_file_to_image(g->disp.mlx, FW3,
			&(g->sp[WALL_R].width), &(g->sp[WALL_R].height));
	g->sp[CORNER_L].img = mlx_xpm_file_to_image(g->disp.mlx, FW4,
			&(g->sp[CORNER_L].width), &(g->sp[CORNER_L].height));
	g->sp[CORNER_R].img = mlx_xpm_file_to_image(g->disp.mlx, FW5,
			&(g->sp[CORNER_R].width), &(g->sp[CORNER_R].height));
	g->sp[WALL_D].img = mlx_xpm_file_to_image(g->disp.mlx, FW6,
			&(g->sp[WALL_D].width), &(g->sp[WALL_D].height));
	g->sp[BARRIER_L].img = mlx_xpm_file_to_image(g->disp.mlx, FW7,
			&(g->sp[BARRIER_L].width), &(g->sp[BARRIER_L].height));
	g->sp[BARRIER_R].img = mlx_xpm_file_to_image(g->disp.mlx, FW8,
			&(g->sp[BARRIER_R].width), &(g->sp[BARRIER_R].height));
	g->sp[PIPE_H].img = mlx_xpm_file_to_image(g->disp.mlx, FW9,
			&(g->sp[PIPE_H].width), &(g->sp[PIPE_H].height));
	g->sp[PIPE_V].img = mlx_xpm_file_to_image(g->disp.mlx, FW10,
			&(g->sp[PIPE_V].width), &(g->sp[PIPE_V].height));
	g->sp[EDGE_U].img = mlx_xpm_file_to_image(g->disp.mlx, FW11,
			&(g->sp[EDGE_U].width), &(g->sp[EDGE_U].height));
}

void	load_walls_2(t_game *g)
{
	g->sp[EDGE_D].img = mlx_xpm_file_to_image(g->disp.mlx, FW12,
			&(g->sp[EDGE_D].width), &(g->sp[EDGE_D].height));
	g->sp[EDGE_L].img = mlx_xpm_file_to_image(g->disp.mlx, FW13,
			&(g->sp[EDGE_L].width), &(g->sp[EDGE_L].height));
	g->sp[EDGE_R].img = mlx_xpm_file_to_image(g->disp.mlx, FW14,
			&(g->sp[EDGE_R].width), &(g->sp[EDGE_R].height));
	g->sp[BOUNDED].img = mlx_xpm_file_to_image(g->disp.mlx, FW15,
			&(g->sp[BOUNDED].width), &(g->sp[BOUNDED].height));
	g->sp[BOUNDLESS].img = mlx_xpm_file_to_image(g->disp.mlx, FW16,
			&(g->sp[BOUNDLESS].width), &(g->sp[BOUNDLESS].height));
	g->sp[CORNER_DL].img = mlx_xpm_file_to_image(g->disp.mlx, FW17,
			&(g->sp[CORNER_DL].width), &(g->sp[CORNER_DL].height));
	g->sp[CORNER_DR].img = mlx_xpm_file_to_image(g->disp.mlx, FW18,
			&(g->sp[CORNER_DR].width), &(g->sp[CORNER_DR].height));
	g->sp[CORNER_UL_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW19,
			&(g->sp[CORNER_UL_2].width), &(g->sp[CORNER_UL_2].height));
	g->sp[CORNER_UR_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW20,
			&(g->sp[CORNER_UR_2].width), &(g->sp[CORNER_UR_2].height));
	g->sp[CORNER_DL_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW21,
			&(g->sp[CORNER_DL_2].width), &(g->sp[CORNER_DL_2].height));
	g->sp[CORNER_DR_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW22,
			&(g->sp[CORNER_DR_2].width), &(g->sp[CORNER_DR_2].height));
}

void	load_walls_3(t_game *g)
{
	g->sp[BOUNDLESS_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW23,
			&(g->sp[BOUNDLESS_2].width), &(g->sp[BOUNDLESS_2].height));
	g->sp[BARRIER_U_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW24,
			&(g->sp[BARRIER_U_2].width), &(g->sp[BARRIER_U_2].height));
	g->sp[BARRIER_D_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW25,
			&(g->sp[BARRIER_D_2].width), &(g->sp[BARRIER_D_2].height));
	g->sp[BARRIER_L_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW26,
			&(g->sp[BARRIER_L_2].width), &(g->sp[BARRIER_L_2].height));
	g->sp[BARRIER_R_2].img = mlx_xpm_file_to_image(g->disp.mlx, FW27,
			&(g->sp[BARRIER_R_2].width), &(g->sp[BARRIER_R_2].height));
	g->sp[CORNER_BDL].img = mlx_xpm_file_to_image(g->disp.mlx, FW28,
			&(g->sp[CORNER_BDL].width), &(g->sp[CORNER_BDL].height));
	g->sp[CORNER_BDR].img = mlx_xpm_file_to_image(g->disp.mlx, FW29,
			&(g->sp[CORNER_BDR].width), &(g->sp[CORNER_BDR].height));
	g->sp[CORNER_BUL].img = mlx_xpm_file_to_image(g->disp.mlx, FW30,
			&(g->sp[CORNER_BUL].width), &(g->sp[CORNER_BUL].height));
	g->sp[CORNER_BUR].img = mlx_xpm_file_to_image(g->disp.mlx, FW31,
			&(g->sp[CORNER_BUR].width), &(g->sp[CORNER_BUR].height));
}

void	load_walls(t_game *g)
{
	load_walls_1(g);
	load_walls_2(g);
	load_walls_3(g);
}