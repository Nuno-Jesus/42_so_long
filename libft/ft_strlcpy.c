/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:47:01 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/09 21:21:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	
	int size = atoi(argv[2]);
	char dest[50] = {0};
	
	printf("Sending argv[1] = \"%s\"\n", argv[1]);
	printf("Sending argv[2] = %d\n", size);
	printf("Sending dest = \"%s\"\n", dest);
	
	size = ft_strlcpy(dest, argv[1], size);
	printf("Returning dest = \"%s\"\n", dest);
}
 */