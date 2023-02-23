/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/23 22:04:26 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_sprite(t_game *g, t_sprite *s, t_point p, int frame)
{
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, s->img[frame], \
		p.x * s->width + XOFFSET, p.y * s->height);
}

void	render_tile(t_game *g, t_point p)
{
	t_sprite	*sp;

	sp = &g->sp;
	if (g->map->bytes[p.y][p.x] == EXIT)
		sp->curr = E1;
	else if (g->map->bytes[p.y][p.x] == SPACE)
		sp->curr = S1;
	else if (g->map->bytes[p.y][p.x] == PLAYER)
	{
		sp = &g->pframes[RIGHT];
		sp->curr = g->player->frame;
	}
	else if (g->map->bytes[p.y][p.x] == COIN)
	{
		sp = &g->cframes;
		sp->curr = g->coins->frame;
	}
	else
		return ;
	render_sprite(g, sp, p, sp->curr);
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

int	render_frame(t_game *g)
{
	animate_player(g);
	animate_coins(g);
	if (!is_valid_movement(g))
		return (0);
	render_counter(g);
	if (at(g, g->next) == COIN)
		g->collected++;
	else if (at(g, g->next) == EXIT && g->collected == g->map->num_coins)
		quit(g);
	move_player(g);
	return (0);
}
