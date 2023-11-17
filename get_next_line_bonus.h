#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif // !BUFFER_SIZE

# include <stddef.h>

void	ft_memcpy(char *dst, char *src, size_t len);
char	*load_file(int fd);
char	*get_next_line(int fd);

typedef struct s_files_list
{
	char				*content;
	char				*read_ptr;
	int					fd;
	struct s_files_list	*next;
}	t_files_list;

#endif
