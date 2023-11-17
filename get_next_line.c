/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:55:33 by mel-meka          #+#    #+#             */
/*   Updated: 2023/11/10 16:43:16 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char	*get_line_from_file(char **ptr)
{
	size_t	len;
	char	*line;
	char	*read_ptr;

	read_ptr = *ptr;
	len = 0;
	while (read_ptr[len] != '\0')
	{
		if (read_ptr[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	if (len == 0)
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, read_ptr, len);
	line[len] = '\0';
	read_ptr += len;
	*ptr = read_ptr;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file;
	static char	*read_ptr;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (file == NULL)
	{
		file = load_file(fd);
		read_ptr = file;
	}
	if (file == NULL)
		return (NULL);
	line = get_line_from_file(&read_ptr);
	if (*read_ptr == '\0')
	{
		free(file);
		file = NULL;
	}
	return (line);
}

// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (i < ac)
// 	{
// 		int fd = open(av[i], O_RDWR);
// 		while (1)
// 		{
// 			char *line = get_next_line(fd);
// 			if (line == NULL)
// 				break;
// 			printf("%s", line);
// 			free(line);
// 		}
// 		close(fd);
// 		i++;
// 	}
// }
// // last line