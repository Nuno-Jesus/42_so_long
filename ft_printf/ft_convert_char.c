/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:06 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 16:59:43 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_conversion(t_flags *flags, va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, STDOUT_FILENO);
	free(flags);
	return (1);
}
