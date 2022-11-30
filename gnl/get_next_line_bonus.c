#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	t_list			*buf_node;
	static t_list	*root;
	int				check;
	size_t			size;
	
	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);

}
