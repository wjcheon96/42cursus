/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:49:29 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/04 19:23:26 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_stack_node	*cur;

	if (stack->cnt < 2)
		return ;
	cur = pop_top(stack);
	cur->next = stack->top->next->next;
	stack->top->next->next->prev = cur;
	cur->prev = stack->top->next;
	stack->top->next->next = cur;
	(stack->cnt)++;
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	t_stack_node	*cur;

	if (stack->cnt < 2)
		return ;
	cur = pop_top(stack);
	cur->next = stack->top->next->next;
	stack->top->next->next->prev = cur;
	cur->prev = stack->top->next;
	stack->top->next->next = cur;
	(stack->cnt)++;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cur;

	if (stack_a->cnt < 2 || stack_a->cnt < 2)
		return ;
	cur = pop_top(stack_a);
	cur->next = stack_a->top->next->next;
	stack_a->top->next->next->prev = cur;
	cur->prev = stack_a->top->next;
	stack_a->top->next->next = cur;
	cur = pop_top(stack_b);
	cur->next = stack_b->top->next->next;
	stack_b->top->next->next->prev = cur;
	cur->prev = stack_b->top->next;
	stack_b->top->next->next = cur;
	(stack_a->cnt)++;
	(stack_b->cnt)++;
	ft_printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_top(stack_a, pop_top(stack_b));
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_top(stack_b, pop_top(stack_a));
	ft_printf("pb\n");
}
