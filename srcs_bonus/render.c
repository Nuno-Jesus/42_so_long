/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 23:54:49 by crypto           ###   ########.fr       */
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
	if (at(g, p) == EXIT)
		frame = E1;
	else if (at(g, p) == SPACE)
		frame = S1;
	else if (at(g, p) == PLAYER)
		sp = &g->pframes[RIGHT];
	else if (at(g, p) == COIN)
		sp = &g->cframes;
	else if (at(g, p) == ENEMY)
		sp = &g->eframes[RIGHT];
	else
		return ;
	render(g, sp, p, frame);
}

void	render_map(t_game *g)
{
	t_point	p;
	
	render_outter_walls(g);
	render_inner_walls(g);
	p.y = 0;
	while (++p.y < g->map->rows - 1)
	{
		p.x = 0;
		while (++p.x < g->map->cols - 1)
			render_tile(g, p);
	}
}

void	render_counter(t_game *g)
{
	char	*str[2];
	t_point	p;

	p.x = (g->map->cols - 1) * 16;
	p.y = g->map->rows * 32 + 20;
	str[0] = ft_itoa(g->moves);
	str[1] = ft_itoa(++g->moves);
	mlx_string_put(g->disp.mlx, g->disp.win, p.x, p.y, 0x000000, str[0]);
	mlx_string_put(g->disp.mlx, g->disp.win, p.x, p.y, 0xFFFFFF, str[1]);
	free(str[0]);
	free(str[1]);
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
