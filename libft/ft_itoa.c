/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:15 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/02 18:38:15 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int		size;
	long	num;

	size = 1;
	num = n;
	if (n < 0)
	{
		num = -num;
		size++;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	num;
	int		size;
	char	*str;

	num = n;
	if (n < 0)
		num = -num;
	size = get_size(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[size--] = '\0';
	while (num > 0)
	{
		str[size--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	
	//2147483647 -2147483648
	int n = atoi(argv[1]);
	char expected[50];
	char *res = ft_itoa(n);

	sprintf(expected, "%d", n);
	printf("Sending: %d\n", n);
	printf("Expected: \'%s\'\n", expected);
	printf("Returning: \'%s\'\n", res);

	free(res);
}
 */