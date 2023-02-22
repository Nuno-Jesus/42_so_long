/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/22 22:25:38 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit(game);
	else if (keycode == W)
		game->next = (t_point){game->curr.x, game->curr.y - 1};
	else if (keycode == A)
	{
		game->next = (t_point){game->curr.x - 1, game->curr.y};
		game->player_dir = LEFT;
	}
	else if (keycode == S)
		game->next = (t_point){game->curr.x, game->curr.y + 1};
	else if (keycode == D)
	{
		game->next = (t_point){game->curr.x + 1, game->curr.y};
		game->player_dir = RIGHT;
	}
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
	init_entities(&g);
	load_sprites(&g);
	render_map(&g);
	mlx_hook(g.disp.win, ON_KEYPRESS, KEYPRESS_MASK, move_handler, &g);
	mlx_hook(g.disp.win, ON_CLOSE, CLOSE_MASK, quit, &g);
	mlx_loop_hook(g.disp.mlx, render_frame, &g);
	mlx_loop(g.disp.mlx);
}

void	init_entities(t_game *g)
{
	int		i;
	t_point	p;

	g->coins = malloc(g->map->num_coins * sizeof(t_entity));
	if (!g->coins)
		message(g, "Failed allocation on coins entity array\n");
	g->player = malloc(sizeof(t_entity));
	if (!g->player)
		message(g, "Failed allocation on player entity array\n");
	g->player->pos = g->curr;
	g->player->current_frame = 0;
	i = 0;
	p = (t_point){-1, -1};
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->cols)
		{
			if (at(g, p) == COIN)
			{
				g->coins[i].current_frame = rand() % NUM_COIN_FRAMES;
				g->coins[i++].pos = p;
			}
		}
	}
}

void	load_sprites(t_game *g)
{
	g->sp.img = malloc(NUM_WALLS * sizeof(void *));
	if (!g->sp.img)
		message(g, "Failed allocation on sprites array\n");
	g->pframes = malloc(2 * sizeof(t_sprite));
	if (!g->pframes)
		message(g, "Failed allocation on player frames array\n");
	load_walls(g);
	load_player_frames(g);
	load_coins_frames(g);
	load_exits(g);
	load_spaces(g);
}
