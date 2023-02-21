/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 19:37:22 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	if (game->sp)
		destroy_sprites(game);
	if (game->disp.img)
		mlx_destroy_image(game->disp.mlx, game->disp.img);
	if (game->disp.win)
		mlx_destroy_window(game->disp.mlx, game->disp.win);
	if (game->disp.mlx)
		mlx_destroy_display(game->disp.mlx);
	if (game->map)
		destroy_map(game->map);
	free(game->disp.mlx);
}

void	destroy_sprites(t_game *g)
{
	int	i;
	int k;

	i = 0;
	while (i < NUM_WALLS)
		mlx_destroy_image(g->disp.mlx, g->sp[i++].img);
	k = -1;
	while(++k < DIRECTIONS)
	{
		i = 0;
		while (i < NUM_PLAYER_FRAMES)
			mlx_destroy_image(g->disp.mlx, g->pframes[k][i++].img);
		free(g->pframes[k]);	
	}
	free(g->pframes);
	free(g->sp);
}

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	ft_delete_matrix(map->bytes);
	free(map);
}
