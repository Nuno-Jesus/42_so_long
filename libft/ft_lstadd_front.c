/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:43:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}	
}
/* 
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

void delete(void *content)
{
	free(content);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	printf("\n\t>>> TESTING WITH > 0 ELEMENTS <<<\n\n");
	
	int size = atoi(argv[1]);
	t_list *lst = ft_lstnew(strdup("TAIL"));
	
	for(int i = 0; i < size; i++)
		ft_lstadd_front(&lst, ft_lstnew(strdup("BODY")));

	ft_lstadd_front(&lst, ft_lstnew(strdup("HEAD")));
	ft_lstprint(lst);

	printf("\n\t>>> TESTING WITH NULL LIST HEAD <<<\n\n");
	
	t_list *lst2 = NULL;
	
	ft_lstadd_front(&lst2, ft_lstnew(strdup("HEAD")));
	ft_lstprint(lst2);
	
	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");
	
	ft_lstadd_front(NULL, NULL);
	printf("It worked.\n");
	
	ft_lstclear(&lst, &delete);
	ft_lstclear(&lst2, &delete);
} */
