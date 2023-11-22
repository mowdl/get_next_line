/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:08:15 by mel-meka          #+#    #+#             */
/*   Updated: 2023/11/21 23:57:34 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif // !BUFFER_SIZE

# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_memchr(char *buf, char c, size_t bytes);
void	ft_memcpy(char *dst, char *src, size_t n);

typedef struct s_string {
	char	*s;
	size_t	len;
	size_t	size;
}			t_string;

#endif
