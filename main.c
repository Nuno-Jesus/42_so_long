/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:04:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/21 17:00:54 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

bool	is_filename_valid(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strnstr(filename + (len - 4), ".ber", 4) != NULL);
}

int	main(int argc, char **argv)
{	
	if (argc - 1 != 1)
		message(NULL, "Invalid number of parameters.\n");
	if (!is_filename_valid(argv[1]))
		message(NULL, "Filename must end in \".ber\".\n");
	init_game(argv[1]);
}
