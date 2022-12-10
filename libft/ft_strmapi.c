/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:49:31 by crypto            #+#    #+#             */
/*   Updated: 2022/11/06 10:07:48 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	mapped = (char *)malloc(ft_strlen(s) + 1);
	if (!mapped)
		return (NULL);
	while (s[i])
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
/* 
char change (unsigned int i, char c)
{
	return (c + i);
}

int main(int argc, char **argv)
{
	(void) argc;
	char *res;
	
	printf("Sending \'%s\'\n", argv[1]);
	res = ft_strmapi(argv[1], &change);
	printf("Returning \'%s\'\n", res);	
} */
