/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:48:41 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 10:10:52 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	new = ft_substr(s1, start, (end - start) + 1);
	if (!new)
		return (NULL);
	return (new);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	char *res = ft_strtrim(argv[1], argv[2]);

	printf("Sending s1 = \'%s\'\n", argv[1]);
	printf("Sending set = \'%s\'\n", argv[2]);
	printf("Returning res = \'%s\'\n", res);
} */
