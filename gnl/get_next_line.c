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

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup && ft_is_newline(backup) >= 0)
		line = backup;
}
