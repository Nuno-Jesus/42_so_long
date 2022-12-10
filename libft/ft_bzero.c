/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:37:40 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 10:45:20 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/* 
void print_array(void *ptr, size_t jump, int n)
{
	printf("{");
	for(int i = 0; i < n; i++)
	{
		if(jump == 4)
			printf("%d ", ((int *)ptr)[i]);
		else
			printf("%c", ((char *)ptr)[i]);
	}
	printf("}\n");
}

int main(void)
{
	int test1[] = {1, 324, 2, -123, 0, INT_MAX, INT_MIN};
	int test1copy[] = {1, 324, 2, -123, 0, INT_MAX, INT_MIN};
	size_t n1 = 7 * sizeof(int);
	
	char test2[] = "Nuno Jesus";
	char test2copy[] = "Nuno Jesus";
	size_t n2 = 5 * sizeof(char);
	
	printf("\n\t>>> TEST1: USING bzero() <<<\n\n");
	printf("Sending:\n\ttest1 =  ");
	print_array(test1, sizeof(int), n1 / sizeof(int));
	
	bzero(test1, n1);
	printf("Result:\n\ttest1 =  ");
	print_array(test1, sizeof(int), n1 / sizeof(int));
	
	printf("\n\t>>> TEST1: USING ft_bzero() <<<\n\n");
	printf("Sending:\n\ttest1 =  ");
	print_array(test1copy, sizeof(int), n1 / sizeof(int));
	
	ft_bzero(NULL, n1);
	printf("Result:\n\ttest1 =  ");
	print_array(test1copy, sizeof(int), n1 / sizeof(int));
	
	printf("\n\t>>> TEST2: USING bzero() <<<\n\n");
	printf("Sending:\n\ttest2 =  ");
	print_array(test2, sizeof(char), 11);
	
	bzero(test2 + 5, n2);
	printf("Result:\n\ttest2 =  ");
	print_array(test2, sizeof(char), 11);
	
	printf("\n\t>>> TEST2: USING ft_bzero() <<<\n\n");
	printf("Sending:\n\ttest2 =  ");
	print_array(test2copy, sizeof(char), 11);
	
	ft_bzero(test2copy + 5, n2);
	printf("Result:\n\ttest2 =  ");
	print_array(test2copy, sizeof(char), 11);
}
 */
