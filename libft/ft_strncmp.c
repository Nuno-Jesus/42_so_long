/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:41:12 by crypto            #+#    #+#             */
/*   Updated: 2022/11/06 14:41:02 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	int size = atoi(argv[3]);
	char *rest1 = strndup(argv[1], size);
	char *rest2 = strndup(argv[2], size);
	
	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Sending argv[2] = \'%s\'\n", argv[2]);

	printf("\n\t************** USING strncmp() **************\n\n");
	
	int res = strncmp(argv[1], argv[2], size);
	if(res < 0)
		printf("\"%s\" is less than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else if(res > 0)
		printf("\"%s\" is bigger than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else
		printf("\"%s\" is equal to \"%s\" (%d bytes) \n", rest1, rest2, size);
	
	printf("\n\t************** USING ft_strncmp() **************\n\n");

	res = ft_strncmp(argv[1], argv[2], size);
	if(res < 0)
		printf("\"%s\" is less than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else if(res > 0)
		printf("\"%s\" is bigger than \"%s\" (%d bytes) \n", rest1, rest2, size);
	else
		printf("\"%s\" is equal to \"%s\" (%d bytes) \n", rest1, rest2, size);

	free(rest1);
	free(rest2);
}
 */