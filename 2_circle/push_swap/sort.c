/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:34:32 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/05 22:33:50 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a, int *arr)
{
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return ;
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		sa(stack_a);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		rra(stack_a);
	else if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (arr[1] < arr[2] && arr[2] < arr[0])
	{
		ra(stack_a);
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cur;
	int				arr[3];
	int				i;

	(void)stack_b;
	i = 0;
	cur = stack_a->top->next;
	while (cur->next)
	{
		arr[i] = cur->num;
		i++;
		cur = cur->next;
	}
	sort_three(stack_a, arr);
}
