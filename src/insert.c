/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 04:03:09 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/02 15:45:56 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_chepest_move(t_stack *stack_a, t_stack *stack_b)
{
	int	rra_score;
	int	rrb_score;
	int	score[4];
	int	i;
	int	j;

	rra_score = stack_a->size - stack_a->cheapest;
	rrb_score = stack_b->size - stack_a->target;
	score[0] = ft_max(stack_a->cheapest, stack_a->target);
	score[1] = ft_max(rra_score, rrb_score);
	score[2] = stack_a->cheapest + rrb_score;
	score[3] = rra_score + stack_a->target;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (score[i] > score[j])
				break ;
		}
		if (j == 4)
			return (i);
	}
	return (-1);
}

void	insert(t_stack *stack_a, t_stack *stack_b)
{
	int	move;

	move = find_chepest_move(stack_a, stack_b);
	if (move == 0)
		ra_rb(stack_a, stack_b);
	else if (move == 1)
		rra_rrb(stack_a, stack_b);
	else if (move == 2)
		ra_rrb(stack_a, stack_b);
	else if (move == 3)
		rra_rb(stack_a, stack_b);
	else
		exit(1);
	pb(stack_a, stack_b);
}

// void	insert(t_stack *stack_a, t_stack *stack_b)
// {
// 	int a_rr_score;
// 	int b_rr_score;

// 	a_rr_score = stack_a->size - stack_a->cheapest;
// 	b_rr_score = stack_b->size - stack_a->target;
// 	if (a_rr_score > stack_a->cheapest)
// 		while (stack_a->cheapest)
// 		{
// 			ra(stack_a->head);
// 			stack_a->cheapest--;
// 		}
// 	else
// 		while (a_rr_score)
// 		{
// 			rra(stack_a->head);
// 			a_rr_score--;
// 		}
// 	if (b_rr_score > stack_a->target)
// 		while (stack_a->target)
// 		{
// 			rb(stack_b->head);
// 			stack_a->target--;
// 		}
// 	else
// 		while (b_rr_score)
// 		{
// 			rrb(stack_b->head);
// 			b_rr_score--;
// 		}
// 	pb(stack_a, stack_b);
// 	if (is_min_of_stack(*(*stack_b->head)->content, *stack_b->head))
// 		rb(stack_b->head);
// }