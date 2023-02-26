/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_wall_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:16:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/26 23:32:57 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	has_diags(int **mat, t_point *p, char *diagonals)
{
	bool	has_diags;

	has_diags = true;
	if (diagonals[0] != NOT_USED)
		has_diags &= (mat[p->y + 1][p->x + 1] == ft_tosymbol(diagonals[0]));
	if (diagonals[1] != NOT_USED)
		has_diags &= (mat[p->y - 1][p->x - 1] == ft_tosymbol(diagonals[1]));
	if (diagonals[2] != NOT_USED)
		has_diags &= (mat[p->y + 1][p->x - 1] == ft_tosymbol(diagonals[2]));
	if (diagonals[3] != NOT_USED)
		has_diags &= (mat[p->y - 1][p->x + 1] == ft_tosymbol(diagonals[3]));
	return (has_diags);
}

bool	bin(t_point *p, int **mat, t_point vals, int op)
{
	if (op == DIFF)
		return ((int)vals.y == (mat[p->y - 1][p->x] - mat[p->y + 1][p->x])
			&& (int)vals.x == (mat[p->y][p->x - 1] - mat[p->y][p->x + 1]));
	else if (op == SUM)
		return ((int)vals.y == (mat[p->y - 1][p->x] + mat[p->y + 1][p->x])
			&& (int)vals.x == (mat[p->y][p->x - 1] + mat[p->y][p->x + 1]));
	else if (op == DIFFSUM)
		return ((int)vals.y == (mat[p->y - 1][p->x] + mat[p->y + 1][p->x])
			&& (int)vals.x == (mat[p->y][p->x - 1] - mat[p->y][p->x + 1]));
	else
		return ((int)vals.y == (mat[p->y - 1][p->x] - mat[p->y + 1][p->x])
			&& (int)vals.x == (mat[p->y][p->x - 1] + mat[p->y][p->x + 1]));
}

void	fill_binary_matrix(t_game *g, int **mat)
{
	t_point	p;

	p.y = -1;
	while (++p.y < g->map->rows)
	{
		p.x = -1;
		while (++p.x < g->map->cols)
			if (at(g, p) == WALL)
				mat[p.y + 1][p.x + 1] = 1;
	}
}

int	**create_binary_matrix(unsigned int y, unsigned int x)
{
	int				**mat;
	unsigned int	i;

	i = -1;
	mat = ft_calloc(y + 1, sizeof(int *));
	if (!mat)
		return (NULL);
	while (++i < y)
	{
		mat[i] = ft_calloc(x + 2, sizeof(int));
		if (!mat[i])
		{
			ft_delete_matrix(mat);
			return (NULL);
		}
	}
	return (mat);
}
