/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:22 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/03 20:57:52 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	push_bottom(stack, pop_top(stack));
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	push_bottom(stack, pop_top(stack));
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	push_bottom(stack_a, pop_top(stack_a));
	push_bottom(stack_b, pop_top(stack_b));
	ft_printf("rr\n");
}
