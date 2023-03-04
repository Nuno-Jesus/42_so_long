/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:13:49 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/04 06:46:50 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


unsigned int	get_pixel(t_img *img, t_point p)
{	
	return (*(unsigned int *)(img->addr + (p.y * img->line_len + p.x * (img->bpp / 8))));
}

void	my_pixel_put(t_img *img, t_point p, int color)
{
	char	*dst;
	
	dst = img->addr + (p.y * img->line_len + p.x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_img_to_img(t_img *src, t_img *dst, t_point start)
{
	t_point	p;

	p = (t_point){-1, -1};
	while (++p.y < 32)
	{
		p.x = -1;
		while (++p.x < 32)
		{
			my_pixel_put(dst, (t_point){start.x + p.x, start.y + p.y}, get_pixel(src, p));
		}
	}
}

void	init_background (t_game *g)
{
	t_point	p;
	t_point	pix;
	int		**mat;

	p = (t_point){-1, -1};
	mat = ft_new_matrix(g->map->rows + 2, g->map->cols + 2, sizeof(int));
	fill_bin_matrix(g, mat);
	binary_map_print(g, mat);
	g->background = new_image(g, (t_point){g->disp.dims.x + 32, g->disp.dims.y + 32});
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->cols)
		{
			pix = (t_point){p.x * 32, p.y * 32};
			#ifdef DEBUG
				printf("p.x: %d, p.y: %d, pix.x: %d, pix.y: %d\n", p.x, p.y, pix.x, pix.y);
			#endif
			if(at (g, p) == WALL)
			{
				int n = pick_wall_sprite((t_point){p.x + 1, p.y + 1}, mat);
				put_img_to_img(&g->walls_sp.frames[n], &g->background, pix);
			}
			else
				put_img_to_img(&g->floor_sp.frames[0], &g->background, pix);
		}
	}
	destroy_matrix(mat, g->map->rows + 2);
}

void	init_game(char *filename)
{
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	ft_bzero(&g.player, sizeof(t_entity));
	read_map(&g, filename);
	validate_map(&g);
	init_graphics(&g);
	init_player(&g);
	init_enemies(&g);
	init_coins(&g);
	load_sprites(&g);
	init_background(&g);
	// mlx_put_image_to_window(g.disp.mlx, g.disp.win, g.background.img, XOFFSET, 0);
	// sleep(3);
	// quit(&g);
	render_map(&g);
	mlx_hook(g.disp.win, ON_KEYPRESS, KEYPRESS_MASK, move_handler, &g);
	mlx_hook(g.disp.win, ON_CLOSE, CLOSE_MASK, quit, &g);
	mlx_loop_hook(g.disp.mlx, render_frame, &g);
	mlx_loop(g.disp.mlx);
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
	g->disp.dims = (t_point){32 * (g->map->cols - 1), 32 * g->map->rows};
}

void	init_player(t_game *g)
{
	g->player.frame_freq = CALLS_PER_FRAME;
	g->player.animate_speed = ANIMATE_CALLS;
	g->player.type = PLAYER;
}

void	init_enemies(t_game *g)
{
	int		i;
	t_point	p;

	i = 0;
	p = (t_point){-1, -1};
	g->enemies = ft_calloc(g->map->num_enemies, sizeof(t_entity));
	if (!g->enemies)
		message(g, "Failed allocation on coins entity array\n");
	g->enemy_strategy = &random_strategy;
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->cols)
		{
			if (at(g, p) != ENEMY)
				continue ;
			g->enemies[i].frame = rand() % NUM_ENEMY_FRAMES;
			g->enemies[i].frame_freq = CALLS_PER_FRAME;
			g->enemies[i].move_freq = rand () % MOVE_CALLS + MOVE_CALLS;
			g->enemies[i].animate_speed = ANIMATE_CALLS;
			g->enemies[i].type = ENEMY;
			g->enemies[i].pos = p;
			g->enemies[i++].next = p;
		}
	}
}

void	init_coins(t_game *g)
{
	int		i;
	t_point	p;

	i = 0;
	p = (t_point){-1, -1};
	g->coins = ft_calloc(g->map->num_potions, sizeof(t_entity));
	if (!g->coins)
		message(g, "Failed allocation on coins entity array\n");
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->cols)
		{
			if (at(g, p) != POTION)
				continue ;
			g->coins[i].frame = rand() % NUM_COIN_FRAMES;
			g->coins[i].frame_freq = CALLS_PER_FRAME;
			g->coins[i].animate_speed = ANIMATE_CALLS;
			g->coins[i].type = POTION;
			g->coins[i++].pos = p;
		}
	}
}
