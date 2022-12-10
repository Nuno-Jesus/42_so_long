/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:58:13 by crypto            #+#    #+#             */
/*   Updated: 2022/11/06 14:53:15 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;	

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	little_len = ft_strlen(little);
	if (!little[0])
		return ((char *)big);
	while (big[i] != '\0' && i <= len - little_len && len > 0)
	{
		if (big[i] == little[0])
			if (!ft_memcmp(big + i, little, little_len))
				return ((char *)big + i);
		i++;
	}	
	return (NULL);
}
/* 
int main(int argc, char **argv)
{	
	(void)argc;
	
	int n = atoi(argv[3]);
	char *res = ft_strnstr(argv[2], argv[1], n);

	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Sending argv[2] = \'%s\'\n", argv[2]);
	printf("Sending argv[3] = %d\n", n);

	if(!res)
		printf("\'%s\' is not in %d bytes of \'%s\'\n", argv[1], n, argv[2]);
	else
		printf("Found: '%s'\n", res);
}
 */