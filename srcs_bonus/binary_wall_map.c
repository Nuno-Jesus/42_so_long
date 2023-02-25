/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_wall_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:16:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/25 15:52:27 by ncarvalh         ###   ########.fr       */
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
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
		{
			if (g->map->bytes[y][x] == WALL)
				mat[y + 1][x + 1] = 1;
		}
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
