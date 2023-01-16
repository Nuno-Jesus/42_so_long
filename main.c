/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/16 18:52:04 by ncarvalh         ###   ########.fr       */
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
	return (keycode);
}

int	main(void)
{
	t_game	g;

	g.map = NULL;
	g.display.mlx = mlx_init();
	g.display.win = mlx_new_window(g.display.mlx, 512, 512, "Hello world!");
	g.display.img = mlx_new_image(g.display.mlx, 512, 512);
	g.display.addr = mlx_get_data_addr(g.display.img, &(g.display.bpp), &(g.display.line_length), &(g.display.endian));
	my_mlx_pixel_put(&(g.display), 5, 5, 0xFF0000);
	mlx_put_image_to_window(g.display.mlx, g.display.win, g.display.img, 0, 0);
	mlx_key_hook(g.display.win, handler, &g);
	mlx_loop(g.display.mlx);
}
