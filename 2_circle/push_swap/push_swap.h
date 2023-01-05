/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocheon <wocheon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:40:28 by wocheon           #+#    #+#             */
/*   Updated: 2023/01/04 17:44:24 by wocheon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node
{
	int					num;
	int					rank;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				cnt;
}	t_stack;

void			ft_error(void);
void			push_swap(int argc, char **argv);
void			init_deque(t_stack *stack);
int				make_stack(t_stack *stack, char **argv);
void			is_valid(t_stack *stack, char *str);
int				num_check(char *str);
int				dup_check(t_stack *stack, long long num);
t_stack_node	*init_new_node(t_stack *stack, int num);
void			push_top(t_stack *stack, t_stack_node *new_node);
void			push_bottom(t_stack *stack, t_stack_node *new_node);
t_stack_node	*pop_top(t_stack *stack);
t_stack_node	*pop_bottom(t_stack *stack);
int				find_rank(t_stack *stack, t_stack_node *new);
void			greedy(t_stack *stack_a, t_stack *stack_b, int rank);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack_a, t_stack *stack_b);
void			sort_small(t_stack *stack_a, t_stack *stack_b);
void			sort_three(t_stack *stack_a, int *arr);

#endif
