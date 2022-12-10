/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:40:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 10:45:29 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	ft_memmove(dest, src, n);
	return (dest);
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
	size_t n1 = 7 * sizeof(int);
	int test1[10] = {1, 324, 2, -123, 0, INT_MAX, INT_MIN};
	int test1res[10] = {0};
	
	size_t n2 = 20;
	char test2[] = "Nuno Jesus";
	char test2res[20] = {0};
	
	printf("\n\t>>> TEST1: USING memcpy() <<<\n\n");
	printf("Sending:\n\ttest1res =  ");
	print_array(test1res, sizeof(int), n1 / sizeof(int));
	
	memcpy(test1res, test1, n1);
	printf("Result:\n\ttest1res =  ");
	print_array(test1res, sizeof(int), n1 / sizeof(int));
	
	printf("\n\t>>> TEST1: USING ft_memcpy() <<<\n\n");
	bzero(test1res, n1);
	printf("Sending:\n\ttest1res =  ");
	print_array(test1res, sizeof(int), n1 / sizeof(int));
	
	ft_memcpy(test1res, test1, n1);
	printf("Result:\n\ttest1res =  ");
	print_array(test1res, sizeof(int), n1 / sizeof(int));
	
	printf("\n\t>>> TEST2: USING memcpy() <<<\n\n");
	printf("Sending:\n\ttest2res =  ");
	print_array(test2res, sizeof(char), n2);
	
	memcpy(test2res, test2, n2);
	printf("Result:\n\ttest2res =  ");
	print_array(test2res, sizeof(char), n2);
	
	printf("\n\t>>> TEST2: USING ft_memcpy() <<<\n\n");
	bzero(test2res, n2);
	printf("Sending:\n\ttest2res =  ");
	print_array(test2res, sizeof(char), n2);
	
	ft_memcpy(test2res, test2, n2);
	printf("Result:\n\ttest2res =  ");
	print_array(test2res, sizeof(char), n2);
} */