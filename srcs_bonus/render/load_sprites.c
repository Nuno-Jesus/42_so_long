/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/04 05:28:02 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_xpm(t_game *g, t_sprite *s, char *prefix, int n)
{
	size_t	len;
	int		i;
	char	path[200];

	i = 0;
	ft_bzero(path, 200);
	ft_strlcpy(path, prefix, ft_strlen(prefix) + 1);
	ft_strlcat(path, "00.xpm", 200);
	len = ft_strlen(path);
	while (++i <= n)
	{
		path[len - 6] = ft_tochar(i / 10);
		path[len - 5] = ft_tochar(i % 10);
		s->frames[i - 1] = new_image(g, path);
	}
}

void	load_static_entites_frames(t_game *g)
{
	g->walls_sp.frames = malloc(NUM_WALLS * sizeof(t_img));
	if (!g->walls_sp.frames)
		message(g, "Failed allocation on wall frames\n");
	g->floor_sp.frames = malloc(NUM_FLOOR_FRAMES * sizeof(t_img));
	if (!g->floor_sp.frames)
		message(g, "Failed allocation on floor frames\n");
	g->exit_sp.frames = malloc(NUM_EXIT_FRAMES * sizeof(t_img));
	if (!g->exit_sp.frames)
		message(g, "Failed allocation on exit frames\n");
	g->potions_sp.frames = malloc(NUM_COIN_FRAMES * sizeof(t_img));
	if (!g->potions_sp.frames)
		message(g, "Failed allocation on potions frames\n");
	g->walls_sp.nframes = NUM_WALLS;
	g->floor_sp.nframes = NUM_FLOOR_FRAMES;
	g->exit_sp.nframes = NUM_EXIT_FRAMES;
	g->potions_sp.nframes = NUM_COIN_FRAMES;
	load_xpm(g, &g->walls_sp, WALL_PATH, NUM_WALLS);
	load_xpm(g, &g->floor_sp, FLOOR_PATH, NUM_FLOOR_FRAMES);
	load_xpm(g, &g->exit_sp, EXIT_PATH, NUM_EXIT_FRAMES);
	load_xpm(g, &g->potions_sp, POTION_PATH, NUM_COIN_FRAMES);
}

void	load_enemies_frames(t_game *g)
{
	g->enemy_sp = malloc(NUM_SPRITE_VERSIONS * sizeof(t_sprite));
	if (!g->enemy_sp)
		message(g, "Failed allocation on enemy frames array\n");
	g->enemy_sp[NORMAL].frames = malloc(NUM_ENEMY_FRAMES * sizeof(t_img));
	g->enemy_sp[ENRAGED].frames = malloc(NUM_ENEMY_FRAMES * sizeof(t_img));
	if (!g->enemy_sp[NORMAL].frames)
		message(g, "Failed allocation on normal enemy frames\n");
	if (!g->enemy_sp[ENRAGED].frames)
		message(g, "Failed allocation on enraged enemy frames\n");
	g->enemy_sp[NORMAL].nframes = NUM_ENEMY_FRAMES;
	g->enemy_sp[ENRAGED].nframes = NUM_ENEMY_FRAMES;
	load_xpm(g, &g->enemy_sp[NORMAL], ENEMY_CALM_PATH, NUM_ENEMY_FRAMES);
	load_xpm(g, &g->enemy_sp[ENRAGED], ENEMY_RAGE_PATH, NUM_ENEMY_FRAMES);
}

void	load_player_frames(t_game *g)
{
	g->player_sp = malloc(NUM_SPRITE_VERSIONS * sizeof(t_sprite));
	if (!g->player_sp)
		message(g, "Failed allocation on player frames array\n");
	g->player_sp[RIGHT].frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_img));
	g->player_sp[LEFT].frames = malloc(NUM_PLAYER_FRAMES * sizeof(t_img));
	if (!g->player_sp[RIGHT].frames)
		message(g, "Failed allocation on right player frames\n");
	if (!g->player_sp[LEFT].frames)
		message(g, "Failed allocation on left player frames\n");
	g->player_sp[RIGHT].nframes = NUM_PLAYER_FRAMES;
	g->player_sp[LEFT].nframes = NUM_PLAYER_FRAMES;
	load_xpm(g, &g->player_sp[RIGHT], PLAYER_RIGHT_PATH, NUM_PLAYER_FRAMES);
	load_xpm(g, &g->player_sp[LEFT], PLAYER_LEFT_PATH, NUM_PLAYER_FRAMES);
}

void	load_sprites(t_game *g)
{	
	load_static_entites_frames(g);
	load_player_frames(g);
	load_enemies_frames(g);
}
