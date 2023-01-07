/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:01:22 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 11:01:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_leftover(char *memory)
{
	char	*leftover;
	size_t	jump;
	size_t	len;

	len = ft_strclen(memory, '\0');
	jump = ft_strclen(memory, '\n');
	if (memory[jump] == '\n')
		jump++;
	leftover = ft_strndup(memory + jump, len - jump + 1);
	if (!leftover)
		return (NULL);
	free(memory);
	return (leftover);
}

char	*get_line(char *memory)
{
	char	*line;
	size_t	len;

	len = ft_strclen(memory, '\n');
	if (memory[len] == '\n')
		len++;
	line = ft_strndup(memory, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*store_chunks(int fd, char *memory)
{
	char	*chunk;
	ssize_t	bytes;

	bytes = 1;
	chunk = (char *)malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	while (bytes > 0 && !ft_strchr_mod(memory, '\n'))
	{
		bytes = read(fd, chunk, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[bytes] = '\0';
		memory = ft_strjoin_mod(memory, chunk);
	}
	free(chunk);
	if (ft_strclen(memory, '\0') > 0)
		return (memory);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = store_chunks(fd, memory);
	if (!memory)
		return (NULL);
	line = get_line(memory);
	memory = get_leftover(memory);
	if (!memory[0])
	{
		free(memory);
		memory = NULL;
	}
	return (line);
}

/* 
void print_chunk(char *chunk, size_t n)
{
	for(size_t i = 0; i < n; i++)
		printf("%zu - 0x%02X = %c\n", i + 1, chunk[i], chunk[i]);
}
 */
/* 
int main(int argc, char **argv)
{	
	(void)argc;
	(void)argv;

	int fd;
	if((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);

	char *res;
	
	res = get_next_line(fd);
	while (res)
	{
		puts(res);
		free(res);
		res = get_next_line(fd);
	}
} */