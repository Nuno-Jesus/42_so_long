/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:37:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/16 22:09:02 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;
	size_t	total;

	total = nmemb * size;
	buf = malloc(total);
	if (!buf)
		return (NULL);
	ft_bzero(buf, total);
	return (buf);
}
/* 
void print_array(void *ptr, size_t jump, int n)
{
	printf("{ ");
	for(int i = 0; i < n; i++)
	{
		if(jump == 4)
			printf("%d ", ((int *)ptr)[i]);
		else
			printf("0x%02X ", ((char *)ptr)[i]);
	}
	printf("}\n");
}

int main(void)
{
	int *t1 = NULL;
	int *t2 = NULL;
	size_t n1 = 10;
	
	char *t3 = NULL;
	char *t4 = NULL;
	size_t n2 = 1;
	
	printf("\n\t>>> TEST1: USING calloc() <<<\n\n");
	
	t1 = calloc(n1, sizeof(int));
	printf("Result:\n\ttest1 =  ");
	print_array(t1, sizeof(int), n1);
	
	printf("\n\t>>> TEST1: USING ft_calloc() <<<\n\n");
	
	t2 = ft_calloc(n1, sizeof(int));
	printf("Result:\n\ttest1 =  ");
	print_array(t2, sizeof(int), n1);
	
	printf("\n\t>>> TEST2: USING calloc() <<<\n\n");
	
	t3 = calloc(n1, sizeof(char));
	printf("Result:\n\ttest2 =  ");
	print_array(t3, sizeof(char), n2);
	
	printf("\n\t>>> TEST2: USING ft_calloc() <<<\n\n");
	
	t4 = ft_calloc(n1, sizeof(char));
	printf("Result:\n\ttest2 =  ");
	print_array(t4, sizeof(char), n2);

	free(t1);
	free(t2);
	free(t3);
	free(t4);
} */