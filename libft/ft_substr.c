/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:52:30 by crypto            #+#    #+#             */
/*   Updated: 2022/11/06 10:10:58 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len && s[i + start])
		{
			res[i] = s[i + start];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	int start = atoi(argv[2]);
	int len = atoi(argv[3]);
	char *res = ft_substr(argv[1], start, len);

	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Sending argv[2] = %d\n", start);
	printf("Sending argv[3] = %d\n", len);

	printf("Returning \'%s\'\n", res);
}
 */