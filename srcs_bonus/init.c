/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/12 12:05:14 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	g->sp = malloc(NUM_SPRITES_BONUS * sizeof(t_sprite));
	if (!g->sp)
		message(g, "Failed allocation on sprites array\n");
	g->sp[W1].img = mlx_xpm_file_to_image(g->disp.mlx, FW1,
			&(g->sp[W1].width), &(g->sp[W1].height));
	g->sp[W2].img = mlx_xpm_file_to_image(g->disp.mlx, FW2,
			&(g->sp[W2].width), &(g->sp[W2].height));
	g->sp[W3].img = mlx_xpm_file_to_image(g->disp.mlx, FW3,
			&(g->sp[W3].width), &(g->sp[W3].height));
	g->sp[W4].img = mlx_xpm_file_to_image(g->disp.mlx, FW4,
			&(g->sp[W4].width), &(g->sp[W4].height));
	g->sp[W5].img = mlx_xpm_file_to_image(g->disp.mlx, FW5,
			&(g->sp[W5].width), &(g->sp[W5].height));
	g->sp[S1].img = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp[S1].width), &(g->sp[S1].height));
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1,
			&(g->sp[C1].width), &(g->sp[C1].height));
	g->sp[E1].img = mlx_xpm_file_to_image(g->disp.mlx, FE1,
			&(g->sp[E1].width), &(g->sp[E1].height));
	g->sp[P1].img = mlx_xpm_file_to_image(g->disp.mlx, FP1,
			&(g->sp[P1].width), &(g->sp[P1].height));
}
