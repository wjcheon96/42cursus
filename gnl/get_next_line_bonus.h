#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif

typedef struct	s_list
{
	int				fd;
	char			*backup;
	struct s_lst	*next;
}	t_list;

static t_list	*ft_lst_create(int fd);
t_list			*ft_lst_find_create(t_list **list, int fd);
size_t			ft_strlen(const char *s);
char			*find_newline(char *str);
char    		*get_next_line(int fd);

#endif
