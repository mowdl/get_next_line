#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_memcpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*resize_file(char *file, size_t size, size_t len)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * size);
	if (tmp == NULL)
	{
		free(file);
		return (NULL);
	}
	ft_memcpy(tmp, file, len + 1);
	free(file);
	return (tmp);
}

char	*check_resize(char **file, size_t *size, size_t len, int bytes)
{
	if (*size < len + bytes + 1)
	{
		*size *= 2;
		*file = resize_file(*file, *size, len);
		if (file == NULL)
		{
			return (NULL);
		}
	}
	return (*file);
}

char	*load_file_loop(int fd, char *file, char *buf, size_t size)
{
	size_t	len;
	int		bytes;

	*file = '\0';
	len = 0;
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == 0)
	{
		free(file);
		file = NULL;
	}
	while (bytes > 0)
	{
		if (check_resize(&file, &size, len, bytes) == NULL)
			break ;
		ft_memcpy(file + len, buf, bytes);
		len += bytes;
		file[len] = '\0';
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (file);
}

char	*load_file(int fd)
{
	size_t	size;
	char	*file;
	char	*buf;

	size = 1024;
	while (size < BUFFER_SIZE)
		size *= 2;
	file = malloc(sizeof(char) * size);
	if (file == NULL)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
	{
		free(file);
		return (NULL);
	}
	return (load_file_loop(fd, file, buf, size));
}
