/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:53:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 21:11:13 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_matrix(void *matrix)
{	
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (((char **)matrix)[i])
		free(((char **)matrix)[i++]);
	free(matrix);
}

void	destroy_sprite(t_game *g, t_sprite *sp, int n)
{
	int	i;

	i = 0;
	if (!sp || !sp->img)
		return ;
	while (i < n)
		mlx_destroy_image(g->disp.mlx, sp->img[i++]);
	ft_free(sp->img);
}

void	destroy_all_sprites(t_game *g)
{
	int	k;

	k = -1;
	destroy_sprite(g, &g->walls_sp, NUM_WALLS);
	destroy_sprite(g, &g->exit_sp, NUM_EXIT_FRAMES);
	destroy_sprite(g, &g->floor_sp, NUM_FLOOR_FRAMES);
	destroy_sprite(g, &g->potions_sp, NUM_COIN_FRAMES);
	while (++k < NUM_SPRITE_VERSIONS)
	{
		destroy_sprite(g, &g->player_sp[k], NUM_PLAYER_FRAMES);
		destroy_sprite(g, &g->enemy_sp[k], NUM_ENEMY_FRAMES);
	}
	ft_free(g->player_sp);
	ft_free(g->enemy_sp);
}

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	destroy_matrix(map->bytes);
	ft_free(map);
}

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	ft_free(game->coins);
	ft_free(game->enemies);
	destroy_all_sprites(game);
	if (game->disp.win)
		mlx_destroy_window(game->disp.mlx, game->disp.win);
	if (game->disp.mlx)
		mlx_destroy_display(game->disp.mlx);
	if (game->map)
		destroy_map(game->map);
	ft_free(game->disp.mlx);
}
