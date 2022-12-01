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
	char			*buf;
	struct s_lst	*next;
	char			*backup;
}	t_list;

size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);

#endif
