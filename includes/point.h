/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:55:30 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 12:59:59 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"

typedef struct s_point
{
	size_t x;
	size_t y;
}t_point;

t_point *point_new(size_t x, size_t y);

void	point_delete(t_point *point);