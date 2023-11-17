#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

t_files_list	*load_new_file_to_list(int fd, t_files_list **files_lst)
{
	char			*content;
	t_files_list	*file;

	file = (t_files_list *)malloc(sizeof(t_files_list) * 1);
	if (file == NULL)
		return (NULL);
	content = load_file(fd);
	if (content == NULL)
	{
		free(file);
		return (NULL);
	}
	file->next = *files_lst;
	*files_lst = file;
	file->content = content;
	file->read_ptr = content;
	file->fd = fd;
	return (file);
}

t_files_list	*get_file_from_list(int fd, t_files_list **files_lst)
{
	t_files_list	*file;

	if (files_lst == NULL)
	{
		files_lst = malloc(sizeof(t_files_list) * 1);
		if (files_lst == NULL)
			return (NULL);
		*files_lst = (NULL);
	}
	file = *files_lst;
	while (file != NULL)
	{
		if (file->fd == fd)
			break ;
		file = file->next;
	}
	if (file == NULL)
	{
		file = load_new_file_to_list(fd, files_lst);
		if (file == NULL)
			return (NULL);
	}
	return (file);
}

void	remove_file_from_list(int fd, t_files_list **files_lst)
{
	t_files_list	*prev;
	t_files_list	*to_delete;

	to_delete = NULL;
	if (fd == (*files_lst)->fd)
	{
		to_delete = *files_lst;
		*files_lst = to_delete->next;
		free(to_delete->content);
		free(to_delete);
		return ;
	}
	prev = *files_lst;
	while (to_delete == NULL)
	{
		if (prev->next->fd == fd)
			to_delete = prev->next;
		else
			prev = prev->next;
	}
	prev->next = to_delete->next;
	free(to_delete->content);
	free(to_delete);
}

char	*get_next_line(int fd)
{
	static t_files_list	*files_lst;
	t_files_list		*file;
	char				*line;

	if (fd < 0)
		return (NULL);
	file = get_file_from_list(fd, &files_lst);
	if (file == NULL)
		return (NULL);
	line = get_line_from_file(&(file->read_ptr));
	if (file->read_ptr[0] == '\0')
		remove_file_from_list(fd, &files_lst);
	return (line);
}

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	int fds[ac-1];
// 	while (i < ac)
// 	{
// 		fds[i] = open(av[i+1], O_RDWR);
// 		i++;
// 	}
// 	int read = 1;
// 	while (read)
// 	{
// 		read = 0;
// 		i = 0;
// 		char *line;
// 		while (i < ac - 1)
// 		{
// 			line = get_next_line(fds[i]);
// 			if (line != NULL)
// 			{
// 				read = 1;
// 				printf("from file %s: %s", av[i+1], line);
// 			}
// 			free(line);
// 			i++;
// 		}
// 	}
// }
// // last line
