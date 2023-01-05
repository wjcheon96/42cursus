/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:31:52 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/05 22:32:03 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_stack *stack, long long num)
{
	t_stack_node	*cur;

	cur = stack->top->next;
	if (num == 0)
	{
		while (cur->next)
		{
			if (cur->num == 0)
				return (0);
			else
				cur = cur->next;
		}
		return (1);
	}
	cur = stack->top->next;
	while (cur->next)
	{
		if (cur->num == num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	num_check(char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	is_valid(t_stack *stack, char *str)
{
	char	**split_str;
	int		rank;

	rank = 0;
	split_str = ft_split(str, ' ');
	if (!split_str)
		ft_error();
	while (*split_str)
	{
		if (!num_check(*split_str))
			ft_error();
		if (ft_atoi(*split_str) > MAX || ft_atoi(*split_str) < MIN)
			ft_error();
		if (!dup_check(stack, ft_atoi(*split_str)))
			ft_error();
		push_bottom(stack, init_new_node(stack, ft_atoi(*split_str)));
		split_str++;
	}
}
