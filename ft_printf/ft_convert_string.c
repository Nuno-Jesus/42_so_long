/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:24 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 16:47:15 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_conversion(t_flags *flags, va_list args)
{
	char	*str;
	int		ret;

	ret = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		free(flags);
		return (6);
	}
	while (flags->width-- && flags->space)
		ret += write(STDOUT_FILENO, " ", 1);
	ft_putstr_fd(str, STDOUT_FILENO);
	ret += ft_strlen(str);
	free(flags);
	return (ret);
}
