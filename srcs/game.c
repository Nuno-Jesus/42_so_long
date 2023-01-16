/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/16 19:13:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_delete(t_game *game)
{
	if (!game)
		return ;
	if (game->display.img)
		mlx_destroy_image(game->display.mlx, game->display.img);
	if (game->display.win)
		mlx_destroy_window(game->display.mlx, game->display.win);
	if (game->display.mlx)
		mlx_destroy_display(game->display.mlx);
	if (game->map)
		map_delete(game->map);
	free(game->display.mlx);
}
