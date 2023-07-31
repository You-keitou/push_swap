/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:17:09 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 07:19:54 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->target && stack_a->cheapest)
	{
		rr(stack_a->head, stack_b->head);
		stack_a->cheapest--;
		stack_a->target--;
	}
	if (stack_a->cheapest != 0)
	{
		while (stack_a->cheapest--)
			ra(stack_a->head);
	}
	else
	{
		while (stack_a->target--)
			rb(stack_b->head);
	}
}

void	rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	int	rra_cost;
	int	rrb_cost;

	rra_cost = stack_a->size - stack_a->cheapest;
	rrb_cost = stack_b->size - stack_a->target;
	while (rra_cost && rrb_cost)
	{
		rrr(stack_a->head, stack_b->head);
		rra_cost--;
		rrb_cost--;
	}
	if (rra_cost != 0)
	{
		while (rra_cost--)
			rra(stack_a->head);
	}
	else
	{
		while (rrb_cost--)
			rrb(stack_b->head);
	}
}

void	ra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	int	rrb_cost;

	rrb_cost = stack_b->size - stack_a->target;
	while (stack_a->cheapest--)
		ra(stack_a->head);
	while (rrb_cost--)
		rrb(stack_b->head);
}

void	rra_rb(t_stack *stack_a, t_stack *stack_b)
{
	int	rra_cost;

	rra_cost = stack_a->size - stack_a->cheapest;
	while (rra_cost--)
		rra(stack_a->head);
	while (stack_a->target--)
		rb(stack_b->head);
}
