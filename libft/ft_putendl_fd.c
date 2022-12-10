/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:42:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 19:11:55 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{	
	if (fd < 0)
		return ;
	if (s)
		ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/* 
int main(int argc, char **argv)
{
	(void) argc;
	ft_putendl_fd(argv[1], STDOUT_FILENO);
} */