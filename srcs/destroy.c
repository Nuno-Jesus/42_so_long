/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 14:24:39 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_delete(t_game *game)
{
	if (!game)
		return ;
	if (game->sp)
		delete_sprites(game);
	if (game->disp.img)
		mlx_destroy_image(game->disp.mlx, game->disp.img);
	if (game->disp.win)
		mlx_destroy_window(game->disp.mlx, game->disp.win);
	if (game->disp.mlx)
		mlx_destroy_display(game->disp.mlx);
	if (game->map)
		map_delete(game->map);
	free(game->disp.mlx);
}

void	delete_sprites(t_game *g)
{
	int	i;

	i = 0;
	while (i < NUM_SPRITES)
		mlx_destroy_image(g->disp.mlx, g->sp[i++].img);
	free(g->sp);
}

void	map_delete(t_map *map)
{
	if (!map)
		return ;
	matrix_delete(map->bytes);
	free(map);
}