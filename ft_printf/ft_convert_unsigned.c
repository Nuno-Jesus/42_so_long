/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:26 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/20 12:42:32 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_conversion(t_flags *flags, va_list args)
{
	unsigned int	n;
	int				num_size;

	num_size = 0;
	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, DECBASE, &num_size);
	free(flags);
	return (num_size);
}
