/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:54:58 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/20 15:38:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_movement(t_game *g)
{
	return 
	(
		!is_same_point(g->curr, g->next)
		&& at(g, g->next) != WALL
		&& g->next.y >= 0  && g->next.y < g->map->rows
		&& g->next.x >= 0  && g->next.x < g->map->cols
	);
}

void	move_player(t_game *game)
{
	game->map->bytes[game->curr.y][game->curr.x] = SPACE;
	game->map->bytes[game->next.y][game->next.x] = PLAYER;
	render_tile(game, game->curr.x, game->curr.y);	
	render_tile(game, game->next.x, game->next.y);	
	game->curr = game->next;
}