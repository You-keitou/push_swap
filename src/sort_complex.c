/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 03:16:56 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 03:06:57 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cal_score(int index_of_a, int stack_a_num, t_stack *stack_a, t_stack *stack_b)
{
	int		search_index;
	int		biggest_b;
	int		score[4];
	t_list	*head_b;

	search_index = 0;
	head_b = *stack_b->head;
	biggest_b = INT_MIN;
	while (head_b->content)
	{
		if (*(head_b->content) < stack_a_num && *(head_b->content) > biggest_b)
		{
			stack_a->b_target_tmp = search_index;
			biggest_b = *(head_b->content);
		}
		head_b = head_b->next;
		search_index++;
	}
	if (biggest_b == INT_MIN)
		stack_a->b_target_tmp = find_biggest_node(*stack_b->head, INT_MAX);
	score[0] = ft_max(index_of_a, stack_a->b_target_tmp);
	score[1] = ft_max(stack_a->size - index_of_a,
		stack_b->size - stack_a->b_target_tmp);
	score[2] = ft_max(index_of_a, stack_b->size
		- stack_a->b_target_tmp);
	score[3] = ft_max(stack_a->size - index_of_a,
		stack_a->b_target_tmp);
	return (ft_min(score[3], ft_min(ft_min(score[0], score[1]), ft_min(score[1],
					score[2]))));
}

static void	excute(t_stack *stack_a, t_stack *stack_b)
{
	int	a_rr_score;
	int	b_rr_score;

	a_rr_score = stack_a->size - stack_a->cheapest_a_index;
	b_rr_score = stack_b->size - stack_a->b_target;
	if (a_rr_score > stack_a->cheapest_a_index)
		while (stack_a->cheapest_a_index)
		{
			ra(stack_a->head);
			stack_a->cheapest_a_index--;
		}
	else
		while (a_rr_score)
		{
			rra(stack_a->head);
			a_rr_score--;
		}
	if (b_rr_score > stack_a->b_target)
		while (stack_a->b_target)
		{
			rb(stack_b->head);
			stack_a->b_target--;
		}
	else
		while (b_rr_score)
		{
			rrb(stack_b->head);
			b_rr_score--;
		}
	pb(stack_a, stack_b);
	if (is_min_of_stack(*(*stack_b->head)->content, *stack_b->head))
		rb(stack_b->head);
}

void	siage(t_stack *stack_a, t_stack *stack_b)
{
	int	rr_cost;
	int	r_cost;

	while (stack_b->size)
		pa(stack_a, stack_b);
	rr_cost = stack_a->size - find_nth_node(0, *stack_a->head);
	r_cost = find_nth_node(0, *stack_a->head);
	if (rr_cost < r_cost)
		while (rr_cost--)
			rra(stack_a->head);
	else
		while (r_cost--)
			ra(stack_a->head);
}

void	sort_complex(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	int		search_index;
	int		min_score;

	while (stack_a->size > 0)
	{
		search_index = 0;
		tmp = *stack_a->head;
		min_score = 0x7fffffff;
		while (tmp->content)
		{
			if (min_score > cal_score(search_index, *(tmp->content), stack_a, stack_b))
			{
				stack_a->b_target = stack_a->b_target_tmp;
				stack_a->cheapest_a_index = search_index;
				min_score = cal_score(search_index, *(tmp->content), stack_a, stack_b);
			}
			tmp = tmp->next;
			search_index++;
		}
		excute(stack_a, stack_b);
	}
	siage(stack_a, stack_b);
}
