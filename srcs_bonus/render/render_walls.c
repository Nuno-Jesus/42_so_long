/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:14:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/28 20:03:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_wall	pick_wall_sprite_3(t_point *p, int **mat)
{
	if (sides(p, mat, (t_point){2, 1}, SUMDIFF))
		return (WALL_D);
	if (sides(p, mat, (t_point){-1, 2}, DIFFSUM))
		return (BARRIER_L);
	if (sides(p, mat, (t_point){1, 2}, DIFFSUM))
		return (BARRIER_R);
	if (sides(p, mat, (t_point){2, 0}, SUM))
		return (PIPE_H);
	if (sides(p, mat, (t_point){0, 2}, SUM))
		return (PIPE_V);
	if (sides(p, mat, (t_point){0, 0}, SUM))
		return (BOUNDED);
	if (sides(p, mat, (t_point){0, 0}, DIFF) && diags(mat, p, "0000"))
		return (BOUNDLESS_2);
	if (sides(p, mat, (t_point){2, 2}, SUM))
		return (BOUNDLESS);
	return (WALL_U);
}

t_wall	pick_wall_sprite_2(t_point *p, int **mat)
{
	if (sides(p, mat, (t_point){0, 0}, DIFF) && diags(mat, p, "1011"))
		return (CORNER_BUL);
	if (sides(p, mat, (t_point){0, 0}, DIFF) && diags(mat, p, "1110"))
		return (CORNER_BUR);
	if (sides(p, mat, (t_point){0, 0}, DIFF) && diags(mat, p, "1101"))
		return (CORNER_BDL);
	if (sides(p, mat, (t_point){0, 0}, DIFF) && diags(mat, p, "0111"))
		return (CORNER_BDR);
	if (sides(p, mat, (t_point){-1, 2}, DIFFSUM) && diags(mat, p, "0NN0"))
		return (BARRIER_L_2);
	if (sides(p, mat, (t_point){1, 2}, DIFFSUM) && diags(mat, p, "N00N"))
		return (BARRIER_R_2);
	if (sides(p, mat, (t_point){0, -1}, DIFF) && diags(mat, p, "0N0N"))
		return (BARRIER_U_2);
	if (sides(p, mat, (t_point){0, 1}, DIFF) && diags(mat, p, "N0N0"))
		return (BARRIER_D_2);
	if (sides(p, mat, (t_point){-1, -1}, DIFF))
		return (CORNER_L);
	if (sides(p, mat, (t_point){1, -1}, DIFF))
		return (CORNER_R);
	return (pick_wall_sprite_3(p, mat));
}

t_wall	pick_wall_sprite(t_point p, int **mat)
{
	if (sides(&p, mat, (t_point){-1, 1}, DIFF) && mat[p.y - 1][p.x + 1])
		return (CORNER_DL);
	if (sides(&p, mat, (t_point){1, 1}, DIFF) && mat[p.y - 1][p.x - 1])
		return (CORNER_DR);
	if (sides(&p, mat, (t_point){-1, -1}, DIFF) && !mat[p.y + 1][p.x + 1])
		return (CORNER_UL_2);
	if (sides(&p, mat, (t_point){1, -1}, DIFF) && !mat[p.y + 1][p.x - 1])
		return (CORNER_UR_2);
	if (sides(&p, mat, (t_point){-1, 1}, DIFF) && !mat[p.y - 1][p.x + 1])
		return (CORNER_DL_2);
	if (sides(&p, mat, (t_point){1, 1}, DIFF) && !mat[p.y - 1][p.x - 1])
		return (CORNER_DR_2);
	if (sides(&p, mat, (t_point){0, -1}, SUMDIFF))
		return (EDGE_U);
	if (sides(&p, mat, (t_point){0, 1}, SUMDIFF))
		return (EDGE_D);
	if (sides(&p, mat, (t_point){-1, 0}, DIFFSUM))
		return (EDGE_L);
	if (sides(&p, mat, (t_point){1, 0}, DIFFSUM))
		return (EDGE_R);
	return (pick_wall_sprite_2(&p, mat));
}

void	render_inner_walls(t_game *g)
{
	int		**mat;
	int		frame;
	t_point	p;

	mat = new_matrix(g->map->rows + 2, g->map->cols + 2);
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
			render(g, &g->walls_sp, p, frame);
		}
	}
	destroy_matrix(mat);
}

void	render_outter_walls(t_game *g)
{
	unsigned int	i;

	i = 0;
	while (++i < g->map->cols - 1)
		render(g, &g->walls_sp, (t_point){i, 0}, WALL_U);
	i = -1;
	while (++i < g->map->cols)
		render(g, &g->walls_sp, (t_point){i, g->map->rows - 1}, WALL_U);
	i = -1;
	while (++i < g->map->rows - 1)
	{
		render(g, &g->walls_sp, (t_point){0, i}, WALL_L);
		render(g, &g->walls_sp, (t_point){g->map->cols - 1, i}, WALL_R);
	}
}
