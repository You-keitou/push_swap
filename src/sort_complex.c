/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 03:16:56 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 19:31:24 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_biggest_node(t_list *stack)
{
	int res;
	int max;
	int index;

	max = INT_MIN;
	index = 0;
	res = 0;
	while (stack->content)
	{
		if (*(stack->content) > max)
		{
			res = index;
			max = *(stack->content);
		}
		index++;
		stack = stack->next;
	}
	return res;
}

static bool	is_exist(int num, t_list *stack)
{
	while (stack->content)
	{
		if (num == *(stack->content))
			return true;
		stack = stack->next;
	}
	return false;
}

static bool	is_min_of_stack(int num, t_list *stack)
{
	while (stack->content)
	{
		if (*(stack->content) < num)
			return false;
		stack = stack->next;
	}
	return true;
}

static int	find_nth_node(int num, t_list *stack)
{
	int index;

	index = 0;
	while (stack->content)
	{
		if (*(stack->content) == num)
			return index;
		index++;
		stack = stack->next;
	}
	return index;
}

static int	find_smallest_node_bigger_than(int num, t_list *stack)
{
	int res;

	res = INT_MAX;
	while (stack->content)
	{
		if (*(stack->content) > num && *(stack->content) < res)
			res = *(stack->content);
		stack = stack->next;
	}
	return res;
}

static void	rotate_to_top(int num, t_list **stack_a)
{
	int index;
	int size_stack;
	int rr_cost;

	size_stack = ft_lstsize(*stack_a);
	index = find_nth_node(num, *stack_a);
	rr_cost = size_stack - index;
	if (rr_cost < index)
		while(rr_cost--)
			rra(stack_a);
	else
		while (index--)
			ra(stack_a);
}

static int	cal_score(int index_of_a, int stack_a_num, t_list **stack_b, t_stack *stack_manage)
{
	int search_index;
	int biggest_b;
	int score[4];
	t_list *head_b;

	if (stack_a_num == 1)
	{
		stack_a_num++;
		stack_a_num--;
	}
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
	if (biggest_b == INT_MIN)
		stack_manage->b_target_tmp = find_biggest_node(*stack_b);
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
	if (is_min_of_stack(*(*stack_b)->content, *stack_b))
		rb(stack_b);
}

void	print_all(t_list *stack)
{
	ft_printf("######################\n");
	while (stack->content)
	{
		ft_printf("%d\n", *(stack->content));
		stack = stack->next;
	}
}

void	siage(t_list **stack_a, t_list **stack_b)
{
	t_list *b_head;
	int 	rr_cost;
	int 	r_cost;

	sort_three(stack_a);
	while (ft_lstsize(*stack_b))
	{
		b_head = *stack_b;
		if (is_exist(*(b_head->content) + 1, *stack_a))
			rotate_to_top(*(b_head->content) + 1, stack_a);
		else
			rotate_to_top(find_smallest_node_bigger_than(*(b_head->content), *stack_a), stack_a);
		pa(stack_a, stack_b);
	}
	print_all(*stack_a);
	print_all(*stack_b);
	rr_cost = ft_lstsize(*stack_a) - find_nth_node(0, *stack_a);
	r_cost = find_nth_node(0, *stack_a);
	if (rr_cost < r_cost)
		while (rr_cost--)
			rra(stack_a);
	else
		while (r_cost--)
			ra(stack_a);
}

void sort_complex(t_list * *stack_a, t_list * *stack_b, t_stack * stack_manage)
{
	t_list *tmp;
	int search_index;
	int min_score;

	while (ft_lstsize(*stack_a) > 3)
	{
		search_index = 0;
		tmp = *stack_a;
		min_score = 0x7fffffff;
		while (tmp->content)
		{
			if (min_score > cal_score(search_index, *(tmp->content), stack_b, stack_manage))
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
	print_all(*stack_a);
	print_all(*stack_b);
	siage(stack_a, stack_b);
}
