/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:39:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:41:55 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}
/* 
void delete(void *content)
{
	if(content)
		free(content);
}

int main(int argc, char **argv)
{	
	(void) argc;
	
	printf("\n\t>>> TESTING WITH NON-NULL CONTENT <<<\n\n");
	t_list* new = ft_lstnew(strdup(argv[1]));
	if(!new)
	{
		perror("malloc(): ");
		return -1;
	}
	
	printf("The inputed string was: \'%s\'\n", (char *)new->content);

	printf("\n\t>>> TESTING WITH NULL CONTENT <<<\n\n");
	t_list* new2 = ft_lstnew(NULL);
	if(!new2)
	{
		perror("malloc(): ");
		return -1;
	}
	
	printf("The inputed string was: \'%s\'\n", (char *)new->content);
	
	ft_lstdelone(new, &delete);
	ft_lstdelone(new2, &delete);
}
 */