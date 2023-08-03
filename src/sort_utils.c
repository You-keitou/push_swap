/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:22:44 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/04 00:45:49 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(int num, t_stack *stack)
{
	int	ra_cost;
	int	rra_cost;

	ra_cost = num;
	rra_cost = stack->size - ra_cost;
	if (rra_cost <= ra_cost)
	{
		while (rra_cost--)
			rra(stack->head);
	}
	else
	{
		while (ra_cost--)
			ra(stack->head);
	}
}

int	find_nth_node(int num, t_list *stack)
{
	int	index;

	index = 0;
	while (stack->content)
	{
		if (*(stack->content) == num)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}

bool	is_min_of_stack(int num, t_list *stack)
{
	while (stack->content)
	{
		if (*(stack->content) < num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	find_biggest_node(t_list *stack, int num)
{
	int	res;
	int	max;
	int	index;

	max = INT_MIN;
	index = 0;
	res = 0;
	while (stack->content)
	{
		if (*(stack->content) > max && *(stack->content) < num)
		{
			res = index;
			max = *(stack->content);
		}
		index++;
		stack = stack->next;
	}
	return (res);
}

int	find_smallest_node(t_list *stack, int num)
{
	int	res;
	int	min;
	int	index;

	min = INT_MAX;
	index = 0;
	res = 0;
	while (stack->content)
	{
		if (*(stack->content) < min && *(stack->content) > num)
		{
			res = index;
			min = *(stack->content);
		}
		index++;
		stack = stack->next;
	}
	return (res);
}
