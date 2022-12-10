/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:47:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/15 21:46:18 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/* 
int main(int argc, char **argv)
{
	for(int i = 0; i < argc; i++)
		printf("Len [%d](\'%s\') = %ld\n", i, argv[i], ft_strlen(argv[i]));
	return (0);
} */