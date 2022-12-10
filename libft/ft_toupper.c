/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:10:11 by crypto            #+#    #+#             */
/*   Updated: 2022/11/05 17:33:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	printf("\n\t>>> USING toupper() <<<\n\n");
	
	printf("Sending \'%s\'\n", argv[1]);
	printf("Returning: ");
	for(int i = 0; argv[1][i]; i++)
		printf("%c", toupper(argv[1][i]));
	printf("\n");
	
	printf("\n\t>>> USING ft_toupper() <<<\n\n");
	
	printf("Sending \'%s\'\n", argv[1]);
	printf("Returning: ");
	for(int i = 0; argv[1][i]; i++)
		printf("%c", ft_toupper(argv[1][i]));
	printf("\n");
} */