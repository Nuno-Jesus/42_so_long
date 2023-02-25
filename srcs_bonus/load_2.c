/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:29:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/25 15:52:49 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemies(t_game *g)
{
	g->eframes = malloc(2 * sizeof(t_sprite));
	if (!g->eframes)
		message(g, "Failed allocation on enemy frames array\n");
	g->eframes[RIGHT].img = malloc(NUM_ENEMY_FRAMES * sizeof(void *));
	g->eframes[LEFT].img = malloc(NUM_ENEMY_FRAMES * sizeof(void *));
	if (!g->eframes[RIGHT].img)
		message(g, "Failed allocation on right enemy frames\n");
	if (!g->eframes[LEFT].img)
		message(g, "Failed allocation on left enemy frames\n");
	g->eframes[LEFT].nframes = NUM_ENEMY_FRAMES;
	g->eframes[RIGHT].nframes = NUM_ENEMY_FRAMES;
	load_xpm(g, &g->eframes[LEFT], ENEMY_CALM_PATH, NUM_ENEMY_FRAMES);
	load_xpm(g, &g->eframes[RIGHT], ENEMY_RAGE_PATH, NUM_ENEMY_FRAMES);
}

void	load_player(t_game *g)
{
	g->pframes = malloc(2 * sizeof(t_sprite));
	if (!g->pframes)
		message(g, "Failed allocation on player frames array\n");
	g->pframes[RIGHT].img = malloc(NUM_PLAYER_FRAMES * sizeof(void *));
	g->pframes[LEFT].img = malloc(NUM_PLAYER_FRAMES * sizeof(t_sprite));
	if (!g->pframes[RIGHT].img)
		message(g, "Failed allocation on right player frames\n");
	if (!g->pframes[LEFT].img)
		message(g, "Failed allocation on left player frames\n");
	g->pframes[RIGHT].nframes = NUM_PLAYER_FRAMES;
	g->pframes[LEFT].nframes = NUM_PLAYER_FRAMES;
	load_xpm(g, &g->pframes[RIGHT], PLAYER_RIGHT_PATH, NUM_PLAYER_FRAMES);
	load_xpm(g, &g->pframes[LEFT], PLAYER_LEFT_PATH, NUM_PLAYER_FRAMES);
}

void	load_sprites(t_game *g)
{	
	load_rest(g);
	load_player(g);
	load_enemies(g);
	load_coins(g);
}
