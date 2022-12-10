/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:41:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 14:46:50 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if ((size_t)dest - (size_t)src < n)
	{
		i = n;
		while (--i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	
	char *s1 = strdup(argv[1]);
	char *s2 = strdup(argv[1]);
	int n = atoi(argv[2]);

	printf("\n\t>>> USING memmove() <<<\n\n");
	printf("Sending s1 = \'%s\'\n", s1);
	ft_memmove(s1, s1 + 1, n);
	printf("Returning \'%s\'\n", s1);

	printf("\n\t>>> USING ft_memmove() <<<\n\n");
	printf("Sending s2 = \'%s\'\n", s2);
	memmove(s2, s2 + 1, n);
	printf("Returning \'%s\'\n", s2);

	if(s1)
		free(s1);
	if(s2)
		free(s2);
}
 */