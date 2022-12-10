/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:46 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/05 21:30:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst != NULL)
	{
		curr = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(curr, del);
	}
}
/* 
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
	
	printf("Size before ft_lstclear(): %d\n", ft_lstsize(lst));
	ft_lstclear(&lst, &delete);
	printf("Size after ft_lstclear(): %d\n", ft_lstsize(lst));
	
	printf("\n\t>>> TESTING WITH NULL LIST HEAD <<<\n\n");
	t_list *lst2 = NULL;
	
	printf("Size before ft_lstclear(): %d\n", ft_lstsize(lst2));
	ft_lstclear(&lst2, &delete);
	printf("Size after ft_lstclear(): %d\n", ft_lstsize(lst2));
	
	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");
	
	ft_lstclear(NULL, &delete);
	printf("It worked.\n");
}
 */