/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/17 16:37:47 by ncarvalh         ###   ########.fr       */
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
	g->display.win = mlx_new_window(g->display.mlx, 512, 512, "so_long");
	if (!g->display.win)
		message(g, "Failed allocation on window pointer");
}	
	
void game_init(char *filename)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	map_read(&game, filename);
	map_validate(&game);
	//map_print(game.map);
	graphics_init(&game);
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
