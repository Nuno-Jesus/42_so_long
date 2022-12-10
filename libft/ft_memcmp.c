/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:40:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/16 22:51:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	int size = atoi(argv[3]);
	char *rest1 = strndup(argv[1], size);
	char *rest2 = strndup(argv[2], size);
	
	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Sending argv[2] = \'%s\'\n", argv[2]);

	printf("\n\t************** USING memcmp() **************\n\n");
	
	int res = memcmp(argv[1], argv[2], size);
	if(res < 0)
		printf("\"%s\" is less than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else if(res > 0)
		printf("\"%s\" is bigger than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else
		printf("\"%s\" is equal to \"%s\" (%d bytes) \n", rest1, rest2, size);
	
	printf("\n\t************** USING ft_memcmp() **************\n\n");

	res = ft_memcmp(argv[1], argv[2], size);
	if(res < 0)
		printf("\"%s\" is less than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else if(res > 0)
		printf("\"%s\" is bigger than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else
		printf("\"%s\" is equal to \"%s\" (%d bytes) \n", rest1, rest2, size);

	free(rest1);
	free(rest2);
}
 */