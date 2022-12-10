/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:44:06 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/06 12:52:09 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_delim(char const *str, char delim)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delim)
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char delim)
{
	size_t	i;
	size_t	len;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == delim)
			i++;
		len = ft_strlen_delim(s + i, delim);
		i += len;
		if (len > 0)
			n++;
	}
	return (n);
}

static void	*ft_delete_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		k;
	int		num;
	char	**words;

	if (!s)
		return (NULL);
	i = 0;
	k = -1;
	num = ft_count_words(s, c);
	words = (char **)malloc((num + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (++k < num)
	{
		while (s[i] == c)
			i++;
		words[k] = ft_substr(s, i, ft_strlen_delim(s + i, c));
		if (!words[k])
			return (ft_delete_matrix(words));
		i += ft_strlen_delim(s + i, c);
	}
	words[num] = NULL;
	return (words);
}
/* 
int main(int argc, char **argv)
{	
	(void)argc;
	char **words;
	
	words = ft_split(argv[1], argv[2][0]);

	int i = 0;
	for(; words[i]; i++)
		printf("words[%d] = \'%s\'\n", i, words[i]);
	printf("words[%d] = NULL\n", i);

	ft_delete_matrix(words);
}
 */