/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 19:12:30 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_game *g, t_sprite *s, t_point p, int frame)
{
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, s->img[frame], \
		p.x * s->width + XOFFSET, p.y * s->height);
}

void	render_tile(t_game *g, t_point p)
{
	t_sprite	*sp;
	int			frame;

	sp = &g->sp;
	frame = 0;
	if (g->map->bytes[p.y][p.x] == EXIT)
		frame = E1;
	else if (g->map->bytes[p.y][p.x] == SPACE)
		frame = S1;
	else if (g->map->bytes[p.y][p.x] == PLAYER)
		sp = &g->pframes[RIGHT];
	else if (g->map->bytes[p.y][p.x] == COIN)
		sp = &g->cframes;
	else if (g->map->bytes[p.y][p.x] == ENEMY)
		sp = &g->eframes[RIGHT];
	else
		return ;
	render(g, sp, p, frame);
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
	char	*str2;
	t_point	p;

	p.x = (g->map->cols - 1) * 16;
	p.y = g->map->rows * 32 + 20;
	str = ft_itoa(g->moves);
	str2 = ft_itoa(++g->moves);
	mlx_string_put(g->disp.mlx, g->disp.win, p.x, p.y, 0x000000, str);
	mlx_string_put(g->disp.mlx, g->disp.win, p.x, p.y, 0xFFFFFF, str2);
	free(str);
	free(str2);
}

int	render_frame(t_game *g)
{
	animate(g, &g->player, g->pframes, 1);
	animate(g, g->enemies, g->eframes, g->map->num_enemies);
	animate(g, g->coins, &g->cframes, g->map->num_coins);
	move_enemies(g);
	if (can_player_move(g, &g->player))
	{
		render_counter(g);
		player_controller(g);
		move_player(g);
	}
	return (0);
}
