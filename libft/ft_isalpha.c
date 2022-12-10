/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:37:54 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/03 12:31:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	printf("\n\t>>> USING isalpha() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (isalpha(argv[1][0]))
		printf("The char \'%c\' is alphabetic.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not alphabetic.\n", argv[1][0]);
	
	printf("\n\t>>> USING ft_isalpha() <<<\n\n");
	printf("Sending \'%c\'\n", argv[1][0]);
	
	if (ft_isalpha(argv[1][0]))
		printf("The char \'%c\' is alphabetic.\n", argv[1][0]);
	else
		printf("The char \'%c\' is not alphabetic.\n", argv[1][0]);
} */
