/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/07 18:49:41 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int argc, char **argv)
{
	(void)argc;
	
	char filename[255] = {0};
	sprintf(filename, "maps/%s.ber", argv[1]);
	t_game *game = game_new();
	if (!game)
		return 0;
	read_map(game, filename);
	validate_map(game);
	map_print(game->map);
	game_delete(game);
	return 0;
}