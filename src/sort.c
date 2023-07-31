/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:30:27 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 00:21:52 by jinyang          ###   ########.fr       */
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

static void	sort_under_six(t_list **stack_a, t_list **stack_b)
{
	int	stack_head_num;
	int	will_push_num;

	will_push_num = 0;
	while (ft_lstsize(*stack_a) > 3)
	{
		stack_head_num = *((*(stack_a))->content);
		if (will_push_num == stack_head_num)
		{
			pb(stack_a, stack_b);
			will_push_num++;
		}
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_stack	*stack_manage;

	stack_manage = (t_stack *)malloc(sizeof(t_stack));
	stack_manage->head = stack_a;
	stack_manage->size = size;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 6)
		sort_under_six(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b, stack_manage);
}
