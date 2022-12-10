/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:39:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:42:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

	t_list *lst = ft_lstnew(strdup("HEAD"));
	int size = atoi(argv[1]);
	
	for(int i = 0; i < size; i++)
		ft_lstadd_back(&lst, ft_lstnew(strdup("WORD")));

	ft_lstadd_back(&lst, ft_lstnew(strdup("TAIL")));
	
	printf("The given list has size: %d\n", ft_lstsize(lst));
	ft_lstprint(lst);
	
	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");

	printf("The given list has size: %d\n", ft_lstsize(NULL));
	ft_lstclear(&lst, &delete);
}
 */