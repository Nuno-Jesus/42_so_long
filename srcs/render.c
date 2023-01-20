/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 21:01:29 by ncarvalh         ###   ########.fr       */
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

int	render_frame(t_game *g)
{
	if (!is_valid_movement(g))
		return (0);
	ft_putstr_fd("Number of movements: ", STDOUT_FILENO);
	ft_putnbr_fd(++g->moves, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (at(g, g->next) == COIN)
		g->coins++;
	else if (at(g, g->next) == EXIT && g->coins == g->map->num_coins)
		quit(g);
	move_player(g);
	return (0);
}
