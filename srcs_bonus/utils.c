/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:04:46 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/17 21:39:33 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_entity	at(t_game *g, t_point p)
{
	return (g->map->bytes[p.y][p.x]);
}

bool	is_same_point(t_point p1, t_point p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

void	matrix_delete(char **matrix)
{	
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	message(t_game *game, char *text)
{
	destroy_game(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(text, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/* 
void	print_point(t_point *point)
{
	printf("%d/%d\n", point->x, point->y);
}
*/