/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/14 10:12:32 by crypto           ###   ########.fr       */
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
		free(mat[i++]);
	free(mat);
}

void	print_matrix(int **mat, unsigned int x, unsigned int y)
{
	unsigned int i;
	unsigned int k;
	
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
	unsigned int y;
	unsigned int x;

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

int	**create_binary_matrix(unsigned int y, unsigned int x)
{
	int				**tmp;
	unsigned int	i;
	
	i = -1;
	tmp = ft_calloc(y + 1, sizeof(int *));
	if (!tmp)
		return (NULL);
	while (++i < y)
	{
		tmp[i] = ft_calloc(x + 2, sizeof(int));
		if(!tmp[i])
		{
			delete_matrix(tmp);
			return (NULL);
		}
	}
	return (tmp);
}

int diff(int **mat, t_point p, char dim)
{
	if (dim == 'x')
		return (mat[p.y][p.x - 1] - mat[p.y][p.x + 1]);
	else
		return (mat[p.y - 1][p.x] - mat[p.y + 1][p.x]);
}

void	render_inner_walls(t_game *g)
{
	int	**tmp;
	t_point p;

	tmp = create_binary_matrix(g->map->rows + 2, g->map->cols + 2);
	fill_binary_matrix(g, tmp);
	print_matrix(tmp, g->map->cols + 2, g->map->rows + 2);
	p.y = 0;
	while (++p.y < g->map->rows - 1)
	{
		p.x = 0;
		while (++p.x < g->map->cols - 1)
		{
			if (at(g, p) != WALL)
				continue;
			if (diff(tmp, (t_point){p.x + 1, p.y + 1}, 'x') == -1 && diff(tmp, (t_point){p.x + 1, p.y + 1}, 'y') == -1)
				render_sprite(g, &g->sp[W4], p, (t_point){-16, 0});
			else if (diff(tmp, (t_point){p.x + 1, p.y + 1}, 'x') == 1 && diff(tmp, (t_point){p.x + 1, p.y + 1}, 'y') == -1)
				render_sprite(g, &g->sp[W5], p, (t_point){-16, 0});
			else
				render_sprite(g, &g->sp[W1], p, (t_point){-16, 0});
		}
	}
	delete_matrix(tmp);
	// exit(1);
}

void	render_tile(t_game *g, t_point p)
{
	t_sprite	sp;

	if (g->map->bytes[p.y][p.x] == WALL)
		return ;
		// sp = g->sp[W1];
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
	render_inner_walls(g);
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

	x = (g->map->cols - 1) * 16;
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
