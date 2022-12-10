/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:39:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:43:58 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*node;

	lst2 = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, node);
		lst = lst->next;
	}
	return (lst2);
}
/* 
void* change(void *content)
{
	((char*)content)[0] = 'S';
	return strdup((char *)content);
}

void delete(void *content)
{
	free(content);
}

void ft_lstprint(t_list *lst)
{
	int i = 0;
	t_list *aux = lst;
	while(aux != NULL)
	{
		printf("Content %d: \'%s\'\n", i, (char *)aux->content);
		aux = aux->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	
	printf("\n\t>>> TESTING WITH > 0 ELEMENTS <<<\n\n");
	t_list *lst = ft_lstnew(strdup("TENT"));
	int size = atoi(argv[1]);
	
	for(int i = 0; i < size; i++)
		ft_lstadd_back(&lst, ft_lstnew(strdup("TICK")));
	
	ft_lstadd_back(&lst, ft_lstnew(strdup("TAIL")));
	ft_lstprint(lst);
	
	printf("\n");
	t_list *lst2 = ft_lstmap(lst, &change, &delete);
	ft_lstprint(lst2);

	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");

	(void)ft_lstmap(NULL, &change, &delete);
	printf("It worked with NULL list.\n");

	printf("\n\t>>> TESTING WITH NULL FUNCTIONS <<<\n\n");

	(void)ft_lstmap(lst2, NULL, NULL);
	printf("It worked with NULL functions.\n");

	ft_lstclear(&lst, &delete);
	ft_lstclear(&lst2, &delete);
}
 */