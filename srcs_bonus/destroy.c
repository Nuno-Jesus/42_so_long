/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/24 05:31:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	if (game->coins)
		free(game->coins);
	if (game->enemies)
		free(game->enemies);
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
	int	k;

	i = 0;
	while (i < NUM_WALLS)
		mlx_destroy_image(g->disp.mlx, g->sp.img[i++]);
	free(g->sp.img);
	i = 0;
	while (i < NUM_COIN_FRAMES)
		mlx_destroy_image(g->disp.mlx, g->cframes.img[i++]);
	free(g->cframes.img);
	k = -1;
	while (++k < DIRECTIONS)
	{
		i = -1;
		while (++i < NUM_PLAYER_FRAMES)
			mlx_destroy_image(g->disp.mlx, g->pframes[k].img[i]);
		free(g->pframes[k].img);
		i = -1;
		while (++i < NUM_ENEMY_FRAMES)
			mlx_destroy_image(g->disp.mlx, g->eframes[k].img[i]);
		free(g->eframes[k].img);
	}
	free(g->eframes);
	free(g->pframes);
}

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	ft_delete_matrix(map->bytes);
	free(map);
}
