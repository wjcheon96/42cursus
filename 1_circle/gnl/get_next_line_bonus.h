/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:53:30 by wocheon           #+#    #+#             */
/*   Updated: 2022/12/16 22:27:59 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*data;
	int				fd;
}	t_line;

typedef struct	s_list
{
	t_line	*head;
	t_line	*tail;
}	t_list;

char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, ssize_t read_byte);
void	delete_node(t_list *list, t_line *backup);
t_line	*push_back(t_list *list, int fd);
t_line	*find_node(t_list *list, int fd);
char    *get_next_line(int fd);

#endif
