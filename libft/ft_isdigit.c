/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:05 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/16 22:00:05 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	printf("\n\t>>> USING isdigit() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (isdigit(argv[1][0]))
		printf("The char \'%c\' is numeric.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not numeric.\n", argv[1][0]);
	
	printf("\n\t>>> USING ft_isdigit() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (ft_isdigit(argv[1][0]))
		printf("The char \'%c\' is numeric.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not numeric.\n", argv[1][0]);
} */
