/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:51:39 by crypto            #+#    #+#             */
/*   Updated: 2022/11/07 15:51:27 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == c)
			return ((char *)s + i);
		if (i == 0)
			return (NULL);
		i--;
	}
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	char *res = strrchr(argv[2], argv[1][0]);

	printf("\n\t>>> USING strrchr()<<<\n\n");
	if(!res)
		printf("Didn't find \'%c\' in \'%s\'\n", argv[1][0], argv[2]);
	else
		printf("Found \'%c\' in: %s\n", argv[1][0], res);
	
	char *res2 = ft_strrchr(argv[2], argv[1][0]);

	printf("\n\t>>> USING ft_strrchr()<<<\n\n");
	if(!res)
		printf("Didn't find \'%c\' in \'%s\'\n", argv[1][0], argv[2]);
	else
		printf("Found \'%c\' in: %s\n", argv[1][0], res2);
} */
