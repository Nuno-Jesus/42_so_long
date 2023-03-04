/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:13 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 08:05:59 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_game *g, t_img *img, t_point p)
{
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, img->img, \
		p.x * img->width + XOFFSET, p.y * img->height);
}

void	render_tile(t_game *g, t_point p)
{
	t_img	*img;

	img = &g->walls_sp.frames[0];
	if (at(g, p) == EXIT)
		img = &g->exit_sp.frames[0];
	else if (at(g, p) == FLOOR)
		img = &g->floor_sp.frames[0];
	else if (at(g, p) == PLAYER)
		img = &g->player_sp[RIGHT].frames[0];
	else if (at(g, p) == POTION)
		img = &g->potions_sp.frames[0];
	else if (at(g, p) == ENEMY)
		img = &g->enemy_sp[NORMAL].frames[0];
	else
		return ;
	render(g, img, p);
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
	ft_free(str[0]);
	ft_free(str[1]);
}

int	render_frame(t_game *g)
{
	animate(g, &g->player, g->player_sp, 1);
	animate(g, g->enemies, g->enemy_sp, g->map->num_enemies);
	animate(g, g->coins, &g->potions_sp, g->map->num_potions);
	move_enemies(g);
	if (player_can_move(g, &g->player))
	{
		render_counter(g);
		player_controller(g);
		move_player(g);
	}
	return (0);
}
