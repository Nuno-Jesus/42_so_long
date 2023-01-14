/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/14 19:53:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	my_mlx_pixel_put(t_graphic *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int f(int keycode, t_graphic *data)
{
	printf("%d\n", keycode);
		
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (keycode);
}

int	main(void)
{
	t_graphic	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 512, 512, "Hello world!");
	data.img = mlx_new_image(data.mlx, 512, 512);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
	my_mlx_pixel_put(&data, 5, 5, 0xFF0000);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	// Hook to handle resize
	mlx_key_hook(data.win, f, &data);
	mlx_loop(data.mlx);
}
