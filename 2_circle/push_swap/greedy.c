/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:50:27 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/05 22:44:41 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_pb(t_stack *stack_a, t_stack *stack_b, int rank)
{
	t_stack_node	*cur;
	int				i;
	int				cnt;
	int				pivot[2];

	pivot[0] = rank / 3;
	pivot[1] = rank / 3 * 2;
	i = 0;
	cnt = stack_a->cnt;
	while (i < cnt)
	{
		cur = stack_a->top->next;
		if (cur->rank > pivot[1])
			ra(stack_a);
		else if (pivot[0] < cur->rank && cur->rank <= pivot[1])
			pb(stack_a, stack_b);
		else if (cur->rank <= pivot[0])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		i++;
	}
	while (stack_a->cnt > 3)
		pb(stack_a, stack_b);
}

int	find_max(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				rank;

	cur = stack_a->top->next;
	rank = 0;
	while (cur->next)
	{
		if (rank < cur->rank)
			rank = cur->rank;
		cur = cur->next;
	}
	return (rank);
}

int	get_max(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				rank;
	int				cnt;

	cnt = 0;
	cur = stack_a->top->next;
	rank = find_max(stack_a);
	while (cur->next)
	{
		if (rank == cur->rank)
			break ;
		cnt++;
		cur = cur->next;
	}
	return (cnt);
}

int	get_cnt(t_stack *stack_a, int rank, int temp)
{
	t_stack_node	*cur;
	int				cnt;

	cnt = 0;
	cur = stack_a->top->next;
	while (cur->next)
	{
		if (temp == cur->rank)
			break ;
		cnt++;
		cur = cur->next;
	}
	if (temp < rank)
		cnt++;
	return (cnt);
}

int	ft_abs(int num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}
int	get_diff(t_stack *stack_a, int rank)
{
	t_stack_node	*cur;
	int				temp;
	int				diff;
	int				cnt;

	diff = MAX;
	cur = stack_a->top->next;
	while (cur->next)
	{
		if (diff > ft_abs(cur->rank - rank))
		{
			diff = ft_abs(cur->rank - rank);
			temp = cur->rank;
		}
		cur = cur->next;
	}
	cnt = get_cnt(stack_a, rank, temp);
	return (cnt);
}

int	set_a_location(t_stack *stack_a, int rank)
{
	t_stack_node	*cur;
	int				cnt;

	cnt = 0;
	cur = stack_a->top->next;
	while (cur->next)
	{
		if (rank > find_max(stack_a))
		{
			cnt = get_max(stack_a) + 1;
			break;
		}
		else
			cnt = get_diff(stack_a, rank);
		cur = cur->next;
	}
	if (cnt >= (stack_a->cnt / 2))
		cnt = cnt - stack_a->cnt;
	return (cnt);
}


int	get_bigger(int a, int b, int a_loc, int b_loc)
{
	return (ft_abs(a) + ft_abs(b) > ft_abs(a_loc) + ft_abs(b_loc));
}

void	get_min_rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	t_stack_node	*cur;
	int				a_loc;
	int				b_loc;
	int				i;
	int				rank;

	i = 0;
	cur = stack_b->top->next;
	while (i < stack_b->cnt)
	{
		rank = cur->rank;
		a_loc = set_a_location(stack_a, rank);
		if (i >= (stack_b->cnt) / 2)
			b_loc = i - stack_b->cnt;
		else
			b_loc = i;
		if (i == 0 || get_bigger(*a, *b, a_loc, b_loc))
		{
			*a = a_loc;
			*b = b_loc;
		}
		cur = cur->next;
		i++;
	}
}

void	rotate_same(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		rr(stack_a, stack_b);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		rrr(stack_a, stack_b);
		(*a)++;
		(*b)++;
	}
}

void	rotate_a(t_stack  *stack_a, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stack_a);
			a--;
		}
		else
		{
			rra(stack_a);
			a++;
		}
	}
}

void	rotate_b(t_stack *stack_b, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stack_b);
			b--;
		}
		else
		{
			rrb(stack_b);
			b++;
		}
	}
}

void	greedy(t_stack *stack_a, t_stack *stack_b, int rank)
{
	int				a;
	int				b;

	greedy_pb(stack_a, stack_b, rank);
	sort_small(stack_a, stack_b);
	while (stack_b->cnt)
	{
		a = stack_a->cnt;
		b = stack_b->cnt;
		get_min_rotate(stack_a, stack_b, &a, &b);
		rotate_same(stack_a, stack_b, &a, &b);
		rotate_a(stack_a, a);
		rotate_b(stack_b, b);
		pa(stack_a, stack_b);
	}
//	sort_last(stack_a);
}
