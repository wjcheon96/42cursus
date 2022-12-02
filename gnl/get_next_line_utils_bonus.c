#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*find_newline(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (str);
			str++;
		}
	}
	return (NULL);
}

static t_list	*ft_lst_create(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> fd = fd;
	new -> backup = NULL;
	new -> next = NULL;
	return (new);
}

t_list	*ft_lst_find_create(t_list **list, int fd)
{
	t_list	*cur;

	if (*list == NULL)
	{
		*list = ft_lst_create(fd);
		return (*list);
	}
	cur = *list;
	while (cur -> fd != fd)
	{
		if (cur -> next == NULL)
			cur -> next = ft_lst_create(fd);
		cur = cur -> next;
		if (cur == NULL)
			return (NULL);
	}
	return (cur);
}
