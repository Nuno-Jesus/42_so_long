/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 10:24:27 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
}

int	move_handler(int keycode, t_game *game)
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
	g->disp.win = mlx_new_window(g->disp.mlx, 32 * g->map->cols, \
		32 * g->map->rows, "so_long");
	if (!g->disp.win)
		message(g, "Failed allocation on window pointer");
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
	mlx_hook(g.disp.win, ON_KEYPRESS, KEYPRESS_MASK, move_handler, &g);
	mlx_hook(g.disp.win, ON_CLOSE, CLOSE_MASK, quit, &g);
	mlx_loop_hook(g.disp.mlx, render_frame, &g);
	mlx_loop(g.disp.mlx);
}

void	load_sprites(t_game *g)
{
	g->sp = malloc(NUM_SPRITES * sizeof(t_sprite));
	if (!g->sp)
		message(g, "Failed allocation on sprites array\n");
	g->sp[W1].img = mlx_xpm_file_to_image(g->disp.mlx, FW1,
			&(g->sp[W1].width), &(g->sp[W1].height));
	g->sp[S1].img = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp[S1].width), &(g->sp[S1].height));
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->sp[C1].width), &(g->sp[C1].height));
	g->sp[E1].img = mlx_xpm_file_to_image(g->disp.mlx, FE1,
			&(g->sp[E1].width), &(g->sp[E1].height));
	g->sp[P1].img = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->sp[P1].width), &(g->sp[P1].height));
}
