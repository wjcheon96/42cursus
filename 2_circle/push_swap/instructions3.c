/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:14:35 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/03 21:02:30 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	push_top(stack, pop_bottom(stack));
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	push_top(stack, pop_bottom(stack));
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	push_top(stack_a, pop_bottom(stack_a));
	push_top(stack_b, pop_bottom(stack_b));
	ft_printf("rrr\n");
}
