/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/27 20:48:05 by crypto           ###   ########.fr       */
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
		path[len - 6] = ft_tosymbol(i / 10);
		path[len - 5] = ft_tosymbol(i % 10);
		s->img[i - 1] = mlx_xpm_file_to_image(g->disp.mlx, \
				path, &(s->width), &(s->height));
	}
}

void	load_rest(t_game *g)
{
	g->walls_sp.img = malloc(NUM_WALLS * sizeof(void *));
	if (!g->walls_sp.img)
		message(g, "Failed allocation on wall frames\n");
	g->floor_sp.img = malloc(NUM_FLOOR_FRAMES * sizeof(void *));
	if (!g->floor_sp.img)
		message(g, "Failed allocation on floor frames\n");
	g->exit_sp.img = malloc(NUM_EXIT_FRAMES * sizeof(void *));
	if (!g->exit_sp.img)
		message(g, "Failed allocation on wall frames\n");
	g->walls_sp.nframes = NUM_WALLS;
	g->floor_sp.nframes = NUM_FLOOR_FRAMES;
	g->exit_sp.nframes = NUM_EXIT_FRAMES;
	load_xpm(g, &g->walls_sp, WALL_PATH, NUM_WALLS);
	load_xpm(g, &g->floor_sp, FLOOR_PATH, NUM_FLOOR_FRAMES);
	load_xpm(g, &g->exit_sp, EXIT_PATH, NUM_EXIT_FRAMES);
}

void	load_coins(t_game *g)
{
	g->potions_sp.img = malloc(NUM_COIN_FRAMES * sizeof(void *));
	if (!g->potions_sp.img)
		message(g, "Failed allocation on potions frames\n");
	g->potions_sp.nframes = NUM_COIN_FRAMES;
	load_xpm(g, &g->potions_sp, POTION_PATH, NUM_COIN_FRAMES);
}
