/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:39:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/18 18:34:22 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		render_sprite(g, &g->sp[WALL_U], (t_point){i, 0}, (t_point){-16, 0});
	i = -1;	
	while (++i < g->map->cols)
		render_sprite(g, &g->sp[WALL_U], (t_point){i, g->map->rows - 1}, (t_point){-16, 0});
	i = -1;
	while (++i < g->map->rows - 1)
	{
		render_sprite(g, &g->sp[WALL_L], (t_point){0, i}, (t_point){-16, 0});
		render_sprite(g, &g->sp[WALL_R], (t_point){g->map->cols - 1, i}, (t_point){-16, 0});
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
	int				**mat;
	unsigned int	i;
	
	i = -1;
	mat = ft_calloc(y + 1, sizeof(int *));
	if (!mat)
		return (NULL);
	while (++i < y)
	{
		mat[i] = ft_calloc(x + 2, sizeof(int));
		if(!mat[i])
		{
			delete_matrix(mat);
			return (NULL);
		}
	}
	return (mat);
}

int diff(int **mat, t_point p, char dim)
{
	if (dim == 'x')
		return (mat[p.y][p.x - 1] - mat[p.y][p.x + 1]);
	else
		return (mat[p.y - 1][p.x] - mat[p.y + 1][p.x]);
}

int sum(int **mat, t_point p, char dim)
{
	if (dim == 'x')
		return (mat[p.y][p.x - 1] + mat[p.y][p.x + 1]);
	else
		return (mat[p.y - 1][p.x] + mat[p.y + 1][p.x]);
}

int at2(int **mat, t_point p)
{
	return (mat[p.y][p.x]);
}

//! Need to change this
int	choose_wall_sprite(t_point p, int **mat)
{
	if (diff(mat, p, 'x') == -1 && diff(mat, p, 'y') == 1 && at2(mat, (t_point){p.x + 1, p.y - 1}))
		return (CORNER_DL);
	if (diff(mat, p, 'x') == 1 && diff(mat, p, 'y') == 1 && at2(mat, (t_point){p.x - 1, p.y - 1}))
		return (CORNER_DR);
	if (diff(mat, p, 'x') == -1 && diff(mat, p, 'y') == -1 && !at2(mat, (t_point){p.x + 1, p.y + 1}))
		return (CORNER_UL_2);
	if (diff(mat, p, 'x') == 1 && diff(mat, p, 'y') == -1 && !at2(mat, (t_point){p.x - 1, p.y + 1}))
		return (CORNER_UR_2);
	if (diff(mat, p, 'x') == -1 && diff(mat, p, 'y') == 1 && !at2(mat, (t_point){p.x + 1, p.y - 1}))
		return (CORNER_DL_2);
	if (diff(mat, p, 'x') == 1 && diff(mat, p, 'y') == 1 && !at2(mat, (t_point){p.x - 1, p.y - 1}))
		return (CORNER_DR_2);
	
	if (!diff(mat, p, 'x') && !diff(mat, p, 'y') && mat[p.y + 1][p.x + 1] && !mat[p.y - 1][p.x - 1] && mat[p.y + 1][p.x - 1] && mat[p.y - 1][p.x + 1])
		return (CORNER_BUL);
	if (!diff(mat, p, 'x') && !diff(mat, p, 'y') && mat[p.y + 1][p.x + 1] && mat[p.y - 1][p.x - 1] && mat[p.y + 1][p.x - 1] && !mat[p.y - 1][p.x + 1])
		return (CORNER_BUR);
	if (!diff(mat, p, 'x') && !diff(mat, p, 'y') && mat[p.y + 1][p.x + 1] && mat[p.y - 1][p.x - 1] && !mat[p.y + 1][p.x - 1] && mat[p.y - 1][p.x + 1])
		return (CORNER_BDL);
	if (!diff(mat, p, 'x') && !diff(mat, p, 'y') && !mat[p.y + 1][p.x + 1] && mat[p.y - 1][p.x - 1] && mat[p.y + 1][p.x - 1] && mat[p.y - 1][p.x + 1])
		return (CORNER_BDR);
		
	if (diff(mat, p, 'x') == -1 && sum(mat, p, 'y') == 2 && !mat[p.y - 1][p.x + 1] && !mat[p.y + 1][p.x + 1])
		return (BARRIER_L_2);
	if (diff(mat, p, 'x') == 1 && sum(mat, p, 'y') == 2 && !mat[p.y - 1][p.x - 1] && !mat[p.y + 1][p.x - 1])
		return (BARRIER_R_2);
	if (!diff(mat, p, 'x') && diff(mat, p, 'y') == -1 && !mat[p.y + 1][p.x - 1] && !mat[p.y + 1][p.x + 1])
		return (BARRIER_U_2);
	if (!diff(mat, p, 'x') && diff(mat, p, 'y') == 1 && !mat[p.y - 1][p.x - 1] && !mat[p.y - 1][p.x + 1])
		return (BARRIER_D_2);
	if (diff(mat, p, 'x') == -1 && diff(mat, p, 'y') == -1)
		return (CORNER_L);
	if (diff(mat, p, 'x') == 1 && diff(mat, p, 'y') == -1)
		return (CORNER_R);
	if (sum(mat, p, 'x') == 2 && diff(mat, p, 'y') == 1)
		return (WALL_D);
	if (diff(mat, p, 'x') == -1 && sum(mat, p, 'y') == 2)
		return (BARRIER_L);
	if (diff(mat, p, 'x') == 1 && sum(mat, p, 'y') == 2)
		return (BARRIER_R);
	if (sum(mat, p, 'x') == 2 && sum(mat, p, 'y') == 0)
		return (PIPE_H);
	if (sum(mat, p, 'x') == 0 && sum(mat, p, 'y') == 2)
		return (PIPE_V);
	if (sum(mat, p, 'x') == 0 && diff(mat, p, 'y') == -1)
		return (EDGE_U);
	if (sum(mat, p, 'x') == 0 && diff(mat, p, 'y') == 1)
		return (EDGE_D);
	if (diff(mat, p, 'x') == -1 && sum(mat, p, 'y') == 0)
		return (EDGE_L);
	if (diff(mat, p, 'x') == 1 && sum(mat, p, 'y') == 0)
		return (EDGE_R);
	if (sum(mat, p, 'x') == 0 && sum(mat, p, 'y') == 0)
		return (BOUNDED);
	if (!diff(mat, p, 'x') && !diff(mat, p, 'y') && !mat[p.y - 1][p.x - 1] && !mat[p.y - 1][p.x + 1] && !mat[p.y + 1][p.x - 1] && !mat[p.y + 1][p.x + 1])
		return (BOUNDLESS_2);
	if (sum(mat, p, 'x') == 2 && sum(mat, p, 'y') == 2)
		return (BOUNDLESS);
	
	return (WALL_U);
}

void	render_inner_walls(t_game *g)
{
	int	**mat;
	int index;
	t_point p;

	mat = create_binary_matrix(g->map->rows + 2, g->map->cols + 2);
	fill_binary_matrix(g, mat);
	print_matrix(mat, g->map->cols + 2, g->map->rows + 2);
	p.y = 0;
	while (++p.y < g->map->rows - 1)
	{
		p.x = 0;
		while (++p.x < g->map->cols - 1)
		{
			if (at(g, p) != WALL)
				continue;
			index = choose_wall_sprite((t_point){p.x + 1, p.y + 1}, mat);
			render_sprite(g, &g->sp[index], p, (t_point){-16, 0});
		}
	}
	delete_matrix(mat);
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
