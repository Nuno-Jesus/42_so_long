/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 14:18:14 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(t_game *game)
{
	game_delete(game);
	exit(EXIT_SUCCESS);	
}

int	handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit(game);
	return (keycode);
}

void	init_graphics(t_game *g)
{
	g->disp.mlx = mlx_init();
	if (!g->disp.mlx)
		message(g, "Failed allocation on mlx pointer\n");
	g->disp.win = mlx_new_window(g->disp.mlx, 32 * g->map->cols, 32 * g->map->rows, "so_long");
	if (!g->disp.win)
		message(g, "Failed allocation on window pointer");
}

void	game_init(char *filename)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, filename);
	validate_map(&game);
	init_graphics(&game);
	load_sprites(&game);
	render_map(&game);
	mlx_key_hook(game.disp.win, handler, &game);
	mlx_hook(game.disp.win, CLOSE_WINDOW, 0, quit, &game);
	mlx_loop(game.disp.mlx);
}

void	load_sprites(t_game *g)
{
	g->sp = malloc(NUM_SPRITES * sizeof(t_sprite));
	if (!g->sp)
		message(g, "Failed allocation on sprites array\n");
	g->sp[W1].img = mlx_xpm_file_to_image(g->disp.mlx, FW1, &(g->sp[W1].width), &(g->sp[W1].height));
	g->sp[S1].img = mlx_xpm_file_to_image(g->disp.mlx, FS1, &(g->sp[S1].width), &(g->sp[S1].height));
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, FC1, &(g->sp[C1].width), &(g->sp[C1].height));
	g->sp[E1].img = mlx_xpm_file_to_image(g->disp.mlx, FE1, &(g->sp[E1].width), &(g->sp[E1].height));
	g->sp[P1].img = mlx_xpm_file_to_image(g->disp.mlx, FP1, &(g->sp[P1].width), &(g->sp[P1].height));
}
