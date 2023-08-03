/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:30:27 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/04 00:43:59 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *((*(stack_a))->content);
	second = *(((*(stack_a))->next)->content);
	third = *(((*(stack_a))->next->next)->content);
	if (first > second && second < third && third > first)
		sa(stack_a);
	else if (first > second && second > third && third < first)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && third < first)
		ra(stack_a);
	else if (first < second && second > third && third > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && third < first)
		rra(stack_a);
}

static void	sort_under_six(t_stack *stack_a, t_stack *stack_b)
{
	int		will_push_num;
	int		target_index;

	will_push_num = 0;
	while (stack_a->size > 3)
	{
		target_index = find_nth_node(will_push_num, *(stack_a->head));
		move_to_top(target_index, stack_a);
		pb(stack_a, stack_b);
		will_push_num++;
	}
	sort_three(stack_a->head);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	sort(t_list **head_a, t_list **head_b, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return ;
	stack_a->head = head_a;
	stack_a->size = size;
	stack_b->head = head_b;
	stack_b->size = 0;
	if (size == 2)
		sa(head_a);
	else if (size == 3)
		sort_three(head_a);
	else if (size <= 6)
		sort_under_six(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}
