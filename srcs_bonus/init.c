/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/18 12:02:54 by ncarvalh         ###   ########.fr       */
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
	g->sp[W1].img = mlx_xpm_file_to_image(g->disp.mlx, UPPER_WALL,
			&(g->sp[W1].width), &(g->sp[W1].height));
	g->sp[W2].img = mlx_xpm_file_to_image(g->disp.mlx, LEFT_WALL,
			&(g->sp[W2].width), &(g->sp[W2].height));
	g->sp[W3].img = mlx_xpm_file_to_image(g->disp.mlx, RIGHT_WALL,
			&(g->sp[W3].width), &(g->sp[W3].height));
	g->sp[W4].img = mlx_xpm_file_to_image(g->disp.mlx, CORNER_LEFT,
			&(g->sp[W4].width), &(g->sp[W4].height));
	g->sp[W5].img = mlx_xpm_file_to_image(g->disp.mlx, CORNER_RIGHT,
			&(g->sp[W5].width), &(g->sp[W5].height));
	g->sp[W6].img = mlx_xpm_file_to_image(g->disp.mlx, LOWER_WALL,
			&(g->sp[W6].width), &(g->sp[W6].height));
	g->sp[W7].img = mlx_xpm_file_to_image(g->disp.mlx, BARRIER_LEFT,
			&(g->sp[W7].width), &(g->sp[W7].height));
	g->sp[W8].img = mlx_xpm_file_to_image(g->disp.mlx, BARRIER_RIGHT,
			&(g->sp[W8].width), &(g->sp[W8].height));
	g->sp[W9].img = mlx_xpm_file_to_image(g->disp.mlx, PIPE_HORIZONTAL,
			&(g->sp[W9].width), &(g->sp[W9].height));
	g->sp[W10].img = mlx_xpm_file_to_image(g->disp.mlx, PIPE_VERTICAL,
			&(g->sp[W10].width), &(g->sp[W10].height));
	g->sp[W11].img = mlx_xpm_file_to_image(g->disp.mlx, EDGE_UPPER,
			&(g->sp[W11].width), &(g->sp[W11].height));
	g->sp[W12].img = mlx_xpm_file_to_image(g->disp.mlx, EDGE_LOWER,
			&(g->sp[W12].width), &(g->sp[W12].height));
	g->sp[W13].img = mlx_xpm_file_to_image(g->disp.mlx, EDGE_LEFT,
			&(g->sp[W13].width), &(g->sp[W13].height));
	g->sp[W14].img = mlx_xpm_file_to_image(g->disp.mlx, EDGE_RIGHT,
			&(g->sp[W14].width), &(g->sp[W14].height));
	g->sp[W15].img = mlx_xpm_file_to_image(g->disp.mlx, BOUNDED,
			&(g->sp[W15].width), &(g->sp[W15].height));
	g->sp[W16].img = mlx_xpm_file_to_image(g->disp.mlx, BOUNDLESS,
			&(g->sp[W16].width), &(g->sp[W16].height));
	g->sp[W17].img = mlx_xpm_file_to_image(g->disp.mlx, CORNER_LOWER_LEFT,
			&(g->sp[W17].width), &(g->sp[W17].height));
	g->sp[W18].img = mlx_xpm_file_to_image(g->disp.mlx, CORNER_LOWER_RIGHT,
			&(g->sp[W18].width), &(g->sp[W18].height));
	g->sp[S1].img = mlx_xpm_file_to_image(g->disp.mlx, SPACE1,
			&(g->sp[S1].width), &(g->sp[S1].height));
	g->sp[C1].img = mlx_xpm_file_to_image(g->disp.mlx, POTION1,
			&(g->sp[C1].width), &(g->sp[C1].height));
	g->sp[E1].img = mlx_xpm_file_to_image(g->disp.mlx, EXIT1,
			&(g->sp[E1].width), &(g->sp[E1].height));
	g->sp[P1].img = mlx_xpm_file_to_image(g->disp.mlx, PLAYER1,
			&(g->sp[P1].width), &(g->sp[P1].height));
}
