/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/18 13:46:27 by crypto           ###   ########.fr       */
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

void graphics_init(t_game *g)
{
	g->display.mlx = mlx_init();
	if (!g->display.mlx)
		message(g, "Failed allocation on mlx pointer\n");
	g->display.win = mlx_new_window(g->display.mlx, 32 * g->map->cols, 32 * g->map->rows, "so_long");
	printf("Window size (cols/rows): %u/%u\n", 32 * g->map->cols, 32 * g->map->rows);
	if (!g->display.win)
		message(g, "Failed allocation on window pointer");
}	

void	map_display(t_game *g)
{
	int	width;
	int height;
	
	(void)width;
	(void)height;
	
	void *wall = mlx_xpm_file_to_image(g->display.mlx, "xpm/wall1.xpm", &width, &height);
	if (!wall)
		message(g, "Failed allocation on map tile");
	printf("Map size (cols/rows): %u/%u\n", g->map->cols, g->map->rows);
	for (unsigned int y = 0; y < g->map->rows; y++)
	{
		for (unsigned int x = 0; x < g->map->cols; x++)
		{			
			if (g->map->bytes[y][x] == WALL)
				mlx_put_image_to_window(g->display.mlx, g->display.win, wall, x * 32, y * 32);
		}		
	}
	mlx_destroy_image(g->display.mlx, wall);
}
	
void game_init(char *filename)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	map_read(&game, filename);
	map_validate(&game);
	map_print(game.map);
	graphics_init(&game);
	map_display(&game);
	mlx_key_hook(game.display.win, handler, &game);
	mlx_hook(game.display.win, CLOSE_WINDOW, 0, quit, &game);
	mlx_loop(game.display.mlx);
}

int	main(int argc, char **argv)
{	
	if (argc - 1 != 1)
		message(NULL, "Invalid number of parameters.\n");
	if (!is_valid(argv[1]))
		message(NULL, "Filename must end in \".ber\".\n");
	game_init(argv[1]);	
}
