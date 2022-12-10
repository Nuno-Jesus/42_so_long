/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:57 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:42:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/* 
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
	
	int size = atoi(argv[1]);
	t_list* lst = NULL;

	for(int i = 0; i < size; i++)
		ft_lstadd_back(&lst, ft_lstnew(strdup("WORD")));

	ft_lstadd_back(&lst, ft_lstnew(strdup("TAIL")));
	ft_lstprint(lst);
	
	printf("\nLast content: %s\n", (char*)ft_lstlast(lst)->content);

	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");
	
	(void)ft_lstiter(NULL, &delete);
	printf("It worked with a NULL list.\n");
	
	ft_lstclear(&lst, &delete);
}
 */