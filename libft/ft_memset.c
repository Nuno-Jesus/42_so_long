/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:41:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 10:45:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	
	int n = atoi(argv[3]);
	int c = argv[2][0];
	
	char *str = strdup(argv[1]), *res;
	
	printf("\n\t>>> : USING memset() <<<\n\n");
	
	printf("Sending \'%s\' and \'%c\' (n = %d)\n", argv[1], c, n);
	res = memset(argv[1], c, n);
	printf("Result:\n\tres = \'%s\'\n", res);
	
	printf("\n\t>>> : USING ft_memset() <<<\n\n");
	
	printf("Sending \'%s\' and \'%c\' (n = %d)\n", str, c, n);
	res = ft_memset(str, c, n);
	printf("Result:\n\tres =  \'%s\'\n", res);

	free(str);
}
 */