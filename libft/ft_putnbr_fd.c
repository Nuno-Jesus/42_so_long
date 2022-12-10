/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:43:28 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 19:12:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_tochar(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (fd < 0)
		return ;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		ft_putchar_fd(ft_tochar(num), fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(ft_tochar(num % 10), fd);
	}
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	
	//2147483647 -2147483648
	ft_putnbr_fd(atoi(argv[1]), STDOUT_FILENO);
}
 */