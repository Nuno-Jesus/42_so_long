/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:25:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/17 10:57:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void change (unsigned int i, char *c)
{
	*c = *c + i;
}

int main(int argc, char **argv)
{
	(void) argc;
	
	printf("Sending \'%s\'\n", argv[1]);
	ft_striteri(argv[1], &change);
	printf("Returning \'%s\'\n", argv[1]);	
} */
