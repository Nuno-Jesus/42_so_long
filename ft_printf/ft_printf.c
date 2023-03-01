/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:26:21 by crypto            #+#    #+#             */
/*   Updated: 2022/11/21 16:48:18 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(const char *format, size_t *i, va_list args)
{
	t_flags	*flags;

	flags = consume_flags(format, i);
	if (format[*i] == 'c')
		return (char_conversion(flags, args));
	else if (format[*i] == 's')
		return (string_conversion(flags, args));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return (integer_conversion(flags, args));
	else if (format[*i] == 'p')
		return (pointer_conversion(flags, args));
	else if (format[*i] == 'u')
		return (unsigned_conversion(flags, args));
	else if (ft_tolower(format[*i]) == 'x')
		return (hexadecimal_conversion(flags, args, format[*i] == 'X'));
	else if (format[*i] == '%')
		return (module_conversion(flags));
	free(flags);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	size_t	i;
	va_list	args;

	res = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			res += convert(format, &i, args);
		else
		{
			ft_putchar_fd(format[i], STDOUT_FILENO);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
