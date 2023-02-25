/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:33:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/25 15:54:08 by ncarvalh         ###   ########.fr       */
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
	g->sp.img = malloc((NUM_WALLS + NUM_REST) * sizeof(t_sprite));
	if (!g->sp.img)
		message(g, "Failed allocation on left player frames\n");
	g->sp.nframes = NUM_WALLS + NUM_REST;
	load_xpm(g, &g->sp, WALL_PATH, NUM_WALLS);
	g->sp.img[S1] = mlx_xpm_file_to_image(g->disp.mlx, FS1,
			&(g->sp.width), &(g->sp.height));
	g->sp.img[E1] = mlx_xpm_file_to_image(g->disp.mlx, FE1,
			&(g->sp.width), &(g->sp.height));
}

void	load_coins(t_game *g)
{
	g->cframes.img = malloc(NUM_COIN_FRAMES * sizeof(t_sprite));
	if (!g->cframes.img)
		message(g, "Failed allocation on potions frames\n");
	g->cframes.nframes = NUM_COIN_FRAMES;
	load_xpm(g, &g->cframes, COIN_PATH, NUM_COIN_FRAMES);
}
