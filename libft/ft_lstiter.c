/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:54 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:42:36 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
void print(void *content)
{
	printf("Content: %s\n", (char *)content);
}

void delete(void *content)
{
	free(content);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	printf("\n\t>>> TESTING WITH > 0 ELEMENTS <<<\n\n");
	
	t_list *lst = ft_lstnew(strdup("HEAD"));
	int size = atoi(argv[1]);
	
	for(int i = 0; i < size; i++)
		ft_lstadd_back(&lst, ft_lstnew(strdup("BODY")));

	ft_lstadd_back(&lst, ft_lstnew(strdup("TAIL")));
	
	ft_lstiter(lst, &print);

	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");
	
	ft_lstiter(NULL, &delete);
	
	printf("It worked with a NULL list.\n");
	printf("\n\t>>> TESTING WITH NULL FUNCTION <<<\n\n");

	ft_lstiter(lst, NULL);
	printf("It worked with a NULL function.\n");
	
	ft_lstclear(&lst, &delete);
}
 */