/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:20 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 17:01:33 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	integer_conversion(t_flags *flags, va_list args)
{
	int		n;
	int		ret;
	char	*str;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
	{
		free(flags);
		return (0);
	}
	ret = ft_strlen(str);
	while (flags->width-- + 1 && flags->space && n >= 0)
		ret += write(STDOUT_FILENO, " ", 1);
	if (flags->plus && n >= 0)
	{
		ft_putchar_fd('+', STDOUT_FILENO);
		ret++;
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	free(flags);
	return (ret);
}
