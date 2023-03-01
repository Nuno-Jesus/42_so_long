/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:28 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 17:02:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexadecimal_conversion(t_flags *flags, va_list args, int is_upper)
{
	long long		n;
	int				num_size;
	char			*base;

	num_size = 0;
	n = va_arg(args, unsigned int);
	base = ft_strdup(HEXBASE);
	if (!base)
		return (0);
	if (is_upper)
		ft_striteri(base, &ft_toupper_helper);
	if (flags->cardinal && n != 0)
	{
		num_size = 2;
		if (is_upper)
			ft_putstr_fd("0X", STDOUT_FILENO);
		else
			ft_putstr_fd("0x", STDOUT_FILENO);
	}
	ft_putnbr_base(n, base, &num_size);
	free(base);
	free(flags);
	return (num_size);
}
