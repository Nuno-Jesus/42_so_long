/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:04:46 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/26 23:28:12 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_type	at(t_game *g, t_point p)
{
	return (g->map->bytes[p.y][p.x]);
}

void	set(t_game *g, t_point p, t_type type)
{
	g->map->bytes[p.y][p.x] = type;
}

bool	is_same_point(t_point p1, t_point p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

void	ft_delete_matrix(void *matrix)
{	
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (((char **)matrix)[i])
		free(((char **)matrix)[i++]);
	free(matrix);
}

void	message(t_game *game, char *text)
{
	destroy_game(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(text, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_tosymbol(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 0 && c <= 9)
		return (c + '0');
	return (c);
}
