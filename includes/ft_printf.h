/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:11:34 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/03/01 00:14:39 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h> 
# include <ctype.h> 
# include "libft.h"

# define CONVERSIONS "%cspdiuxX\0" 

# define HEXBASE "0123456789abcdef"
# define DECBASE "0123456789"

# define FALSE 0 
# define TRUE 1 

# define DEBUG

typedef struct s_flags
{
	int		dot;	
	int		plus;
	int		zero;	
	int		minus;	
	int		space;	
	int		width;
	int		asterisk;
	int		cardinal;	
	int		precision;
}t_flags;

int		ft_printf(const char *format, ...);

//! Conversions

int		char_conversion(t_flags *flags, va_list args);

int		string_conversion(t_flags *flags, va_list args);

int		integer_conversion(t_flags *flags, va_list args);

int		pointer_conversion(t_flags *flags, va_list args);

int		unsigned_conversion(t_flags *flags, va_list args);

int		hexadecimal_conversion(t_flags *flags, va_list args, int is_upper);

int		module_conversion(t_flags *flags);

//! Utils module

int		ft_numsize(long long n);

void	ft_putnbr_base(unsigned long long n, char *base, int *size);

void	ft_toupper_helper(unsigned int dummy, char *c);

//! Flags module

t_flags	*new_flags(void);

t_flags	*consume_flags(const char *format, size_t *i);

void	print_flags(const t_flags *flags);

#endif