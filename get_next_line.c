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

char	*get_next_line(int fd)
{
	static char		buf;
	t_string str;
	// init buff if first call
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL); 
	}
	// cpy from buf whats left from previous call
	str.size = 2 * bytes_left + 1;
	str.s = malloc(sizeof(char) * str.size);
	if (str.s == NULL)
		return (NULL);
	ft_memcpy(str.s, buf + (BUFFER_SIZE - bytes_left), bytes_left);
	str.s[bytes_left] = '\0';
	str.len = bytes_left;
	bytes_left = 0;
	// main loop
	int b_read = 0;
	int last_b_index = 0;
	while (true)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		while (last_b_index < b_read)
		{
			if (buf[])
		}
	}
}


#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd = open(av[1], O_RDWR);
		for (int i = 0; i < 100; i++)
		{
			printf("%s", get_next_line(fd));
		}
	}
}
