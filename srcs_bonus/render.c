/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/12 12:29:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sprite(t_game *g, t_sprite *s, t_point p, t_point offset)
{
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, s->img, \
		offset.x + p.x * s->width, offset.y + p.y * s->height);
}

void	render_outter_walls(t_game *g)
{
	unsigned int	i;
	
	i = 0;	
	while (++i < g->map->cols - 1)
		render_sprite(g, &g->sp[W1], (t_point){i, 0}, (t_point){-16, 0});
	i = -1;	
	while (++i < g->map->cols)
		render_sprite(g, &g->sp[W1], (t_point){i, g->map->rows - 1}, (t_point){-16, 0});
	i = -1;
	while (++i < g->map->rows - 1)
	{
		render_sprite(g, &g->sp[W2], (t_point){0, i}, (t_point){-16, 0});
		render_sprite(g, &g->sp[W3], (t_point){g->map->cols - 1, i}, (t_point){-16, 0});
	}
}

void	delete_matrix(int **mat)
{
	int i;

	i = 0;
	while (mat[i])
		free(mat[i]);
	free(mat);
}

void	print_matrix(int **mat, int x, int y)
{
	int i;
	int k;
	
	i = -1;
	while (++i < y)
	{
		k = -1;
		while (++k < x)
			printf("%d", mat[i][k]);
		printf("\n");			
	}
}

void	fill_binary_matrix(t_game *g, int **mat)
{
	int y;
	int x;

	y = -1;

	while (++y < g->map->rows)
	{
		x = -1;
		while (++x < g->map->cols)
		{
			if (g->map->bytes[y][x] == WALL)
				mat[y + 1][x + 1] = 1;
		}
	}
}

void	render_inner_walls(t_game *g, t_point p)
{
	int	i;
	int	**tmp;

	i = -1;
	tmp = malloc((g->map->rows + 1) * sizeof(int));
	if (!tmp)
		return ;
	while (++i < g->map->rows)
	{
		tmp[i] = ft_calloc(g->map->cols + 1, sizeof(int));
		if(!tmp[i])
		{
			delete_matrix(tmp);
			return ;
		}
	}
	fill_binary_matrix(g, tmp);
	print_matrix(tmp, g->map->cols, g->map->rows);
	exit(1);
}

void	render_tile(t_game *g, t_point p)
{
	t_sprite	sp;

	if (g->map->bytes[p.y][p.x] == WALL)
		sp = g->sp[W1];
	else if (g->map->bytes[p.y][p.x] == COIN)
		sp = g->sp[C1];
	else if (g->map->bytes[p.y][p.x] == EXIT)
		sp = g->sp[E1];
	else if (g->map->bytes[p.y][p.x] == SPACE)
		sp = g->sp[S1];
	else if (g->map->bytes[p.y][p.x] == PLAYER)
		sp = g->sp[P1];
	render_sprite(g, &sp, p, (t_point){-16, 0});
}

void	render_map(t_game *g)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	render_outter_walls(g);
	while (++y < g->map->rows - 1)
	{
		x = 0;
		while (++x < g->map->cols - 1)
			render_tile(g, (t_point){x, y});
	}
}

void	render_counter(t_game *g)
{
	char	*str;
	int		x;
	int		y;

	x = g->map->cols * 16;
	y = g->map->rows * 32 + 20;

	str = ft_itoa(++g->moves);
	mlx_put_image_to_window(g->disp.mlx, g->disp.win, g->disp.img, x, y - 20);
	mlx_string_put(g->disp.mlx, g->disp.win, x, y, 0xFFFFFF, str);
	free(str);
}

int	render_frame(t_game *g)
{
	if (!is_valid_movement(g))
		return (0);
	render_counter(g);
	if (at(g, g->next) == COIN)
		g->coins++;
	else if (at(g, g->next) == EXIT && g->coins == g->map->num_coins)
		quit(g);
	move_player(g);
	return (0);
}
