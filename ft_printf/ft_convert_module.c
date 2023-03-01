/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_module.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:18:22 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/21 16:59:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	module_conversion(t_flags *flags)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	free(flags);
	return (1);
}
