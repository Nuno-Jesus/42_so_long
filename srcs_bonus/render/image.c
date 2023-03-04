/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 05:13:54 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/04 08:07:21 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/* 
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
 */
t_img	new_image(t_game *g, t_point dims)
{
	t_img	img;

	img.width = dims.x;
	img.height = dims.y;
	img.img = mlx_new_image(g->disp.mlx, dims.x, dims.y);	
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
		&img.line_len, &img.endian);
	return (img);
}

t_img	new_file_image(t_game *g, char *path)
{
	t_img	img;
	
	if (path)
		img.img = mlx_xpm_file_to_image(g->disp.mlx, \
			path, &(img.width), &(img.height));
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
		&img.line_len, &img.endian);
	return (img);
}