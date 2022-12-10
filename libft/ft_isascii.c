/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:01 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/03 12:42:01 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	printf("\n\t>>> USING isascii() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (isascii(argv[1][0]))
		printf("The char \'%c\' is from ascii table.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not from ascii table.\n", argv[1][0]);
	
	printf("\n\t>>> USING ft_isascii() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (ft_isascii(argv[1][0]))
		printf("The char \'%c\' is from ascii table.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not from ascii table.\n", argv[1][0]);
} */