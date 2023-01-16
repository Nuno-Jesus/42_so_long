/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/16 19:02:19 by ncarvalh         ###   ########.fr       */
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

bool is_valid(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strnstr(filename + (len - 4), ".ber", 4) != NULL);	
}

int	main(int argc, char **argv)
{
	t_game	g;
	
	if (argc - 1 != 1)
		message(NULL, "Invalid number of parameters.\n");
	if (!is_valid(argv[1]))
		message(NULL, "Filename must end in \".ber\".\n");
	
	g.map = NULL;
	g.display.mlx = mlx_init();
	g.display.win = mlx_new_window(g.display.mlx, 512, 512, "so_long");
	g.display.img = mlx_new_image(g.display.mlx, 512, 512);
	g.display.addr = mlx_get_data_addr(g.display.img, &(g.display.bpp), &(g.display.line_length), &(g.display.endian));
	my_mlx_pixel_put(&g.display, 5, 5, 0xFF0000);
	mlx_put_image_to_window(g.display.mlx, g.display.win, g.display.img, 0, 0);
	mlx_key_hook(g.display.win, handler, &g);
	mlx_loop(g.display.mlx);
}
