/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:04:16 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 16:46:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*new_flags(void)
{
	t_flags	*new;

	new = (t_flags *)malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	new->dot = FALSE;
	new->plus = FALSE;
	new->zero = FALSE;
	new->minus = FALSE;
	new->space = FALSE;
	new->width = FALSE;
	new->asterisk = FALSE;
	new->cardinal = FALSE;
	new->precision = FALSE;
	return (new);
}

void	consume_value_modifier(t_flags *flags, const char *format, size_t *i)
{
	int	value;

	value = ft_atoi(&format[*i]);
	*i += ft_numsize(value) - 1;
	if (flags->dot)
		flags->precision = value;
	else
		flags->width = value;
}

t_flags	*consume_flags(const char *format, size_t *i)
{
	t_flags	*flags;

	flags = new_flags();
	if (!flags)
		return (NULL);
	while (!ft_strchr(CONVERSIONS, format[++(*i)]))
	{
		if (format[*i] == '+')
			flags->plus = TRUE;
		else if (format[*i] == ' ')
			flags->space = TRUE;
		else if (format[*i] == '#')
			flags->cardinal = TRUE;
		else if ((format[*i] >= '1' && format[*i] <= '9') || format[*i] == '*')
			consume_value_modifier(flags, format, i);
	}
	return (flags);
}
