/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 03:16:56 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 08:50:33 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_min_of_stack_b(int num_a, t_list *stack_b)
{
	while (stack_b->content)
	{
		if (*(stack_b->content) < num_a)
			return false;
		stack_b = stack_b->next;
	}
	return true;
}

static int	cal_score(int index_of_a, int stack_a_num, t_list **stack_b, t_stack *stack_manage)
{
	int search_index;
	int biggest_b;
	int score[4];
	t_list *head_b;

	search_index = 0;
	head_b = *stack_b;
	biggest_b = INT_MIN;
	while (head_b->content)
	{
		if (*(head_b->content) < stack_a_num && *(head_b->content) > biggest_b)
		{
			stack_manage->b_target_tmp = search_index;
			biggest_b = *(head_b->content);
		}
		head_b = head_b->next;
		search_index++;
	}

	score[0] = ft_max(index_of_a, stack_manage->b_target_tmp);
	score[1] = ft_max(ft_lstsize(*(stack_manage->head)) - index_of_a, ft_lstsize(*stack_b) - stack_manage->b_target_tmp);
	score[2] = ft_max(index_of_a, ft_lstsize(*stack_b) - stack_manage->b_target_tmp);
	score[3] = ft_max(ft_lstsize(*(stack_manage->head)) - index_of_a, stack_manage->b_target_tmp);
	return ft_min(score[3],ft_min(ft_min(score[0], score[1]), ft_min(score[1], score[2])));
}

void	excute(t_list **stack_a, t_list **stack_b, t_stack *stack_manage)
{
	int a_len;
	int b_len;
	int a_rr_score;
	int b_rr_score;

	a_len = ft_lstsize(*stack_a);
	b_len = ft_lstsize(*stack_b);
	a_rr_score = a_len - stack_manage->cheapest_a_index;
	b_rr_score = b_len - stack_manage->b_target;
	if (a_rr_score > stack_manage->cheapest_a_index)
		while (stack_manage->cheapest_a_index)
		{
			ra(stack_a);
			stack_manage->cheapest_a_index--;
		}
	else
		while (a_rr_score)
		{
			rra(stack_a);
			a_rr_score--;
		}
	if (b_rr_score > stack_manage->b_target)
		while (stack_manage->b_target)
		{
			rb(stack_b);
			stack_manage->b_target--;
		}
	else
		while (b_rr_score)
		{
			rrb(stack_b);
			b_rr_score--;
		}
	pb(stack_a, stack_b);
}

void	siage(t_list **stack_a, t_list **stack_b, t_stack *stack_manage)
{
	int prev;
	int cur;

	while(ft_lstsize(*stack_b))
	{
		prev = *(*stack_b)->content;
		pa(stack_a, stack_b);
		if ((*stack_b)->content)
			cur = *(*stack_b)->content;
		else
			break;
		if (cur != prev - 1)
		{
			if (cur == stack_manage->size - 1)
				continue;
			while (*(*stack_a)->content != cur + 1)
				ra(stack_a);
		}
	}
	while (*(*stack_a)->content)
		ra(stack_a);
}

void	sort_complex(t_list **stack_a, t_list **stack_b, t_stack *stack_manage)
{
	t_list *tmp;
	int	search_index;
	int	min_score;

	while (ft_lstsize(*stack_a) > 3)
	{
		if (is_min_of_stack_b(*(*stack_a)->content, *stack_b))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		search_index = 0;
		tmp = *stack_a;
		min_score = 0x7fffffff;
		while (tmp->content)
		{
			if (min_score > cal_score(search_index, *(tmp->content) ,stack_b, stack_manage))
			{
				stack_manage->b_target = stack_manage->b_target_tmp;
				stack_manage->cheapest_a_index = search_index;
				min_score = cal_score(search_index, *(tmp->content), stack_b, stack_manage);
			}
			tmp = tmp->next;
			search_index++;
		}
		excute(stack_a, stack_b, stack_manage);
	}
	siage(stack_a, stack_b, stack_manage);
}
