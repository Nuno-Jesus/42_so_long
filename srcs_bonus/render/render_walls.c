/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:14:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/04 08:05:03 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_wall	pick_wall_sprite_3(t_point *p, int **mat)
{
	if (sides(mat, p, "1101"))
		return (WALL_D);
	if (sides(mat, p, "1011"))
		return (BARRIER_L);
	if (sides(mat, p, "1110"))
		return (BARRIER_R);
	if (sides(mat, p, "0101"))
		return (PIPE_H);
	if (sides(mat, p, "1010"))
		return (PIPE_V);
	if (sides(mat, p, "0000"))
		return (BOUNDED);
	if (sides(mat, p, "1111") && diags(mat, p, "0000"))
		return (BOUNDLESS_2);
	if (sides(mat, p, "1111"))
		return (BOUNDLESS);
	return (WALL_U);
}

t_wall	pick_wall_sprite_2(t_point *p, int **mat)
{
	if (sides(mat, p, "1111") && diags(mat, p, "1011"))
		return (CORNER_BUL);
	if (sides(mat, p, "1111") && diags(mat, p, "1110"))
		return (CORNER_BUR);
	if (sides(mat, p, "1111") && diags(mat, p, "1101"))
		return (CORNER_BDL);
	if (sides(mat, p, "1111") && diags(mat, p, "0111"))
		return (CORNER_BDR);
	if (sides(mat, p, "1011") && diags(mat, p, "0NN0"))
		return (BARRIER_L_2);
	if (sides(mat, p, "1110") && diags(mat, p, "N00N"))
		return (BARRIER_R_2);
	if (sides(mat, p, "0111") && diags(mat, p, "0N0N"))
		return (BARRIER_U_2);
	if (sides(mat, p, "1101") && diags(mat, p, "N0N0"))
		return (BARRIER_D_2);
	if (sides(mat, p, "0011"))
		return (CORNER_L);
	if (sides(mat, p, "0110"))
		return (CORNER_R);
	return (pick_wall_sprite_3(p, mat));
}

t_wall	pick_wall_sprite(t_point p, int **mat)
{
	if (sides(mat, &p, "1001") && diags(mat, &p, "NNN1"))
		return (CORNER_DL);
	if (sides(mat, &p, "1100") && diags(mat, &p, "N1NN"))
		return (CORNER_DR);
	if (sides(mat, &p, "0011") && diags(mat, &p, "0NNN"))
		return (CORNER_UL_2);
	if (sides(mat, &p, "0110") && diags(mat, &p, "NN0N"))
		return (CORNER_UR_2);
	if (sides(mat, &p, "1001") && diags(mat, &p, "NNN0"))
		return (CORNER_DL_2);
	if (sides(mat, &p, "1100") && diags(mat, &p, "N0NN"))
		return (CORNER_DR_2);
	if (sides(mat, &p, "0010"))
		return (EDGE_U);
	if (sides(mat, &p, "1000"))
		return (EDGE_D);
	if (sides(mat, &p, "0001"))
		return (EDGE_L);
	if (sides(mat, &p, "0100"))
		return (EDGE_R);
	return (pick_wall_sprite_2(&p, mat));
}

void	render_inner_walls(t_game *g)
{
	int		**mat;
	int		frame;
	t_point	p;

	mat = ft_new_matrix(g->map->rows + 2, g->map->cols + 2, sizeof(int));
	fill_bin_matrix(g, mat);
	p.y = 0;
	while (++p.y < g->map->rows - 1)
	{
		p.x = 0;
		while (++p.x < g->map->cols - 1)
		{
			if (at(g, p) != WALL)
				continue ;
			frame = pick_wall_sprite((t_point){p.x + 1, p.y + 1}, mat);
			render(g, &g->walls_sp.frames[frame], p);
		}
	}
	destroy_matrix(mat, g->map->rows + 2);
}

void	render_outter_walls(t_game *g)
{
	unsigned int	i;

	i = 0;
	while (++i < g->map->cols - 1)
		render(g, &g->walls_sp.frames[WALL_U], (t_point){i, 0});
	i = -1;
	while (++i < g->map->cols)
		render(g, &g->walls_sp.frames[WALL_U], (t_point){i, g->map->rows - 1});
	i = -1;
	while (++i < g->map->rows - 1)
	{
		render(g, &g->walls_sp.frames[WALL_L], (t_point){0, i});
		render(g, &g->walls_sp.frames[WALL_R], (t_point){g->map->cols - 1, i});
	}
}
