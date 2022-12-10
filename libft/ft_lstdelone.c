/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:38:50 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:42:45 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
	
	printf("\n\t>>> TESTING WITH NULL LIST <<<\n\n");
	
	ft_lstdelone(NULL, &delete);
	
	printf("It worked with a NULL list.\n");
	printf("\n\t>>> TESTING WITH NULL FUNCTION <<<\n\n");

	ft_lstdelone(lst, NULL);
	printf("It worked with a NULL function.\n");
}
 */