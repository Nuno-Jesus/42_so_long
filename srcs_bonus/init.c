/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/18 12:25:33 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	quit(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
}

int	kb_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit(game);
	else if (keycode == W)
		game->next = (t_point){game->curr.x, game->curr.y - 1};
	else if (keycode == A)
		game->next = (t_point){game->curr.x - 1, game->curr.y};
	else if (keycode == S)
		game->next = (t_point){game->curr.x, game->curr.y + 1};
	else if (keycode == D)
		game->next = (t_point){game->curr.x + 1, game->curr.y};
	return (keycode);
}

void	init_graphics(t_game *g)
{
	g->disp.mlx = mlx_init();
	if (!g->disp.mlx)
		message(g, "Failed allocation on mlx pointer\n");
	g->disp.win = mlx_new_window(g->disp.mlx, 32 * (g->map->cols - 1), \
		32 * g->map->rows + 32, "so_long");
	if (!g->disp.win)
		message(g, "Failed allocation on window pointer\n");
	g->disp.img = mlx_new_image(g->disp.mlx, 8 * g->map->cols, 32);
	if (!g->disp.img)
		message(g, "Failed allocation on mlx image pointer\n");
}

void	init_game(char *filename)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	read_map(&g, filename);
	validate_map(&g);
	init_graphics(&g);
	load_sprites(&g);
	render_map(&g);
	mlx_hook(g.disp.win, ON_KEYPRESS, KEYPRESS_MASK, kb_hook, &g);
	mlx_hook(g.disp.win, ON_CLOSE, CLOSE_MASK, quit, &g);
	mlx_loop_hook(g.disp.mlx, render_frame, &g);
	mlx_loop(g.disp.mlx);
}

void	load_sprites(t_game *g)
{
	g->sp = malloc(NUM_SPRITES * sizeof(t_sprite));
	if (!g->sp)
		message(g, "Failed allocation on sprites array\n");
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
	g->sp[S1].img = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp[S1].width), &(g->sp[S1].height));
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->sp[C1].width), &(g->sp[C1].height));
	g->sp[E1].img = mlx_xpm_file_to_image(g->disp.mlx, FE1,
			&(g->sp[E1].width), &(g->sp[E1].height));
	g->sp[P1].img = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->sp[P1].width), &(g->sp[P1].height));
}
