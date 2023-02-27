/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:04:46 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 23:22:25 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_same_point(t_point p1, t_point p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	message(t_game *game, char *text)
{
	destroy_game(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(text, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_tochar(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	return (c);
}

int	ft_tonum(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	return (c);
}
