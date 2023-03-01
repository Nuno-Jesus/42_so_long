/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:07 by marvin            #+#    #+#             */
/*   Updated: 2022/11/18 14:22:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long n, char *base, int *size)
{
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base, size);
	ft_putchar_fd(base[n % base_len], STDOUT_FILENO);
	(*size)++;
}

int	ft_numsize(long long n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_toupper_helper(unsigned int dummy, char *c)
{
	(void)dummy;
	*c = ft_toupper(*c);
}
