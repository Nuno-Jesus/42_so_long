/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 13:08:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/map.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_map *map = map_new(point_new(10, 20));
	map_delete(map);
}