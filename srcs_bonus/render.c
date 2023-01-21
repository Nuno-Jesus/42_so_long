/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/21 05:57:49 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *g, int x, int y)
{
	t_sprite	sp;

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
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, sp.img, \
		x * sp.width, y * sp.height);
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

void	render_counter(t_game *g)
{
	char	*str;
	int		x;
	int		y;

	x = g->map->cols * 16;
	y = g->map->rows * 32 + 20;

	str = ft_itoa(++g->moves);
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, g->disp.img, x, y - 20);
	mlx_string_put(g->disp.mlx, g->disp.win, x, y, 0xFFFFFF, str);
	free(str);
}

int	render_frame(t_game *g)
{
	if (!is_valid_movement(g))
		return (0);
	render_counter(g);
	if (at(g, g->next) == COIN)
		g->coins++;
	else if (at(g, g->next) == EXIT && g->coins == g->map->num_coins)
		quit(g);
	move_player(g);
	return (0);
}
