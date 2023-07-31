/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 03:16:56 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 06:20:49 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cal_score(int a_index, t_stack *stack_a, t_stack *stack_b)
{
	int	rra_cost;
	int	rrb_cost;
	int	score[4];
	int	*sorted;
	int	best_score;

	rra_cost = stack_a->size - a_index;
	rrb_cost = stack_b->size - stack_a->target_tmp;
	score[0] = ft_max(a_index, stack_a->target_tmp);
	score[1] = ft_max(rra_cost, rrb_cost);
	score[2] = a_index + rrb_cost;
	score[3] = rra_cost + stack_a->target_tmp;
	sorted = bubble_sort(score, 4);
	best_score = *sorted;
	free(sorted);
	return (best_score);
}

static void	find_insert_position(t_list *node, t_stack *stack_a,
		t_stack *stack_b)
{
	int	node_num;

	node_num = *(node->content);
	if (is_min_of_stack(node_num, *stack_b->head))
		stack_a->target_tmp = find_biggest_node(*stack_b->head, INT_MAX);
	else
		stack_a->target_tmp = find_biggest_node(*stack_b->head, node_num);
}

static void	push_back(t_stack *stack_a, t_stack *stack_b)
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
		min_score = INT_MAX;
		while (tmp->content)
		{
			find_insert_position(tmp, stack_a, stack_b);
			if (min_score > cal_score(search_index, stack_a, stack_b))
			{
				stack_a->target = stack_a->target_tmp;
				stack_a->cheapest = search_index;
				min_score = cal_score(search_index, stack_a, stack_b);
			}
			tmp = tmp->next;
			search_index++;
		}
		insert(stack_a, stack_b);
	}
	push_back(stack_a, stack_b);
}
