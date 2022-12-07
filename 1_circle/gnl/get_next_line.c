/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:29:18 by wocheon           #+#    #+#             */
/*   Updated: 2022/11/05 15:45:36 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_join_buf(char *backup, char *buf)
{
	char	*temp;

	temp = backup;
	backup = ft_strjoin(temp, buf);
	free(temp);
	temp = NULL;
	return (backup);
}

char	*ft_get_line(int fd, char *buf, char *backup)
{
	int	read_bytes;

	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (!backup)
				free(backup);
			return (NULL);
		}
		if (read_bytes == 0)
			break;
		buf[read_bytes] = '\0';
		if (!backup)
			backup = ft_strdup("");
		backup = ft_join_buf(backup, buf);
		if (!backup)
			return (NULL);
		if (ft_is_newline(buf) >= 0)
			break ;
	}
	return (backup);
}

char	*ft_backup(char **line)
{
	int		i;
	char	*new_backup;

	i = ft_is_newline(*line);
	new_backup = ft_substr(*line, i + 1, -1);
	if (!new_backup)
		return (NULL);
	if (!*new_backup)
	{
		free(new_backup);
		new_backup = NULL;
		return (NULL);
	}
	(*line)[i + 1] = '\0';
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup && ft_is_newline(backup) >= 0)
		line = backup;
	else
	{
		buf = (char *)malloc(sizeof(char)* (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		line = ft_get_line(fd, buf, backup);
		backup = NULL;
		free(buf);
		buf = NULL;
		if (!line)
			return (NULL);	
	}
	if (ft_is_newline(line) >= 0)
		backup = ft_backup(&line);
	return (line);
}
