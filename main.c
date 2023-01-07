/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/01/07 12:39:30 by ncarvalh         ###   ########.fr       */
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

	for(int i = 0; game->map->bytes[i]; i++)
		printf("%s", game->map->bytes[i]);
	game_delete(game);
	return 0;
}