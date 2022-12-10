/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:39:51 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 10:45:41 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	
	char *res;
	int n = atoi(argv[3]);
	int search = atoi(&argv[2][0]);
	
	printf("\n\t>>> : USING memchr() <<<\n\n");
	
	res = memchr(argv[1], search, n);
	printf("Result:\n\tres = \'%s\'\n", res);
	
	printf("\n\t>>> : USING ft_memchr() <<<\n\n");
	
	res = ft_memchr(argv[1], search, n);
	printf("Result:\n\tres =  \'%s\'\n", res);
} */
