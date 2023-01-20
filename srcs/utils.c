/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:04:46 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 14:33:59 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game_delete(game);
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd(text, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}
