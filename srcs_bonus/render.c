/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 10:43:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_sprite(t_game *g, t_sprite *s, t_point p, t_point offset)
{
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, s->img, \
		offset.x + p.x * s->width, offset.y + p.y * s->height);
}

void	render_tile(t_game *g, t_point p)
{
	t_sprite	sp;

	if (g->map->bytes[p.y][p.x] == COIN)
		sp = g->sp[C1];
	else if (g->map->bytes[p.y][p.x] == EXIT)
		sp = g->sp[E1];
	else if (g->map->bytes[p.y][p.x] == SPACE)
		sp = g->sp[S1];
	else if (g->map->bytes[p.y][p.x] == PLAYER)
		sp = g->pframes[RIGHT][0];
	else
		return ;
	render_sprite(g, &sp, p, (t_point){-16, 0});
}

void	render_map(t_game *g)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	render_outter_walls(g);
	render_inner_walls(g);
	while (++y < g->map->rows - 1)
	{
		x = 0;
		while (++x < g->map->cols - 1)
			render_tile(g, (t_point){x, y});
	}
}

void	render_counter(t_game *g)
{
	char	*str;
	int		x;
	int		y;

	x = (g->map->cols - 1) * 16;
	y = g->map->rows * 32 + 20;
	str = ft_itoa(++g->moves);
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, g->disp.img, x, y - 20);
	mlx_string_put(g->disp.mlx, g->disp.win, x, y, 0xFFFFFF, str);
	free(str);
}

void	animate_player(t_game *g)
{
	static int	calls = 0;
	static int	freq = 0;
	int			next;

	if (!(++calls % CALLS))
	{
		if (!(++freq % CALLS_PER_FRAME))
			++g->player_frame;
		next = g->player_frame % NUM_PLAYER_FRAMES;
		render_sprite(g, &g->sp[S1], g->curr, (t_point){-16, 0});
		render_sprite(g, &g->pframes[g->player_dir][next], \
			g->curr, (t_point){-16, 0});
	}
}

int	render_frame(t_game *g)
{
	animate_player(g);
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
