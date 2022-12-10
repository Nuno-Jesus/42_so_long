/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:37:34 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 14:38:50 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n'
		|| c == '\r' || c == '\t'
		|| c == '\v' || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	int		signal;

	i = 0;
	res = 0;
	signal = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		res = res * 10 + nptr[i++] - '0';
	return (signal * res);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;

	printf("\n\t>>> USING ft_atoi() <<<\n\n");
	printf("Sending str = \'%s\'\n", argv[1]);
	printf("Resulting in: %d\n", ft_atoi(argv[1]));
	
	printf("\n\t>>> USING atoi() <<<\n\n");
	printf("Sending str = \'%s\'\n", argv[1]);
	printf("Resulting in: %d\n", atoi(argv[1]));
}
 */