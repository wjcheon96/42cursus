/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:01:21 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/04 14:33:03 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*init_new_node(t_stack *stack, int num)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		ft_error();
	new->next = NULL;
	new->prev = NULL;
	new->num = num;
	new->rank = find_rank(stack, new);
	return (new);
}

void	push_top(t_stack *stack, t_stack_node *new_node)
{
	new_node->next = stack->top->next;
	stack->top->next->prev = new_node;
	new_node->prev = stack->top;
	stack->top->next = new_node;
	(stack->cnt)++;
}

void	push_bottom(t_stack *stack, t_stack_node *new_node)
{
	new_node->prev = stack->bottom->prev;
	stack->bottom->prev->next = new_node;
	new_node->next = stack->bottom;
	stack->bottom->prev = new_node;
	(stack->cnt)++;
}

t_stack_node	*pop_top(t_stack *stack)
{
	t_stack_node	*cur;

	cur = stack->top->next;
	if (cur)
	{
		stack->top->next = cur->next;
		cur->next->prev = stack->top;
		(stack->cnt)--;
		return (cur);
	}
	else
		return (NULL);
}

t_stack_node	*pop_bottom(t_stack *stack)
{
	t_stack_node	*cur;

	cur = stack->bottom->prev;
	if (cur)
	{
		stack->bottom->prev = cur->prev;
		cur->prev->next = stack->bottom;
		(stack->cnt--);
		return (cur);
	}
	else
		return (NULL);
}
