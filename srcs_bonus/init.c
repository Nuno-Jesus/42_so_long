/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 00:41:34 by ncarvalh         ###   ########.fr       */
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
	load_walls(g);
	load_players(g);
	load_coins(g);
	load_exits(g);
	load_spaces(g);
}
