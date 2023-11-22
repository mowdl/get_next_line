#include "get_next_line.h"

char	*ft_memchr(char *buf, char c, size_t bytes)
{
	while (bytes != 0)
	{
		if (*buf == c)
			return (buf);
		buf++;
		bytes--;
	}
	return (NULL);
}

void	ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}
