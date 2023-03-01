/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:20:30 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 16:59:20 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_conversion(t_flags *flags, va_list args)
{
	unsigned long long	address;
	int					num_size;

	num_size = 0;
	address = va_arg(args, unsigned long long);
	if (address == 0)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		free(flags);
		return (5);
	}
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putnbr_base(address, HEXBASE, &num_size);
	free(flags);
	return (2 + num_size);
}
