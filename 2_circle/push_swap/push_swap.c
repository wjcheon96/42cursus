/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:30:33 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/05 22:31:33 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rank(t_stack *stack, t_stack_node *new)
{
	t_stack_node	*cur;
	int				rank;

	rank = 0;
	cur = stack->top->next;
	while (cur->next)
	{
		if (cur->num > new->num && rank > cur->rank)
			rank = cur->rank;
		else if (cur->num < new->num && rank < cur->rank)
			rank = cur->rank;
		cur = cur->next;
	}
	if (rank == 0)
		rank++;
	cur = stack->top->next;
	while (cur->next)
	{
		if ((cur->rank == rank && cur->num > new->num) || cur->rank > rank)
			(cur->rank)++;
		else if (cur->rank == rank && cur->num < new->num)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

int	make_stack(t_stack *stack, char **argv)
{
	t_stack_node	*cur;
	int				i;
	int				rank;

	i = 1;
	rank = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			ft_error();
		else
			is_valid(stack, argv[i]);
		i++;
	}
	cur = stack->top->next;
	while (cur->next)
	{
		if (rank <= cur->rank)
			rank = cur->rank;
		cur = cur->next;
	}
	return (rank);
}

void	init_deque(t_stack *stack)
{
	stack->top = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!stack->top)
		ft_error();
	stack->bottom = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!stack->bottom)
		ft_error();
	stack->top->prev = NULL;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->bottom->next = NULL;
	stack->cnt = 0;
}

void	push_swap(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		rank;

	(void)argc;
	init_deque(&stack_a);
	if (!argv[1][0])
		ft_error();
	rank = make_stack(&stack_a, argv);
	if (stack_a.cnt <= 3)
		sort_small(&stack_a, &stack_b);
	init_deque(&stack_b);
	greedy(&stack_a, &stack_b, rank);
}
