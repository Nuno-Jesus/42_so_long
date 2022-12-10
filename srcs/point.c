/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:55:13 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 13:08:36 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

t_point	*point_new(size_t x, size_t y)
{
	t_point	*point;

	point = malloc(sizeof(point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

void	point_delete(t_point *point)
{
	if (!point)
		return ;
	free(point);
}