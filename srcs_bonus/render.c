/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/01 01:10:49 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sprite(t_game *g, t_sprite *s, t_point p)
{
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, s->img, \
		p.x * s->width, p.y * s->height);
}

void	render_outter_walls(t_game *g)
{
	unsigned int	i;
	
	i = 0;
	while (++i < g->map->rows - 1)
	{
		render_sprite(g, &g->sp[W2], (t_point){0, i});
		render_sprite(g, &g->sp[W3], (t_point){g->map->cols - 1, i});
	}
	i = -1;	
	while (++i < g->map->cols)
	{
		render_sprite(g, &g->sp[W1], (t_point){i, 0});
		render_sprite(g, &g->sp[W1], (t_point){i, g->map->rows - 1});
	}	
	render_sprite(g, &g->sp[W4], (t_point){0, 0});
	render_sprite(g, &g->sp[W5], (t_point){g->map->cols - 1, 0});
	// render_sprite(g, &g->sp[W1], (t_point){i, g->map->rows - 1});
	// render_sprite(g, &g->sp[W1], (t_point){i, g->map->rows - 1});
}

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

	y = 0;
	render_outter_walls(g);
	while (++y < g->map->rows - 1)
	{
		x = 0;
		while (++x < g->map->cols - 1)
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
