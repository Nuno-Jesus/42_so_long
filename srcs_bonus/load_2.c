/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:29:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 20:26:42 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemies(t_game *g)
{
	g->enemy_sp = malloc(NUM_SPRITE_VERSIONS * sizeof(t_sprite));
	if (!g->enemy_sp)
		message(g, "Failed allocation on enemy frames array\n");
	g->enemy_sp[NORMAL].img = malloc(NUM_ENEMY_FRAMES * sizeof(void *));
	g->enemy_sp[ENRAGED].img = malloc(NUM_ENEMY_FRAMES * sizeof(void *));
	if (!g->enemy_sp[NORMAL].img)
		message(g, "Failed allocation on normal enemy frames\n");
	if (!g->enemy_sp[ENRAGED].img)
		message(g, "Failed allocation on enraged enemy frames\n");
	g->enemy_sp[NORMAL].nframes = NUM_ENEMY_FRAMES;
	g->enemy_sp[ENRAGED].nframes = NUM_ENEMY_FRAMES;
	load_xpm(g, &g->enemy_sp[NORMAL], ENEMY_CALM_PATH, NUM_ENEMY_FRAMES);
	load_xpm(g, &g->enemy_sp[ENRAGED], ENEMY_RAGE_PATH, NUM_ENEMY_FRAMES);
}

void	load_player(t_game *g)
{
	g->player_sp = malloc(NUM_SPRITE_VERSIONS * sizeof(t_sprite));
	if (!g->player_sp)
		message(g, "Failed allocation on player frames array\n");
	g->player_sp[RIGHT].img = malloc(NUM_PLAYER_FRAMES * sizeof(void *));
	g->player_sp[LEFT].img = malloc(NUM_PLAYER_FRAMES * sizeof(void *));
	if (!g->player_sp[RIGHT].img)
		message(g, "Failed allocation on right player frames\n");
	if (!g->player_sp[LEFT].img)
		message(g, "Failed allocation on left player frames\n");
	g->player_sp[RIGHT].nframes = NUM_PLAYER_FRAMES;
	g->player_sp[LEFT].nframes = NUM_PLAYER_FRAMES;
	load_xpm(g, &g->player_sp[RIGHT], PLAYER_RIGHT_PATH, NUM_PLAYER_FRAMES);
	load_xpm(g, &g->player_sp[LEFT], PLAYER_LEFT_PATH, NUM_PLAYER_FRAMES);
}

void	load_sprites(t_game *g)
{	
	load_rest(g);
	load_player(g);
	load_enemies(g);
	load_coins(g);
}
