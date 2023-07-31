/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 02:22:44 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 02:33:57 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
