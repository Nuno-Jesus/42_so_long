/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 13:10:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	my_mlx_pixel_put(t_graphics *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int quit(t_game *game)
{
	game_delete(game);
	exit(EXIT_SUCCESS);
}

int handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		quit(game);
	printf("%d\n", keycode);
	return (keycode);
}

bool is_valid(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strnstr(filename + (len - 4), ".ber", 4) != NULL);	
}

void init_graphics(t_game *g)
{
	g->disp.mlx = mlx_init();
	if (!g->disp.mlx)
		message(g, "Failed allocation on mlx pointer\n");
	g->disp.win = mlx_new_window(g->disp.mlx, 32 * g->map->cols, 32 * g->map->rows, "so_long");
	if (!g->disp.win)
		message(g, "Failed allocation on window pointer");
}

void	delete_sprites(t_game *g)
{
	int	i;

	i = 0;
	while (i < NUM_SPRITES)
		mlx_destroy_image(g->disp.mlx, g->sp[i++].img);
	free(g->sp);
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

void	render_tile(t_game *g, int x, int y)
{
	t_sprite sp;
	
	if (g->map->bytes[y][x] == WALL)
		sp = g->sp[W1];
	else if (g->map->bytes[y][x] == COIN)
		sp = g->sp[C1];
	else if (g->map->bytes[y][x] == EXIT)
		sp = g->sp[E1];
	else if (g->map->bytes[y][x] == SPACE)
		sp = g->sp[S1];
	else if (g->map->bytes[y][x] == PLAYER)
		sp = g->sp[P1];
    mlx_put_image_to_window(g->disp.mlx, g->disp.win, sp.img, x * sp.width, y * sp.height);
}

void	render_map(t_game *g)
{		
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
			render_tile(g, x, y);
	}
}
	
void game_init(char *filename)
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

int	main(int argc, char **argv)
{	/* 
	(void)argc;	
	(void)argv;	
	game_init("maps/valid1.ber");	
	 */
	if (argc - 1 != 1)
		message(NULL, "Invalid number of parameters.\n");
	if (!is_valid(argv[1]))
		message(NULL, "Filename must end in \".ber\".\n"); 
	game_init(argv[1]);	
	
}
