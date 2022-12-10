/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:44:46 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 10:48:09 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	
	char *res;
	int search = argv[2][0];
	
	printf("\n\t>>> : USING strchr() <<<\n\n");
	
	res = strchr(argv[1], search);
	printf("Result:\n\tres = \'%s\'\n", res);
	
	printf("\n\t>>> : USING ft_strchr() <<<\n\n");
	
	res = ft_strchr(argv[1], search);
	printf("Result:\n\tres =  \'%s\'\n", res);
}
 */