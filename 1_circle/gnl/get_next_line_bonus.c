#include "get_next_line_bonus.h"

static char	*ft_strjoin(char *s1, const char *s2, size_t s1_len, size_t s2_len)
{
	char	*str;
	size_t	idx;

	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	idx = 0;
	while (idx < s1_len)
	{
		str[idx] = s1[idx];
		idx++;
	}
	while (*s2)
		str[idx++] = *s2++;
	str[idx] = '\0';
	if (s1)
		free(s1);
	return (str);
}

static char	*ft_line_read(int fd, char *backup)
{
	char	*buf;
	size_t	read_byte;
	size_t	backup_len;

	if (find_newline(backup))
		return (backup);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	backup_len = ft_strlen(backup);
	buf[0] = '\0';
	while (!find_newline(buf))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buf[read_byte] = '\0';
		backup = ft_strjoin(backup, buf, backup_len, read_byte);
		backup_len += read_byte;
		if (!backup)
			break ;
	}
	free(buf);
	return (backup);
}

static char	*get_line(char	**backup_ptr, char *backup)
{
	char	*line;
	char	*newline_idx;
	size_t	i;

	newline_idx = find_newline(backup);
	if (!newline_idx)
	{
		line = backup;
		*backup_ptr = NULL;
		return (line);
	}
	line = malloc((newline_idx - backup + 2) * sizeof(char));
	if (!line)
	{
		free(backup);
		*backup_ptr = NULL;
		return (NULL);
	}
	i = 0;
	while (backup != newline_idx)
		line[i++] = *backup++;
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*buf_list = NULL;
	t_list			*cur_list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cur_list = ft_lst_find_create(&buf_list, fd);
	if (!cur_list)
		return (NULL);
	cur_list -> backup = ft_line_read(fd, cur_list -> backup);
	if (cur_list -> backup != NULL)
		line = get_line(&cur_list -> backup, cur_list -> backup);
	else
		line = NULL;

}
